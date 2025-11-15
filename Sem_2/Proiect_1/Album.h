#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Track.h"

struct Album {
    std::string titlu;
    int anLansare;
    std::vector<Track> melodii;
    
    public:
        Album(const std::string& t, int an, const std::vector<Track>& m) : titlu(t), anLansare(an), melodii(m) {}
        
        void afisare() const {
            std::cout << "Album: " << titlu << ", An Lansare: " << anLansare << std::endl;
            std::cout << "Melodii:" << std::endl;
            for (const auto& melodie : melodii) {
                melodie.afisare();
            }
        }
        
};