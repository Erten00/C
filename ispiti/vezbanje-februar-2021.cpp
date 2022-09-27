// 1.	
//      (35 poena)  Realizovati sledeće klase (klase opremiti onim konstruktorima, destruktorima i operatorima dodele 
//      (preklopljenim operatorima) koji su potrebni za bezbedno i efikasno korišćenje.
//      Klasa Artikal ima naziv, realnu cenu i celobrojni iznos popusta (podrazumevano 0).
//      Podaci artikla se zadaju pri stvaranju (nije potrebna provera). Može da se ispisati naziv, cena sa popustom i iznos popusta.
//      Na glavnom izlazu se ispisuje u obliku naziv(cena_sa_popustom).
// 2.	
//    Klasa Stavka računa se kreira za zadati artikal i zadatu celobrojnu količinu.
//    Stavki računa se dodeljuje redni broj na računu prilikom dodavanja stavke na račun. 
//    Može da se izračuna iznos stavke računa kao proizvod količine i cene artikla. 
//    Omogućiti kopiranje vrednosti pomoću kopi konstruktora.
//    Može se ispisati artikal stavke. Na glavnom izlazu se ispisuje u obliku:
//    S redni_broj_na_računu(artikal):količina|iznos.
//    U main funkciji kreirati 2 objekta klase Stavka i testirati sve metode.
//    Kreirati i treći objekat kao kopiju prvog.
// 3. (35 poena)   Koristeći klase iz prethodnog zadatka proširiti program tako da se doda klasa Račun koja sadrži proizvoljan
//    broj stavki(niz stavki) i celobrojni iznos dodatnog popusta.
//    Stvara se prazan, nakon čega se stavke dodaju pojedinačno. Dodavanje stavke odraditi
//    preklapanjem operatora += (račun += stavka). Može da se postavi iznos dodatnog popusta. Može da se izračuna iznos računa kao suma iznosa svih pojedinačnih stavki na računu. Ukoliko postoji dodatni popust, on se obračunava samo za artikle koji već nisu na popustu. Na glavnom izlazu se ispisuje u obliku Racun: iznos_računa, a zatim se u svakom redu ispisuje po jedna stavka u obliku: stavka [iznos_sa_dodatnim_popustom].
//    U main funkciji stvoriti jedan  objekat klase račun i u njega dodati nekoliko stavki
//    sa po jednim artiklom. Ispisati stanje računa nakon dodavanja tih stavki.


#include<iostream>
#include<string>

using namespace std;

class Artikal{
    private:
    string naziv;
    float cena;
    int popust;
    public:
    Artikal(string naziv, float cena, int popust){
        this->naziv = naziv;
        this->cena = cena;
        this->popust = popust;
    }
    Artikal(){
        popust = 0;
    }
    float cenaSaPopustom(){
        float cenaSaPopustom = 0;
        cenaSaPopustom = cena-(cena * (float)popust/ 100);
        return cenaSaPopustom;
    }
    string getNaziv(){
        return naziv;
    }
    int getCena(){
        return cena;
    }
    friend ostream& operator<<(ostream& out, Artikal &a1){
        out<<a1.naziv<<"("<<a1.cenaSaPopustom()<<")"<<", popust:"<<a1.popust<<endl;
        return out;
    }

};




class Stavka{
    private:
    Artikal a1;
    int kolicina;
    int redniBroj;
    public:
    Stavka(Artikal a1, int kolicina, int redniBroj){
        this->a1 = a1;
        this->kolicina = kolicina;
        this->redniBroj = redniBroj;   
    }
    Stavka(){}
    int iznosStavke(){
        int iznos;
        iznos = kolicina * a1.cenaSaPopustom();
        return iznos;
    }
    Stavka(const Stavka &s1){
        kolicina = s1.kolicina;
        redniBroj = s1.redniBroj;
    }
    friend ostream& operator<<(ostream& out,Stavka &s1){
        out<<s1.redniBroj<<"("<< s1.a1.getNaziv()<<")"<<"kolicina:"<<s1.kolicina<<" | "<<s1.iznosStavke()<<endl;
        return out;
    }
    Artikal getArtikal(){
        return a1;
    }


};

// 3. (35 poena)   Koristeći klase iz prethodnog zadatka proširiti program tako da se doda klasa Račun koja sadrži proizvoljan
//    broj stavki(niz stavki) i celobrojni iznos dodatnog popusta.
//    Stvara se prazan, nakon čega se stavke dodaju pojedinačno. Dodavanje stavke odraditi
//    preklapanjem operatora += (račun += stavka). Može da se postavi iznos dodatnog popusta. Može da se izračuna iznos računa kao suma iznosa svih pojedinačnih stavki na računu. Ukoliko postoji dodatni popust, on se obračunava samo za artikle koji već nisu na popustu. 
//Na glavnom izlazu se ispisuje u obliku Racun: iznos_računa, a zatim se u svakom redu ispisuje po jedna stavka u obliku: stavka [iznos_sa_dodatnim_popustom].
//    U main funkciji stvoriti jedan  objekat klase račun i u njega dodati nekoliko stavki
//    sa po jednim artiklom. Ispisati stanje računa nakon dodavanja tih stavki.

class Racun{
    private:
    Stavka *stavke;
    int dodatniPopust;
    int trenutni_broj_stavki;
    public:
    Racun(){
        trenutni_broj_stavki = 0;
    }
    Racun operator+=(Stavka &s1){
        Stavka *temp = new Stavka[trenutni_broj_stavki];
        for(int i = 0; i < trenutni_broj_stavki; i++){
            temp[i] = stavke[i];
        }
        trenutni_broj_stavki++;
        stavke = new Stavka[trenutni_broj_stavki];
        for(int i = 0; i < trenutni_broj_stavki - 1; i++){
            stavke[i] = temp[i];
        }
        stavke[trenutni_broj_stavki -1] = s1;
        return *this;
    }
    void setDodatniPopust(int dodatniPopust){
        this->dodatniPopust = dodatniPopust;

    }
   int iznosRacuna(){
    int s = 0;
    int cenaSaDodatnimPopustom = 0;
    for(int i = 0; i < trenutni_broj_stavki; i++){
        if(stavke[i].getArtikal().cenaSaPopustom() < stavke[i].getArtikal().getCena()){
            return s+=stavke[i].getArtikal().cenaSaPopustom();
        }
         else{
           s+=cenaSaDodatnimPopustom = stavke[i].getArtikal().getCena() - (stavke[i].getArtikal().getCena()*dodatniPopust/100);
        }
        }
        return s;
    }
    friend ostream& operator<<(ostream& out,Racun &r1){
        out<<"Iznos racuna:"<<r1.iznosRacuna()<<endl;
        for(int i = 0;i < r1.trenutni_broj_stavki; i++){
            out<<i<<". "<<r1.stavke[i];
            if(r1.stavke[i].getArtikal().getCena() != r1.stavke[i].getArtikal().cenaSaPopustom()){
                int cenaSaDodatnimPopustom = r1.stavke[i].getArtikal().getCena() - (r1.stavke[i].getArtikal().getCena()*r1.dodatniPopust/100);
                out<<"["<<cenaSaDodatnimPopustom<<"]"<<endl;
            }
        }
        return out;
    }
};

int main(){
    Artikal a1("Balan stangla",100,10);
    Artikal a2("Svecice",70,5);
    Stavka s1(a1, 2,4);
    Stavka s2(a2, 7,3);
    Racun r1;
    r1.setDodatniPopust(10);
    r1+=s1;
    r1+=s2;
    cout<<r1;
  
return 0;
}

