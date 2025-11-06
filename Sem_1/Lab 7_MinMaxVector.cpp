#include <iostream>

using namespace std;

void minimaxi(int v[], int l){

    int vmax=v[0];
    int vmin=v[0];
    for (int i=1;i<l;i++){
        if (v[i]>vmax)
            vmax=v[i];
        if (v[i]<vmin)
            vmin=v[i];
    }
    cout << "val min=" << vmin << " " << "val max" << vmax << endl;
}

int main()
{

    int v[100],l;
    cout << "lungime vector:" << endl;
    cin >> l;
    for (int i=0;i<l;i++){
        cout << "introduce v[" << i << "]:" << endl;
        cin >> v[i];
    }
    minimaxi(v,l);

    return 0;
}
