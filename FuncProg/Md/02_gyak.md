# #15 02 FuncProg - 18/09/2023

### Fuggveny precedencia
 - **:i** megmutatja a fuggveny precedenciajat
 - **infixl 7** ezt *99 `div` 11 `div` 2* igy fogja kiszamolni *(99 `div` 11) `div` 2*
 - Ha *prefix* modon hasznaljuk a fuggvenyt eloszor mindig a prefix fuggvenyt szamolja ki majd minden mast: **(+) 5 8*3 = 39**
 - Sajat fuggvenyemnek igy tudok precedenciat adni:
``` Java
f x y = x + y; infixl 6 `f`
```

### Fuggveny tipus check
 - **:t** megadja az adott kifejezes(fuggveny) tipusat

### Tipusvaltozo
 - **Num** ez egy tipusvaltozo. Ez megengedi, hogy minden Num tipusu *tipust* megadhatok neki
 - Pl: **(+) 5 5 = 10** de ez is jo **(+) 6.9 4.2**
``` Java
:t (+) Num => a -> a -> -> a
```

### Mintaillesztes
``` Java
neg :: Bool -> Bool
neg True = False
neg False = True
```
 - **Totalis fuggveny:** a fuggveny minden lehetseges parameterere definialt
 - **Parcialis fuggveny:** van olyan bemenete amire nem definialt

``` Java
(&&&) :: Bool -> Bool -> Bool
True &&& True = True
_ &&& _ = False
```
 - A **_ &&& _** ilyen default case akar lenni

### Forditasi hiba
 - Minden olyan hiba, amelyikeket a *fordito* fogja meg
 - Piros error szoveggel kezdodik

### Futasi hiba
 - Minden olyan hiba ami a forsito szerint helyes, de a futaskor a program nem mukodik helyesen
 - ***Exception:-nel kezdodik

### Haskell lazy
 - Csak azt ertekeli ki amire szuksege van es ami feltetlenul szukseges

### Rendezett par - Tuple
 - (a, b) = {{a}, {a, b}}
 - (b, ) = {{b}, {a, b}}

### Int vs Integer
 - Az *Int* korlatos a 2^63
 - Az *Integer* korlatlan. Annyi lehet, amennyit bir a memory