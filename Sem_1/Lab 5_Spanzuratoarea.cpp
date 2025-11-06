#include <iostream>
#include <string.h>

using namespace std;

int main()
{

    //initializare sir//
    char sir[500];
    cout << "Cititi un cuvant de la tastatura" << "\n";
    cin >> sir;

    //initializare joc//
    char joc[strlen(sir)];
    for (int i=0; i<strlen(sir); i++)
        joc[i]='_';
    cout << joc << "\n";

    //start joc//
    int g=0;char car;
    while (g!=7 &&  strcmp(joc,sir) != 0){

        cout << "Introduceti un singur caracter" << "\n";
        cin >> car;

        if (strchr(sir,car) == 0 ){
            g++;
            cout << "A fost facut o greasala! Au ramas inca " <<  7-g << " incercari" << "\n";
        }else{
            for (int i=0; i<strlen(sir); i++)
                if (sir[i] == car)
                    joc[i]=car;
            cout << joc << "\n";
        }
    }
    // Concluzie //
    (g==7)?
        cout << "Ati pierdut!Incercati din nou":
    cout << "Ati castigat! Felicitari!";


    return 0;
}
