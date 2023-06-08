// 1. Nacrtati strukturni dijagram toka algoritma i na programskom jeziku C napisati program koji učitava
// cele brojeve i štampa magične cifre sve dok korisnik ne unese broj koji nema nijednu magičnu cifru.
// Cifra broja je magična ukoliko je njena vrednost jednaka poziciji na kojoj se nalazi.
// Cifra jedinica se nalazi na poziciji 1, cifra desetica se nalazi na poziciji 2, cifra najveće
// težine N-tocifrenog broja se nalazi na poziciji N.
// Na primer:
// U broju 71 cifra 1 je magična jer se nalazi na prvoj poziciji.
// Broj 325 ima dve magične cifre, cifru 2 koja se nalazi na drugoj poziciji
// i cifru 3 koja se nalazi na trećoj poziciji.

#include <stdio.h>

int main() {
    int number, position = 1, digit;
    while (1) {
        printf("Enter a number: ");
        scanf("%d", &number);
        digit = number % 10;
        while (digit == position) {
            printf("Magic digit: %d\n", digit);
            position++;
            number /= 10;
            digit = number % 10;
        }
        if (digit != position) {
            break;
        }
    }
    return 0;
}