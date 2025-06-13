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
            4. FZ-ben csak azokat tartom meg ahol a fuggoseg jobb es bal oldala is 
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
    
    Tehat ami nekunk itt projekcio Z-re az a nev -> hely => FZ = {nev -> hely}
```

# BCNF dekompozíció

- Egy relacio BCNF <=> Ha az minden F-beli fuggoseg bal oldalan levo attributum szuperkulcs.
- Egy attributum szuperkulcs <=> {attr}+ = {osszes relaciobeli attributum}
- BCNF felbontas: R1 = X+, R2 = R - (X+ - X)

```
Alogritmus: Adott R es F.
            1. Megnezem, hogy R BCNF e.
            2. Ha nem felbontom ez a BCNF felbontas szerint.
               (Az R1, R2 relaciok F1, F2 halmazok meghatarozasa: { A -> X eleme F | A eleme R es X eleme R })
            3. Megnezem, hogy R1 es R2 BCNF e.
            4. Ezt csinalom addig amig a felbontas mindket resze BCNF (ha egy felbontas F halmaza ures akkor az is BCNF)

    Főnökök(név, cím, kedveltTeák, gyártó, kedvencTea)
    F = {név->cím, név->kedvencTea, kedveltTeák->gyártó}

    1. Fonokok BCNF e?
    {nev}+ = {nev, cim, kedvencTea}, hianyzik a kedveltTeák es a gyarto => nem BCNF

    2. Fonokok felbontasa
    Fonokok1 = {nev}+ = {nev, cim, kedvencTea}
    F1 = {nev->cim, nev->kedvencTea}
    Fonokok2 = Fonokok - ({nev}+ - {nev}) = {nev, kedveltTeák, gyarto}
    F2 = {kedveltTeák->gyarto}

    3. Fonokok1, Fonokok2 ellenorzese
    Fonokok1 BCNF, mert {nev} egy szuperkulcs, azaz {nev}+ = {nev, cim, kedvencTea}.
    Fonokok2 nem BCNF, mert {kedveltTeák}+ = {kedveltTeák, gyarto} hianyzik a nev.

    4. Fonokok2 felbontasa
    Fonokok3 = {kedveltTeák}+ = {kedveltTeák, gyarto}
    F3 = {kedveltTeák->gyarto}
    Fonokok4 = Fonokok2 - ({kedveltTeák}+ - {kedveltTeák}) = {nev, kedveltTeák}
    F4 = {}

    5. Fonokok3, Fonokok4 ellenorzese
    Fonokok3 BCNF, mert {kedveltTeák} szuperkulcs.
    Fonokok4 BCNF, mert F4 ures halmaz.

    Tehat Fonokok BCNF felbontasa: Fonokok1(nev, cim, kedvencTea), Fonokok3(kedveltTeák, gyarto), Fonokok4(nev, kedveltTeák)
```
