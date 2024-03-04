# Gyak 04

### Lancolt sor/Queue
- Adattagok:
    - first: *E1(Node) 
    - last: *E1(Node)
    - size
- Muveletek:
    - Add(x: T)
    - Rem(): T
    - First(): T
    - Size()
    - IsEmpty()
    - SetEmpty()
    - Queue()
    - ~Queue()

- **Queue()**:
``` C
first := new E1
first->next := null
last := first
size := 0
```

- **Add(x: T)**:
``` C
last->key := x
last->next := new E1
last := last->next
last->last := null
size++
```

- **First(): T**:
``` C
if size != 0 {
    return first->key
}
else {
    ERROR
}
```

- **Rem(): T**:
``` C
if size != 0 {
    x := first->key
    p := first
    first := first->next
    delete(p)
    size--
}
else {
    ERROR
}
```

- **SetEmpty()**:
``` C
while first != last {
    p := first
    first := first->next
    delete(p)
    size--
}
```

- **~Queue()**:
``` C
SetEmpty()
delete(first)
```

### InsertionSort
- **naiveInsertionSort(A[1..n]: T)**:
``` C
// 2 8 10 15 3 4 => 2 8 10 3 15 4 => 2 8 3 10 15 4 => 2 3 8 10 15 4
i := 2
while i <= n {
    j := i
    while j > 1 && A[j - 1] > A[j] {
        swap(A[j - 1], A[j])
        j := j - 1
    }
}
```
- **insertionSort(A[1..n]: T)**:
``` C
// PREZIBEN
```
- **Muveletigeny**:
    - mT(n) = O(n)
    - MT(n) = O(n^2)
    - AT(n) = O(n^2)

### MergeSort
- 2 rendezett tomb kell; (vagy szetvalasztunk I guess)
- Mindig toljuk az indexeket es ossze hasonlitjuk az ertekeket, majd beszurjuk a vegso listaba;
```
     [3,1,10,8]
   [3, 1] | [10,8]
[3] | [1] | [10] | [8]
    [1,3] | [8,10]
     [1,3,8,10]
```

```C
// Alg. a preziben!
```