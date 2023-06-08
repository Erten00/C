// Nacrtati strukturni dijagram toka algoritma i na programskom jeziku C napisati program koji čita
// brojeve sa standardnog ulaza, sve dok se ne pronade prvi simetričan broj. Prikazati taj broj.
// Primeri simetričnih brojeva: 1221, 1331, 8448, itd.

#include <stdio.h>

int isSymmetric(int number) {
    int originalNumber = number;
    int reverse = 0;

    while (number > 0) {
        int digit = number % 10;
        reverse = reverse * 10 + digit;
        number /= 10;
    }

    return (originalNumber == reverse);
}

int main() {
    int number;

    printf("Enter numbers: ");

    while (scanf("%d", &number) == 1) {
        if (isSymmetric(number)) {
            printf("Symmetric number found: %d\n", number);
            break;
        }
    }

    return 0;
}