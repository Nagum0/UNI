6. **Heine-tetel**:
  - Indirekt tfh. nem f nem egyenletesen folytonos
  - delta = 1/n => (xn) es (yn) sorozatok
  - (xn) korlatos => (xnk) konv, alfa limes
  - (ynk) felirasa
  - atviteli tetel => lim (nk -> poz. inf.) f(xnk) - f(ynk) = 0 (ellentmondas)

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
