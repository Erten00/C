/*
Napisati program koji vrši obradu nad spiskom odlaznih letova iz nekog grada koji se nalaze u datoteci odlasci.txt. 
Jedan red datoteke sadrži ime dolaznog grada (jedna reč od maksimalno 20 slova), broj leta (ceo broj) i oznaku aviona (jedna reč od maksimalno 20 slova).
U datoteci može postojati više letova za jednu destinaciju.
Datoteka avioni.txt sadrži informacije o avionima.
Jedan red datoteke sadrži oznaku aviona (jedna reč od maksimalno 20 slova) i broj sedišta u avionu, pri čemu se svaki avion za koji postoji let u datoteci odlasci.txt sigurno pojavljuje u datoteci avioni.txt.
Program treba da pročita sa standardnog ulaza ime dolaznog grada, da izračuna koliko ukupno postoji sedišta na svim letovima do tog grada i ispiše taj broj na standardnom izlazu. 
Voditi računa o ispravnoj upotrebi resursa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITY_LEN 20
#define MAX_FLIGHTS 100
#define MAX_PLANES 100

typedef struct {
    char city[MAX_CITY_LEN+1];
    int flight_number;
    char aircraft[MAX_CITY_LEN+1];
} Flight;

typedef struct {
    char plane[MAX_CITY_LEN+1];
    int num_seats;
} Plane;

int main() {
    char city[MAX_CITY_LEN+1];
    int total_seats = 0;

    printf("Enter the name of the incoming city: ");
    scanf("%s", city);

    // Read in the list of flights
    FILE *departures_file = fopen("departures.txt", "r");
    if (!departures_file) {
        printf("Error: Could not open departures file.\n");
        return 1;
    }

    Flight flights[MAX_FLIGHTS];
    int num_flights = 0;

    char dep_city[MAX_CITY_LEN+1];
    int flight_number;
    char aircraft[MAX_CITY_LEN+1];

    while (fscanf(departures_file, "%s %d %s", dep_city, &flight_number, aircraft) == 3) {
        if (strcmp(city, dep_city) == 0) {
            strcpy(flights[num_flights].city, dep_city);
            flights[num_flights].flight_number = flight_number;
            strcpy(flights[num_flights].aircraft, aircraft);
            num_flights++;
        }
    }

    fclose(departures_file);

    // Read in the list of planes
    FILE *planes_file = fopen("planes.txt", "r");
    if (!planes_file) {
        printf("Error: Could not open planes file.\n");
        return 1;
    }

    Plane planes[MAX_PLANES];
    int num_planes = 0;

    char plane_name[MAX_CITY_LEN+1];
    int num_seats;

    while (fscanf(planes_file, "%s %d", plane_name, &num_seats) == 2) {
        for (int i = 0; i < num_flights; i++) {
            if (strcmp(flights[i].aircraft, plane_name) == 0) {
                strcpy(planes[num_planes].plane, plane_name);
                planes[num_planes].num_seats = num_seats;
                num_planes++;
                break;
            }
        }
    }

    fclose(planes_file);

    // Calculate total number of seats
    for (int i = 0; i < num_planes; i++) {
        total_seats += planes[i].num_seats;
    }

    printf("Total number of seats for flights to %s: %d\n", city, total_seats);

    return 0;
}
