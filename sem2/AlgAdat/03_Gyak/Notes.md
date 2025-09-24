# Gyak 03

### Lengyel forma
- **Postfix**:
    - a + b <=> a b +
    - a + b * c <=> a b c * +
    - (a + b) * c <=> a b + c *
    - a * b ^ c + d <=> a b c ^ * d +
    - a + b * c + d <=> a b c * + d +
    - a + b * c ^ d * e <=> a b c d ^ * e * +

- **Feladat 1**:
(Adjuk meg a LF formara hozas algoritmusat ebben az egyszerubb esetben amikor nincsenek zarojelek)
- *LFSimple(s: String)*:
``` python
v := new Stack()
x := Read(s)
while x != EOS {
    if x = OP {
        if Prec(x) > v.Top() {
            v.Push(x)
        }
        else {
            while Prec(v.Top()) >= Prec(x) and not v.Empty() {
                Write(v.Pop())
            }
            v.Push(x)
        }
    }
    else {
        Write(x)
    }
}
while not v.Empty() {
    Write(v.Pop())
}
```

- **Feladat 2**:
(Mivan akkor, ha vannak zarojelek?)
    - (a + b) * (c + d) <=> x := (a + b); y := (c + d) <=> x y * <=> a b + c d + *
    - Ha csuko zarojelet talalunk addig uritjuk az operator stack-et amig el nem erunk egy nyito zarojelet;
    - a - (b + c * (d - f)) + h <=> a b c d f - * + - h +
- *LFFull(s: String)*:
``` python
v := new Stack()
x := Read(s)
while x != EOS {
    if x = "(" {
        v.Push(x)
    }
    elif x = ")" {
        while v.Top() != "(" {
            Write(v.Pop())
        }
        v.Pop() # Nyitozarojel kidobasa;
    }
    elif x = OP {
        while not v.Empty() and v.Top() != "(" and Prec(v.Top()) >= Prec(x) {
            Write(v.Pop())
        }
        v.Push(x)
    }
    elif x != OP and x != "(" and x != ")" {
        Write(x)
    }
}
while not v.Empty() {
    Write(v.Pop())
}
```
- *HW for myself*: Write a Stack in C# and this function (maybe a parser for this too);

- **Feladat 3**:
(LF kiertekelese algoritmus)
- LFEval(s: String)
``` python
v := new Stack()
x := Read(s)
while x != EOS {
    if x = OP {
        a := v.Pop()
        b := v.Pop()
        v.Push(a x b) # x az operator
    }
    else {
        v.Push(x)
    }
}
return v.Top()
```

### Sor/Queue adattipus lancolt abrazolassal
- **Queue**:
    - FIFO (First in first out)
- **Muveletek**:
    - Queue(): *Constructor*
    - add(x: T)
    - rem(): T
    - first(): T
    - length(): N
    - ~Queue(): *Destructor*
    - setEmpty()
    - isEmtpy(): L