// 2. Napisati program kojim se u niz X umeće broj b neposredno iza minimalnog elementa niza. Unos niza,
// modifikovanje niza I ispis niza odraditi pomoću funkcija. Nije dozvoljeno korišćenje pomoćnog niza

#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

void unos(int niz[SIZE],int n){
    for(int i = 0;i < n;i++){
        scanf("%d",&niz[i]);
    }
}

void ispis(int niz[SIZE],int n){
    for(int i = 0;i < n;i++){
        printf("%d ",niz[i]);
    }
}

void umetanje(int niz[SIZE],int n,int b){
    int min = niz[0];
    int pozicijaElemena = 0;
    for(int i = 0;i < n;i++){
        if(niz[i] < min){
            min = niz[i];
        }
        if(niz[i] == min){
            pozicijaElemena = i;
        }
    }
    n+=1;
    for(int i = n  - 1;i >= pozicijaElemena;i--){
        niz[i] = niz[i - 1];
    }
    niz[pozicijaElemena - 1] = b;
    niz[pozicijaElemena] = min;
}

int main(){
    int niz[SIZE];
    int n,b;
    printf("Unsite n:");
    scanf("%d",&n);
    printf("Unsite elemente niza X:\n");
    unos(niz,n);
    printf("\nUnsite b:");
    scanf("%d",&b);
    umetanje(niz,n,b);
    printf("\nUneti niz X je:\n");
    ispis(niz,n);

    return 0;
}