/*
1. Na programskom jeziku C napisati strukturni program kojim se na početku zadaje tražena suma S, 
a zatira se redomo unose isključivo četvorocifreni brojevi sve dok suma unešenih brojeva ne postane veca od zadate sume S.
Sumirati samo one brojeve čije su sve cifre prosti brojevi. U toku rešavanja programa prikazati unete brojeve koji zadovoljavaju uslov i učestvuju u sumiranju .
Na kraju prikazati izračunatu sumu.

Napomena: Nije dozvoljena upotreba indeksiranih promenljivih.
*/

#include <stdio.h>

int isPrime(int number) {
    if (number < 2) {
        return 0;
    }
    for (int i = 2; i <= number / 2; i++) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int S, sum = 0, number;
    printf("Enter the required sum (S): ");
    scanf("%d", &S);
    printf("Enter four-digit numbers:\n");
    while (sum <= S) {
        scanf("%d", &number);
        if (number >= 1000 && number <= 9999) {
            int digit;
            int isAllPrime = 1;
            
            // Check if all digits are prime
            for (int i = 0; i < 4; i++) {
                digit = number % 10;
                number /= 10;
                
                if (!isPrime(digit)) {
                    isAllPrime = 0;
                    break;
                }
            }
            if (isAllPrime) {
                printf("Entered number: %d\n", number);
                sum += number;
            }
        }
    }
    printf("Sum: %d\n", sum);
    return 0;
}