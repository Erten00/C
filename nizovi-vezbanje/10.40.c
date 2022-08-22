/*10.40. Саставити програм за сортирање унетог низа целих бројева дужине n у неопадајући поредак
методом уметања (Insert Sort). Исписати сортирани низ.
Insert Sort: Нека је првих k елемената већ уређено у неопадајућем поретку, тада се узима
(k+1)-ви елемент и умеће на одговарајуће место међу првих k елемената тако да првих k+1
елемената буде уређено. Овај се метод примењује за k од 0 до n-2.
*/
#include <stdio.h>

void main(){
    int n, i, j; 
    //unos niza
    printf("unesite koliko niz ima elemenata");
    scanf("%d", &n);
    int niz[n];
    printf("Unesite niz");
    for(i = 0; i < n; i++){
        scanf("%d", &niz[i]);
    }
    //sortiranje
    for(i = 0; i<n; i++){
        for(j = i + 1; j<n; j++){
            if(niz[i]>niz[j]){
                niz[i] = niz[i] ^ niz[j];
                niz[j] = niz[i] ^ niz[j];
                niz[i] = niz[i] ^ niz[j];
            }
        }
    }
    //ispis
    for(i = 0; i < n; i++){
        printf("%d", niz[i]);
    }
}