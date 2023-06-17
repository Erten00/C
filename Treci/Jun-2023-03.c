/*
3.Napisati program koji vrši određenu obradu nad tekstualnom datotekom koja sadrži podatke o rezultatima stranaka na parlamentarnim izborima u Republici Srbiji.
Svaki red tekstualne datoteke sadrži podatke o jednoj stranci po sledećem formatu:
redni broj stranke na glasačkom listiću (ceo broj), broj osvojenih glasova (ceo broj) i naziv stranke (niz od najviše 30 znakova koji može sadržati blanko znake).
Broj redova u datoteci nije poznati.
Program treba najpre da pročita sadržaj datoteke a zatim da odredi broj mandata koji je svaka stranka osvojila.
Stranka može osvojiti pozitivan broj mandata (uči u parlament) jedino ako je prešla cenzus (osvojila barem 5% od ukupne sume glasova koje su sve stranke dobile na izborima).
Mandati se dodeljuju strankama po pravilima D'Ontovog sistema:
za svaku stranku se računa količnik po formuli V/(s+1), gde je V broj glasova koji je stranka dobila, a s broj mandata koji je stranci dodeljen do posmatranog trenutka (na početku 0 za sve stranke).
Stranka koja ima najveći količnik dobija sledeći mandat, a zatim se količnici ponovo računaju dok se ne raspodele svi mandati.
Ukoliko najveći količnik ima više stranaka, sledeći mandat se dodeljuje onoj stranci koja ima manji redni broj na glasačkom listiću.
Smatrati da se ukupno raspodeljuje 250 mandata.
Nakon toga potrebno je u izlaznu tekstualnu datoteku ispisati informacije o strankama koje su ušle u parlament (za svaku stranku u zasebnom redu) po formatu: redni broj stranke, naziv stranke, osvojeni broj mandata.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Stranaka 1000
#define MAX_NAME_LENGTH 31

typedef struct {
    int BrojStranke;
    int Glasovi;
    char ImeStranke[MAX_NAME_LENGTH];
    int Mandati;
} Stranka;

void PodelaMandata(Stranka stranka[], int BrojStranaka) {
    int UkupnoGalsova = 0;
    int i;

    // Calculate total number of votes
    for (i = 0; i < BrojStranaka; i++) {
        UkupnoGalsova += stranka[i].Glasovi;
    }

    // Calculate mandates for each party
    for (i = 0; i < BrojStranaka; i++) {
        stranka[i].Mandati = (stranka[i].Glasovi * 250) / UkupnoGalsova;
    }

    // Sort parties based on mandates in descending order
    for (i = 0; i < BrojStranaka - 1; i++) {
        int j;
        for (j = 0; j < BrojStranaka - i - 1; j++) {
            if (stranka[j].Mandati < stranka[j + 1].Mandati) {
                Stranka temp = stranka[j];
                stranka[j] = stranka[j + 1];
                stranka[j + 1] = temp;
            }
        }
    }

    // Distribute remaining mandates based on D'Ont system
    int remainingMandates = 250 - BrojStranaka;
    while (remainingMandates > 0) {
        int maxQuotient = -1;
        int maxQuotientIndex = -1;

        // Find party with highest quotient
        for (i = 0; i < BrojStranaka; i++) {
            int quotient = stranka[i].Glasovi / (stranka[i].Mandati + 1);
            if (quotient > maxQuotient) {
                maxQuotient = quotient;
                maxQuotientIndex = i;
            }
        }

        // Assign next mandate to party with highest quotient
        stranka[maxQuotientIndex].Mandati++;
        remainingMandates--;
    }
}

void writeResultsToFile(Stranka stranka[], int BrojStranaka) {
    FILE* file = fopen("results.txt", "w");
    if (file == NULL) {
        printf("Failed to open file for writing.\n");
        return;
    }

    // Write party information to the file
    for (int i = 0; i < BrojStranaka; i++) {
        fprintf(file, "%d, %s, %d\n", stranka[i].BrojStranke, stranka[i].ImeStranke, stranka[i].Mandati);
    } 
    fclose(file);
}

int main() {
    Stranka stranka[MAX_Stranaka];
    int BrojStranaka = 0;

    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Failed to open input file.\n");
        return 1;
    }

    while (fscanf(file, "%d %d %c[^\n]", &stranka[BrojStranaka].BrojStranke,&stranka[BrojStranaka].Glasovi, stranka[BrojStranaka].ImeStranke) == 3) {
        BrojStranaka++;
        if (BrojStranaka == MAX_Stranaka) {
            printf("Maximum number of parties exceeded.\n");
            break;
        }
    }
    fclose(file);

    PodelaMandata(stranka, BrojStranaka);

    writeResultsToFile(stranka, BrojStranaka);

    printf("Mandate distribution completed. Results written to 'results.txt' file.\n");

    return 0;
}