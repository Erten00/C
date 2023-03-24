 //
 
 
#include <stdio.h>
#include <stdlib.h>

int count_magical_digits(int n);

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