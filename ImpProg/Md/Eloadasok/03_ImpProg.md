# #91 03 ImpProg - 25/09/2023

## Kulcsszavak
- if, typedef, const, while, int, stb.
- Valtozo nevek nem lehetnek *kulcsszavak*

## Azonositok
- **Camelcase:** thisIsAVariable
- **Underscore notation:** this_is_a_variable
- **Preprocessor** nevek mindig nagy betu:
``` C
#define THIS_IS_A_CONSTANT
```

## Konstansok/Literalok
- **int** =>
le lehet irni decimalisan *(0-9)* = 25; 
lehet oktalis *031* = 25;
lehet hexadecimalis *0x19* = 25;
hosszu egesz **long** vagy **long int**;
merete *rugalmas* es *hardwaretol* fuggo;
``` C
sizeof(int); // Megadja, hogy hany bytos az int.
```
## Karakterek
- kicsi egesz szamok
``` C
char c = 'c';
```
- **backslash** segitsegevel lehet escape sequenceket irni
``` C
printf("\n"); // \n => new lines
```