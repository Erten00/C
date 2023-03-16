/*
u programskom jeziku c napisati strukturu programa za sumiranje g.
najpre uneti maksimalnu sumu a potom unositi cele brojeve . sumirati samo proste brojeve
dok njihova suma ne postane veća od zadate maksimalne sume.  
prikazati dobijenu sumu .
*/

#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>

int main(){
    int maksimalnaSuma, suma = 0, broj;
    bool flag = true;
    printf("unesite maksimalnu sumu :");
    scanf("%d", &maksimalnaSuma);
    printf("\n");
    while(suma < maksimalnaSuma){
        scanf("%d", &broj);
        // Odredjivanje prostih brojeva
        for(int i = 2; i < broj; i++){
            if(broj % i == 0){
                flag = false;
                break;
            }
        }

        if(flag){
            suma = suma + broj;
        }
        printf("%d  %d \n", maksimalnaSuma, suma);
    }
    printf("%d ", suma);
    return 0;
}