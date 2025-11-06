#include <iostream>
//#include "Adresa.h"
#include "Imobil.h"
using namespace std;

int main()
{
    Adresa a("Bucuresti", "Orhideelor", 1);
    //cout <<a<< endl;
    Adresa b;

    string vect[5]={"unu","doi","trei","patru","cinci"};
    int dim=5;
    int dim1=0;
    Imobil piesa(a,dim,vect);
    cout << piesa;
    Imobil piesa2;
    cin >> piesa2;
    cout << piesa2;
    //piesa2.SetImbunatatiri(vect,dim);
    //cout << piesa2;
    //piesa2 = piesa;
    //cout << piesa2;
    cout << piesa2.CheckOras("Bucuresti");
    //cin>>b;
    //cout<<b;
    cout << " " << (piesa==piesa2);
    Imobil piesa3;
    piesa3=piesa2;
    piesa3.SetImbunatatiri(nullptr,dim1);
    cout << piesa3;
    return 0;
}

/*
    1. Implementați si testati toate metodele tinand cont de regulile folosite pentru agregare.
    2. Ce modificari ar trebui facute daca in Adresa orasul si strada ar fi de tip char*?
    3. Ce mai trebuie implementat pentru a putea scrie o secventa care verifica daca un anumit imobil se gaseste intr-un anumit oras? Implementati si testati.
*/
