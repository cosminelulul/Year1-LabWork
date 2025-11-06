#include "Adresa.h"
#pragma once

class Imobil
{
    Adresa adr;
    int nr; //cate imbunatatiri are
    string *imbunatatiri; //vector cu imbunatatile: centrala, termopan, izolatie
public:
    Imobil();
    Imobil(const Adresa&, int, string *);
    Imobil(const Imobil&);
    Imobil& operator=(const Imobil&);
    ~Imobil();
    friend ostream& operator<<(ostream&, const Imobil &);
    friend istream& operator>>(istream&,  Imobil&);
    void SetImbunatatiri(string *, int &);
    bool CheckOras(string oras_cerut);
    friend bool operator==(const Imobil&, const Imobil&);
    //functia de verificare pt inegalitate
    friend bool operator!=(const Imobil&, const Imobil&);
};

