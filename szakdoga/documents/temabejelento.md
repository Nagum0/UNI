A GIT CLONE projekt egy egyszerűsített Git implementáció, amely a verziókezelő rendszerek alapelveit és funkcióit implementálja.
A projekt célja, hogy reprodukálja a Git alapvető funkcióit, beleértve a repository inicializálását, a módosítások staging area-ba történő felvételét,
a commit létrehozását, a branch-ek kezelését és a merge műveleteket, miközben eszközöket biztosít a commit history és a belső repository objektumok vizsgálatára is.

A repository-t az Init segítségével lehet létrehozni és inicializálni, míg az Add lehetővé teszi a módosított elemek hozzáadását a staging area-hoz.
A Commit funkció létrehozza a staging area snapshot-ját és elmenti azt a history-ba, valamint biztosítja a lehetőséget, hogy a felhasználó különböző
commit-ok között navigáljon.

A Branching lehetővé teszi új branch-ek létrehozását és közöttük való váltást, minden branch a saját commit vonalát tartja nyilván.
A Merge funkció segítségével a branch-ek egyesíthetők, és a rendszer bemutatja az esetleges merge konfliktusokat diffek segítségével. 

A logging funkciók lehetővé teszik a branch commit history-jának megtekintését, valamint specifikus információk lekérését a 
repository objektumairól, például a staging index-ről, blob fájlokról, commit objektumokról és tree objektumokról. 

A projekt támogatja a remote repository-k kezelését is, biztosít egy szervert a repository-k távoli tárolásához, valamint a fetch és push funkciókat,
amelyek lehetővé teszik a távoli repository-val való szinkronizálást és az új objektumok elküldését a remote repository-ba,
miközben ellenőrzi az esetleges konfliktusokat a veriziók közt.

------

A szakdolgozat témája egy Git stílusú verziókezelő rendszer fejlesztése. A cél egy olyan program létrehozása,
amellyel fájlok és projektek különböző verziói kezelhetők és visszakövethetők. 
A rendszerhez tartozik egy távoli szerver is, ahol ezek a verziók tárolhatók és megoszthatók más felhasználókkal.
A projekt során a hangsúly a verziókezelés alapelveinek és a kliens–szerver közti kommunikáció megvalósításán lesz.
A végeredmény egy működő, egyszerűen használható verziókezelő rendszer lesz, ami bemutatja, hogyan épül fel és működik egy ilyen típusú szoftver.
