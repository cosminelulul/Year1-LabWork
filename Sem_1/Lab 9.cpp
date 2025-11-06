#define _CRT_SECURE_NO_WARNINGS
#include<cmath>
#include <iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;

/*
struct coord
{
    double x, y;
};

void citire(coord &pct)
{
    cin >> pct.x;
    cin >> pct.y;
}

void distanta(coord pct,coord pct2)
{
    double dist;
    dist = sqrt(((pct2.x - pct.x) * (pct2.x - pct.x)) + ((pct2.y - pct.y) * (pct2.y - pct.y)));
    cout << dist<<" ";
}

void scriere(coord pct)
{
    cout << pct.x<<" " << pct.y;;
    cout << endl;

}
int main()
{
    coord* vect;
    int n;
    cin >> n;
    vect = (coord*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        citire(vect[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        distanta(vect[i], vect[i + 1]);
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        scriere(vect[i]);
    }

}
*/

struct TPCLP {
    char* alias;
    char grupa[5];
    int note[12];
};

void citire(TPCLP &elev)
{
    char buff[20];
    cin >> buff;
    elev.alias = (char*)malloc((strlen(buff) + 1) * sizeof(char));
    strcpy(elev.alias, buff);
    cin.get();
    cin.getline(elev.grupa,5);
    for (int i = 0; i < 12; i++)
        cin >> elev.note[i];
}
void afisare(TPCLP elev)
{
    cout << elev.alias;
    cout << endl;
    cout << elev.grupa;
    cout << endl;
    for (int i = 0; i < 12; i++)
        cout<< elev.note[i]<<" ";
}

void atribuire(TPCLP elev1, TPCLP elev2)
{
    elev2.alias = (char*)malloc((strlen(elev1.alias)+1)*sizeof(char));
    strcpy(elev2.alias, elev1.alias);
}

int main()
{
    TPCLP* z;
    int n;
    cin >> n;
    z = (TPCLP*)malloc(n * sizeof(TPCLP));
    for (int i = 0; i < n; i++)
    {
        citire(z[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 12; j++)
            if (z[i].note[j] = 0)
                return 2;
    }



}
