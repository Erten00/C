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
void display(int mat[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to simulate the neighbor corruption for one step
void simulate(int mat[M][N]) {
    int new_mat[M][N];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (mat[i][j] == 2) {
                new_mat[i][j] = 2; // Broken oranges stay broken
            } else if (mat[i][j] == 1) {
                // Check neighbors for corruption
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
                    new_mat[i][j] = 2; // Orange is now broken
                } else {
                    new_mat[i][j] = 1; // Orange stays fresh
                }
            } else {
                new_mat[i][j] = 0; // Empty crate stays empty
            }
        }
    }
    // Copy new matrix back to original matrix
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            mat[i][j] = new_mat[i][j];
        }
    }
}

int main() {
    int mat[M][N];
    // Read in matrix
    printf("Enter the initial state of the crate:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    // Display initial state
    printf("Initial state:\n");
    display(mat);
    // Simulate 3 steps of spoilage
    for (int i = 1; i <= 3; i++) {
        printf("State after step %d:\n", i);
        simulate(mat);
        display(mat);
    }
    return 0;
}