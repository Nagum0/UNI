# #91 02 ProgAlap - 18/09/2023

## Szekvencia
 - pl: recept
 - *utasitasok*

## Elagazas
 - Algoritmus leiro nyelvek
 - *if* (2 iranyu)
 - *switch* (tobb iranyu)

``` CS
// if
if (x == 1) {
    Console.WriteLine("0");
}
else {
    Console.WriteLine("1");
}

// switch
switch (x) {
    case 1:
        Console.WriteLine("0");
    default:
        Console.WriteLine("1");
}
```

### Feladatmegoldas
 - A feladatot le kell bontani fontos reszekre
 - Mi a *bemenet* ?
 - Mi a *kimenet* ?
 - **Specifikacio**
 - Bemenet *(pl: x eleme R)*, kimenet, elofeltetel *(Mik lehetnek a bemenetek?)*, utofeltetel *(a bemeneteket az uf-be behelyettesitve igaznak kell lennie)*

### Ciklus
 - *Ismetelt vegrehajtas*
 - pl: Amig nem forr a viz varok 1 masodpercet
 - Addig fut a ciklus amig a feltele igaz
 - **Feladat:** Legkisebb osztalya e az *o* az *n*-nek? *(n > 1 & n eleme N)*

``` CS
int n = 15;
int o = 3;

if (n > 1 && o > 1) {
    for (int i = 0; i < n; i++) {
        if (i == 1) {
            continue;
        }

        if (n % i == 0) {
            if (o == i) {
                Console.WriteLine("Az o a legkisebb osztoja n-nek.")
                break;
            }
            else {
                Console.WriteLine("Az o nem a legkisebb osztoja n-nek.")
                break;
            }
        }
        else {
            continue;
        }
}
}
```
 - **Feladat 2:** Hatarozzuk meg egy N szam *(n > 1)* osztoi osszeget

``` CS
/*
Be: n eleme N
Ki: sum eleme N
Ef: n > 1
Uf: sum = SZUM(i=1..n, i, i|n) 
*/

int n = 15;
int sum = 0;

if (n > 1) {
    for (int i = 0; i < 15; i++) {
        if (n % i == 0) {
            sum += i;
        }
        else {
            continue;
        }
    }

    Console.WriteLine($"Sum: {sum}.");
}
```

### Rekord
 - *array*

``` CS
string[] szinek = {"Piros", "Fekete", "Zold", "Kek"};
```
 - *struct*

``` CS
public struct Pont {
    public double x, y;
}

Pont p;
p.x = 5;
p.y = 10;
```
 - *Ponttal* ferhetunk hozza a *struct* elemeihez

 - **Specifikacioban:**

``` CS
/* 
Be: p eleme Pont, Pont = X x Y, X = R 
*/
```