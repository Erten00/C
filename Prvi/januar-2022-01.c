// 1. Nacrtati strukturni dijagram toka algoritma i na programskom jeziku C napisati program koji učitava
// cele brojeve i štampa magične cifre sve dok korisnik ne unese broj koji nema nijednu magičnu cifru.
// Cifra broja je magična ukoliko je njena vrednost jednaka poziciji na kojoj se nalazi.
// Cifra jedinica se nalazi na poziciji 1, cifra desetica se nalazi na poziciji 2, cifra najveće
// težine N-tocifrenog broja se nalazi na poziciji N.
// Na primer:
// U broju 71 cifra 1 je magična jer se nalazi na prvoj poziciji.
// Broj 325 ima dve magične cifre, cifru 2 koja se nalazi na drugoj poziciji
// i cifru 3 koja se nalazi na trećoj poziciji.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){
    int magicniBroj;
    while(1){
        bool flag = false;
        printf("Unsite magicni broj:");
        scanf("%d",&magicniBroj);
        int temp = magicniBroj;
        int i = 1;
        while(temp != 0){
            if(temp % 10 == i){
                if(flag == false){
                    printf("broj %d ima magične cifre : %d ", magicniBroj, i);
                    flag = true;
                }
                else{
                    printf("%d ", i);
                }
            }
            temp /= 10;
            i++;
        }
        printf("\n");
        if(!flag){
            break;
        }
    }
    return 0;
}