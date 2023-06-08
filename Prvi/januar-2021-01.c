// 1. Nacrtati strukturni dijagram toka algoritma i na programskom jeziku napisati strukturni program za sumiranje
// celih pozitivnih N to cifrenih brojeva Brojevi se unose sa tastature redom, a sumiranje se vrši sve dok se ne unese
// broj čija je prva cifra veća od njegove poslednje cifre. Prikazati dobijenu sumu brojeva: Napomena: Nije dozvoljena
// upotreba indeksiranih promenljivih. Korisnik pre unosa brojeva mora uneti broj N. Sumirati samo brojeve koji imaju N cifara

#include <stdio.h>
#include <stdlib.h>

int get_sum(int N) {
    int num_sum = 0;
    char number[10];

    while (1) {
        printf("Enter a whole positive N-digit number (or enter a number with first digit > last digit to stop): ");
        scanf("%s", number);

        if (number[0] > number[N - 1]) {
            break;
        }

        if (strlen(number) == N) {
            num_sum += atoi(number);
        }
    }

    return num_sum;
}

int main() {
    int N;

    printf("Enter the value of N: ");
    scanf("%d", &N);

    int sum_result = get_sum(N);

    printf("Sum of N-digit numbers: %d\n", sum_result);

    return 0;
}