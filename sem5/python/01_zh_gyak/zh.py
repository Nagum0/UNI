# 1.
s = "Never odd or even"
s_reversed = s[::-1]
print(s_reversed)

# 2.
d = { "Adam" : 11, "Jerry" : 4, "Michael" : 45, "Ben" : 10 }
d_result = [key for key, val in d.items() if val > 10]
print(d_result)

# 3.
lst = [33, 22, 33, 21, 33, 44, 33, 11, 11, 2, 1]
s = {33, 22, 45, 47, 42, 52}
lst_set = set(lst)
lst_s_intersect = s.intersection(lst_set)
lst_s_union = s.union(lst_set)
lst_s_diff = s.difference(lst_set)
print(lst_s_intersect, lst_s_union, lst_s_diff)

# 4.
def sum_nums(*args) -> int:
    result = 0

    input = list(args)
    for i in input:
        if i > 5:
            result += i

    return result

from functools import reduce
from typing import override

sum_nums_lambda = lambda *args: reduce(lambda acc, x: acc + x if x > 5 else acc, list(args), 0)

print(sum_nums(6, 8, 1))
print(sum_nums_lambda(6, 8, 1))

# 5.
wop_s = "big wop small wop tiny wop"
count_wop = lambda s: s.count("wop")
print(count_wop(wop_s))

# 6.
lst = ["xx", "xxxxx", "xxxxxxxxxxx", "xxxxxxxxxxxxxxxxxxxxxxxxxx"]
more_than_5 = lambda lst: list(filter(lambda s: len(s) > 5, lst))
print(more_than_5(lst))

# 7.
d = {
    "a": 69,
    "b": 420,
    "c": 67
}
sort_by_value = lambda d: sorted(d.items(), key=lambda x: x[1])
print(sort_by_value(d))

# 8.
lst = [4, 1, 3, -2]
find_smallest = lambda lst: reduce(lambda acc, x: x if x < acc else acc, lst, lst[0])
print(find_smallest(lst))

# 9.
lst = ["lol", "hmm", "zeki"]
double_first_letter = lambda *args: list(map(lambda s: s[0] + s, list(args)))
print(double_first_letter(*lst))

# 10.
class Flower:
    def __init__(self, name: str, color: str, beauty: int) -> None:
        self.name: str = name
        self.color: str = color

        if beauty in range(1, 11):
            self.beauty: int = beauty
            self.beauty_mult: float = 1
        else:
            raise ValueError("Beauty is between 1 and 10.")

    def __str__(self) -> str:
        return f"name: {self.name}; color: {self.color}; beauty: {self.beauty * self.beauty_mult}"

    def __eq__(self, value: object) -> bool:
        if not isinstance(value, Flower):
            raise TypeError

        return self.beauty * self.beauty_mult == value.beauty * value.beauty_mult

    def __lt__(self, value: object) -> bool:
        if not isinstance(value, Flower):
            raise TypeError

        return self.beauty * self.beauty_mult < value.beauty * value.beauty_mult

class Rose(Flower):
    def __init__(self, name: str, color: str, beauty: int) -> None:
        super().__init__(name, color, beauty)
        self.beauty_mult = 2

class Tulip(Flower):
    def __init__(self, name: str, color: str, beauty: int) -> None:
        super().__init__(name, color, beauty)
        self.beauty_mult = 1 / 2
    
class Daisy(Flower):
    def __init__(self, name: str, color: str, beauty: int) -> None:
        super().__init__(name, color, beauty)

class Bouquet:
    n: int

    def __init__(self) -> None:
        self.flowers: list[Flower] = []

    def add_flowers(self, *args) -> None:
        self.flowers += list(args)

    def __str__(self) -> str:
        sorted_flowers = sorted(self.flowers)
        result = ""

        for flower in sorted_flowers:
            result += f"| {flower} |"

        return result

bouquet = Bouquet()
bouquet.add_flowers(
        Tulip("A", "Red", 6), 
        Rose("B", "Red", 1), 
        Daisy("C", "Yellow", 10),
        Rose("D", "Red", 3))
print(bouquet)
