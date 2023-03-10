//3. Datoteka stanje.txt sadri podatke o zubima. 
// Prvi red datoteke sadrži broj pacijenata[5], a zaim u po dva reda se nalate zatečeno stanje zuba. 
// U prvoj vrsti se nalazi stanje gornje vilice a u drugoj vrsti stanje donje vilice. 
// Ako je I-element u vrsti 0 onda znači da taj pacijent nema zub na-tom mestu, ako je 1 onda znači da ima zubi da je zdrav, a ako je 2 onda znači da ima zub ali je kvaran 
// U drugoj datoteci intervencije.txt nalaze se podaci o izvršenim intervencijama broj pacijenta, broj zuba, intrevencija (P-popravljen zub, I-izvadjen zub) 
// Izvrsiti osvežavanje podataka u prvoj datoteci na osnovu podataka iz druge datoteke intrevencije.txt. 
// Za svakog pacijenta prikazati stanje i pisati izveštaj koliko ukupno ima zuba, koliko ima kvarnih zuba i procenat kvarnih zuba u odnosu na ukupan broj zuba.

#include <stdio.h>

#define MAX_PACIJENATA 100
#define MAX_ZUBA 32

int main() {
    int BrojPacijenata;
    int GornjaVilica[MAX_ZUBA]
    int DonjaVilica[MAX_ZUBA];
    int Pacijent, Zub;
    char Invervencija;

    // cita stanje.txt
    FILE *fp = fopen("stanje.txt", "r");
    fscanf(fp, "%d", &BrojPacijenata);
    for (int i = 0; i < MAX_ZUBA; i++) 
    {
        fscanf(fp, "%d", &GornjaVilica[i]);
    }
    for (int i = 0; i < MAX_ZUBA; i++) 
    {
        fscanf(fp, "%d", &DonjaVilica[i]);
    }
    fclose(fp);

    // cita intervencije iz intervencije.txt i osvezava stanje zuba
    fp = fopen("intervencije.txt", "r");
    while (fscanf(fp, "%d %d %c", &Pacijent, &Zub, &Invervencija) == 3) 
    {
        if (Zub < 0 || Zub >= MAX_ZUBA) {
            printf("Nevazeci broj zuba %d za pacijenta %d\n", Zub, Pacijent);
            continue;
        }
        if (Pacijent < 1 || Pacijent > BrojPacijenata) {
            printf("Nevazeci broj pacijenta %d\n", Pacijent);
            continue;
        }

    // Deljenje zuba na gornju i doljnju vilicu
        int *Vilica = GornjaVilica;
        if (Zub >= MAX_ZUBA / 2) {
            Vilica = DonjaVilica;
            Zub -= MAX_ZUBA / 2;
        }

    //Proverava stanje zuba
        int *status = &Vilica[Zub];
        if (Invervencija == 'P') {
            *status = 1;
        } 
        else if (Invervencija == 'I') {
            *status = 0;
        } 
        else {
            printf("Nevažeća vrsta intervencije '%c'\n", Invervencija);
        }

    }
    fclose(fp);

    // Izvestaj
    for (int i = 1; i <= BrojPacijenata; i++) {
        int UkupnoZuba = 0, NemaZub = 0, KvarniZub = 0;

        for (int j = 0; j < MAX_ZUBA; j++) {

            int *Vilica = GornjaVilica;
            if (j >= MAX_ZUBA / 2) {
                Vilica = DonjaVilica;
            }
            int status = Vilica[j];
            if (status != 0) {
                UkupnoZuba++;
            }
            if (status == 0) {
                NemaZub++;
                }
 else if (status == 2) {
                KvarniZub++;
            }

        }
        printf("Pacijent %d:\n", i);
        printf("Ukupno zuba: %d\n", UkupnoZuba);
        printf("Broj nedostajucih zuba: %d\n", NemaZub);
        printf("Kvarni zubi: %d (%.2f%%)\n", KvarniZub,
               (float)KvarniZub / UkupnoZuba * 100);
    }
    return 0;
}