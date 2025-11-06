#include "Aliment_Ambalat.h"

Aliment_Ambalat::Aliment_Ambalat():tip_ambalaj("null"),ambalaj_reciclabil(false) {};

//Aliment_Ambalat::Aliment_Ambalat(Aliment Ali,string tip,bool cond):Aliment(Ali),tip_ambalaj(tip),ambalaj_reciclabil(cond){};

Aliment_Ambalat::Aliment_Ambalat(string str,int price,int nr, string* v_informatii,string tip,bool cond):Aliment(str,price,nr,v_informatii),tip_ambalaj(tip),ambalaj_reciclabil(cond) {};

void Aliment_Ambalat::afisare() const
{
    this->Aliment::afisare();
    cout << tip_ambalaj << " " << ambalaj_reciclabil << endl;

}

void Aliment_Ambalat::citire(){
    this->Aliment::citire();
    cin >> tip_ambalaj >> ambalaj_reciclabil;

}

bool Aliment_Ambalat::getReciclabil(){
    return ambalaj_reciclabil;
}
