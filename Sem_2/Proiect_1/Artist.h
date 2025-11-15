#include "Persoana.h";
#include "Album.h";

struct Artist : public Persoana {
        string genMuzical;
        vector<Album> albume;
    public:
        Artist(const string& n, int v, const string& gen, vector<Album> a) : Persoana(n, v), genMuzical(gen), albume(a) {}

        Artist(const Persoana& p, string gen, vector<Album> a) : Persoana(p), genMuzical(gen), albume(a) {}
        
        void afisare() const override {
            Persoana::afisare();
            cout << "Gen Muzical: " << genMuzical << endl;
            cout << "Albume:" << endl;
            for (const auto& album : albume) {
                album.afisare();
            }
        }
        
        ~Artist() override = default;
};