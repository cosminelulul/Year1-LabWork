#include <iostream>

using namespace std;

int main()
{
    int d;

    // Ex 4
    cout << "d="; cin >> d; cout << endl;

    int v1[d],v2[d],v3[d];

    //V1 termeni
    cout << "Cititi v1" << endl;
    for (int i=0; i<d; i++)
            cin >> v1[i];
    //V2 termeni
    cout << "Cititi v2" << endl;
    for (int i=0; i<d; i++)
            cin >> v2[i];

    //Adunare;
    for (int i=0;i<d;i++)
        v3[i]=v1[i]+v2[i];

    //Sortare
    int aux;
    for (int i=d-1;i>0;i--)
        if (v3[i] < v3[i-1]){
            aux=v3[i-1];
            v3[i-1]=v3[i];
            v3[i]=aux;
        }

    //Afisare
    cout << "v3=[ ";
    for (int i=0;i<d;i++)
        cout << v3[i] << " ";
    cout << "]" << endl;




    return 0;
}
