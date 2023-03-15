
// 1. Nacrtati strukturni dijagram toka algoritma i na programskom jeziku napisati strukturni program za sumiranje
// celih pozitivnih N to cifrenih brojeva Brojevi se unose sa tastature redom, a sumiranje se vrši sve dok se ne unese
// broj čija je prva cifra veća od njegove poslednje cifre. Prikazati dobijenu sumu brojeva: Napomena: Nije dozvoljena
// upotreba indeksiranih promenljivih. Korisnik pre unosa brojeva mora uneti broj N. Sumirati samo brojeve koji imaju N cifara

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int main(){
    int suma = 0;
    int n,i,j;
    int k;
    int broj = 0;
    int duzinaBroja = 0;
    int pomocniNiz[k];
    printf("Koliko cete brojeva uneti:");
    scanf("%d",&k);

    printf("Unesite broj cifara:");
    scanf("%d",&n);
    printf("Unosite broj sa %d cifara",&n);
    
    for(i = 0;i < k;i++){
        for(j = 0;j < n;j++){
        int temp;
        printf("\nUnesite cifru:");
        scanf("%d",&temp);
        broj = broj * 10 + temp;
        }
        
        pomocniNiz[k] = broj;
       
    }
    for(i = 0; i < k; i++){
        duzinaBroja = 0;
        for(j = 0; j < n; j++){
            broj = broj / 10;
            duzinaBroja++;
        }
    }
    printf("Vasi brojevi su:\n");
    for(i = 0;i < k;i++){
        if(broj / duzinaBroja == 0){
            printf("%d,",pomocniNiz[k]);
        }
    }
   
    return 0;
}

