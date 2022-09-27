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
#include <iostream>
#include <string>

using namespace std;
class Artikal{
    protected:
    string naziv;
    float realna_cena;
    int popust;
    public:
    Artikal(string naziv = "Hurma", float realna_cena=199.99, int popust=0){
        this->naziv = naziv;
        this->realna_cena = realna_cena;
        this->popust = popust;
    }
    Artikal(const Artikal &a1){
        this->naziv = a1.naziv;
        this->realna_cena = a1.realna_cena;
        this->popust = a1.popust;
    }
    string  get_naziv(){ return this->naziv; }
    float get_realna_cena(){ return this->realna_cena;}
    int get_popust(){ return this->popust;}
    float cena_sa_popustom(){ 
        float kolicina_popusta = realna_cena / 100 * popust;
        return realna_cena - kolicina_popusta;
    }
    friend ostream& operator <<(ostream& out, Artikal a){
	    out << a.naziv << " ( " << a.cena_sa_popustom() << " ) " << endl;
        return out;
    }
};

class Stavka{
    protected:
    Artikal a1;
    int kolicina;
    public:
    Stavka(){}
    Stavka(Artikal a1, int kolicina = 1 ){
        this->a1 = a1;
        this->kolicina = kolicina;
    }
    Stavka(const Stavka& s1){
        this->a1 = s1.a1;
        this->kolicina = s1.kolicina;
    }
    float cena(){
        return a1.cena_sa_popustom() * kolicina;
    }
    friend ostream& operator<<(ostream& out,Stavka& s1){
        out << "( " <<  s1.a1.get_naziv() << " ) : " << s1.kolicina << " | " << s1.cena()  << endl;
        return out;
    }
    Artikal get_artikal(){
        return a1;
    }
};

class Racun{
    protected:
    Stavka * stavke;
    int dodatni_popust;
    int broj_stavki;
    public:
    Racun(){
        broj_stavki = 0;
        dodatni_popust = 0;
    }
    Racun& operator+=(Stavka s){
        Stavka * pomocni = new Stavka[broj_stavki];
        for(int i = 0; i < broj_stavki; i++){
            pomocni[i] = stavke[i];
        }
        broj_stavki++;
        stavke  = new Stavka[broj_stavki];
        for(int i = 0; i < broj_stavki - 1; i++){
            stavke[i] = pomocni[i];
        }
        stavke[broj_stavki-1] = s;
        return *this;
    }
    void set_dodatni_popust(int popust){
        this->dodatni_popust = popust;
    }
    float ukupna_cena(){
        float ukupno_koje_vec_imaju_popust = 0;
        float ukupno_koje_nemaju_popust = 0;
        for(int i = 0; i < broj_stavki; i++){
            if(stavke[i].get_artikal().get_popust() == 0){
                ukupno_koje_nemaju_popust += stavke[i].cena();
            }
            else{
                ukupno_koje_vec_imaju_popust += stavke[i].cena();
            }
        }
        float cena_sa_dodatnim_popustom = ukupno_koje_nemaju_popust - ukupno_koje_nemaju_popust  / 100 * dodatni_popust;
        return cena_sa_dodatnim_popustom + ukupno_koje_vec_imaju_popust;
    }
    friend ostream& operator<<(ostream& out, Racun r1){
        out << "Račun: " << r1.ukupna_cena() << endl;
        for(int i = 0; i < r1.broj_stavki; i++){
            if(r1.stavke[i].get_artikal().get_popust() == 0){
                if(r1.dodatni_popust == 0){
                    out << r1.stavke[i] << " [ " << r1.stavke[i].cena() << " ] "  <<endl;
                }
                else{
                    out << r1.stavke[i] << "[" <<   r1.stavke[i].cena()  / 100 * r1.dodatni_popust << " ]" << endl; 
                }
            }
            else{
                out << r1.stavke[i] << " [ " << r1.stavke[i].cena() << " ] "  <<endl;
            }
        }
        return out;
    }
};

int main() {
    Artikal a1("Smokva", 100, 0);
    Artikal a2("Borovnica", 700, 5);
    Stavka s1(a1, 5);
    Stavka s2(a2, 10);
    Stavka s3 = s1;
    Racun r1;
    r1 += s1;
    r1 += s2;
    r1 += s3;
    r1.set_dodatni_popust(50);
    cout << r1;
    return 0;
}