#include <iostream>

using namespace std;

int main()
{

    int l1,l2,c1,c2;
    cout << "l1 & c1 " << "\n";
    cin >> l1 >> c1;
    cout << "l2 & c2 " << "\n";
    cin >> l2 >> c2;

    int A[l1][c1],B[l2][c2],C[l1][c1];
    cout << "Elemente A:" << "\n";
    for (int i=0;i<l1;i++)
        for (int j=0;j<c1;j++)
            cin >> A[i][j];
    cout << "Elemente B:" << "\n";
    for (int i=0;i<l2;i++)
        for (int j=0;j<c2;j++)
            cin >> B[i][j];

    if (l1 == c1 && l2 == c2 && l1==l2){
        cout << "Elemente C:" << "\n";
        for (int i=0;i<l2;i++){
            for (int j=0;j<c2;j++){
                    C[i][j]=A[i][j]+B[i][j];
                    cout << C[i][j] << " ";
            }
            cout << "\n";
        }
    }
    else cout << "Matricele nu sunt patratice sau nu au aceiasi dimensiune" << "\n";

    return 0;
}
