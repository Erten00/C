// 1. Na programskom jeziku C napisati strukturni program za unos celih brojeva. Za svaki od unetih
// brojeva proveriti da li je prost. Brojeve unositi sve dok ukupna suma samo onih brojeva koji
// su prosti ne postane veća od unapred zadate sume S. Prikazivati na ekranu sve proste brojeve
// redom kao trenutno izračunatusumu unetih prostih brojeva. Prikazati i ukupan broj unetih prostih
// brojeva. Napomena: Nije dozvoljena upotreba indeksiranih promenljivih.


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 100

int main(){
    int broj;    int suma = 0;
    int S = 0;
    int niz[SIZE],i;
    bool flag = true;
    int prostiBrojevi = 0;
    int temp = 0;
   
    printf("Unesite sumu S:");
    scanf("%d",&S);
    printf("Unesite broj:");
    scanf("%d",&broj);
  
    while(S >= suma){
        scanf("%d",&broj);
       if(flag == true){
        temp = broj;
        niz[prostiBrojevi] = broj;
        suma += broj;
        prostiBrojevi++;
        }
    }
  
    if(broj == 0 || broj == 1){
        flag = true;
    }
    while(i > broj){
        i = 2;
        if(broj % i == 0){
        flag = false;
        break;
       }
       i++;
       }
  
        printf("Prosti brojevi su:");
         if(flag == true){
          printf("%d ",temp);
        }
        
    for(i = 0;i < prostiBrojevi + 1; i++){
        if(flag == true){
            if(niz[i] == 0){
                break;
            }
            printf("%d ",niz[i]);
        }
    }
    printf("\nIma %d prostih brojeva",prostiBrojevi);
    return 0;
}
