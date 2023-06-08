// 1. Sa tastature se učitava prirodan broj n,
// i zatim n prirodnih brojeva među kojima su bar dva različita.
// Napisati program koji jednim prolaskom kroz niz određuje drugu po veličini vrednost.
// Na primer za pet brojeva 6, 6, 7, 6, 2 ispisuje: Druga po veličini vrednost je 6.

#include <stdio.h>

int main() {
    int n, i;
    int largest = 0, secondLargest = 0;
    int number;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter a natural number: ");
        scanf("%d", &number);

        if (number > largest) {
            secondLargest = largest;
            largest = number;
        } else if (number > secondLargest && number < largest) {
            secondLargest = number;
        }
    }
    printf("The second largest value is: %d\n", secondLargest);
    return 0;
}