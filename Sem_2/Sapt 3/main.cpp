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

// LAB 3

bool operator==(const Masina&car1,const Masina&car2){
    if (car1.pret == car2.pret&& strcmp(car1.nr_inmatriculare,car2.nr_inmatriculare) == 0
        && ( strlen(car1.marca) ==  strlen(car2.marca) && strcmp(car1.marca,car2.marca) == 0 ) )
            return 1;
    else return 0;
 }

bool operator!=(const Masina&car1,const Masina&car2){
    return (!(car1==car2));
}

void Sortare(Masina *v,int n){

    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n-i;j++)
            if ( strcmp(v[i].marca,v[j].marca) > 0 ){
                Masina aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
}

int countEgal(Masina *v, int n, Masina &car_cautat){

    int nr=0;

    for (int i=0;i<n;i++)
        if (v[i]==car_cautat);
            nr++;

    return nr;
}

void ReAlocare(Masina *&v,int newdim){
    Masina *vc = new Masina[newdim];
    for (int i=0;i<newdim;i++)
        vc[i]=v[i];
    delete[]v;
    v = vc;


}

void AdaugaObiect(Masina *&v, int &n,Masina &car_adaugat){

    if ( countEgal(v,n,car_adaugat) != 0){

        ReAlocare(v,n+1);
        v[n]=car_adaugat;
        n++;
    }
}

// BONUS

void ElmDuplicat(Masina *&v, int &n){

    int cn = n; //
    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n-i;j++)
            if (v[i]==v[j]){
                for (int k=j;k<n-1;k++)
                    v[k]=v[k+1];
                cn--;
        }

    if (cn!=n){
        ReAlocare(v,cn);
        n = cn;
    }

}

int main()
{
    // LAB 3
    Masina car1;
    Masina car2("AUDI","B123ABC",5775.75);

    cout <<(car1!=car2) << " ";

    car1 = car2;

    cout <<(car1==car2) << endl << endl;

    int n = 5;
    Masina *v=new Masina[n];

    for (int i=0;i<n;i++){
        v[i].citire();
    }
   /* cout << endl << "Afisare" << endl << endl;
    for (int i=0;i<n;i++){
        v[i].afisare();
    } */

    Masina car_cautat("AUDI","B123ABC",5775.75);
    cout << countEgal(v,n,car_cautat);

    Masina car_adaugat("MERCEDES","B777ROU",55505.999);
    AdaugaObiect(v,n,car_adaugat);

    cout << endl << "Afisare" << endl << endl;
    for (int i=0;i<n;i++){
        v[i].afisare();
    }

    ElmDuplicat(v,n);

    cout << endl << "Afisare" << endl << endl;
    for (int i=0;i<n;i++){
        v[i].afisare();
    }

    return 0;
}
