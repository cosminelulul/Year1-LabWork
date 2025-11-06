#include "Aliment.h"

Aliment::Aliment():nr_info(0){
    informatii = NULL;
}

void Aliment::setinfo(int nr, string *v_informatii){
    delete[]informatii;
    nr_info = nr;
    if (v_informatii != NULL){
        informatii = new string[nr+1];
        for (int i=0;i<nr;i++)
            informatii[i] = v_informatii[i];
    }else informatii = NULL;
}

Aliment::Aliment(string str,int price,int nr, string* v_informatii):Produs(str,price){
    informatii = NULL;
    setinfo(nr,v_informatii);
}

//Aliment::Aliment(Produs pr,int nr, string* v_informatii):Aliment(pr.marca,pr.pret,nr,v_informatii){};
//!!!!

Aliment::Aliment(Produs pr,int nr, string* v_informatii){
    Produs::operator=(pr);
    setinfo(nr,v_informatii);
}

void Aliment::afisare() const{
    this->Produs::afisare();
    cout << nr_info << " ";
    for (int i = 0; i < nr_info; i++)
        cout << informatii[i] << " ";
}

Aliment::Aliment(const Aliment&Ali):Aliment(Ali.marca,Ali.pret,Ali.nr_info,Ali.informatii){}

Aliment& Aliment::operator=(Aliment&Ali){
    if (this != &Ali) {
     Produs::operator=(Ali);
     setinfo(Ali.nr_info,Ali.informatii);
    }
     return *this;
}

Aliment::~Aliment(){
    delete[]informatii;
}

void Aliment::citire(){
    this->Produs::citire();
    cin >> nr_info; informatii = new string[nr_info];
    if (nr_info != 0)
        for (int i = 0;i<nr_info;i++)
            cin >> informatii[i];
}

int Aliment::getNrInfo(){
    return nr_info;
}
