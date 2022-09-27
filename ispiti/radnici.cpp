/*
Realizovati klase Radnik i Sef koje imaju ime, prezime i platu, 
metode konstruktor bez argumenata i ispis().
Klasa Firma je generička klasa koja ima niz (Radnika, Sefova) 
i broj Radnika/Sefova koji je podrazumevano 10. Metodu plate() koja 
ispisuje podatke o Radnicima/Sefovima.
Kreirati 2 Firme, jednu Firmu Sefova (koja ima 10 Sefova) i Firmu Radnika (koja ima 3 Radnika).
*/

#include<iostream>
#include<string.h>
using namespace std;
class Radnik{
    public:
    float plata;
    char ime[15];
    char prezime[20];
    Radnik(){
        cout << "Pozvan je konstrukor";
        strcpy(ime,"Petar");
        strcpy(prezime,"Petrovic");
        plata = 10000;    
    }
    void ispis(){ 
        cout<<ime<<" "<<prezime<<" je radnik u preduzecu i ima platu "<<plata<<endl;   
    }
};
class Sef{
    public:
    float plata;   
    char ime[15];
    char prezime[20];
    Sef(){
        strcpy(ime,"Mitar");
        strcpy(prezime,"Miric");
        plata = 15000;          
    }  
    void ispis(){
        cout<<ime<<" "<<prezime<<" je sef u preduzecu i ima platu "<<plata<<endl;
    }
};

template <typename T,int k=10> 
class Firma{
    T t[k];
    public:
    void plate()
    {for(int i=0;i<k;i++)
        t[i].ispis();
    }
};
int main(){
    Firma<Sef> firSef;
    firSef.plate();
    Firma<Radnik,3> firRad;
    firRad.plate();
    return 0;   
}

