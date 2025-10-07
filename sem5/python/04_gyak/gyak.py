#Dokumentációk segítségnek: https://docs.python.org/3/library/heapq.html
#                           https://docs.python.org/3/library/sys.html
#                           https://docs.python.org/3/library/os.html
#                           https://docs.python.org/3/library/random.html

#1 Adott az alábbi listánk:
ex1 = [3, 3, 2, 1, 4, 3, 2, 1, 2, 2, 2, 1, 2, 3, 1, 3, 2, 2, 1, 1, 1, 1, 0, 0, 4, 2, 3]
# Írjuk ki a 2 leggyakrabban előforduló elemet!

print("\n1: ")

m = {}

for i in ex1:
    m[i] = 1 if i not in m.keys() else m[i] + 1

m = sorted(m.items(), key=lambda x: x[1], reverse=True)

for t in m[:2]:
    print(t[0])

#2 A heapq modul definiálja nekünk a minimum prioritásos sort.
# Az alábbi listából tároljuk el az értékeket minimum prioritásos sorban,
# majd írassuk ki őket növekvő sorrendben!
ex2 = [81, 49, 21, 421, 4, -4, 42, 77, 0]

print("\n2: ")

import heapq
from typing_extensions import Any

heapq.heapify(ex2)

for _ in range(len(ex2)):
    print(heapq.heappop(ex2))

#3 Alakítsuk át az előző feladatot úgy, hogy a listát csökkenő sorrendben rendezze!
# Végezzük el az ex3 változón!

ex3 = [321, 4, 7, 432, 989, -421, -4, 555, 505, 37, 42]

print("\n3: ")

ex3 = [-x for x in ex3]

heapq.heapify(ex3)

for _ in range(len(ex3)):
    print(-heapq.heappop(ex3))

#4 Írjunk egy függvényt, ami összefűzi a fájl futtatásakor megadott paramétereinket!
# Használd a sys modult!

print("\n4: ")

import sys

args = sys.argv
bigArg = ""

for arg in args:
    bigArg += f"{arg} "

print(bigArg)

#5 Kössük össze egy elérési útvonal elemeit operációs rendszertől függetlenül!
# Az elérési útvonal elemeit kapjuk meg a fájl futtatásakor!
# (feltételezzük, hogy helyes az útvonal)
# Használjuk az os, sys modult!

print("\n5: ")

# ?????????

#6 Írjuk meg a saját map, filter függvényünket!
# Írjuk meg úgy a saját all, any függvényünket, hogy várjanak egy predikátumot is (feltételt), 
# amit alkalmaznak az elemekre!

print("\n6: ")

def myMap(lst, f) -> list[Any]:
    return [f(i) for i in lst]

def myFilter(lst, p) -> list[Any]:
    return [i for i in lst if p(i)]

def myAll(lst, p) -> bool:
    for i in lst:
        if not p(i):
            return False

    return True

def myAny(lst, p) -> bool:
    for i in lst:
        if p(i):
            return True

    return False

print(myMap([1, 2, 3], lambda x: x ** 2))
print(myFilter([1, 2, 3], lambda x: x % 2 == 0))
print(myAll([2, 4, 6], lambda x: x > 1))
print(myAny([-1, 0, 1, 2], lambda x: x > 1))

#7 Írjunk egy függvényt, ami véletlenszerűen kiválaszt egy elemet egy tetszőleges méretű listából!
# Használd a random modult!

print("\n7: ")

import random

def choice(lst) -> Any:
    return random.choice(lst)

print(choice([1, 2, 3, 4]))
