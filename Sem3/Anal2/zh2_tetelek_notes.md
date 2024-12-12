2. **Az osszegfv. integralhatosaga**:
  - Felirom a inf, es sup jeloleseket es levezetem vele a becsleseket
  - Szorzok (xi - xi - 1)-el es osszegzek
  - Felirom a felso es also kozelito osszegekkel a becslest
  - Bevezetem a tau1, tau2-t es tau = tau1 unio tau2, aztan levezetem a becslest az also darboux integralig
  - Hasonloan belatom a felso darboux integralt is
  - f, g eleme R[a, b] => also es felso darboux-k megegyeznek, ezert az osszege is => f + g eleme R[a, b]

3. **A szorzatfv. integralhatosaga**:
  - (i): f, g >= 0:
    - Levezetem az osszegfv-s allitast az osszcillacios osszegik aztan az f * g oszcillacios osszeget kisebb, mint az szummas felirasa
    - Bevezetem az M f, g felso korlatjat es felirom vele az osszcillacios osszeget (vegeredmeny: M * osc(g, T) + osc(f, T))
    - Mivel f,g Riemann integralhato [a, b]-n => oszcillacios osszeg tetel => oszcillacios osszeg tetel csak f * g-re => f * g Riemann integralhato [a, b]-n
  - (ii): f, g tetszoleges:
    - Legyen mf = inf f es mg = inf g
    - Ekkor (f - mf), (g - mg) > 0
    - Az (i) miatt (f - mf) * (g - mg) = f * g - ... => f * g Riemann integralhato [a, b]-n

4. **Hanyados fv. integralhatosaga**:
  - A szorzatfv integralhatosaga miatt eleg belatni, hogy 1/g eleme R[a, b]
  - Legyen tau egy felosztas es minden x, y-ra igaz, hogy 1/g(x) - 1/g(y) = ... <= (Gi - gi)/m^2
  - (xi - xi - 1)-el valo szorzas es osszegzes utan oszcillacios osszeg es integralhatosag tetel
  - osc(1/g, tau) <= epsilon/m^2 => 1/g eleme R[a, b]

5. **Monoton fv-k integralhatosaga**:
  - Oszcillacios osszeg tetel felhasznalasa
  - Ha f(a) = f(b) => igaz, mert f allando
  - Ha f(a) < f(b) => minden tau felosztasra letezik inf f = f(xi - 1) es sup f = f(xi). Ezekkel felirom az oszcillacios osszeget
  - Kivalasztok egy epsilont es egy n-t: (b-a/n) < epsilon/(f(b) - f(a)), tau egyenletes felosztas
  - (xi - xi - 1) < epsilon/(f(b) - f(a)) => felulbecsulem ezzel az oszcillacios osszeget es megkapom az epsilont
  - Tehat f eleme R[a, b]

6. **Heine-tetel**:
  - Indirekt tfh. nem f nem egyenletesen folytonos
  - delta = 1/n => (xn) es (yn) sorozatok
  - (xn) korlatos => (xnk) konv, alfa limes
  - (ynk) felirasa
  - atviteli tetel => lim (nk -> poz. inf.) f(xnk) - f(ynk) = 0 (ellentmondas)

7. **A folytonos fv. integralhatosaga**:
  - Azt kell belatni, hogy minden folyonos f eseten igaz az oszcillacios osszeg es Riemann integralhatosag tetel
  - Mivel f folytonos ezert egyenletesen folytonos es igy a vegen |f(x) - f(y)| < epsilon/(b - a)
  - Legyen epsilon > 0 es egy tau felosztas es legyen a ||T|| = max{xi - (xi - 1) | i = 1..n} < delta
  - Bevezetem az mi-t (f(ui)) es Mi-t (f(vi)) es felirom az oszcillacios osszeg tetelt ezekkel, ami epsilon lesz
  - Tehat f eleme R[a, b]

8. **Az N-L tetel**:
  - Bevezetek egy tau felosztast
  - A lagrange k.e.t. szerint minden i indexre letezik kszi (xi) es (xi - 1)-en
  - Ekkor az F(xi) - F(xi - 1) = F'(kszi i) * (xi - xi - 1) = f(kszi i) * (xi - xi - 1)
  - Ebbol jon, hogy: F(b) - F(a) = SUM(i=1..n, f(kszi i) * (xi - xi - 1)) = sigma(f, tau, kszi)
  - Mivel inf f < f(kszi i) < sup f => s(f, tau) <= sigma(...) <= S(f, tau)
  - also darboux = sup s(f, tau) < sigma < inf S(f, tau) = felso darboux
  - Mivel f eleme R[a, b] => also darboux = felso darboux, igy F(b) - F(a) = int(a..b)f(x)dx

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
