#include <stdio.h>

float povrsina_kruga(float r){
    float  pi = 3.14;
    float p = r * r * pi;
    return p;
}

int main(){
    printf("Površina kruga je %f", povrsina_kruga(5));
    return 0;
}