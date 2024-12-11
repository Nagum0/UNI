3. **A szorzatfv. integralhatosaga**:
  - (i): f, g >= 0:
    - Levezetem az osszegfv-s allitast az osszcillacios osszegik aztan az f * g oszcillacios osszeget kisebb, mint az szummas felirasa
    - Bevezetem az M f, g felso korlatjat es felirom vele az osszcillacios osszeget (vegeredmeny: M * osc(g, T) + osc(f, T))
    - Mivel f,g Riemann integralhato [a, b]-n => oszcillacios osszeg tetel => oszcillacios osszeg tetel csak f * g-re => f * g Riemann integralhato [a, b]-n
  - (ii): f, g tetszoleges:
    - Legyen mf = inf f es mg = inf g
    - Ekkor (f - mf), (g - mg) > 0
    - Az (i) miatt (f - mf) * (g - mg) = f * g - ... => f * g Riemann integralhato [a, b]-n

6. **Heine-tetel**:
  - Indirekt tfh. nem f nem egyenletesen folytonos
  - delta = 1/n => (xn) es (yn) sorozatok
  - (xn) korlatos => (xnk) konv, alfa limes
  - (ynk) felirasa
  - atviteli tetel => lim (nk -> poz. inf.) f(xnk) - f(ynk) = 0 (ellentmondas)

9. **Az integral fv. folytonossaga**:
  - Legyenek x,y valos szamok es x < y, ekkor felirom az |F(y) - F(x)| = ... = M * (y - x)
  - Bevezetem az M-et, ami az f egy felso korlatja
  - Ezutan felirom az egyenletes folytonossag tetelet (M * delta < epsilon eseten) es |F(y) - F(x)| < M * epsilon/M => F eleme C[a, b]

10. **Az integral fv. differencialhatosaga**:
  - h-ra teljesul, hogy d + h eleme (a, b): F(d + h) - F(d) = ...
  - f(d) = 1/h * d..d+h int. f(d)dt, ezert (F(d + h) - F(d) / h) - f(d) = 1/h * d..d+h int. f(t) - f(d) dt
  - 2 esetet megnezem: 0 < h < delta, -delta < h < 0
  - Ez elozoek alapjan megkapom, hogy abs(a fenti dolog) < epsilon
  - Ezert lim (h -> 0) ... = 0 => lim (h -> 0) ... = f(d) => F eleme D{d} es F'(d) = f(d)

12. **A helyettesites integralas szabalya hatarozott integralon**:
  - F(x) (g(alfa), x), G(u) felirasa
  - Belatjuk, hogy, ami a tetelben van a kozepe: F(g(B)) = G(B)
  - Felirjuk a folytonossag miatt az F es G derivaltjat
  - (F o g)' = f o g * g' => (F o g - G)' = 0
  - Letezik c valos szam, hogy F o g - G = 0. Ugyanakkor F(alfa) = 0 = G(alfa)
  - c = 0 => F o g = G => F(g(B)) = G(B)
