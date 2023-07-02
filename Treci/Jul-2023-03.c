/*
3. Date su dve datoteke ROBA.DAT i PROMET.DAT.
Prva datoteka (ROBA.DAT) sastoji se od slogova koji sadrže: šifru artikla koji se nalazi u magacinu, naziv robe, naziv proizvođača i količinu na početku.
Druga datoteka PROMET.DAT, na kraju radnog dana, sadrži informaciju o tome koliko se uvećala ili smanjila količina nekog artikla u magacinu, 
Slog druge datoteke čine šifra artikla i količina.
 Vrednost polja količina može biti pozitivna (uvećanje količine robe u magacinu) ili negativna (smanjenje količine robe u magacinu). 
Napisati program kojim će se na kraju radnog dana ubaciti prave količine artikala u datoteku ROBA.DAT a na osnovu datoteke PROMET DAT.
*/

#include <stdio.h>

typedef struct {
    int Sifra;
    char NazivRobe[50];
    char NazivProizvodjaca[50];
    int Kolicina;
} Item;

void updateQuantities(FILE *robafp, FILE *prometfp) {
    Item item;
    int Sifra, Kolicina;
    
    while (fscanf(prometfp, "%d %d", &Sifra, &Kolicina) == 2) {
        // Search for the item in the ROBA.DAT file
        int found = 0;
        fseek(robafp, 0, SEEK_SET);
        while (fread(&item, sizeof(Item), 1, robafp) == 1) {
            if (item.Sifra == Sifra) {
                found = 1;
                break;
            }
        }
        // Update the quantity if the item is found
        if (found) {
            item.Kolicina += Kolicina;
            // Move the file pointer back by sizeof(Item) to overwrite the updated record
            fseek(robafp, -sizeof(Item), SEEK_CUR);
            // Write the updated item to the ROBA.DAT file
            fwrite(&item, sizeof(Item), 1, robafp);
        }
    }
}

int main() {
    FILE *robafp, *prometfp;
    
    robafp = fopen("ROBA.DAT", "rb+");
    prometfp = fopen("PROMET.DAT", "rb");
    
    if (robafp == NULL || prometfp == NULL) {
        printf("Failed to open one or more files.\n");
        return 1;
    }
    
    // Update the quantities based on the PROMET.DAT file
    updateQuantities(robafp, prometfp);
    
    // Close the files
    fclose(robafp);
    fclose(prometfp);
    
    printf("Quantities updated successfully.\n");
    
    return 0;
}