#include <iostream>
#include "Produs.h"
#include "Aliment.h"
#include "Aliment_Ambalat.h"

using namespace std;

Sortare(Aliment_Ambalat*vect,int dim){
    for (int i = 0;i<dim-1;i++)
        for (int j = 0;j<dim-1-i;j++)
            if (vect[i].tip_ambalaj.compare(vect[j].tip_ambalaj)<0){
                Aliment_Ambalat aux = vect[i];
                vect[i]=vect[j];
                vect[j]=aux;
            }
};

void AfisareSelectiva(Aliment_Ambalat*vect,int dim){
        for (int i = 0;i<dim;i++)
            if ( (vect[i].getPret() > 10) && (vect[i].getNrInfo() > 10) && (vect[i].getReciclabil() == 1))
                vect[i].afisare();

}

int main()
{
    Produs test_produs("lays",3);
    test_produs.afisare();
    cout << endl;

    string test_info[2]={"230cal/100g","valabil pana: 12.12.2024"};
    Aliment test_aliment("lays",3,2,test_info);
    test_aliment.afisare();
    cout << endl;

    Aliment test_aliment2;
    test_aliment2 = test_aliment;
    test_aliment2.afisare();
    cout << endl;

    Aliment_Ambalat test_aliment_amb;
    test_aliment_amb.afisare();
    Aliment_Ambalat test_aliment_amb2("7 days",4,2,test_info,"carton",true);
    test_aliment_amb2.afisare();

    Aliment_Ambalat *vect;
    vect = new Aliment_Ambalat[5];

    for (int i=0;i<5;i++)
        vect[i].citire();

    cout << endl;
    for (int i=0;i<5;i++)
        vect[i].afisare();

    Sortare(vect,5);

    cout << endl;
    for (int i=0;i<5;i++)
        vect[i].afisare();

    cout << endl;
    cout << "functie test:" << endl;
    AfisareSelectiva(vect,5);

    //cout << "Hello world!" << endl;
    return 0;
}
