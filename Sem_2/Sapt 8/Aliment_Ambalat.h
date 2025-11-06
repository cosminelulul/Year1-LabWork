#include <iostream>
#include "Aliment.h"
#pragma once

using namespace std;

class Aliment_Ambalat: public Aliment {
 string tip_ambalaj; // ex. carton
 bool ambalaj_reciclabil;
public:
    Aliment_Ambalat();
    Aliment_Ambalat(string,int,int,string*,string,bool);
   // Aliment_Ambalat(Aliment,string,bool);
    void afisare() const;
    void citire();
    bool getReciclabil();
    friend Sortare(Aliment_Ambalat*,int);
};

