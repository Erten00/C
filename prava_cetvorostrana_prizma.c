#include <stdio.h>
#include <math.h>

float povrsina_kvadrata(float a) {
    // P = a • a
    return a * a;
}

float povrsina_pravougaonika(float a, float b) {
    // P = a • b
    return a * b;
}

float povrsina_prizme(float a, float h) {
    // P = 2B + M
    float b, m;
    b = 2 * povrsina_kvadrata(a);
    m = 4 * povrsina_pravougaonika(a, h);
    return b + m;
}

int main() {
    float a, h;
    printf("Unesite stranicu a i visinu h: ");
    scanf("%f %f", &a, &h);
    printf("Površina prizme je: %.2f", povrsina_prizme(a, h));
    return 0;
}