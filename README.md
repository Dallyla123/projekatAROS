# projekatAROS
Program za razmenu tekstualnih poruka izmedju procesa koristeci mehanizam reda sa porukama

Poštovani profesori, asistenti, saradnici i kolege,
Predstavljam vam program za razmenu tekstualnih poruka između procesa implementiran u programskom jeziku C koristeći mehanizam reda sa porukama. 

******SADRŽAJ PROJEKTA******

Ovaj projekat (program) sastoji se iz 2 potprograma, od kojih je jedan pošiljalac (sender), dok je drugi primalac (reciever).
Pokretanjem oba potprograma u jednom prozoru, ostvaruje se jednostavna komunikacija između dva procesa koja su aktivna. Putem sender-a se poruka jednostavno unosi preko tastature i pritiskom tastera ENTER se šalje putem mehanizma reda sa porukama drugom procesu, odnosno reciever-u. Sistem koji omogućava da se ova komunikacija između procesa dešava jeste POSIX message queue.

******ŠTA JE POTREBNO ZA OVAJ PROJEKAT******
- Linux operativni sistem koji podržava mehanizam reda sa porukama
- GCC kompajler

******UPUTSTVO ZA RAD******

1) Instalacija:

Potrebno je klonirati ili downloadovati projekat:

git link

Nakon toga potrebno je pozicionirati se u direktorijum koji sadrži projekat

cd project-repo


2) Kompajliranje programa:

gcc -o receiver receiver.c -lrt
gcc -o sender sender.c -lrt

3) Pokretanje programa:

U jednom terminalu pokrenuti ./sender
A u drugom pokrenuti ./receiver


4) Korišćenje programa

Potrebno je u terminalu u kome je pokrenut sender program napisati poruku i pritisnuti taster ENTER. Istovremeno će se u terminalu u kome je pokrenut program receiver pojaviti poruka koja je poslata. Ukoliko želimo da prekinemo rad potrebno je napisati poruku "izlaz" i pritisnuti enter.
