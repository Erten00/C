//3. Datoteka stanje.txt sadri podatke o zubima. 
// Prvi red datoteke sadrži broj pacijenata[5], a zaim u po dva reda se nalate zatečeno stanje zuba. 
// U prvoj vrsti se nalazi stanje gornje vilice a u drugoj vrsti stanje donje vilice. 
// Ako je I-element u vrsti 0 onda znači da taj pacijent nema zub na-tom mestu, ako je 1 onda znači da ima zubi da je zdrav, a ako je 2 onda znači da ima zub ali je kvaran 
// U drugoj datoteci intervencije.txt nalaze se podaci o izvršenim intervencijama (broj pacijenta, broj zuba, intrevencija (P-popravljen zub, I-izvadjen zub) 
// Izvrsiti osvežavanje podataka u prvoj datoteci na osnovu podataka iz druge datoteke intrevencije.txt. 
// Za svakog pacijenta prikazati stanje i pisati izveštaj koliko ukupno ima zuba, koliko ima kvarnih zuba i procenat kvarnih zuba u odnosu na ukupan broj zuba.

#include <stdio.h>

#define MAX_PATIENTS 100
#define MAX_TEETH 32

int main() {
    int BrojPacijenata;
    int GornjaVilica[MAX_TEETH]
    int DonjaVilica[MAX_TEETH];
    int Pacijent, Zub;
    char Invervencija;

    // cita stanje.txt
    FILE *fp = fopen("stanje.txt", "r");
    fscanf(fp, "%d", &BrojPacijenata);
    for (int i = 0; i < MAX_TEETH; i++) {
        fscanf(fp, "%d", &GornjaVilica[i]);
    }
    for (int i = 0; i < MAX_TEETH; i++) {
        fscanf(fp, "%d", &DonjaVilica[i]);
    }
    fclose(fp);

    // cita intervencije iz intervencije.txt i osvezava stanje zuba
    fp = fopen("intervencije.txt", "r");
    while (fscanf(fp, "%d %d %c", &Pacijent, &Zub, &Invervencija) == 3) 
    {
        if (Zub < 0 || Zub >= MAX_TEETH) {
            printf("Invalid tooth number %d for patient %d\n", Zub, Pacijent);
            continue;
        }
        if (Pacijent < 1 || Pacijent > BrojPacijenata) {
            printf("Invalid patient number %d\n", Pacijent);
            continue;
        }

        int *jaw = GornjaVilica;
        if (Zub >= MAX_TEETH / 2) {
            jaw = DonjaVilica;
            Zub -= MAX_TEETH / 2;
        }
        int *status = &jaw[Zub];
        if (Invervencija == 'P') {
            *status = 1;
        } else if (Invervencija == 'I') {
            *status = 0;
        } else {
            printf("Nevažeća vrsta intervencije '%c'\n", Invervencija);
        }

    }
    fclose(fp);

    // Izvestaj
    for (int i = 1; i <= BrojPacijenata; i++) {
        int total_teeth = 0, missing_teeth = 0, defective_teeth = 0;
        for (int j = 0; j < MAX_TEETH; j++) {

            int *jaw = GornjaVilica;
            if (j >= MAX_TEETH / 2) {
                jaw = DonjaVilica;
            }
            int status = jaw[j];
            if (status != 0) {
                total_teeth++;
            }
            if (status == 0) {
                missing_teeth++;
            } else if (status == 2) {
                defective_teeth++;
            }

        }
        printf("Pacijent %d:\n", i);
        printf("Totalno zuba: %d\n", total_teeth);
        printf("Broj nedostajucih zuba: %d\n", missing_teeth);
        printf("Kvarni zubi: %d (%.2f%%)\n", defective_teeth,
               (float)defective_teeth / total_teeth * 100);
    }

    return 0;
}