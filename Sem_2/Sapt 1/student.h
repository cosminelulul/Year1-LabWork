/*

Facultatea de Stiinte Aplicate dorește să țină evidenta studentilor sai. Se doreste:
1. ca studenții să fie stocati într-un vector (alocat dinamic), datele sa fie introduse de la tastatura
2. sa fie afișate toate detaliile despre toți studenții
3. sa se poată modifica grupa unui student
4. sa se poată modifica datele unui student, folosind ca parametru datele unui alt student
5. sa se poată modifica nota unui student la o anumita materie
6. sa se sorteze vectorul în funcție de media notelor din semestrul I.
Pentru a tine evidența este nevoie de tipul de date (structura) Student cu campurile și funcțiile
membre de mai jos:


*/



struct Student
{
    // implicit ar fi publice, dar nu vreau ca
    // oricine sa poata modifica aceste campuri -> private
    private:
        int id;
        char *nume;
        char gr[5]; //1315
        int note_sem_I[6]; // Fizica 1, Chimie 2, Matematica 2, ...
    // daca nu as face metodele publice, ar fi private ca si campurile
    // si nu as putea sa interactionez cu datele stocate
    public:
        // inițializează fiecare camp cu 0 sau NULL
        void init();
        // citeste de la tastatura datele unui student
        void citire();
        // afiseaza informatii student
        void afisare() const;
        // modifica grupa studentului
        void modificare(char []);
        // modifica toate campurile folosind valorile stocate in
        // variabila Student data ca parametru
        void modificare(const Student &);
        // modifica nota de pe o anumita pozitie (primul parametru),
        // iar noua valoare a notei e transmisa in al doilea parametru
        void modificare(int, int);
        // obtine nota de pe index-ul i
        double gpa();
};
