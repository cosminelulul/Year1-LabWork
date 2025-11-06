#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int d1,d2;
    int v1[d1],v2[d2];

    // Ex 2

    cout << "EX 2:" << endl;
    cout << "d1="; cin >> d1; cout << endl ;
    cout << "d2="; cin >> d2; cout << endl;

    if  (d1 != d2)
        cout << "Nu se poate calcula!";
    else{
        int v3[d1];
        for (int i=1; i<=d1; i++)
            cin >> v1[i];
        for (int i=1; i<=d2; i++)
            cin >> v2[i];
        cout << "v3=[";
        for (int i=1; i<=d1; i++){
            v3[i]=abs(v1[i]-v2[i]);
            cout << v3[i] << " ";
        }
        cout << "]" << endl;
    }


    return 0;
}
