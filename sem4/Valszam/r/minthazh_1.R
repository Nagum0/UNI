### FELADAT 1
# Veszek egyet -> ez nyer -> ez is nyer
# A = {nyerunk}
pA = 1 / 4
# B = {A megint nyer}
pB = pA * pA
round(pB, 2)

### FELADAT 2
# A: a kék kockával dobott érték 6
# B: a két dobott szám összege 8
# P(A | B) = ? = (P(A) * P(B)) / P(B)
pA = 1 / 6
# Az ertekek lehetnek: 6 + 2, 2 + 6, 4 + 4, 5 + 3, 3 + 5
# jo esetek szama = 5
# osszes eset szama = 36
pB = 5 / 36
pAmetszetB = 1 / 36
pAB = pAmetszetB / pB

### FELADAT 3
# Fuggetlenek, mert a 2 kocka bodas nem befolyasolja egymast

### FELADAT 4
ossz = 6 ^ 5
jok = 6 * 5 * choose(5, 2) * 10
p = jok / ossz
round(p, 2)

### FELADAT 5
n = 6
k = 3
p4 = 0.6
p6 = 0.4
round(dbinom(k, n, p4), 2)

### FELADAT 6
ex4 = n * p4
ex6 = n * p6

### FELADAT 7
# P(beteg) = 0.04
# P(egeszseges) = 0.96
# P(pozitiv | beteg) = 0.95
# P(pozitiv | egeszseges) = 0.08
# osszes = P(pozitiv | beteg) * P(beteg) + P(pozitiv | egeszseges) * P(egeszseges)
# P(beteg | pozitiv) = P(pozitiv | beteg) * P(beteg) / osszes
p = (0.95 * 0.04) / (0.95 * 0.04 + 0.08 * 0.96)
round(p, 2)

### FELADAT 8
# Megoldom az egyenletet P(2)-re, aztan a negyzetes keplet szerint szamolok

### FELADAT 9
# TODO

### FELADAT 10
p = 0.6 + 0.6 - 0.6 * 0.6

### FELADAT 11
lambda = 0.35
1 - dpois(0, lambda)

### FELADAT 12
c = round(log(2) / 2, 2)

### FELADAT 14
m = 110
s = 10
z = (120 - m) / s
1 - pnorm(z)