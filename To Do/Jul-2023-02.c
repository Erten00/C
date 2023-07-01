/*
2. Jedno preduzeće je od banke uzelo kredit u iznosu od K eura sa rokom otplate od n godine I kamatnom stopom od p procenata godišnje. 
Napisati program koji će Izračunati kolika će biti ukupna kamata.
Zatim formirati niz koji predstavlja anuitete otplate ako su sve rate jednake(jednake vrednosti uplata glavnice) i ispisati plan otplate kredita.
Računanje ukupne kamate, formiranje niza anuiteta i ispis plana otplate uraditi
I= K*p*((n+1)/2)
Ik= K*(1-((k-1)/n))*p
K-iznos kredita, p-godišnja kamatna stopa, n- nejednaki anuiteti, I - ukupna kamata (interes), Ik- pripadajući interes k-tom anuitetu.
Vrednosti K, p, n, se unose sa tastature.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int K;
    int p;
    int n;
    int I;
    int Ik;
    printf("Unesite iznos kamate");
    scanf("%d", &K);
    printf("Unesite iznos kamate");
    scanf("%d", &n);
    printf("Unesite godisnju kamatnu stopu");
    scanf("%d", &p);







}