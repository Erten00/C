// 1. Sastaviti program koji će učitati dva broja min. Oha broja treba da budu prirodna.
// Ak taj uslov nije ispinjen, učitavanje treba ponoviti. Ako je om, zameniti na sa n.ž
// Nači i ispisati sumu kvadratnih Korena svih neparnih brojeva od m do n

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SIZE 100

int main(){
    int m = 0,n = 0;
    int i;
    int s = 0;
    int niz1[SIZE],niz2[SIZE];
    printf("Uneiste m:");
    while(m <= 0){
        scanf("%d",&m);
        if(m <= 0){
            printf("Unesite ponovo m:");
        }
    }
     printf("Uneiste n:");
    while(n <= 0){
        scanf("%d",&n);
        if(n <= 0){
            printf("Unesite ponovo n:");
        }
    }
    if(n < m){
        m = m ^ n;
        n = m ^ n;
        m = m ^ n;
    }
    printf("Zamenili smo m i n pa je sada m: %d ,n: %d",m,n);

    //Suma kvadratnih korena od m do n
    if(n > m){
       
    for(m = m;m < n;m++){
        niz2[m] = m;
        if(m % 2 == 1){
           s+=sqrt(niz2[m]); 
        }
    }
    }
    if(m > n){
    
    for(n = n;n < m;n++){
        niz1[n] = n;
        if(n % 2 == 1){
            s+=sqrt(niz1[n]);
        }
    }
    }
   printf("\nSuma kvadratnih korena od m do n je:%d",s);

    return 0;
}