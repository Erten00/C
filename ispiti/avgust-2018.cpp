// Realizovati sledeće klase :
// (klase opremiti onim konstruktorima, destruktorima i operatorima dodele (preklopljenim operatorima)
// koji su potrebni za bezbedno i efikasno korišćenje.
// 1. Nalepnica ima naziv i jednoznačni automatski generisan identifikator kojem može da se pristupi. 
//     Naziv se zadaje sa standardnog ulaza prilikom stvaranje objekta.
//     Prilikom kopiranja voditi računa da se kopira naziv a da se identifikator sam kreira. 
//     Omogućiti metodu za ispis. 
// 2. Flaša pića ima sledeće podatke: 
//     nalepnicu, cenu bez kaucije (u koju nije uračunata cena flaše), 
//     zapreminu (podrazumevano 0,33 litara) i vrstu pića. 
//     Vrsta pića može biti BEZALKOHOLNO (podrazumevano) i ALKOHOLNO.
//     Svi podaci se unose prilikom stvaranja objekta i mogu se odštampati, a samo se cena može promeniti.
//     Kreirati metodu koja može da izračuna cenu flaše pića sa kaucojom
//     (ima razlike za staklenu i plastičnu flašu).
//     Metodu PROVERA koja proverava da li su dve flaše jednake (flaše su jednake ukoliko imaju isti naziv nalepnice,
//     cenu flaše sa kaucijom i vrstu pića. Omogućiti metodu za ispis.

// 3. Staklena flaša pića je flaša pića kod koje se cena sa kaucijom računa tako što se na cenu bez kaucije doda 5% ukoliko
//     je zapremina manja od 0,5 litara ili 10% ukoliko je zapremina veća ili jednaka od 0,5 litara.
//     Preklopiti metodu ispis da ispisuje podatke o flaši i poruku da je flaša staklena.
// 4. Plastična flaša pića je flaša pića kod koje je cena sa kaucijom jednaka ceni bez kaucije. Preklopiti metodu za ispis da 
//     ispisuje podatke o flaši i poruku da je flaša plastnična.
// 5. Formirati funkciju UKUPNO, van klasa koja formira dinamički niz staklenih i plastičnih flaša
//     čije podatke unosi korisnik sa tastature i zatim računa i vraća ukupan zbir svih flaša sa kaucijom.
// U main funkciji napraviti po jedan objekat svake klase i testirati sve metode, kao i funkciju UKUPNO.
#include <iostream>
#include <string>

using namespace std;

enum Vrsta {BEZALKOHOLNO, ALKOHOLNO};

class Nalepnica {
    protected:
    string naziv;
    int identifikator;
    static int brojac;
    public:
    Nalepnica(){
        cout << "Unesite naziv:";
        cin >> naziv;
        identifikator = brojac;
        brojac++;
    }
    Nalepnica(const Nalepnica& n1){
        this->naziv = n1.naziv;
        this->identifikator = brojac;
        brojac++;
    }
    int get_identifikator(){
        return identifikator;
    }
    string get_naziv(){
        return naziv;
    }
    friend ostream& operator<<(ostream& out, Nalepnica &n1){
        out << "Naziv: " << n1.naziv << " id: " << n1.identifikator << endl; 
        return out;
    }
};

class Flasa{
    protected:
    Nalepnica nalepnica;
    float cena_bez_kaucije;
    float zapremina;
    Vrsta vrsta;
    int kaucija;
    public:
    Flasa(float cena_bez_kaucije, float zapremina = 0.33, Vrsta vrsta = BEZALKOHOLNO ){
        this-> cena_bez_kaucije = cena_bez_kaucije;
        this-> zapremina = zapremina;
        this-> vrsta = vrsta;
        kaucija = 0;
    }
    Flasa(){}
    Nalepnica get_nalepnica(){
        return nalepnica;
    }
    float get_cena_bez_kaucije(){
        return cena_bez_kaucije;
    }
    float get_zapremina(){
        return zapremina;
    }
    string get_vrsta(){
        switch(vrsta){
            case 0:
               return "Bezalkoholno";
            case 1:
                return "Alkoholno";
        }
        return "";
    }
    void set_cena_bez_kaucije(float cena_bez_kaucije){
        this-> cena_bez_kaucije = cena_bez_kaucije;
    }
    virtual float cena_sa_kaucijom(){
        return cena_bez_kaucije + (cena_bez_kaucije / 100 * kaucija);
    }
    friend bool da_li_su_jednake(Flasa f1, Flasa f2){
        if(f1.nalepnica.get_naziv() == f2.nalepnica.get_naziv() && f1.cena_sa_kaucijom() == f2.cena_sa_kaucijom() && f1.vrsta == f2.vrsta){
            return true;
        }
        return false;
    }
    bool operator  ==(Flasa &f1){
        if(f1.nalepnica.get_naziv() == nalepnica.get_naziv() && f1.cena_sa_kaucijom() == cena_sa_kaucijom() && f1.vrsta == vrsta){
            return true;
        }
        return false;
    }
    friend ostream& operator<<(ostream& out, Flasa f1){
        out << f1.nalepnica;
        out << "cena bez kaucije: " << f1.cena_bez_kaucije << ", Cena sa kaucijom " << f1.cena_sa_kaucijom() << endl;
        out << "Zapemina : " << f1.zapremina  << "l, vrsta: " << f1.get_vrsta(); 
        return out;
    }
    virtual void ispis(){
        cout << nalepnica;
        cout << "cena bez kaucije: " <<cena_bez_kaucije << ", Cena sa kaucijom " << cena_sa_kaucijom() << endl;
        cout << "Zapemina : " << zapremina  << "l, vrsta: " << get_vrsta() << endl; 
    }
};

class Staklena : public Flasa{
    public:
    Staklena(float cena_bez_kaucije, float zapremina = 0.33, Vrsta vrsta = BEZALKOHOLNO ) : Flasa(cena_bez_kaucije, zapremina, vrsta) {
        if(zapremina < 0.5){
            kaucija = 5;
        }
        else{
            kaucija = 10;
        }
    }
    float cena_sa_kaucijom(){
        return cena_bez_kaucije + (cena_bez_kaucije / 100 * kaucija);
    }
    void ispis() {
        cout << nalepnica;
        cout << "cena bez kaucije: " <<cena_bez_kaucije << ", Cena sa kaucijom " << cena_sa_kaucijom() << endl;
        cout << "Zapemina : " << zapremina  << "l, vrsta: " << get_vrsta() << endl;
        cout << "Flaša je staklena i kaucija na nju iznosi " << kaucija << "%" << endl;
    }
};

class Plasticna : public Flasa{
    public:
    Plasticna (float cena_bez_kaucije, float zapremina = 0.33, Vrsta vrsta = BEZALKOHOLNO ) : Flasa(cena_bez_kaucije, zapremina, vrsta) {}
    void ispis() {
        cout << nalepnica;
        cout << "cena bez kaucije: " <<cena_bez_kaucije << ", Cena sa kaucijom " << cena_sa_kaucijom() << endl;
        cout << "Zapemina : " << zapremina  << "l, vrsta: " << get_vrsta() << endl;
        cout << "Flaša je plastična i kaucija na nju iznosi " << kaucija << "%" << endl;
    }
};

int Nalepnica::brojac = 0;

// 5. Formirati funkciju UKUPNO, van klasa koja formira dinamički niz staklenih i plastičnih flaša
//     čije podatke unosi korisnik sa tastature i zatim računa i vraća ukupan zbir svih flaša sa kaucijom.

float ukupno(){
    cout << "Unesite koliko flaša želite: \n ";
    int n;
    char vrsta;
    float cena;
    float suma = 0;
    float zapremina;
    string alkoholno;
    Vrsta vrsta_pica;
    cin >> n;
    Flasa * niz = new Flasa[n];
    for(int i = 0; i < n; i++){
        cout <<  "Unesite da li je flaša plastičan ili staklena (s / p) : \n";
        cin >> vrsta;
        cout <<  "uneste cenu:" << endl;
        cin >> cena;
        cout <<  "uneste zapreminu:" << endl;
        cin >> zapremina;
        cout <<  "da li je piće alkoholno ?  (da/ne)" << endl;
        cin >> alkoholno;
        if(alkoholno == "da"){
            vrsta_pica = ALKOHOLNO;
        }
        else{
            vrsta_pica = BEZALKOHOLNO;
        }
        if(vrsta == 's'){
            Staklena f(cena, zapremina, vrsta_pica);
            suma += f.cena_sa_kaucijom();
            niz[i] = f;
        }
        else if(vrsta == 'p'){
            Plasticna f(cena, zapremina, vrsta_pica);
            niz[i] = f;
        }
    }
    return suma;
}

int main(){
    // Flasa f1(70, 0.5,  BEZALKOHOLNO);
    // Flasa f2(70, 0.5,  BEZALKOHOLNO);
    // Flasa f3(100, 0.5,  BEZALKOHOLNO);
    // Flasa f4(70,  0.5,  BEZALKOHOLNO);
    // if(f1 == f2){
    //     cout << "f1 == f2" << endl;
    // }
    // cout << f1;
    // Staklena s1(100, 0.33, BEZALKOHOLNO);
    // Staklena s2(110, 0.5, ALKOHOLNO);
    // Staklena s3(120, 1, BEZALKOHOLNO);
    // s1.ispis();
    // cout << s2 << endl;
    // cout << s3.cena_sa_kaucijom();
    // Plasticna p1(70, 0.5, BEZALKOHOLNO);
    // p1.ispis();
    cout << ukupno() << endl;
    return 0;
}