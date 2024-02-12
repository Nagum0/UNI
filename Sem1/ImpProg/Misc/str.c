#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[256];
    int age;
} Person;

Person *createPersons(int n);
void getPersons(Person *ppl, int arraySize);
void appendPerson(Person **ppl, int *arraySize);

int main(void) {
    int arrSize = 0;

    Person *ppl = createPersons(arrSize);
    appendPerson(&ppl, &arrSize);
    getPersons(ppl, arrSize);

    return 0;
}

Person *createPersons(int n) {
    Person *ppl = malloc(n * sizeof(Person));

    for (int i = 0; i < n; i++) {
        printf("Name: ");
        scanf("%s", &ppl[i].name);

        printf("Age: ");
        scanf("%d", &ppl[i].age);
    }

    return ppl;
}

void appendPerson(Person **ppl, int *arraySize) {
    int newSize = *arraySize + 1;
    Person *temp = realloc(*ppl, newSize * sizeof(Person));

    *ppl = temp;

    printf("Name: ");
    scanf("%s", &((*ppl)[*arraySize].name));
    printf("Age: ");
    scanf("%d", &((*ppl)[*arraySize].age));

    *arraySize = newSize;
}

void getPersons(Person *ppl, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        printf("{\n");
        printf("  name: %s\n", ppl[i].name);
        printf("  age: %d\n", ppl[i].age);
        printf("}\n");
    }
}