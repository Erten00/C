// Napisati na jeziku C++ sledeći sistem klasa.
// Klase opremiti onim konstruktorima,destruktoromi operatorima dodelekoji su potrebni za bezbedno i efikasno korišćenje klasa. 
// Greške prijavljivati  izuzecima  tipa  jednostavnih  klasa  koje  su  opremljene  pisanjem  teksta  poruke. 
// Za generičke zbirke nije dozvoljeno korišćenje klasa iz standardne biblioteke šablona (STL).

// 1.	Klasa Sastojak sadrži zadato ime i cenu po kilogramu.
//      Pomoću metoda može da se dohvati vrsta sastojka 
//      i da se izračuna cena za zadatu količinu sastojka u gramima(količina dolazi kao argument metode).
//      Upisuje se u izlazni tok (cout<<s)  u obliku ime-cena/kg.
//      Vrste slanog, slatkog i neutralnog sastojka su SLAN, SLADiNEUT, respektivno. (Odraditi pomoću enumeracije)

// 2.	
//      Klasa Jelo ima ime i sadrži listu sastojaka, 
//      kao i celobrojnu vrednost koja predstavlja količinu sastojka za pripremu jela izraženu u gramima.
//      Cena jela je određena zbirom cene sastojaka,
//      uz eventualno procentualno povećanje ili smanjenje osnovne cene,
//      koje zavisi od sata formiranja cene jela. 
//      Može da se postavi podatak o procentualnoj promeni cene jela i podatak o satu formiranja cene.
//      Može da se doda sastojak određene količine u jelo, 
//      pri čemu se pre dodavanja proverava da li je sastojak adekvatan(greška je ako nije),
//      da se dohvati jednoslovna vrsta jela i da se izračuna njegova cena.
//      Upisuje se u izlazni tok(cout<<j) tako što se u prvom redu upiše 
//      ime:cena, a u narednim redovima se upisuje jedan sastojak poredu u obliku sastojak:količina. 
//      Pri uništavanju jela, uništavaju se i svi sadržani sastojci.
// 3.	
//      Predjelo i glavno jelo su jela koja mogu da sadrže samo slane i neutralne sastojke i njihove vrste su P i G,
//      respektivno. Predjelo se nalazi na akciji u periodu 9-12 časova (kada se cena umanjuje za određeni procenat).
//      Cena glavnog jela se uvećava za određeni procenat u periodu 20-23 časa.
//      Dezert je jelo koje može da sadrži samo slatke i neutralne sastojke i njegova vrsta je D.

// main
//      Napisati na jeziku C++ program koji napravi nekoliko jela, 
//      postavi im određeni procenat promene cene, doda im sastojke, a zatim napravljena jela doda u jelovnik.
//      Potom napravi generator koji generiše  dnevni  meni za  određeni  sat i  ispiše ga na  standardnom  izlazu.
//      Koristiti  fiksne parametre - nije potrebno ništa učitati s glavnog ulaz


#include<iostream>
#include <stdlib.h>

using namespace std;



enum Vrsta {SLAN,SLADAK,NEUTRALAN};

class Sastojak{
    private:
    Vrsta vrsta;
    string ime;
    int cenaPoKilogramu;
    public:
    Sastojak(string ime,int cenaPoKilogramu,Vrsta vrsta){
        this->ime = ime;
        this->cenaPoKilogramu = cenaPoKilogramu;
        this->vrsta = vrsta;
    }
    int getCenaPoKilogramu(){
        return cenaPoKilogramu;
    }
    Sastojak(){
        cenaPoKilogramu = 0;
    }
    string getVrstaString(){
        switch(vrsta){
            case SLAN:
            return "Slan";
            case SLADAK:
            return "Sladak";
            case NEUTRALAN:
            return "Neutralan";
            default: return "Greška";
        }
    }
    Vrsta getVrsta(){
        return vrsta;
    }
    string getIme(){
        return ime;
    }
    float cenaUGramima(int kolicinaUGramima){
       int kolicinaPoKilogarmu = (float)kolicinaUGramima /1000;
        return cenaPoKilogramu * kolicinaPoKilogarmu;
    }
    friend ostream& operator<<(ostream& out,Sastojak &s1){
        out<<s1.ime<<"-"<<s1.cenaPoKilogramu<<"/kg";
        return out;
    }
};

 

class Jelo{
    protected:
    string ime;
    Sastojak *sastojci;
    int *kolicinaUGramima;
    int sat;
    int procenat;
    int trenutni_broj_sastojaka;
    public:
    Jelo(string ime = "Burger"){
        this->ime = ime;
        trenutni_broj_sastojaka = 0;
        procenat = 0;
        sat = 25;
    }
    Jelo(){
        trenutni_broj_sastojaka = 0;
    }
    string getImeJela(){
        return ime;
    }
   virtual void dodajSastojak(Sastojak &s1,int kolicina){
        Sastojak *temp = new Sastojak[trenutni_broj_sastojaka];
        int *temp2 = new int[trenutni_broj_sastojaka];
        for(int i = 0;i < trenutni_broj_sastojaka;i++){
            temp[i] = sastojci[i];
            temp2[i] = kolicinaUGramima[i];
        }
        trenutni_broj_sastojaka++;
        sastojci = new Sastojak[trenutni_broj_sastojaka];
        kolicinaUGramima = new int[trenutni_broj_sastojaka];
        for(int i = 0;i < trenutni_broj_sastojaka - 1;i++){
            sastojci[i] = temp[i];
            kolicinaUGramima[i] = temp2[i];
        }
        sastojci[trenutni_broj_sastojaka - 1] = s1;
        kolicinaUGramima[trenutni_broj_sastojaka - 1] = kolicina;

    }
    virtual int cenaJela(){
        int s = 0;
        for(int i = 0; i < trenutni_broj_sastojaka; i++){
            s += sastojci[i].cenaUGramima(kolicinaUGramima[i]);
        }
        return s;
    }
   void setProcenat(int procenat){
    this->procenat = procenat;
   }
   void setSat(int sat){
    this->sat = sat;

   }
   friend ostream& operator<<(ostream& out,Jelo &j1){
        out<<j1.ime<<":"<<j1.cenaJela()<<"din"<<endl;
        for(int i = 0; i < j1.trenutni_broj_sastojaka; i++){
            out<<j1.sastojci[i]<<" : "<<j1.kolicinaUGramima[i]<<" g"<<endl;
        }
        return out;

   }
   

};
//Predjelo i glavno jelo su jela koja mogu da sadrže samo slane i neutralne sastojke i njihove vrste su P i G,
//      respektivno. Predjelo se nalazi na akciji u periodu 9-12 časova (kada se cena umanjuje za određeni procenat).
//      Cena glavnog jela se uvećava za određeni procenat u periodu 20-23 časa.
//      Dezert je jelo koje može da sadrži samo slatke i neutralne sastojke i njegova vrsta je D.



class Predjelo : public Jelo{
    protected:
    char vrstaJela;
    public:
    Predjelo(string ime) : Jelo(ime) {
        vrstaJela = 'P';
    }

    void dodajSastojak(Sastojak &s1,int kolicina){
        if(s1.getVrsta() == SLAN || s1.getVrsta() == NEUTRALAN){
            Jelo::dodajSastojak(s1, kolicina);
        }
        else{
            cout<<"Ovaj sastojak ("<<s1.getIme()<<")se ne moze dodati u predjelo zato sto nije odgovarajuc"<<endl;
        }
    }
    int cenaJela(){
        int s = 0;
        int cenaSaPopustom = 0;
        for(int i = 0; i < trenutni_broj_sastojaka; i++){
            if(sat >= 9 || sat <= 12){
            cenaSaPopustom = sastojci[i].cenaUGramima(kolicinaUGramima[i]) - (sastojci[i].cenaUGramima(kolicinaUGramima[i])*procenat/100);
            s+= cenaSaPopustom;
            }
            else{
                s+=sastojci[i].cenaUGramima(kolicinaUGramima[i]);
            }
        }
        return s;
    }
     friend ostream& operator<<(ostream& out,Predjelo &p1){
        out<<p1.getImeJela()<<":"<<p1.cenaJela()<<"din"<<endl;
        for(int i = 0; i < p1.trenutni_broj_sastojaka; i++){
            out<<p1.sastojci[i]<<" : "<<p1.kolicinaUGramima[i]<<" g"<<endl;
        }
        return out;

   }
};

class GlavnoJelo : public Jelo{
    protected:
    char vrstaSastojka;
    public:
    GlavnoJelo(string ime) : Jelo(ime) {
        vrstaSastojka = 'G';

    }
    void dodajSastojak(Sastojak &s1,int kolicina){
        if(s1.getVrsta() == SLAN || s1.getVrsta() == NEUTRALAN){
            Jelo::dodajSastojak(s1, kolicina);
        }
        else{
            cout<<"Ovaj sastojak ("<<s1.getIme()<<")se ne moze dodati u predjelo zato sto nije odgovarajuc"<<endl;
        }
    }
    int cenaJela(){
        int s = 0;
        int cenaSaPopustom = 0;
        for(int i = 0; i < trenutni_broj_sastojaka; i++){
            if(sat >= 20 || sat <= 23){
            cenaSaPopustom = sastojci[i].cenaUGramima(kolicinaUGramima[i]) - (sastojci[i].cenaUGramima(kolicinaUGramima[i])*procenat/100);
            s+= cenaSaPopustom;
            }
            else{
                s+=sastojci[i].cenaUGramima(kolicinaUGramima[i]);
            }
        }
        return s;
    }
    friend ostream& operator<<(ostream& out,GlavnoJelo &g1){
        out<<g1.getImeJela()<<":"<<g1.cenaJela()<<"din"<<endl;
        for(int i = 0; i < g1.trenutni_broj_sastojaka; i++){
            out<<g1.sastojci[i]<<" : "<<g1.kolicinaUGramima[i]<<" g"<<endl;
        }
        return out;

   }

};

class Dezert : public Jelo{
    public:
    Dezert(string ime) : Jelo(ime) {}

    void dodajSastojak(Sastojak &s1,int kolicina){
        if(s1.getVrsta() == SLADAK){
            Jelo::dodajSastojak(s1, kolicina);
        }
        else{
            cout<<"Ovaj sastojak ("<<s1.getIme()<<")se ne moze dodati u predjelo zato sto nije odgovarajuc"<<endl;
        }
    }
    int cenaJela(){
        return Jelo::cenaJela();
    }
    friend ostream& operator<<(ostream& out,Dezert &d1){
        out<<d1.getImeJela()<<":"<<d1.cenaJela()<<"din"<<endl;
        for(int i = 0; i < d1.trenutni_broj_sastojaka; i++){
            out<<d1.sastojci[i]<<" : "<<d1.kolicinaUGramima[i]<<" g"<<endl;
        }
        return out;
    }

};


int main(){
    Sastojak s1("Belo meso",250,SLAN);
    Sastojak s2("Salata",100,NEUTRALAN);
    Sastojak s3("Kecap",150,SLAN);
    Sastojak s4("Paradajzs",70,NEUTRALAN);
    GlavnoJelo g1("Doner");
    g1.dodajSastojak(s1,300);
    g1.dodajSastojak(s2,100);
    g1.dodajSastojak(s3,50);
    g1.dodajSastojak(s4,30);
    g1.setProcenat(10);
    g1.setSat(21);
    cout<<g1;

   
    //cout<<s1;

    return 0;
}

