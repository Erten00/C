/*
Sastaviti program koji računa vrednost izraza ex na osnovu prvih nekoliko (n) članova Tejlorovog reda za uneto x.
*/

#include <stdio.h>

double calculate_ex(double x, int n) {
    double sum = 1;
    double term = 1;
    int i;
    for (i = 1; i <= n; i++) {
        term *= x / i;
        sum += term;
    }
    return sum;
}

int main() {
    double x;
    int n;
    printf("Enter the value of x: ");
    scanf("%lf", &x);
    printf("Enter the number of terms (n): ");
    scanf("%d", &n);
    double ex = calculate_ex(x, n);
    printf("e^%.2lf = %.6lf\n", x, ex);
    return 0;
}