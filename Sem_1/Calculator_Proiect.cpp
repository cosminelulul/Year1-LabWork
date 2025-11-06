#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


// COMENZI ACCEPTATE DE CALCULATOR //
// Suma , Scadere , Inmultire , Impartire, Radacina patrata//



void Calculator(){

    cout << "Introduceti comanda corecta" << endl;
    char str[256];

    double a,b,nr,fl;

    cin.getline(str,256);

    //str = tolower(str); 

    if (strcmp(str, "suma") == 0 || strcmp(str, "scadere") == 0 || strcmp(str, "inmultire") == 0 || strcmp(str, "impartire") == 0) {

        cout << "Introduceti doua numere: " << endl;
        cin >> a >> b;

        if (strcmp(str, "suma") == 0)
            nr = a + b;
        else if (strcmp(str, "scadere") == 0)
            nr = a - b;
        else if (strcmp(str, "inmultire") == 0)
            nr = a * b;
        else if (strcmp(str, "impartire") == 0)
            nr = a / b;

        cout << "Numarul rezultat este: " << nr << endl;
    }
    else if ( strstr(str, "radacina") != 0 || strcmp(str, "putere") == 0){

        cout << "Introduceti un numar  " << endl;
        cin >> a;

        if (strstr(str, "radacina") != 0)
            fl  = sqrt(a);
        else if (str == "putere" ){
            cout << "Introduceti puterea " << endl;
            cin >> b;
            fl = pow(a,b);
        }

        cout << "Numarul rezultat este: " << fl << endl;

    }
    
    return;

}


int main(){

    cout << "CALCULATOR AVANSAT 1.0" << endl;
    char cont;
    bool stop = false;

    while (stop == false){
        Calculator();

        cout << "Doriti sa continuati? Y/n?";
        cin >> cont;

        if ( tolower(cont) != 'y' )
            stop = true;
    }



    return 0;
}