#include  <stdio.h>
#include <math.h>

int fakt(int a){
    if(a==0)
        return 1;
    return a * fakt(a-1);

}
int main(){
    printf("%d", fakt(8));
}

// 8 * 8 7 6 5 4 3 2 1