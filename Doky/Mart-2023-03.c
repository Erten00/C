//Napisati strukturni program na programskom jeziku C za pripremu spiska sa rezultatima sa ispita. 
//U datoteci studenti.txt se nalaze brojevi indeksa, imena i prezimena studenata a u datoteci poeni.txt se nalaze brojevi indeksa i osvojen broj poena na ispitu.
// U svakoj datoteci podaci su organizovani tako da se podaci o jednom studentu nalaze u jednom redu. 
//Program treba da formira datoteku rezultat.txt koja treba da sadrži broj indeksa, prezime, ime i osvojen broj poena studenata koji su polagali ispit.
//Podaci u svim datotekama su sortirani na isti način, prema broju indeksa u rastući redosled. Datoteka studenti.txt može da sadrži i zapise o studentima koji nisu izašli na ispit.
//Na kraju program treba da ispiše na ekran koliko je studenata izašlo na ispit.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int index;
    char first_name[50];
    char last_name[50];
    int points;
};

int main() {
    // open input files for reading
    FILE *student_file = fopen("studenti.tkt", "r");
    FILE *points_file = fopen("poeni.tkt", "r");

    // open output file for writing
    FILE* output_file = fopen("result.tkt", "w");

    if (student_file == NULL || points_file == NULL || output_file == NULL) {
        printf("Error opening input/output files.\n");
        return 1;
    }

    struct Student students[MAX_STUDENTS];
    int num_students = 0;

    // read in student data
    while (fscanf(student_file, "%d %s %s", &students[num_students].index,
                  students[num_students].first_name, students[num_students].last_name) != EOF) {
        num_students++;
    }

    // read in points data and add to student records
    int index, points;
    while (fscanf(points_file, "%d %d", &index, &points) != EOF) {
        for (int i = 0; i < num_students; i++) {
            if (students[i].index == index) {
                students[i].points = points;
                break;
            }
        }
    }

    // write passing student data to output file
    for (int i = 0; i < num_students; i++) {
        if (students[i].points >= 50) {
            fprintf(output_file, "%d %s %s %d\n", students[i].index, students[i].last_name,
                    students[i].first_name, students[i].points);
        }
    }

    // print number of students who took the exam
    printf("Number of students who took the exam: %d\n", num_students);

    // close input/output files
    fclose(student_file);
    fclose(points_file);
    fclose(output_file);

    return 0;
}