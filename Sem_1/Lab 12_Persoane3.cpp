#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

struct Persoana
{ char CNP[14];
int varsta;
};

int ContVarsta(Persoana v[],int varsta, int n){

        int nr=0;
        for (int i=0;i<n;i++)
            if (v[i].varsta == varsta)
                nr++;

        return nr;

}

int main()
{

    FILE *f;
    f = fopen("minori.txt","r");

    if (f==NULL){
        cout << "eroare la deschidere!";
        return 1;
    }

    int cont=0;
    Persoana *v=(Persoana*)malloc(1*sizeof(Persoana));

    while (!feof(f)){
            fscanf(f,"%s",&v[cont].CNP);
            fscanf(f,"%d",&v[cont].varsta);
            cont++; v=(Persoana*)realloc(v,(cont+1)*sizeof(Persoana));
    }

    int n=cont;

    cout << "Nr inreg:" << n << endl;

    int varsta_cautata;
    cin >> varsta_cautata;
    cout << "Sunt " <<  ContVarsta(v,varsta_cautata,n) << " persoana cu varsta de " << varsta_cautata << endl;

    if (fclose(f)!=0) cout << "Eroare la inchidere!";
    free(v);


    return 0;
}
