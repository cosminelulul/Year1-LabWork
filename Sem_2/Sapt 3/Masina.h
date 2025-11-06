class Masina {
// atributele sunt implicit private
    char *marca = nullptr;
    char nr_inmatriculare[8]="0";
    double pret=0;
public:
    // constr. fara param;
    // util pentru a crea obiecte intializate cu valori default
    // necesar pt. alocarea spatiului pentru elemente din vect. de masini
    // marca = NULL; nr_inmatriculare este  de ex: "000..0"; pret=0
    Masina()=default;
    // constr. cu param; pentru a initializa cu valori dorite toate atrib.
    Masina(const char*, const char[], const double);
    // constructor de copiere - se apeleaza automat la transmiterea
    // parametrilor in functii prin valoare si la
    // returnarea obiectelor din fctii prin valoare;
    // puneti: cout<<"const de copiere"; (ca sa vedeti unde e apelat)
    Masina(const Masina&);
    // elibereaza spatiu ocupat de un obiect
    ~Masina();
    //afiseaza toate atributele unui obiect de acest tip
    void afisare() const;
    // face o copie profunda a parametrului si o stocheaza in
    // obiectul cu care se face apelul;
    void copie(const Masina &);
    // citeste elem obiectului de la tastatura
    void citire();
    double getPret() const;
    //get function pret
    char* getNrInt();
    //get function nr inmatriculare
    char* getMarca();
    //get function marca

    // LAB 3
    // fnct de copie
    Masina& operator=(const Masina&);
    //functia de verificare pt egalitate
    friend bool operator==(const Masina&, const Masina&);
    //functia de verificare pt inegalitate
    friend bool operator==(const Masina&, const Masina&);
    // functia de sortare a unui vector alocat dinamic
    friend void Sortare(Masina*, int);



};

