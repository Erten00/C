// 2. Napisati program kojim se vrši zamena mesta najvećeg i najmanjeg elemenata
// ispod sporedne dijagonale matrice X. Učitavanje matrice I totalnu obradu realizovati
// pomoću odvojenih funkcija

#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

void unos(int matrix[SIZE][SIZE],int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
}

void ispis(int matrix[SIZE][SIZE],int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d \n", matrix[i][j]);
        }
    }
}

int suma(int matrix[SIZE][SIZE],int n){
    int KonacanBroj = 0;
    int maks = 0;
    int min = matrix[n-1][n-1];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i + j >= n){
                if(matrix[i][j] > maks){
                    maks = matrix[i][j];
                }
                if(matrix[i][j] < min){
                    min = matrix[i][j];
                }
            }
        }
    }
    printf("maks: %d\n",maks);
    printf("min: %d\n",min);
    KonacanBroj = maks + min;
    return KonacanBroj;
}

int main(){
    int X[SIZE][SIZE];
    int n;
    printf("Unsite n:");
    scanf("%d", &n);
    printf("Unsite matricu:");
    unos(X,n);
    printf("Uneta matrica:\n");
    ispis(X,n);
    printf("Suma najmanjeg i najveceg ispod sporedne dijagonale je:%d",suma(X,n));

    
    

    return 0;
}