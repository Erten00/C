//opšte napomene za izradu zadataka:
/*
atributi ne smeju biti javni
kreinati sve potrebne javne metode  koje će omogućiti da program radi uključujući konstrukotor i destrukotor
izbegavati dupliranje koda,
pridržavati se osnovnih principa oop-a (enkasulacija, modularnost, nasleđivanje, polimorfizam)


ukupan broj bodova se određuje kao zbir  svih bodova koje je student osvojio pri čemu je najveći broj bodova na laboratorijskim 
vežbama 20, na pisanom i usmenom ispitu 40, i na kolokvijumima 20.
student koji polaže pisani ispit u celini je položio ispit ako je  na pisanom, usmenom i celom ispitu osvojio više od 50 % 
od maksimalnog broja bodova.
student koji polaže pisani ispit preko kolokvijuma je položio ispit ako je na usmenomm i celom ispitu osvojio više  od 50% od 
maksimalnog broja bodova i na svakom od kolokvijuma  osvojio više do 25 % a zbiru na oba kolokvijuma više od 50% od maksimalnog 
broja bodova.
u evedenciju je moguće dodati novog studenta i ukloniti postojećeg na osnovu zadatog broja indexa.
Nakaon pregleda radova moguće je izmeniti broj bodova studenata na pisanom delu ispita i na bilo kom od kolokvijuma na osnovu zadatog 
broja indeksa studenta i broja dodatnih bodova.
*/

#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

class Student{
    public:
    int bodovi_laboratorijske;
    int bodovi_usmenog;
    int broj_indexa;
    public:
    //make construcor with default values
    Student(int b_laboratorijske=0, int b_usmenog=0, int b_indexa=0){
        bodovi_laboratorijske=b_laboratorijske;
        bodovi_usmenog=b_usmenog;
        broj_indexa=b_indexa;
    }
    int get_broj_indeksa(){
        return broj_indexa;
    }
};

class preko_kolokvijuma : public Student{
    public:
    int bodovi_kolokvijuma[2];
    public:
    //make construcor with default values
    preko_kolokvijuma(int b_laboratorijske=0, int b_usmenog=0, int b_indexa=0, int b_kolokvijuma1=0, int b_kolokvijuma2=0){
        Student(b_laboratorijske, b_usmenog, b_indexa);
        bodovi_kolokvijuma[0]=b_kolokvijuma1;
        bodovi_kolokvijuma[1]=b_kolokvijuma2;
    }
    //make ukupno function
    int ukupno(){
        int ukupno=0;
        for(int i=0; i<2; i++){
            ukupno+=bodovi_kolokvijuma[i];
        }
        //add other ints to ukupno
        ukupno+=bodovi_laboratorijske;
        ukupno+=bodovi_usmenog;
        return ukupno;
    }
    //make položio function
    bool polozio(){
        if(ukupno()>=50){
            if(bodovi_kolokvijuma[0]>5 && bodovi_kolokvijuma[1]>5 && bodovi_kolokvijuma[0] + bodovi_kolokvijuma[1] > 20 && bodovi_usmenog > 20 ){
                return true;
            }
        }
        else{
            return false;
        }
    }
};
// Nakaon pregleda radova moguće je izmeniti broj bodova studenata na pisanom delu ispita i na bilo kom od kolokvijuma na osnovu zadatog 
// broja indeksa studenta i broja dodatnih bodova.


class Preko_pismenog : public Student{
    public:
    int bodovi_pismenog;
    public:
    //make construcor with default values
    Preko_pismenog(int b_laboratorijske=0, int b_usmenog=0, int b_indexa=0, int b_pismenog=0){
        Student(b_laboratorijske, b_usmenog, b_indexa);
        bodovi_pismenog=b_pismenog;
    }
    //make ukupno function
    int ukupno(){
        return (bodovi_laboratorijske+bodovi_usmenog+bodovi_pismenog);
    }
    //make položio function
    bool polozio(){
        if(ukupno()>=50 && bodovi_usmenog>=20 && bodovi_pismenog>=20){
            return true;
        }
        else{
            return false;
        }
    }
};

//create class evidencija which have dinamic  array of students
class Evidencija{
    protected:
    int broj_studenata;
    Student *studenti;
    public:
    //override += studnet
    Evidencija& operator+=(Student &s){
        Student *temp=new Student[broj_studenata+1];
        for(int i=0; i<broj_studenata; i++){
            temp[i]=studenti[i];
        }
        temp[broj_studenata]=s;
        studenti=temp;
        broj_studenata++;
        return *this;
    }
    //make delete one student with specific broj_indeksa property
    Evidencija& operator-=(int broj_indeksa){
        Student *temp=new Student[broj_studenata-1];
        int brojac=0;
        for(int i=0; i<broj_studenata; i++){
            if(studenti[i].get_broj_indeksa()!=broj_indeksa){
                temp[brojac]=studenti[i];
                brojac++;
            }
        }
        studenti=temp;
        broj_studenata--;
        return *this;
    }
    
    //make print function
    // void print(){
    //     for(int i=0; i<broj_studenata; i++){
    //         //print student atributes
    //         cout<<"Broj indexa: "<<studenti[i].get_broj_indeksa()<<endl;
    //         cout<<"Bodovi laboratorijske: "<<studenti[i].bodovi_laboratorijske<<endl;
    //         cout<<"Bodovi usmenog: "<<studenti[i].bodovi_usmenog<<endl;
    //     }
    // }
};
//make main funciton and add some stundets in evidencija
int main(){
    Evidencija evidencija;
    preko_kolokvijuma s1(10,20,1,20,10); // l u i k1 k2
    Preko_pismenog s2(0,30, 2, 30);      // l u i p
    evidencija+=s1;
    evidencija+=s2;
    evidencija-=1;
    evidencija.print();
return 0;    
}