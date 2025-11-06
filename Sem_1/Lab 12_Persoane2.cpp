#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

struct Persoana
{ char CNP[14];
int varsta;
};

void SortareVector(Persoana v[],int n){

    Persoana aux;
    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n-i;j++)
            if ( (v[j].varsta>v[j+1].varsta) || (v[j].varsta==v[j+1].varsta && atoi(v[j].CNP)>atoi(v[j+1].CNP) ) ){

                aux.varsta=v[j].varsta;
                strcpy(aux.CNP,v[j].CNP);

                v[j].varsta=v[j+1].varsta;
                strcpy(v[j].CNP,v[j+1].CNP);

                v[j+1].varsta=aux.varsta;
                strcpy(v[j+1].CNP,aux.CNP);

            }

}

int main()
{
    FILE *f;
    f = fopen("persoane.dat","rb");

    if (f==NULL){
        cout << "eroare la deschidere!";
        return 1;
    }

    int cont=0;
    Persoana *v=(Persoana*)malloc(1*sizeof(Persoana));

    while (!feof(f)){
        fread(&v[cont],sizeof(Persoana),1,f);
        cont++;
        v=(Persoana*)realloc(v,(cont+1)*sizeof(Persoana));
    }
    int n=cont-1;
    cont++; v=(Persoana*)realloc(v,n*sizeof(Persoana));
    cout << "Nr inreg:" << n << endl;


    //vector inainte de sortare
    cout << endl << endl;

    for (int i=0;i<n;i++)
        cout << v[i].CNP << " " << v[i].varsta << endl;

    SortareVector(v,n);

    //vector dupa sortare
    cout << endl << endl;

    for (int i=0;i<n;i++)
        cout << v[i].CNP << " " << v[i].varsta << endl;

    FILE *g;
    g = fopen("minori.txt","w");
    for (int i=0;i<n;i++)
        if (v[i].varsta<18){
            fprintf(g,"%s",v[i].CNP);
            fprintf(g,"%c",' ');
            fprintf(g,"%d",v[i].varsta);
            fprintf(g,"%c",'\n');
    }

    if (fclose(f)!=0)
        cout << "Eroare la inchidere!";

    if (fclose(g)!=0)
        cout << "Eroare la inchidere!";

    return 0;
}
