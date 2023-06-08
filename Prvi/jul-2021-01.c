// 1. Napisati program koji ispisuje poruku da li je uneti broj N savršen. 
// Broj je savršen ako je zbir cifara na parnim pozicijama jednak zbiru cifara
// na neparnim pozicijama. Primer: Broj 15345 je savršen jer je zbir 1+3+5-5+4
// dok broj 12345 nije savršen jer 1+3+5/2+4.

#include <stdio.h>

int isPerfect(int number) {
    int evenSum = 0, oddSum = 0;
    int digit, isEven = 1;

    while (number > 0) {
        digit = number % 10;
        if (isEven) {
            evenSum += digit;
        } else {
            oddSum += digit;
        }
        isEven = !isEven;
        number /= 10;
    }
    return (evenSum == oddSum);
}

int main() {
    int N;
    printf("Enter a number: ");
    scanf("%d", &N);
    if (isPerfect(N)) {
        printf("The number is perfect.\n");
    } else {
        printf("The number is not perfect.\n");
    }
    return 0;
}