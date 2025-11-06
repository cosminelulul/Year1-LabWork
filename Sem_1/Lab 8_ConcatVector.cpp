#include <iostream>
#include <stdlib.h>
using namespace std;

void afis(int v[], int k){
    cout << "Vectorul are elementele: ";
    for (int i=0;i<k;i++)
        cout << v[i] << " ";
    cout << "\n";
}

void citire(int v[], int k){
    cout << "Introduce valori:" << endl;
    int n;
    for (int i=0;i<k;i++){
        if (i==0) cin >> v[i];
        else {
            cin >> n;
            if (n>v[i-1])
                v[i]=n;
            else{
                do
                    cin >> n;
                while(n<v[i-1]);
                }
        }
    }
}

void concat(int v[],int v1[],int v2[],int n1,int n2){


    int i=0, cont=0;
    for (i=0;i<n1;i++){
        v[i]=v1[i];
    }
    cont=n1;
    for (i=0;i<n2;i++){
        v[cont]=v2[i];
        cont++;
    }
    afis(v,n1+n2);
}

int main()
{
    int n1=4;
    int n2=4;
    int *v1=(int*)malloc(n1*sizeof(int));
    int *v2=(int*)malloc(n2*sizeof(int));

    citire(v1,n1);
    citire(v2,n2);

    int *v3=(int*)malloc((n1+n2)*sizeof(int));
    concat(v3,v1,v2,n1,n2);


    return 0;
}
