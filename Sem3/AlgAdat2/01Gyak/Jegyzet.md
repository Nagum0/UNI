# Gyak 01

## Compressions (Tomorites)

- kodszavak
- kod (kodszavak veges halmaza)
- kodfa
- betunkenti kodolas

### Naive method

- Nem lesz ZH-n
- Minden egyes betuhoz hozzarendelunk egy kodszot
- Mennyi bit kell? => ceil(log2(5))
- ABRAKADABRA
  - A 000
  - B 001
  - R 010
  - K 100
  - D 110

### Huffman coding (Huffman kodolas)

- Betunkenti optimalis kodolas
- Gyakran elofordulokhoz rovid es ritkakhoz hosszu kodszot rendelunk
- Baj: Prefix kod (egyik ugy kezdodik, mint a masik)
- Prefix mentes kodolas
- ABRAKADABRA
  - Hanyszor fordul elo egy betu?
  - A 5
  - B 2
  - R 2
  - K 1
  - D 1
  - Min priorty queue-t hasznal <(D,1), (K, 1), (R, 2), (B, 2), (A, 5)>
  - Osszevonja a kicsiket <(DK, 2), (R, 2), (B, 2), (A, 5)>
  - Osszevonja a kicsiket <(B, 2), (DKR, 4), (A, 5)>
  - Osszevonja a kicsiket <(A, 5), (DKRB, 6)>
  - Osszevonja a kicsiket <(DKRBA, 11)>
  - Ekozben egy kodfat alakit (az orai jegyzetben)
  - Irom a nullakat egy oldalra es a egyeseket masik oldalra es leszamolom oket (az orai jegyzetben)

### LZW compression

- Szotarkod
- Csak egyszer dolgozza fel az inputot
- Mikozben olvassuk az inputot epitjuk a szotarat es egyben generaljuk az outputot
