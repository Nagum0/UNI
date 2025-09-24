# Gyak 01

- Totalis fuggveny
  - f : G -> H
- Parcialis fuggveny
  - f eleme G -> H
- Feladat
  - Relacio A x A, ahol az A az allapotter

### 3.a

- Osztója-e adott n természetes számnak az adott d természetes szám

```
A = (n: N, d: N, l: L)
F = {(a, b) eleme A x A | n(a) = n(b) es d(a) = d(b) es l(b) = d(a)|n(a)}
```

### 3.b

- Adjuk meg egy természetes szám egy valódi természetes osztóját.

```
A = (x: N, y: N)
// F({x: 6, y: 3}) = {{x: 6, y: 2}, {x: 6, y: 3}}
F = {(a, b) eleme A x A | x(a) = x(b) es y(b) != 1 es y(b) != x(a) es y(b)|x(a)}
```

### Program (Csere)

```
A = (x: H, y: H) // s: H segedvaltozo

s := x
x := y
y := s

// (3,8) -> <(x: 3, y: 8), (x: 3, y: 8, s: 3), (x: 8, y: 8, s: 3), (x: 8, y: 3, s: 3)>
```

### Program (Signum hozzadas)

```
Legyen H = {a eleme Z | a >= -5}
A = (x: H)

while x != 10 {
	x := x + sgn(x)
}

// 4 -> <4,5,6,7,8,9,10>
// 12 -> <13,14,15...>
// -2 -> < -2, -3, -4, -5, fail>
```
