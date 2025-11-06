#pragma once
#include <string>
#include <ostream>
using namespace std;

class Adresa
{
    string oras="   ";
    string strada="  ";
    int nr=0;
public:
    Adresa() = default;
    Adresa(const string&, const string&, int);
    friend ostream& operator<<(ostream&, const Adresa &);
    friend istream& operator>>(istream&,  Adresa &);
    friend bool operator==(const Adresa&,const Adresa&);
    friend bool operator!=(const Adresa&, const Adresa&);
    string GetOras();
    //se genereaza in mod automat constructor de copiere, operator=, destructor - si functioneaza corect

    // pentru subpunctul 2;
    /*
    Trebuie implementat constructorul de copiere, operator= si destructor, deoarece string-urile devin
    char array;
    */

};
