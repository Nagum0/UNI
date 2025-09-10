# 1. gyakorlat: bevezető feladatok
# Ajánlott VSCode bővítmények: Pylance, Code Runner, Python (Microsofté)
# Ha nincs telepítve a matplotlib: pip install matplotlib
#                     ezzel telepíthető a csomag az utolsó feladathoz (cmd környezetben)

print("0. feladat")
# Írjuk meg a FizzBuzz feladatot! A feladatot számsorozatra értelmezzük.
# Ha egy szám osztható 3-mal, írjuk ki, hogy Fizz, ha 5-tel, írjuk ki, hogy Buzz, ha 15-tel,
# írjuk ki, hogy FizzBuzz! Ha egyikkel sem, írjuk ki a számot.
for i in range(1, 100):
    if i % 15 == 0:
        print("FizzBuzz")
    elif i % 3 == 0:
        print("Fizz")
    elif i % 5 == 0:
        print("Buzz")
    else:
        print(i)

m = {3: "Fizz", 5: "Buzz"}
for i in range(1, 100):
    out = ""
    for k, v in m.items():
        if i % k == 0:
            out += v

    if out != "":
        print(out)
    else:
        print(i)

print('1.feladat')
#1-től 120-ig a számok listában
xs = [i for i in range(1, 121)]


print('2.feladat')
#a lista elemek összege
print(sum(xs))


print('3.feladat')
#3-mal osztható listaelemek a listában
threes = [i for i in xs if i % 3 == 0]
print(threes)


print('4.feladat')
# A listaelemek szorzata
prod = 1
for i in xs:
    prod *= i
print(prod)

print('5.feladat')
# Faktoriálisok 1-től 70-ig, rekurzív függvénnyel
def fact(n: int) -> int:
    if n == 1:
        return 1
    return n * fact(n - 1)

print('70-ig a számok faktoriálisa:')
print(fact(70))

print('5b.feladat')
# Faktoriálisok kiszámítása rekurzió nélkül


print('6.feladat')
# Prímek az eredeti listában és db számuk


print("7. feladat")
# Generáljunk random számokat 1-99 között, majd tároljuk el őket!
# Használjuk a random modult!
# HF Generáljunk 2000 random számot 1-99 között, 
# Rajzoljuk ki az eloszlásukat a matplotlib könyvtár segítségével!
