#include <iostream>
#include "Album.h"
#include "Artist.h"
#include "Track.h"
#include "Persoana.h" 
using namespace std;



int main() {

    Persoana p("Ion Popescu", 30);
    vector<Track> SetTrackAlbum1 = {
        Track("O Doamne iubesc prunele", 210, 1),
        Track("Zece caine si o pisica", 180, 2),
        Track("Iubire, draga iubire!", 240, 3)
    };
    vector<Track> SetTrackAlbum2 = {
        Track("Melodie fara titlu", 200, 1),
        Track("Alta melodie", 220, 2)
    };
    Album album("Debut", 2023, SetTrackAlbum1);
    Album album2("Second Album", 2024, SetTrackAlbum2);
    vector<Album> albume = {album, album2};
    Artist artist(p, "Pop", albume);
    artist.afisare();


    return 0;
}   