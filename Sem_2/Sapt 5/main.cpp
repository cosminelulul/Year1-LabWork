#include "Persoana.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


ostream& operator<<(ostream& dev, const Persoana& per)
{
    dev << per.nume << " " << per.prenume << " " << per.CNP << " " << per.student << endl;
    return dev;
}

istream& operator>>(istream& dev, Persoana& per)
{

    dev >> per.nume;
    dev >> per.prenume;

    dev >> per.CNP;
    dev >> per.student;

    return dev;
}


void Sortare(Persoana *&vect,int &dim)
{

    for (int i=0; i<dim-1; i++)
        for (int j=i+1; j<dim-1; j++){
            string data_i = vect[i].getDataNastere();
            string data_j = vect[j].getDataNastere();
            if ( data_i.compare(data_j) > 0 )
            {
                Persoana aux = vect[i];
                vect[i]=vect[j];
                vect[j]=aux;
            }
        }
}

int Scrie_Specific(Persoana *&vect,int &dim){

     fstream f("scriere_functie.txt",ios::out);
     int nr=0;

     for(int i=0;i<dim;i++){
        if (vect[i].getNrPrenume() > 1 ){
            f << vect[i];
            nr++;
        }
     }

    return nr;

}

int main()
{
    /*
    Persoana p1("Popescu","Ion-Dan","1840101491013",0);
    Persoana p2;

    cout << p1 << p2;
    cin >> p2;
    cout << p2;
    cout << p2.eStudent();

    */

    int n=3;
    Persoana v[n];

    fstream f("file.txt",ios::out);
    for (int i=0; i<n; i++)
        cin >> v[i];

    for (int i=0; i<n; i++)
        f << v[i];

    cout << endl << endl;

    fstream g("file.txt",ios::in);
    Persoana *v_nou;
    v_nou = new Persoana[n];

    for (int i=0; i<n; i++)
        g >> v_nou[i];

    for (int i=0; i<n; i++)
    {
        //if (v_nou[i].eStudent() == 0)
        //cout << v_nou[i];

        cout << v_nou[i].getNrPrenume() << " " << v_nou[i].getNumePrenume();

        if ( v_nou[i].eFemeie() == true )
            cout << " || Femeie || ";
        if (v_nou[i].eStudent() == 1 )
            cout << " || Student || ";

        string *lista;
        lista = v_nou[i].getPrenumeList();
        int contor = v_nou[i].getNrPrenume();

        for (int i=0; i<contor; i++)
            cout << "||PRENUME: " << i+1 << ": " << lista[i];
        delete[]lista;

        cout << endl;

    }

    cout << endl << endl;

    Sortare(v_nou,n);
    for (int i=0; i<n; i++)
        cout << v_nou[i];

    Scrie_Specific(v_nou,n);


    return 0;
}
