# Gyak 02

### Verem/Stack
- Muveletek:
    - **Empty**: _ -> V
    - **IsEmpty**: V -> L
    - **Push**: E -> V
    - **Pop**: V -> V
    - **Top**: V -> E
- Abrazolasa:
    - **Tombos abrazolas**: 
        - Tarolja, hogy hany elem van benne;
        - Vegere pusholunk;
        - HF: Implementald ezt!
    - **Lancolt abrazolas**:
        - Pointerek;
        - Van egy Node, ami tartalmaz egy pointert egy uj Node-ra es van benne egy value;
        - p -> [5 | * ] -> [7 | * ] -> [8 | * ] -> NULL;
- Feladat:
    - **Adott egy szoveg. Dontsuk el, hogy helyesen zarojelezett e**:
    - ( ( () () ) () )
    - 1: Ures eleme HZ
    - 2: x eleme Hz -> (x) eleme HZ
    - 3: x,y eleme HZ -> xy eleme HZ