#include <stdio.h>

void exchange(int arr[], int n) {
    int i, j, sum;
    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = i + 1; j < n; j++) {
            sum += arr[j];
            if (sum == j - i + 1) {
                arr[i] = sum;
                break;
            }
        }
    }
}

void exchange(int arr[], int n);

int main() {
    int n, i, j;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);
    int a[n][n];
    printf("Enter the elements of the matrix: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (i == j || i + j == n - 1) {
                exchange(&a[i][0], n);
            }
        }
    }
    printf("Matrix after transformation: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}