#include <iostream>

using namespace std;

int main()
{


    int m1,n1,m2,n2;

    //Citirea

    cout << "Linia si coloana pt A:"; cin >> m1 >> n1;
    cout << "\n" << "Linia si coloana ptB:"; cin >> m2 >> n2;

    int A[m1][n1],B[m2][n2];

    cout << "Elemente A:" << "\n";
    for (int i=0;i<m1;i++)
        for (int j=0;j<n1;j++)
            cin >> A[i][j];

    cout << "Elemente B:" << "\n";
    for (int i=0;i<m2;i++)
        for (int j=0;j<n2;j++)
            cin >> B[i][j];

    // Inmultire



    if (n1==m2){

        int C[m1][n2]={};

        for (int i=0;i<m1;i++){
            for (int j=0;j<n2;j++)

                for (int k=0;k<=n2-1;k++)
                    C[i][j] += (A[i][k]*B[k][j]);

        }

        for (int i=0;i<m1;i++){
            for (int j=0;j<n2;j++)
                cout << C[i][j] << " ";
            cout << endl;
        }

    } else cout << "n1!=m2";














    return 0;
}
