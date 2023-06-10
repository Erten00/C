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

#define MAX_PARTIES 1000
#define MAX_NAME_LENGTH 31

typedef struct {
    int serialNumber;
    int votes;
    char name[MAX_NAME_LENGTH];
    int mandates;
} Party;

void distributeMandates(Party parties[], int numParties) {
    int totalVotes = 0;
    int i;

    // Calculate total number of votes
    for (i = 0; i < numParties; i++) {
        totalVotes += parties[i].votes;
    }

    // Calculate mandates for each party
    for (i = 0; i < numParties; i++) {
        parties[i].mandates = (parties[i].votes * 250) / totalVotes;
    }

    // Sort parties based on mandates in descending order
    for (i = 0; i < numParties - 1; i++) {
        int j;
        for (j = 0; j < numParties - i - 1; j++) {
            if (parties[j].mandates < parties[j + 1].mandates) {
                Party temp = parties[j];
                parties[j] = parties[j + 1];
                parties[j + 1] = temp;
            }
        }
    }

    // Distribute remaining mandates based on D'Ont system
    int remainingMandates = 250 - numParties;
    while (remainingMandates > 0) {
        int maxQuotient = -1;
        int maxQuotientIndex = -1;

        // Find party with highest quotient
        for (i = 0; i < numParties; i++) {
            int quotient = parties[i].votes / (parties[i].mandates + 1);
            if (quotient > maxQuotient) {
                maxQuotient = quotient;
                maxQuotientIndex = i;
            }
        }

        // Assign next mandate to party with highest quotient
        parties[maxQuotientIndex].mandates++;
        remainingMandates--;
    }
}

void writeResultsToFile(Party parties[], int numParties) {
    FILE* file = fopen("results.txt", "w");
    if (file == NULL) {
        printf("Failed to open file for writing.\n");
        return;
    }

    // Write party information to the file
    for (int i = 0; i < numParties; i++) {
        fprintf(file, "%d, %s, %d\n", parties[i].serialNumber, parties[i].name, parties[i].mandates);
    }
    fclose(file);
}

int main() {
    Party parties[MAX_PARTIES];
    int numParties = 0;

    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Failed to open input file.\n");
        return 1;
    }

    // Read party information from the file
    while (fscanf(file, "%d %d %[^\n]", &parties[numParties].serialNumber,
                  &parties[numParties].votes, parties[numParties].name) == 3) {
        numParties++;
        if (numParties == MAX_PARTIES) {
            printf("Maximum number of parties exceeded.\n");
            break;
        }
    }

    fclose(file);

    // Check if there are enough parties
    if (numParties == 0) {
        printf("No parties found in the input file.\n");
        return 1;
    }

    // Perform mandate distribution
    distributeMandates(parties, numParties);

    // Write results to output file
    writeResultsToFile(parties, numParties);

    printf("Mandate distribution completed. Results written to 'results.txt' file.\n");

    return 0;
}