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

#define M 10
#define N 10

// Ispis Matrice
void Ispis(int mat[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Funkcija za simulaciju pokvarenih suseda za jedan korak
void simulate(int mat[M][N]) {
    int new_mat[M][N];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (mat[i][j] == 2) {
                new_mat[i][j] = 2; // Pokvarena pomorandza ostaje pokvarena
            } else if (mat[i][j] == 1) {
                // Proverava da li su susedi pokvareni
                int corrupt = 0;
                if (i > 0 && mat[i-1][j] == 2) {
                    corrupt = 1;
                }
                if (i < M-1 && mat[i+1][j] == 2) {
                    corrupt = 1;
                }
                if (j > 0 && mat[i][j-1] == 2) {
                    corrupt = 1;
                }
                if (j < N-1 && mat[i][j+1] == 2) {
                    corrupt = 1;
                }
                if (corrupt) {
                    new_mat[i][j] = 2; // Narandza postaje pokvarena
                } else {
                    new_mat[i][j] = 1; // Narandza ostaje sveza
                }
            } else {
                new_mat[i][j] = 0; // Prazno mesto ostaje prazno
            }
        }
    }
    // Kopira novu matricu nazad u originalnu
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            mat[i][j] = new_mat[i][j];
        }
    }
}

int main() {
    int mat[M][N];
    printf("Unesite pocetno stanje gajbice:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    // Ispisuje pocetno stanje
    printf("Pocetno stanje:\n");
    Ispis(mat);
    // Simulirajte 3 koraka kvarenja
    for (int i = 1; i <= 3; i++) {
        printf("State after step %d:\n", i);
        simulate(mat);
        Ispis(mat);
    }
    return 0;
}