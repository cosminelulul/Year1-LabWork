#include <iostream>
#include "Produs.h"
#pragma once
using namespace std;

class Aliment: public Produs {
    protected:
     int nr_info; // nr informatii despre aliment eg. 2
     string *informatii=nullptr; // ex. 230cal/100g, expirare:12.12.2024
    public:
        Aliment();
        Aliment(string,int,int,string*);
        Aliment(Produs,int,string*);
        Aliment(const Aliment &);
        void setinfo(int, string*);
        void afisare() const;
        void citire();
        int getNrInfo();
        Aliment& operator=(Aliment &);
        ~Aliment();
};
