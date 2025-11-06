#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct Persoana {
    char CNP[14];
    int varsta;
};

int main()
{
    int n;
    cin >> n;
    Persoana *v=(Persoana*)malloc(n*sizeof(Persoana));

    FILE *f;
    f = fopen("persoane.dat","wb");

    if (f==NULL){
        cout << "eroare la deschidere!";
        return 1;
    }

    for (int i=0;i<n;i++)
        cin >> v[i].CNP >> v[i].varsta;


    for (int i=0;i<n;i++)
         fwrite(&v[i],sizeof(Persoana),1,f);


   if (fclose(f)!=0)
        cout << "Eroare la inchidere!";

    free(v);
    return 0;
}
