#include <iostream>
#include <string.h>
#include "Masina.h"

using namespace std;

int nrMasini(Masina v[],int n, char jud[]){

    int nr=0;
    for (int i=0;i<n;i++)
        if ( strncmp(v[i].getNrInt(),jud,2) == 0)
            nr++;

    return nr;
}

Masina getMasina(Masina *v,int n){

    Masina masinascumpa;

    for (int i=0;i<n;i++)
        if ( v[i].getPret() > masinascumpa.getPret())
            masinascumpa.copie(v[i]);

    return masinascumpa;

}

void Sortare(Masina *v,int n){

    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n-i;j++)
            if ( strcmp(v[i].getMarca(),v[j].getMarca()) > 0 ){
                Masina aux;
                aux.copie(v[i]);
                v[i].copie(v[j]);
                v[j].copie(aux);
            }


}

int main()
{

    /*Masina car1;
    Masina car2("AUDI","B123ABC",5775.75);
    Masina car3(car2);
    Masina car4;
    car1.afisare();
    car2.afisare();
    car3.afisare();
    car4.copie(car1);
    car4.afisare();*/

    int n;
    cin >> n;
    Masina *vect = new Masina[n];

    //1
    for (int i=0;i<n;i++){
        vect[i].citire();
    }

    //2
    for (int i=0;i<n;i++){
        vect[i].afisare();
    }

    //3
    cout << nrMasini(vect,n,"PH") << endl;;

    //4
    Masina maxcar;
    maxcar.copie(getMasina(vect,n));

    //5
    Sortare(vect,n);

    for (int i=0;i<n;i++){
        vect[i].afisare();
    }


    return 0;
}
