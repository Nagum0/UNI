# 05 GYAK

### Lancolt lista/Linked list
- S1L: Egyiranyu, Fejelem nelkuli
- H1L: Egyiranyu, Fejelemmel
- S2L: Ketiranyu, Fejelem nelkuli
- C2L: Ketiranyu, Fejelemmel
- **Feladat 1 - Beszuras** (Rendezett):
S1LBeszur(&l: E1 *, d: T)
``` C
// l -> [3|] -> [8|] -> [12|NULL]
pe := null
p := l

while p != null & p->data < d {
    pe := p
    p := p->next
}

if pe = null {
    q := new E1
    q->key := d
    q->next := p
    l := q
}
else {
    q := new E1
    q->key := d
    q->next := p
    pe->next := q
}
```

- **Feladat 2 - Kereses** (Rendezett):
S1LKeres(l: E1*, d: T): E1*
``` C
p := l

while p != null & p->data < d {
    p := p->next
}

if p != null & p->data = d {
    return p
}
else {
    return null
}
```

- **Feladat 3 - Torles** (Rendezett):
S1LTorol(&l: E1 *, d: T)
``` C
// Elso talalt elemet torli, ha van tobb azokat beken hagyjuk;
p := l
pe := null

while p != null & p->data < d {
    pe := p
    p := p->next
}

if p != null & p->data = d {
    if pe != null {
        q := p
        p := p->next
        l := p
        delete(q)
    }
    else {
        q := p
        p := p->next
        pe->next := p
        delete(q)
    }
}
else {
    SKIP
}
```
``` C
// Minden talalt element torol;
p := l
pe := null

while p != null & p->data < d {
    pe := p
    p := p->next
}

if p != null & p->data = d {
    while p != null & p->data = d {
        q := p
        p := p->next
        delete(q)
    }

    if pe != null {
        l := p
    }
    else {
        pe->next := p
    }
}
else {
    SKIP
}
```
- **Feladat 4 - Torles** (Rendezetlen, fejelemes):
H1LTorolMind(&l: E1*, d: T)
``` C
// Mindet toroljuk;
pe := l
p := l->next

while p != null {
    if p->data = d {
        q := p
        p := p->next
        pe->next := p
        delete(q)
    }
    else {
        pe := p
        p := p->next
    }
}
```
- **Feladat 5 - Paros-Paratlan szetfuzes** (Fejelemes):
Ha paratlan hagyjuk, ha paros berakjuk egy uj listaba;
H1LSzetfuz(&l: E1*): E1*
``` C
l2 := new E1
l2->next := null
r := l2

pe := l
p := p->next

while p != null {
    if 2|p->data {
        q := p
        p := p->next
        pe->next := p
        q->next := null
        r->next := q
        r := q
    }
    else {
        pe := p
        p := p->next
    }
}

return l2
```

### QuickSort
- A preziben!