// 3. Datoteka stanje.txt sadri podatke o zubima. 
// Prvi red datoteke sadrži broj pacijenata, a zaim u po dva reda se nalate zatečeno stanje zuba. 
// U prvoj vrsti se nalazi stanje gornje vilice a u drugoj vrsti stanje donje vilice. 
// Ako je I-ti element u vrsti 0 onda znači da taj pacijent nema zub na I-tom mestu, ako je 1 onda znači da ima zubi i da je zdrav, a ako je 2 onda znači da ima zub ali je kvaran 
// U drugoj datoteci intervencije.txt nalaze se podaci o izvršenim intervencijama (broj pacijenta, broj zuba, intrevencija (P-popravljen zub, 1-izvadjen zub) 
// Izvrsiti osvežavanje podataka u prvoj datoteci na osnovu podataka iz druge datoteke intrevencije.txt.
// Za svakog pacijenta prikazati stanje i pisati izveštaj koliko ukupno ima zuba, koliko ima kvarnih zuba i procenat kvarnih zuba u odnosu na ukupan broj zuba.


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define SIZE 100

typedef struct Stanje
{
    int BrojPacijenata;
    int GornjaVilica;
    int DonjaVilica;
    int BrojZuba; // 0 oznacava nemanje zuba, 1  ima zub i zdrav je, 2 ima zub ali je kvaran

};

int main(){

    FILE * stanje_datoteka = fopen ("stanje.txt", "r");
    if(stanje_datoteka == NULL){
        printf("greška pri otvaranju stajne.txt");
        exit(1);
    }
    FILE * intervencije_datoteka = fopen ("intervencija.txt", "r");
    if(intervencije_datoteka == NULL){
        printf("greška pri otvaanju intervencija.txt");
        exit(1);
    }
    while(!feof(stanje_datoteka)){
        fscanf(stanje_datoteka, "%d %f %d %d %d",  &stanovi[i].broj_stana, &stanovi[i].povrsina, &stanovi[i].cena, &stanovi[i].broj_soba, &stanovi[i].je_li_slobodan)
}
}