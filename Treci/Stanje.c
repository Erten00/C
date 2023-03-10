#include <stdio.h>

#define MAX_PATIENTS 100
#define MAX_TEETH 32

int main() {
    int num_patients
    int upper_jaw[MAX_TEETH]
    int lower_jaw[MAX_TEETH];
    int patient_num, Zub;
    char intervention;

    // cita stanje.txt
    FILE *fp = fopen("stanje.txt", "r");
    fscanf(fp, "%d", &num_patients);
    for (int i = 0; i < MAX_TEETH; i++) {
        fscanf(fp, "%d", &upper_jaw[i]);
    }
    for (int i = 0; i < MAX_TEETH; i++) {
        fscanf(fp, "%d", &lower_jaw[i]);
    }
    fclose(fp);

    // cita intervencije iz intervencije.txt i osvezava stanje zuba
    fp = fopen("intervencije.txt", "r");
    while (fscanf(fp, "%d %d %c", &patient_num, &Zub, &intervention) == 3) {
        if (Zub < 0 || Zub >= MAX_TEETH) {
            printf("Invalid tooth number %d for patient %d\n", Zub, patient_num);
            continue;
        }
        if (patient_num < 1 || patient_num > num_patients) {
            printf("Invalid patient number %d\n", patient_num);
            continue;
        }
        int *jaw = upper_jaw;
        if (Zub >= MAX_TEETH / 2) {
            jaw = lower_jaw;
            Zub -= MAX_TEETH / 2;
        }
        int *status = &jaw[Zub];
        if (intervention == 'P') {
            *status = 1;
        } else if (intervention == 'I') {
            *status = 0;
        } else {
            printf("Invalid intervention type '%c'\n", intervention);
        }
    }
    fclose(fp);

    // Izvestaj
    for (int i = 1; i <= num_patients; i++) {
        int total_teeth = 0, missing_teeth = 0, defective_teeth = 0;
        for (int j = 0; j < MAX_TEETH; j++) {
            int *jaw = upper_jaw;
            if (j >= MAX_TEETH / 2) {
                jaw = lower_jaw;
            }
            int status = jaw[j];
            if (status != 0) {
                total_teeth++;
            }
            if (status == 0) {
                missing_teeth++;
            } else if (status == 2) {
                defective_teeth++;
            }
        }
        printf("Patient %d:\n", i);
        printf("Total teeth: %d\n", total_teeth);
        printf("Missing teeth: %d\n", missing_teeth);
        printf("Defective teeth: %d (%.2f%%)\n", defective_teeth,
               (float)defective_teeth / total_teeth * 100);
    }

    return 0;
}