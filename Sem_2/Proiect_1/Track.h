#include <iostream>
#include <vector>
#include <string>
#pragma once
using namespace std;

struct Track {
    string titlu;
    int durata; // durata in secunde
    int pozitie;
    public:
        Track(const string& t, int d, int p) : titlu(t), durata(d), pozitie(p) {}
        
        void afisare() const {
            cout << "Titlu: " << titlu << ", Durata: " << durata << " secunde" << ", Pozitie: " << pozitie << endl;
        }
        
};
