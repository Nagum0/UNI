#include <bits/pthreadtypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <time.h>
#include <mqueue.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>

int random_szamlalas(pid_t pid, int max, int min) {
    srand(time(NULL) * pid);
    return rand() % (max - min + 1) + min;
}

#define pt(fstr, ...) {printf("[%s] "fstr"\n", whoami ?: "N/A", ##__VA_ARGS__);}
char* whoami = 0;

char* tapsi_uzenet = NULL;
char* fules_uzenet = NULL;
char* keress_meg = "Keress meg";
char* haza_terhet = "Hazaterhet";

void handler(int signumber, siginfo_t* info, void* nonused) {}

void tapsi_handler(int signumber, siginfo_t* info, void* nonused) {
    tapsi_uzenet = (char*)info->si_value.sival_ptr;
}

void fules_handler(int signumber, siginfo_t* info, void* nonused) {
    fules_uzenet = (char*)info->si_value.sival_ptr;
}

void szemafor_muvelet(int semid, int sem_op) {
    struct sembuf muvelet = {.sem_num = 0, .sem_op = sem_op, .sem_flg = 0};
    semop(semid, &muvelet, 1);
}

char* faluk[7] = { "Baratfa", "Lovas", "Kigyos-patak", "Kaposztas", "Szula", "Malom telek", "Paskom" };
size_t faluk_len = 7;

int main(int argc, char* argv[]) {
    struct sigaction sa;
    sa.sa_sigaction = handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

    int fonok_tapsi[2]; int fonok_fules[2];
    pipe(fonok_tapsi); pipe(fonok_fules);

    int tapsi_fonok[2]; int fules_fonok[2];
    pipe(tapsi_fonok); pipe(fules_fonok);
    
    key_t key = ftok(argv[0], 1);
    int shmid = shmget(key, 100, IPC_CREAT|S_IRUSR|S_IWUSR);
    int* data = (int*)shmat(shmid, NULL, 0);
    size_t tapsi_idx = 0;
    size_t fules_idx = 1;

    int semid = semget(key, 1, IPC_CREAT | 0600);
    semctl(semid, 0, SETVAL, 1);

    pid_t child1, child2;
    
    // -- TAPSI
    child1 = fork();
    if (child1 == 0) {
        whoami = "Tapsi";
        
        // 1.
        close(fonok_tapsi[1]);
        sleep(1);
        kill(getppid(), SIGUSR1);
        int faluk_vege;
        read(fonok_tapsi[0], &faluk_vege, sizeof(int));
        close(fonok_tapsi[0]);
        for (int i = 0; i < faluk_vege; ++i) {
            pt("%s", faluk[i]);
        }

        // 2.
        close(tapsi_fonok[0]);
        int n = random_szamlalas(getpid(), 100, 60);
        write(tapsi_fonok[1], &n, sizeof(int));
        close(tapsi_fonok[1]);

        // 3. & 4.
        sa.sa_sigaction = tapsi_handler;
        sigaction(SIGUSR1, &sa, NULL);

        pause();
        
        if (strcmp(tapsi_uzenet, keress_meg) == 0) {
            n = random_szamlalas(getpid(), 100, 70);
        }

        szemafor_muvelet(semid, -1);
        data[tapsi_idx] = n;
        szemafor_muvelet(semid, 1);

        shmdt(data);

        exit(0);
    }
    
    // -- FULES
    child2 = fork();
    if (child2 == 0) {
        whoami = "Fules";
        
        // 1.
        close(fonok_fules[1]);
        sleep(2);
        kill(getppid(), SIGUSR1);
        int faluk_kezdet;
        read(fonok_fules[0], &faluk_kezdet, sizeof(int));
        close(fonok_fules[0]);
        for (int i = faluk_kezdet; i < faluk_len; ++i) {
            pt("%s", faluk[i]);
        }

        // 2.
        close(fules_fonok[0]);
        int n = random_szamlalas(getpid(), 100, 60);
        write(fules_fonok[1], &n, sizeof(int));
        close(fules_fonok[1]);

        // 3.
        sa.sa_sigaction = fules_handler;
        sigaction(SIGUSR1, &sa, NULL);

        pause();

        if (strcmp(fules_uzenet, keress_meg) == 0) {
            n = random_szamlalas(getpid(), 100, 70);
        }
        
        szemafor_muvelet(semid, -1);
        data[fules_idx] = n;
        szemafor_muvelet(semid, 1);

        shmdt(data);

        exit(0);
    }

    // -- FONYUSZI
    whoami = "Fonyuszi";
    sigaction(SIGUSR1, &sa, NULL);
    close(fonok_tapsi[0]);
    close(fonok_fules[0]);
    
    // 1.
    pause();
    pause();
    int tapsi_faluk_index = 3;
    int fules_faluk_index = 4;
    write(fonok_tapsi[1], &tapsi_faluk_index, sizeof(int));
    write(fonok_fules[1], &fules_faluk_index, sizeof(int));
    close(fonok_tapsi[1]);
    close(fonok_fules[1]);

    // 2. & 3.
    int tavalyi_n1 = random_szamlalas(getpid(), 100, 50);
    int tavalyi_n2 = random_szamlalas(getpid(), 100, 50);
    union sigval msg_ptr;

    close(tapsi_fonok[1]);
    close(fules_fonok[1]);

    int tapsi_n;
    read(tapsi_fonok[0], &tapsi_n, sizeof(int));
    pt("Tapsi szamlalasa: %d", tapsi_n);

    if (tavalyi_n1 > tapsi_n) {
        pt("Tapsi keress meg!");
        msg_ptr.sival_ptr = keress_meg;
    }
    else {
        pt("Tapsi haza terhet!");
        msg_ptr.sival_ptr = haza_terhet;
    }

    sleep(1);
    sigqueue(child1, SIGUSR1, msg_ptr);

    int fules_n;
    read(fules_fonok[0], &fules_n, sizeof(int));
    pt("Fules szamlalasa: %d", fules_n);

    if (tavalyi_n2 > fules_n) {
        pt("Fules keress meg!");
        msg_ptr.sival_ptr = keress_meg;

    }
    else {
        pt("Fules haza terhet!");
        msg_ptr.sival_ptr = haza_terhet;
    }
    
    sleep(1);
    sigqueue(child2, SIGUSR1, msg_ptr);

    close(tapsi_fonok[0]);
    close(fules_fonok[0]);

    // 4.
    sleep(1);
    szemafor_muvelet(semid, -1);
    pt("Uj tapsi: %d", data[tapsi_idx]);
    tapsi_n = data[tapsi_idx];
    
    pt("Uj fules: %d", data[fules_idx]);
    fules_n = data[fules_idx];
    szemafor_muvelet(semid, 1);

    if (tapsi_n + fules_n > tavalyi_n1 + tavalyi_n2) {
        pt("Gyarapodas volt!");
    }
    else {
        pt("Nyuszifogyas volt!");
    }

    wait(NULL);
    wait(NULL);
    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID);
    
    return 0;
}
