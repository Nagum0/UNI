# Armstrong axiomak

- Reflexivitas
- Bovites
- Tranzitivitas

```
R = ABCD; F = { A → C, B → D }; AB → ABCD ?

A -> C (F)
AB -> CB (A2)
AB -> A (A1)
AB -> B (A1)
AB -> CB + AB -> A + AB -> B = AB -> ABC (UNION)
B -> D (F)
AB -> BD (A2)
AB -> ABC + AB -> AB -> DB = AB -> ABCD (UNION)
```

# Lezaras

``` 
Lezaras: (mi vezetheto le egy adott reszattributumhalmazbol az F-en keresztul?)
    Hallgatók(neptun-kód, név, jegyek, hely)
    F = { neptun_kód → név, neptun_kód → jegyek, név → jegyek, név → hely }
    neptun_kód+?
    
    {neptun_kód}
    {neptun_kód, nev} neptun_kód -> nev
    {neptun_kód, nev, jegyek} neptun_kód -> jegyek
    {neptun_kód, nev, jegyek, hely} nev -> hely
```

# Projekcio

## Exponencialis algoritmus

```
Alogritmus: Adott az R, F es Z. 
            Z-re vett projekcio az az FZ halmaz, ami csak olyan fuggosegeket tartalmaz
            ami a Z-ben levo attributumokbol levezetheto.
            1. A Z minden reszattributumhalmazanak (X) kiszamitom a lezartjat.
            2. FZ U { X -> A | A eleme X+ - X}
            3. Eldobom a redundans fuggosegeket
            4. FZ-ben csak azokat ahogy meg ahol a fuggoseg jobb es bal oldala is 
               eleme Z-nek.

    Hallgatók(neptun-kód, név, jegyek, hely)
    F = { neptun_kód → név, neptun_kód → jegyek, név → jegyek, név → hely }
    Z = { név, hely }
    
    FZ = {}
    P(Z) = {{nev}, {hely}, {nev, hely}}

    {nev}+ = {nev, jegyek, hely}
    {nev}+ - {nev} = {jegyek, hely}
    FZ U {nev -> jegyek, nev -> hely}

    {hely}+ = {hely}
    {hely}+ - {hely} = NULL
    FZ U NULL

    {nev, hely}+ = {nev, jegyek, hely}
    {nev, hely}+ - {nev, hely} = {jegyek}
    FZ U {{nev, hely} -> jegyek}

    {nev -> jegyek, nev -> hely, {nev, hely} -> jegyek}} => {nev -> jegyek, nev -> hely}
    
    Tehat ami nekunk itt projekcio Z-re az a nev -> jegyek => FZ = {nev -> hely}
```
