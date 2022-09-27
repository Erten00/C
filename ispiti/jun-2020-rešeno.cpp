#include <iostream>

using namespace std;

class PonudjeniOdgovor{
private:
    string txtOdgovora;
    bool tacnost;
    int udeo;
public:
    PonudjeniOdgovor(string a="", bool b, int c){
        txtOdgovora = a; tacnost = b; udeo = c;
    }
    void setTxtOdgovora(string a){txtOdgovora = a;}
    void setTacnost(bool a){tacnost = a;}
    void setUdeo(int x){udeo = x;}
    string getTxtOdgovora(){return txtOdgovora;}
    bool getTacnost(){return tacnost;}
    int getUdeo(){return udeo;}
    void printTacnost(){cout << tacnost << endl;}
    void printUdeo(){cout << udeo << endl;}
    ostream& operator<<(ostream& out, const PonudjeniOdgovor& O){
        if(udeo <= 100 && udeo >= -100){
            out << O.getTxtOdgovora() << ':' << " " << O.getUdeo() << '%' << endl;
        }else out<<"Procentualni udeo odgovora je pogresan." << endl;
        return out;
    }
};

class Pitanje{
protected:
    string tekst;
    int brojPoena;
    int brPonOdg;
    PonudjeniOdgovor *odgovor;
    int br;
public:
    Pitanje(string a, int b, int c=5){
        tekst = a; brojPoena = b; brPonOdg = c; odgovor = new PonudjeniOdgovor[c];br=0;
    }
    Pitanje& operator+=(PonudjeniOdgovor& o){
        this->odgovor[br] = o;br++;
    }

    void odgovori(int niz[], int br){
        int suma = 0,i;
        for(i=0;i<br;i++){
            if(!odgovor[niz[i]].getTacnost()){
                suma -= 100;
            }else suma += odgovor[niz[i]].getUdeo();
        }
    }

    ostream& operator<<(ostream& os, const Pitanje& p){
        int i;
        os << p.tekst << ":" << p.brojPoena << endl;
        for(i=0;i<=p.br;i++)
            os << p.odgovor[i] << endl;
        return os;
    }
    ~Pitanje(){ delete[] odgovor;}
};

class Student:Pitanje{
private:
    int brIndeksa;
    string ime;
    double osvojeno;
public:
    Student(int a, string b, string c, int e, int f=5):Pitanje(c, e, f){
        brIndeksa = a; ime = b; osvojeno=0;
    }

    void odgovori(int niz[], int br){
        int suma = 0,i;
        for(i=0;i<br;i++){
            if(!odgovor[niz[i]].getTacnost()){
                suma -= 100;
            }else suma += odgovor[niz[i]].getUdeo();
        }
        osvojeno = (double)brojPoena/100*suma;
    }

    ostream& operator<<(ostream& os, const Student& s){
        os << s.brIndeksa << " " << s.ime << " " << osvojeno << endl;
        int i;
        os << p.tekst << ":" << p.brojPoena << endl;
        for(i=0;i<=p.br;i++)
            os << p.odgovor[i] << endl;
        return os;
    }
};

int main(){
    
    return 0;
}