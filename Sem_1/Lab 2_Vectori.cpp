#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "n="; cin >> n;
    int v[n],vf[10]={0};
    int vs[n]={-1};


    cout << "v=";
    for (int i=0; i<n; i++){
        cin >> v[i];
        vf[v[i]]++;
    }


    for (int i=1; i<10; i++)
        vf[i]+=vf[i-1];


    for (int i=0; i<n; i++){

        int index = v[i];
        int index2= vf[index] - 1;
        vs[index2] = index;
        vf[index]--;

    }

    cout << "vs=[ ";
    for (int i=0; i<n; i++)
        cout << vs[i] << " ";
    cout << "]" << endl;



    return 0;
}
