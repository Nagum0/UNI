#1 Implementáljuk a verem adatszerkezetet egy Stack osztállyal!
# (Használjuk a beépített lista műveleteit!)
# Kezeld a szélsőséges eseteket! (Üres veremből kivétel)
# Eszerint implementáld: https://people.inf.elte.hu/pgm6rw/algo/Algo1/ElementaryDataStructures/stack/index.html
class Stack:
    data: list[any]
    n: int
    m: int

    def __init__(self, n: int):
        if not isinstance(n, int):
            raise ValueError("N must be a number!")

        self.data = []
        self.m = n
        self.n = 0

    @classmethod
    def push(self, i):
        if self.is_full():
            raise Exception("Stack overflow!")

        self.n += 1
        self.data.append(i)

    @classmethod
    def top(self) -> any:
        if len(self.data) == 0:
            raise Exception("Stack is empty")

        return self.data[len(self.data) - 1]

    @classmethod
    def pop(self) -> any:
        if len(self.data) == 0:
            raise Exception("Stack is empty")

        self.n -= 1
        return self.data.pop(len(self.data) - 1)
    
    @classmethod
    def is_full(self) -> bool:
        return self.n == self.m
    
    @classmethod
    def is_empty(self) -> bool:
        return self.n == 0
    
    @classmethod
    def set_empty(self):
        self.n = 0
        self.data = []
    
# stack = Stack(3)
# stack.push(1)
# stack.push(2)
# stack.push(3)
# print(stack.pop())
# print(stack.top())

#2 Készítsünk egy Book osztályt, ami tartalmazza egy könyv címét, íróját, oldalszámát.
# Definiáljuk rá a minimum összehasonlító műveleteket, hogy rendezhetőek legyenek oldalszám szerint!
# Kivételekkel kezeld le, ha hiányzik egy-egy tulajdonság példányosításkor!

class Book:
    title: str
    author: str
    page_count: int

    def __init__(self, title: str, author: str, page_count: int):
        assert title != "", "Title cannot be empty!"
        assert author != "", "Author cannot be empty!"
        assert page_count != 0, "Page count cannot be zero!"

        self.title = title
        self.author = author
        self.page_count = page_count

    def __eq__(self, value: "Book"):
        if not isinstance(value, Book):
            raise ValueError("Not a book")

        return self.page_count == value.page_count
    
    def __lt__(self, value: "Book"):
        if not isinstance(value, Book):
            raise ValueError("Not a book")

        return self.page_count < value.page_count
    
book = Book("z", "z", 10)
book2 = Book("z", "z", 11)
print(book > book2)

#3 Készítsünk egy Library osztályt, ami az előző feladatban megoldott könyveket tartalmazza!
# Egy Library példány tárolja osztály szinten, és példány szinten is a könyveket a nyilvántartás miatt.
# Biztosíts lehetőséget arra, hogy a len függvény egy adott példányban elhelyezett könyvek számát adja vissza!
# Hozzáadáskor bizonyosodj meg isinstance-cel, hogy valóban könyveket tárolunk a Libraryban!
# A könyvgyűjtemény kiiratásakor a könyvek lapszám szerint sorrendben jelenjenek meg.
# Kivételekkel kezeld le az esetleges hibákat!

class Library:
    books: list[Book]

    def __init__(self):
        self.books = []

    @classmethod
    def add(self, book: Book):
        if not isinstance(book, Book):
            raise ValueError("Did not receive book!")
        
        self.books.append(book)

    def __len__(self):
        return len(self.books)
    
    def __str__(self):
        sorted_books = sorted(self.books, key=lambda b : b.page_count)

        out = ""
        for book in sorted_books:
            out += f"{book.title}, {book.author}, {book.page_count}\n"

        return out
    
lib = Library()
lib.add(Book("a", "b", 12))
lib.add(Book("c", "d", 10))
print(lib)

#4 Készítsünk egy Shape osztályt, ami bizonyos geometriai alakzatok alapját fogja adni.
# Valósítsd meg a Circle (kör), Sphere (gömb), Cube (kocka) osztályt!
# isinstance-cel vizsgáld meg, hogy helyes értékeket kapjanak példányosításkor az adatok!
# (Működjön float és int típussal is!)
# Adott metódusokkal kérdezzük le a térfogatukat, felszínüket, oldal (vagy sugár) méretüket is!
# Kezeld kivételekkel a szélsőséges eseteket!

class Shape:
    pass

#5 Készítsünk egy console applikációs játékot!

# ---- Játékos
# Legyen egy Hero osztályunk, ami a játékost reprezentálja.
# A Hero osztálynak legyen életereje, ütési ereje, energiája.
# Legyen lehetőség kicsit, nagyot ütni - ütés méretétől függően kisebb-nagyobb energia vonódjon le.

# ---- Ellenségek
# Legyenek különböző osztályaink, amelyek az ellenfeleket reprezentálják!
# Hozz létre Dragon, Ork, Goblin, EvilMan osztályokat!
# Hasonlóan a játékos osztályához, rendelkezzenek ugyanolyan lehetőségekkel az ellenségek is!

# Dragon osztály
# Az ő életereje és ütési ereje legyen a legnagyobb, de használjon fel nagyon sok energiát!

# Ork osztály
# Az ő életereje és ütési ereje legyen a játékosénál kicsit nagyobb, de használjon fel több energiát is az ütése!

# Goblin osztály
# Az ő életereje legyen a játékosénál kicsit kevesebb, ütési ereje legyen kicsi, de az energiája legyen 100-szorosa a játékosnak!
# Ne tudjon nagyot ütni!

# EvilMan osztály
# Az ő tulajdonságai legyenek nagyon hasonlóak a játékoséhoz.

# ---- Játékmenet
# Tároljuk el listában a legyőzendő ellenségeket, ezekből a random modul segítségével válasszunk ki mindig egyet!
# A küzdelem mindig körökre osztva fog történni (először a játékos üt - utána ha él az ellenség, visszaüt)

# Minden kör előtt/után íródjon ki, hogy mennyi életereje/energiája maradt a küzdelem szereplőinek!
# Az energia minimálisan visszatöltődik körönként - de nagy ütésre sose legyen elég egy visszatöltés!

# A játékos adott betűkkel tudja irányítani a karakterét:
# H - hard hit, L - light hit, P - pass, E - escape legyen!
# H esetén erőset üssön, L esetén gyengébbet, P esetén kétszer annyi energiát tölt vissza, nem támad (de az ellenfél igen!)
# E esetén elmenekül a harcból a játékos - ilyenkor a harc előtti életerejét visszakapja az ellenséggel együtt.
# Menekülés esetén az ellenség visszakerül a listába maximális életerővel és energiával.

# Egy ellenség legyőzésekor a játékos nyerje vissza az életerejének bizonyos százalékát (kb. 40%)!

# A játéknak vége van, ha az összes ellenfél le lett győzve.

# ---- Erősítések
# Egy ellenség legyőzése egy véletlenszerű erősítést ad a játékosnak (nagyobb ütőerő, több életerő, nagyobb energia-regeneráció, stb.)
# Csinálj egy Buff osztályt, amiből különböző típusú erősítéseket származtatsz!
# Ha meghal egy ellenség, akkor egy véletlenszerű erősítést ad a játékosnak, ami a játék végéig érvényben marad.
