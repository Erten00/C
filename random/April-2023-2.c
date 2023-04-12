/*
Napisati program koji proverava da li su dva niza cifara anagrami.
Dva niza cifara su anagrami ako se svaka cifra pojavljuje isti broj puta i u jednom i u drugom nizu.
Na primer, nizovi 1 2 3 4 I 2 3 1 4 jesu anagrami, dok 1 2 3 4 I 2 3 1 1 nisu.
Program treba najpre da sa standardnog ulaza učita dužine nizova, a zatim i same elemente nizova,
da proveri da li su učitani nizovi anagrami i da na standardnom izlazu ispiše rezultat provere. 
Učitavanje pojedinačnog niza i proveru da li su dva niza cifara anagrami realizovati kao zasebne potprograme, koji sa glavnim programom komuniciraju isključivo putem argumenata i povratnih vrednosti. 
Smatrati da su elementi nizova decimalne cifre, kao i da nizovi nemaju više od 100 elemenata. 
Ukoliko se za dužinu nekog od nizova unese nedozvoljena vrednost, ispisati poruku o greści i prekinuti izvršavanje programa.
*/

#include <stdio.h>
#include <stdlib.h>

int is_anagram(int *arr1, int *arr2, int len1, int len2) {
    if (len1 != len2) {
        return 0;
    }

    int freq1[10] = {0};
    int freq2[10] = {0};

    for (int i = 0; i < len1; i++) {
        freq1[arr1[i]]++;
        freq2[arr2[i]]++;
    }

    for (int i = 0; i < 10; i++) {
        if (freq1[i] != freq2[i]) {
            return 0;
        }
    }

    return 1;
}

void load_string(int *arr, int len) {
    printf("Enter %d digits: ", len);
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
}

int main() {
    int len1, len2;

    printf("Enter length of first string: ");
    scanf("%d", &len1);
    if (len1 < 1 || len1 > 100) {
        printf("Error: length must be between 1 and 100.\n");
        return 1;
    }

    int arr1[len1];
    load_string(arr1, len1);

    printf("Enter length of second string: ");
    scanf("%d", &len2);
    if (len2 < 1 || len2 > 100) {
        printf("Error: length must be between 1 and 100.\n");
        return 1;
    }

    int arr2[len2];
    load_string(arr2, len2);

    int result = is_anagram(arr1, arr2, len1, len2);
    if (result) {
        printf("The two strings are anagrams.\n");
    } else {
        printf("The two strings are not anagrams.\n");
    }

    return 0;
}
