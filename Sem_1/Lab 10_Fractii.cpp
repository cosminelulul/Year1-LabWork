#include <iostream>
#include <stdlib.h>
using namespace std;

struct Fractie{
        int numarator;
        int numitor;
};

void CitireAfisF(int &numarator, int &numitor){

        //numitor != 0;

        cout << "Citeste numaratorul:"; cin >> numarator;
        cout << "Citeste numitorul:"; cin >> numitor;

        while (numitor == 0){
            cout << "Citeste numitorul:"; cin >> numitor;
        }

        cout << "Numarul este:" << numarator << '|' << numitor << endl;
}

void Simplificare(int &numarator, int &numitor){

    if (numarator == numitor)
        numarator=numitor=1;

    if (numarator%numitor==0){
        numarator /= numitor;
        numitor/=numitor;
    }
}

void AdunareScadere(int numarator1, int numitor1,int numarator2, int numitor2,int tip){
   // obs: tip == 1 adunare
   // obs: tip == 0 scadere

   int aux1,aux2;
   if (numitor1!=numitor2){
       aux1= numitor1;
       aux2 = numitor2;
       numitor1 = aux1 * aux2;
   }else{
        aux1=aux2=1;
   }

   if (tip == 1)
        numarator1 = numarator1*aux2+numarator2*aux1;
   else
        numarator1 = numarator1*aux2-numarator2*aux1;

   Simplificare(numarator1,numitor1);

   cout << "Adunare / Scadere: Numarul este:" << numarator1 << '|' << numitor1 << endl;

}
void Inmultire(int numarator1, int numitor1,int numarator2, int numitor2){

    numarator1 *= numarator2;
    numitor1 *= numitor2;

    Simplificare(numarator1,numitor1);

    cout << "Inmultire : Numarul este:" << numarator1 << '|' << numitor1 << endl;

}

double Raport(int numarator, int numitor){
    return numarator/double(numitor);
}

void sortare(struct Fractie *&v , int n){

    int auxi;
    for (int i=0;i<n-1;i++){
        auxi=i;
        for (int j=i+1;j<n;j++)
            if (Raport(v[j].numarator,v[j].numitor)<Raport(v[auxi].numarator,v[auxi].numitor))
                auxi=j;

        int aux_numarator=v[auxi].numarator;
        int aux_numitor=v[auxi].numitor;

        v[auxi].numarator= v[i].numarator;
        v[auxi].numitor= v[i].numitor;

        v[i].numarator= aux_numarator;
        v[i].numitor= aux_numitor;

    }
}


int main()
{

    struct Fractie x;
    //CitireAfisF(x.numarator,x.numitor);
    struct Fractie y;
    y.numarator=19;
    y.numitor=4;
    // Adunarea si scaderea
    //AdunareScadere(x.numarator,x.numitor,y.numarator,y.numitor,1);
    //AdunareScadere(x.numarator,x.numitor,y.numarator,y.numitor,0);

    //Inmultire
    //Inmultire(x.numarator,x.numitor,y.numarator,y.numitor);

    // Raport
    //cout << "Raportul fractiei este:" << Raport(y.numarator,y.numitor);

    int n; cout << "n:";
    cin >> n;
    struct Fractie *v;
    v=(struct Fractie*)malloc(n*sizeof(struct Fractie));
    for (int j=0;j<n;j++)
        CitireAfisF(v[j].numarator,v[j].numitor);
    sortare(v,n);

    for (int j=0;j<n;j++)
        cout << v[j].numarator << "|" << v[j].numitor<<" ";

    free(v);


    return 0;
}
