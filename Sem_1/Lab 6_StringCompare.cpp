#include <iostream>

using namespace std;

int main()
{

    char sir1[256],sir2[256];
    cin >> sir1;
    cin >> sir2;
    char *p1,*p2;

    int optiune;
    cout << "1 = lungime - 2 = primul caracter" << "\n";
    cin >> optiune;

    if (optiune == 1){
            int count1=0,count2=0;
            p1=sir1;p2=sir2;
            while (*p1!='\0'){
                count1++;
                p1++;
            }
            while (*p2!='\0'){
                count2++;
                p2++;
            }
            if (count1==count2)
                cout << "lungime exacta" << endl;
            else
                cout << "lungime diferita" << endl;
        }
    else if(optiune == 2){
        p1=&sir1[0],p2=&sir2[0];
        if (    *p1 == *p2   )
            cout << "p1==p2" << endl;
        else
            cout << "p1!=p2" << endl;
    }
    else cout << "comanda gresita";

    return 0;
}
