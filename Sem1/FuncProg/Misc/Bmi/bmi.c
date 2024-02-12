#include <stdio.h>

void bmiTell(double bmi) {
    if (bmi <= 18.5) {
        printf("Skinny!\n");
    }
    else if (bmi <=25.0){
        printf("Normal...\n");
    }
    else if (bmi <= 30.0) {
        printf("FAT!\n");
    }
    else {
        printf("WTF!?\n");
    }
}

double bmiCalc(double height, double weight) {
    return weight / (height * height);
}

int main(void) {
    bmiTell(bmiCalc(1.6, 50));
    return 0;
}