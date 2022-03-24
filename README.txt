Coada Vlad,312CB

Cerinta 0:
Consola interactiva am realizat-o in functia main, folosind while. 
Cat timp se citeste input, trebuie sa fie introdusa o cale catre poemul asupra 
caruia se doreste de a se realiza comanda, care poate fi uppercase, trimming, 
make_it_silly sau make_it_friendlier. Aceasta cale este oferita ca parametru 
functiei load_file de a adaug in consola interactiva poemul de la calea 
indicata. De asemenea, consola contine si functia de printare "print" si de 
iesire din input "quit".

Cerinta 1:
Pentru a transforma literele minuscule in majuscule si invers, folosesc functia
"uppercase", care primeste ca parametru poem. In corpul acesteea am iterat prin
fiecare litera si am verificat daca e litera mica sau mare. In caz ca e mare,
adica se contine intre "A" si "Z", ii adaog codului ASCII al acesteea valoarea
32, obtinand astfel codul ASCII al literei respective in forma minuscula.
In caz ca litera e mica, adica e cuprinsa in intervalul de la "a" la "z", ii
scad valoarea cu 32, deci o transform in majuscula. Deasemenea, adaug inca un 
if pentru a verifica daca prima litera din poezie este mica si de a o 
transforma eventual in una mare.

Cerinta 2:
Pentru a elimina spatiile libere si caracterele non-alfabetice declarate in 
macroul DELIM, am utilizat functia "trimming". Am declarat in ea un pointer 
auxiliar de tip char in care am copiat continutul poemului dat ca parametru.
Am declarat o variabila de tip pointer, numita "word", si i-am atribuit 
spatiului de memorie de la adresa respectiva valoarea functiei de tokenizare 
a textului auxiliar folosind ca delimitator macroul "DELIM". Vectorul obtinut, 
adica primul cuvint l-am adaugat intr-un nou vector, care reprezinta noul poem.
Tokenizand vectorul auxiliar si obtinand primul cuvint, primul element de dupa 
acesta a fost setat cu NULL. Pentru a obtine urmatoarele cuvinte, am mai 
realizat o functie "strtok", atribuita lui word, ce incepe cu NULL si are 
ca referinta delimiatoarele din "DELIM". Am realizat un while pentru a 
parcurge cuvintele poemului. In caz ca am gasit "\n", l-am adaugat la noul 
poem. De asemenea, am adaugat spatii intre cuvinte pentru a-i conferi 
aspect intuitiv si citet. Poemul cu efect de trimming este "new_poem".
Continutul acestuia il copiez in "text".

Cerinta 3:
Pentru a modifica natura literelor poemului, adica majuscule sau minuscule, 
citesc o probabilitate "prob". Parcurcind caracterele poemului, daca am 
dat de o litera, generez "sample". Conditia de comparare dintre sample si 
prob decid daca litera se va transforma in majuscula sau minuscula.

Cerinta 4:
Am copiat continul poemului intr-un vector auxiliar, numit "new_poem".
Am tokenizat acest poem. Cat timp se gasesc cuvinte, le trimit ca argument 
in fucntia "get_friendly_word". Daca acel cuvint are diminutiv, atribui 
vectorului "p", care este exact poemul nostru, tot sirul de caractere ce 
urmeaza dupa acel cuvint care are diminutiv. Diminutivul gasit cuvintului 
"word", adica "new_word", il copiez in vectorul auxiliar "aux", caruia ii 
adaog in continuare sirul "p", incepand cu pozitia de dupa "word", obtinand 
astfel diminutivul + sirul de dupa cuvantul care are acel diminutiv. In 
continuare vectorul "p" este initializat cu elementul de dupa diminutivul 
gasit. 


