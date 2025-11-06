#include <iostream>

using namespace std;

int main()
{

    int vf[11]={0};
    int dim;
    cout << "dim="; cin >> dim;
    int v[dim];

    for (int j=0;j<dim;j++){
        cin >> v[j];
        vf[v[j]]++;
    }

    cout << "0"  << " " << "1" << " " << "2" << " " <<  "3" << " " << "4" << " " << "5" << " " << "6" << " " << "7" << " " <<  "8" << " " << "9" << " " << "10" << endl;
    for (int j=0;j<11;j++)
        cout << vf[j] << " ";





    return 0;
}
