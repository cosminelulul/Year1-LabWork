#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
   int *v=(int*)malloc(20*sizeof(int));
   int x=0; // variabila folosita pentru citirea elementelor
   int i=0; // contor
   //citire
   cout << "Cititi de la tastatura elementele vectorului: " << "\n";
   while (x!=-1){
        cin >> x;
        if (x>=0){
            v[i]=x;
            i++;
            if (i>=20)
                v=(int*)realloc(v,i*sizeof(int));
        }
   }
   if (i<19)
    v=(int*)realloc(v,i*sizeof(int));

   for (int j=0;j<i;j++)
        cout << v[j] << " ";

    //cout << "\n" << i*sizeof(int);
    free(v);

    return 0;
}
