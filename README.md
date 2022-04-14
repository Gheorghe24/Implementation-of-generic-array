TEMA 1 IOCLA

Main:
Pentru inceput am alocat comenzile pe care urma sa le citesc de la tastura si acele 2 structuri.
Precizez ca in structura am alocat exact numarul de biti pe care ii foloseste fiecare cuvant si doar am citit pe o lungime maxima(nu am citit sa fi interzis asta).
Apoi folosesc un while pana la comanda exit cu fiecare instructiune in parte
Cea mai dificila din acestea e insert(insert_at e exact aceeasi cu o mica diferenta).
Astfel, citest primele 2 inputuri si apoi aloc in date exact numarul de biti de care am nevoie.Aloc de fiecare data si structura in care retin datele si apoi o dezaloc.Pentru fiecare tip de intrare(1,2,3) initializez inturi si citesc inturi conform instructiunilor si le salvez apoi in structura cu ajutorul lui memcpy si lungimii fiecarui tip.Pentru fiecare salvare in structura maresc lungimea care ma ajuta sa parcurg mai usor si sa stiu unde sa pun fiecare bit.
Citest ultimul cuvant(dedicatul)si de asemenea realoc memorie si ptu acesta pentru a-l insera.
Apoi folosesc functia Add_last si dezaloc memorie ptu date->data
Celelalte cazuri sunt foarte usor de inteles de aceea am zis sa nu fac o explicatie aparte.

ADD_LAST:
Folosesc un pointer auxiliar de tip void in care salvez structura data ca parametru
Parcurg structura si o salvez ca pe un "vector de biti".Am nevoie sa fac cast intotdeuna in dependenta de valorile pe care le am in structura si copiez datele acestea in auxiliarul "tmp".De asemenea calculez lungimea lui data in timp ce parcurg si inserez in tmp.
Dupa aceasta am 2 cazuri, cand vectorul arr e gol si doar aloc memorie ptu acesta si copii auxiliarul meu sau atunci cand nu e gol si e nevoie sa realoc memorie pentru a mai insera un element.Calculez intotdeaua lungimea intregului arr ca sa stiu cu cat ar trebui sa realoc si de unde sa inserez elementul.

ADD_AT:
Exista 3 cazuri:
1.index mai mic ca 0, returnez eroare
2.index mai mare decat len,adaug la final
3.inserez in vector :
Prima data parcurg arr pana la final si aflu lungimea, de asemenea aflu lungimea pana la index
Intr-un alt auxiliar salvez datele ca un element din vector si de asemenea salvez intr-o variabila lungimea acestuia. Realoc memorie inca pentru acest element si aflu pozitia de unde ar trebui sa inserez(Aux2).
Mut elementele de dupa index pana la aux2 + lungimea elementului inserat si apoi in inserez pe acesta.
dezaloc memorie pentru auxiliarul alocat

Find:
la fel sunt 3 cazuri, ptu cazul in care caut in vector,parcurg pana la index la fel ca in functiile precedente si printez apoi exact de la aux o un element din arr cu ajutorul functiei print creata mai jos.

Delete_at:
La fel ca in cazul functiei add_at parcurg vectorul pana la final si ma folosesc de pointeri auxiliari pentru a-mi salva anumite pozitii importante.De asemenea calculez lungimea totala a vectorului, lungimea elementului pe care e nevoie sa il sterg si doar mut pointerii de la finalul elementului index(lungimea len_aux) la inceputul acestuia (arr + len1(lungimea pana la index)). Realoc mai putina memorie, la fel cu lungimile salvate si scad lungimea (len) 

Print:

Cu ajutorul unei structuri repetitive de tip for parcurg tot vectorul cu un index pana la lungimea acestuia(len = numarul de elemente din vector);
Iau primul element castand pozitia arr cu un unsigned char pentru a lua exact "type-ul" dat de la tastatura salvat in structura si dupa in fiecare element
Printez type-ul(chiar asa ii dau numele pentru a-l folosi mai departe).Dupa asta ma misc(misc arr) cu exact lungimea charului si apoi cu bitii lui "header-len". Astfel ajung in pozitia in care am acele 2 bancnote, insa eu trebuie sa afisez mai intai cel de-al doilea nume si de aceea printez arr+sizeof(cele 2 tipuri de numere adunate).Apoi afisez bancnotele si pot sa ma musc mai departe in array cu marimea acestora.
Dupa ce ies din aceste 3 cazuri(3 tipuri), ma misc cu bitii celui de-al doilea cuvant pentru a ajunge la inceputul urmatorului element.

