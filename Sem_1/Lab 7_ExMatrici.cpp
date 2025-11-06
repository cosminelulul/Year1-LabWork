#include <iostream>
using namespace std;

void afis(int A[10][10]){
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
}


void interschimba(int A[10][10],int c1, int c2){
        for (int i=0;i<10;i++){
            int Aux=A[i][c1];
            A[i][c1]=A[i][c2];
            A[i][c2]=Aux;
        }
}

int main()
{
    int A[10][10],l,c;

    cout << "Introduce elemente matrice:" << endl;
    for (int i=0;i<10;i++)
        for (int j=0;j<10;j++)
            cin >> A[i][j];


    // interschimbarea
    int c1,c2;
    cout << "Coloanele dorite interschimbate";
    cin >> c1 >> c2;
    interschimba(A,c1,c2);

    //afisare
    afis(A);



    return 0;
}
