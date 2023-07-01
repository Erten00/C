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
    double K, p;
    int n;
    double I;
    double Ik;

    // Get the loan amount, annual interest rate, and repayment term from the user
    printf("Unesite iznos kredita (K): ");
    scanf("%lf", &K);
    
    printf("Unesite godišnju kamatnu stopu (p): ");
    scanf("%lf", &p);
    
    printf("Unesite rok otplate u godinama (n): ");
    scanf("%d", &n);
    
    I = K * p * ((n + 1.0) / 2.0);

    Ik = K * (1.0 - ((k - 1.0) / n)) * p;
    
    printf("Totalni interes: %.2lf\n", I);
    
    printf("\nPlan otplate:\n");
    
    double principal_payment = K / n;  // Calculate the equal value of principal payments
    
    for (int k = 1; k <= n; k++) {
        double installment = principal_payment + Ik; 
        printf("Rata %d: Plaćanje glavnice: %.2lf, Intrest: %.2lf, Ukupna rata: %.2lf\n",
               k, principal_payment, Ik, installment);
    }  
    return 0;
}