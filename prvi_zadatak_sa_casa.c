#include <stdio.h>
#include <math.h>

int main(){
    int x,y, apsolutnoy;
    printf("Unesite x i y: ");
    scanf("%d %d", &x, &y);
    if(y<0){
        apsolutnoy=-y;
    }else{
        apsolutnoy=y;
    }
    x+=apsolutnoy;
    printf("%d", x);
    return 0;
}