Memóriajáték
============

Példa alkalmazás, egyszerű Qt alapú grafikus felülettel.

A cél, hogy készítsünk egy memóriajátékot, amivel mindenki játszott ovis korában. A játék menete a következő:

1. A játék rajzol nekünk kártyákat, fejjel lefelé.
2. A kártyákra kattintva fel lehet fedni, mi van rajtuk.
3. Egyszerre két kártyát lehet felfedni.
4. Ha eltaláltunk két olyan kártyát, amin ugyanaz a kép van, akkor azok kikerülnek a játékból.
5. Ha nem találtunk el egyforma kártyákat, akkor mind a kettő visszafordul.

Az egyszerűség kedvéért a "kép" egy betű lesz, amit `QPainter` segítségével rajzolunk.

Magyarázat
----------

### MainWindow

A `MainWindow` a játék fő (és egyetlen) ablaka. Ebben megjelenítünk két gombot, amikkel a játékos új
játékot kezdhet, illetve feladhatja.

* mainwindow.h / .cpp - C++ fejléc és forrás, amiben a `MainWindow` osztályt deklaráljuk és definiáljuk
* mainwindow.ui - Qt user interface (felhasználói felület) fájl, ami az ablakban megjelenő dolgokat írja le

### GameBoard

Ez egy `QGraphicsScene` leszármazott C++ osztály, aminek az a feladata, hogy a játéktáblát megjelenítse, és
megvalósítsa a játékmenetet.

### Card

Egy darab kártya megjelenítéséért és rajzolásáért felelős C++ osztály.

### main.cpp

Ez csak a `main()` függvényt tartalmazza, ami nem csinál mást, mint készít egy `MainWindow` példányt és megjeleníti azt.


Mit fogunk csinálni?
--------------------

* Első alkalommal megismerkedünk a Qt Creator környezettel, létrehozzuk a fenti osztályokat, és többé-kevésbé mindenkinek van forduló kódja. :)
* Otthon kijavítottam pár szépséghibát, amit jó lett volna az első alkalom végén, de már nem volt rá idő.
* Második alkalommal megcsináljuk, hogy interaktív legyen, vagyis lehessen vele játszani.
* Szorgalmi feladatként még majd beszélgethetünk pár gondolkodós kérdésről.

Segítség! Hogyan telepítsem...?
--------------------

Szükséged lesz a Qt-ra. Ezt legyen telepítve a gépedre, mielőtt eljössz, illetve légyszi még otthon gondoskodj róla, hogy egy egyszerű
hello world jellegű programot le tudsz fordítani és futtatni.

http://qt.io ---> innen töltsd le az open source verziót. A telepítő feltesz pár kellemetlen kérdést, de ne ijedj meg tőle!

A telepítőből:

* A Preview csoportból **ne** ikszelj be semmit. Itt a soron következő béta verziók vannak, nekünk most nem kellenek.
* Qt alól a legújabb verzióból a **desktop MinGW** változat legyen beikszelve, az android nem kell (hacsak nem akarsz később arra is fejleszteni)
* Maga a Qt forrása nem kell, azt ne ikszeld be
* Ha a MinGW helyett a Visual C++ verziót választod, akkor külön telepítve kell lennie a Visual C++ fordítónak (vagy a Visual Studionak) is. Ezért ezt nem javaslom.






