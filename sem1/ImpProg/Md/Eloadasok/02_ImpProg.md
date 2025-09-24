# #91 02 ImpProg - 18/09/2023

# ISMETLES
#### C IS BEST
#### MINDENT C-BEN IRTAK LOLOLOLOL
#### C AZ TRUE IMPERIALISTA
#### FUNCPROG SZAR + C-BEN IRTAK + RATIO

### C
 - Van egy *main* function
``` C
int main(void) {
    return 0;
}
```
 - Konyvtarakat hasznal *(libraries)*
``` C
#include <stdio.h> // Standard input/output lib
```
 - Statikus tipusrendszer

## Statikus tipusrendszer
 - A tipus meghatarozza, hogy hany *byte* memory kell neki
 - Meg kell mondani a szamitogepnek, hogy *mi* van a bytok mogott
 - **Tipusok:** int, double, char, float
 - Nem valtozik a tipus
 - **Dinamukis** tipusrendszeru nyelvekben nem kell deklaralni, hogy milyen tipusu egy valtozo *(futtato eldonti)*

### Fahr to Celsius
``` C
#include <stdio.h>

int main() {
    int fahr;

    for (fahr = 100; fahr <= 400; fahr += 100) {
        printf("fahr = %d\tcelsius: %d\n", fahr, ((5/9)*(fahr - 32)));
    }

    return 0;
}
```
 - Nemfog lefutni mert 5-ot osztjuk 9-el es *int*-et varunk el.
``` C
#include <stdio.h>

int main() {
    int fahr;

    for (fahr = 100; fahr <= 400; fahr += 100) {
        printf("fahr = %d\tcelsius: %.2lf\n", fahr, ((5./9.)*(fahr - 32)));
    }

    return 0;
}
```
 - Ez mar lefut mivel az osztast *double*-el csinaltuk *(5./9.)* es *%.2lf*-et hasznaltuk a kiprintelesre

### Fahr to Celsius as a function
``` C
#include <stdio.h>

double fahr2cels(double fahr) {
    return 5./9. * (fahr - 32)
}

int main() {
    int fahr;

    for (fahr = 100; fahr <= 400; fahr += 100) {
        printf("fahr = %4d\tcelsius = %.2lf", fahr, fahr2cels(fahr));
    }

    return 0;
}

```
 - Nem szamit, hogy int az argument a fahr2cels fuggvenynel, mert a fordito ezt atalakitja 
``` C
#include <stdio.h>

const int lower = 100;
const int upper = 400;
const int step = 400;

double fahr2cels(double fahr) {
    return 5./9. * (fahr - 32)
}

int main() {
    int fahr;

    for (fahr = lower; fahr <= upper; fahr += step) {
        printf("fahr = %4d\tcelsius = %.2lf", fahr, fahr2cels(fahr));
    }

    return 0;
}

```
- Itt konstansokat deklaraltam a *global* scope-ban es ezeket hasznaltam fel a *for* loopban.
``` C
#include <stdio.h>

#define LOWER 100
#define UPPER 400
#define STEP 100

double fahr2cels(double fahr) {
    return 5./9. * (fahr - 32)
}

int main() {
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        printf("fahr = %4d\tcelsius = %.2lf", fahr, fahr2cels(fahr));
    }

    return 0;
}

```
- Itt a konstansok helyett a *#define* keywordot hasznaltam a konstansok deklaralasahoz.

## A programok szerkezete
 - elofordito (preprocessor directives)
 - kommentek
 - C nyelvi *tokenek*

## Tokenek
 ``` C
 int main() {

 }
 ```
 - *int* => type name -> keyword
 - *main* => function name -> identifier
 - *()* => function call -> operator
 - *konstasok/literalok* => literal
 - Tobb token is van

### Azonositok a C-ben
 - En adom meg
 - Sosem legyen *keyword*
 - **Konvenciok:** *camelCaseNotation, under_score_notation*
 - **Preprocessor nevek** csak nagybetuvel legyenek es az underscore notationt hasznaljak: *UPPER_CASE_ONLY* 