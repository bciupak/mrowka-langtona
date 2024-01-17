Mrówka Langtona

Przed wywołaniem programu należy go skompilować oraz stworzyć folder na pliki z wynikami:
make ---> kompiluje program i tworzy folder na pliki wynikowe

Aby wywołać program należy wpisać:
./edit -m *liczba rzędów* -n *liczba kolumn* -i *liczba kroków mrówki* -d *kierunek startowy mrówki* 

kierunek zgodny z pierwszą literą kierunku po angielsku (np. n=north)

Opcjonalnie:
-g *procent zapełnienia mapy czarnymi polami w losowych miejscach*
-f *nazwa plików z wynikami*
-p *nazwa pliku, z którego wczytujemy mapę*
Podczas jednego wywołania nie możemy korzystać z opcji -p i -g naraz.  

Aby usunąć pliki wynikowe:
make cleanOut

Aby usunąć skompilowane pliki oraz pliki wynikowe:
make clean 
