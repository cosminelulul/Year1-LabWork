#include <iostream>
#pragma once
using namespace std;

class Produs{
    protected:
     string marca;
     int pret;
    public:
        Produs();
        Produs(string,int);
        void afisare() const;
        void citire();
        int getPret();

};

