#include <iostream>
#include <string.h>

using namespace std;

int main()
{

    int ln,kn;
    cout << "introduceti l si k" << "\n";
    cin >> ln >> kn;

    char sir[ln];
    char sec[kn];
    char aux[98];

    cout << "sir:" << "\n";
    cin >> sir;
    cout << "sec:" << "\n";
    cin >> sec;
    
    int l = strlen(sir),k = strlen(sec);
    int nr=0, j=0;
    strcpy(aux,"");

    if (k >= l)
        cout << "k>=l" << "\n";
    else {
        int contor=0;

        for (int i=0;i<=l;i++){

            if (sir[i]==sec[j]){
                aux[contor]=sir[i];
                j++;
                contor++;
            }else {
                strcpy(aux,"");
                contor=0;j=0;
            }

            if (contor == k){
                contor = 0;
                if (strstr(aux,sec) != 0)
                        nr++;
                strcpy(aux,"");
            }

        }
        cout << nr << "\n";
    }


    return 0;
}
