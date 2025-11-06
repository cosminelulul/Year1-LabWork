#include "Produs.h"

Produs::Produs():pret(0),marca("null"){};

Produs::Produs(string str,int price):marca(str),pret(price){};

void Produs::afisare() const{
    cout << marca << " " << pret << " ";
}

int Produs::getPret(){
    return pret;
}

void Produs::citire(){
    cin >> marca >> pret;
}
