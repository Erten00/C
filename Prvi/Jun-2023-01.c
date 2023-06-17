/*
1.Sastaviti na jeziku C program za određivanje narednog datuma u odnosu na zadati dan.
Program treba da čita datume i da ispituje rezultate sve dok za jednu od komponenata datuma ne pročita nulu.
*/

#include <stdio.h>

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1; // Leap year
    } else {
        return 0; // Not a leap year
    }
}

int isValidDate(int day, int month, int year) {
    if (year < 1 || month < 1 || month > 12 || day < 1) {
        return 0; // Invalid date
    }

    int daysInMonth;

    if (month == 2) {
        daysInMonth = isLeapYear(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } else {
        daysInMonth = 31;
    }

    if (day > daysInMonth) {
        return 0; // Invalid date
    }

    return 1; // Valid date
}

void getNextDate(int* day, int* month, int* year) {
    int daysInMonth;

    if (*month == 2) {
        daysInMonth = isLeapYear(*year) ? 29 : 28;
    } else if (*month == 4 || *month == 6 || *month == 9 || *month == 11) {
        daysInMonth = 30;
    } else {
        daysInMonth = 31;
    }

    if (*day < daysInMonth) {
        (*day)++;
    } else {
        *day = 1;

        if (*month < 12) {
            (*month)++;
        } else {
            *month = 1;
            (*year)++;
        }
    }
}

int main() {
    int day, month, year;

    printf("Enter the date (day month year): ");
    scanf("%d %d %d", &day, &month, &year);

    while (day != 0 && month != 0 && year != 0) {
        if (!isValidDate(day, month, year)) {
            printf("Invalid date. Please enter a valid date (day month year): ");
            scanf("%d %d %d", &day, &month, &year);
            continue;
        }

        getNextDate(&day, &month, &year);
        printf("Next date: %d %d %d\n", day, month, year);

        printf("Enter the date (day month year): ");
        scanf("%d %d %d", &day, &month, &year);
    }

    return 0;
}