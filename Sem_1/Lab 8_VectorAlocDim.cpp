#include <iostream>
#include <stdlib.h>
using namespace std;

void citire(int v[], int k){
    cout << "Introduce valori:" << endl;
    for (int i=0;i<k;i++)
        cin >> v[i];
}

void afis(int v[], int k){
    cout << "Vectorul are elementele: ";
    for (int i=0;i<k;i++)
        cout << v[i] << " ";
    cout << "\n";
}

void concat(int vc[],int v1[], int v2[], int n, int m){

    int i=0, cont=0;
    for (i=0;i<n;i++){
        vc[i]=v1[i];

    }
    cont=n;
    for (i=0;i<m;i++){
        vc[cont]=v2[i];
        cont++;
    }
    afis(vc,n+m);

}

int suma(int v[], int n){
    int s=0;
    for (int i=0;i<n;i++)
        s+=v[i];
    return s;
}

int main()
{

    int n,m;
    n=4;
    m=5;
    int con=n+m;
    int *vn=(int*)malloc(n*sizeof(int));
    int *vm=(int*)malloc(m*sizeof(int));

    // Citire vect
    citire(vn,n);
    citire(vm,m);

    // Afis vect
    afis(vn,n);
    afis(vm,m);

    int *vc=(int*)malloc(con*sizeof(int));
    concat(vc,vn,vm,n,m);
    cout << suma(vc,con);


    free(vn);
    free(vm);
    free(vc);





    return 0;
}
