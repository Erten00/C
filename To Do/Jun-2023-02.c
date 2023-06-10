/*
2. Napisati program koji utvrđuje da li je zadata kvadratna matrica tridijagonalna.
Kvadratna matrica je tridijagonalna ukoliko sadrži bar po jedan nenulti element na glavnoj dijagonali, jednoj dijagonali neposredno ispod i jednog dijagonali neposredno iznad glavne dijagonale.
Svi ostali elementi moraju biti jednaki nuli. Dimenzije matrice mogu biti u opsegu 3≤N≤100, što je potrebno proveriti prilikom unosa.
Program najpre treba da učita dimenziju matrice i njene elemente sa glavnog ulaza, a zatim izvrši zahtevanu proveru i ispiše da li je matrica tridijagonalna ili ne.
Učitavanje i proveru da li je matrica tridijagonalna realizovati kao zasebne potprograme koji sa glavnim programom komuniciraju samo putem argumenata i povratne vrednosti.
*/

#include <stdio.h>

int isTridiagonal(int matrix[][100], int n) {
    int i, j;
    
    // Check elements below the main diagonal
    for (i = 1; i < n; i++) {
        for (j = 0; j < i - 1; j++) {
            if (matrix[i][j] != 0) {
                return 0; // Not tridiagonal
            }
        }
    }
    
    // Check elements above the main diagonal
    for (i = 0; i < n - 1; i++) {
        for (j = i + 2; j < n; j++) {
            if (matrix[i][j] != 0) {
                return 0; // Not tridiagonal
            }
        }
    }
    
    return 1; // Tridiagonal
}



int main() {
    int n, i, j;
    int matrix[100][100];
    
    printf("Enter the dimension of the matrix (3-%d): ", 100);
    scanf("%d", &n);
    
    if (n < 3 || n > 100) {
        printf("Invalid dimension. Please enter a valid dimension.\n");
        return 1;
    }
    
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    if (isTridiagonal(matrix, n)) {
        printf("The matrix is tridiagonal.\n");
    } else {
        printf("The matrix is not tridiagonal.\n");
    }
    
    return 0;
}