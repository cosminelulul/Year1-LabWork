#include <iostream>
#include <string>
#pragma once
using namespace std;

struct Persoana{
    protected:
        string nume;
        int varsta;
    public:
        Persoana(const string& n, int v) : nume(n), varsta(v) {}
        virtual void afisare() const {
            cout << "Nume: " << nume << ", Varsta: " << varsta << endl;
        }
        virtual ~Persoana() = default;
};