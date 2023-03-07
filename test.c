//Naci i ispistai na standardnom izlazu zbir.razliku,proizvod i kolicnik dva uneta broja

#include<stdio.h>

int main(){
    int a,b;
    printf("Unesite dva broja a i b:");
    scanf("%d %d", &a,&b);
    int zbir=a+b;
    int razlika=a-b;
    int proizvod=a*b;
    float kolicnik=(float)a/(float)b;
    printf("Zbir brojeva %d i %d je: %d \n",a , b , zbir);
    printf("Razlika brojeva %d i %d je:%d \n",a, b, razlika);
    printf("Proizvod brojeva %d i %d je: %d \n",a, b, proizvod);
    printf("količnik brojeva %d i %d je: %f \n",a,b,kolicnik);
}


