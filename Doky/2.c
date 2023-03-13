// 2. Na programskom jeziku C napisati strukturni program za prikaz gajbice sa narandžama i praćenje procesa njihovog kvarenja. 
// Na početku programa korisnik unosi dimenzije gajbice (predstaviti je preko matrice dimenzije MxN) podatke o narandžama u njoj.
// Svako polje matrice može imati jednu od sledece tri vrednosti: 0-prazno mesto, 1-narandža, 2 – pokvarena narandza. 
// Smatrati da korisnik nece uneti nevalidne vrednosti. 
// Unete vrednosti predstavijaju inicijalno stanje gajbice, nakon čega pokvarene narandže počinju "da kvare” svoje susede.
// Napisati funkciju koja za prosledjenu matricu vraca njeno stanje nakon prvog koraka "kvarenja suseda".
// U glavnom programu prikazati pocetno stanje gajbice sa narandzama.
// Pomoću kreirane funkcije simulirati 3 koraka kvarenja narandži i prikazati krajnje stanje.
// Napomena: Za maksimalan broj poena alocirati memoriju dinamički.

#include <stdio.h>
#include <stdlib.h>


// Unos Matrice
void Unos(int matrix[SIZE][SIZE],int m,int n){
    int i,j;
     for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d",&matrix[i][j]);
        }
    }
}

// Ispis Matrice
void Ispis(int matrix[SIZE][SIZE],int m,int n){
    int i,j;
     for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}