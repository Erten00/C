// Uzima broj i okrece ga
#include <stdio.h>
int main(){
    unsigned long long a;
    scanf("%llu", &a);
    long t=a;
    int j;
    while(t!=0){
        j=t%10;
        t/=10;
        printf("%d", j);
    }
    return 0;
}