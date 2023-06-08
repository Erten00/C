//Na programskom jeziku C napisati program koji učitava cele brojeve i stampa magične cifre sve dok korisnik ne unese broj koji nema nijednu magičnu cifru.
//Cifra broja je magična ukoliko je njena vrednost jedinaka poziciji na kojoj se nalazi.
//Cifra jedinica se nalazi na pozic 1, cifra desetica se nalazi na poziciji 2, cifra najveće težine N-tocifrenog broja se nalazi na poziciji N
//Na primer:
//U broju 71 cifra 1 je magična jer se nalazi na prvoj poziciji.
//Broj 325 ima dve magične cifre, cifru 2 koja se nalazi na drugoj poziciji i cifru 3 koja se nalazi na trećoj poziciji.
 
#include <stdio.h>
#include <stdlib.h>

int count_magical_digits(int n) {
    int count = 0, position = 1;
    while (n > 0) {
        int digit = n % 10;
        if (digit == position) {
            count++;
        }
        position++;
        n /= 10;
    }
    return count;
} 

int main() {
    int n;
    while (1) {
        printf("Enter a number: ");
        if (scanf("%d", &n) != 1) {
            printf("Invalid input, exiting...\n");
            exit(1);
        }
        if (count_magical_digits(n) == 0) {
            printf("%d has no magical digits.\n", n);
            break;
        }
        printf("%d has %d magical digits.\n", n, count_magical_digits(n));
    }
    return 0;
}