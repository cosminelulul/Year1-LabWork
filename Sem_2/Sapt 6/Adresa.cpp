#include "Adresa.h"
#include <iostream>
using namespace std;



Adresa::Adresa(const string &o, const string &s, int n):oras(o), strada(s), nr(n)
{

}
ostream& operator<<(ostream& dev, const Adresa &a)
{
    dev<<a.oras<<" "<<a.strada<<" "<<a.nr<<endl;
    return dev;
}
istream& operator>>(istream &dev, Adresa &a)
{
    dev>>a.oras;
    dev>>a.strada;
    dev>>a.nr;
    return dev;
}

string Adresa::GetOras(){
    return oras;
}

bool operator==(const Adresa&adr1, const Adresa&adr2){
    return ((adr1.nr==adr2.nr)&&(adr1.oras==adr2.oras)&&(adr1.strada==adr2.strada));

}

bool operator!=(const Adresa&adr1, const Adresa&adr2){
    return !(adr1==adr2);

}
