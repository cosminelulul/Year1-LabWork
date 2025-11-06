#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

enum SuprafataRulare {
terestra, acvatica, aeriana, spatiala
};

struct Vehicul {
    char *marca = NULL; // e.g., ”Renault”
    SuprafataRulare s; // 0,1,2 sau 3
    unsigned int putere:8; // ex: 100, 120, maxim 200
};

struct Fractie{
    int numitor,numarator;
};

void citire_Vehicul(struct Vehicul &V){

    unsigned short int putere1,s1=4;
    char marca_aux[35];

    cout << "Marca:";
    cin >> marca_aux;
    V.marca=(char*)malloc((strlen(marca_aux)+1)*sizeof(char));
    strcpy(V.marca,marca_aux);

    while (s1 < 0 || s1 >3){
        cout << "Suprafata Rulare:";
        cin >> s1;
    }
    V.s=(SuprafataRulare)s1;

    cout << "Putere:";
    cin >> putere1; V.putere = putere1;

}

void Afis_Date(struct Vehicul V){

    if (V.marca != NULL)
        cout << "Marca: " << V.marca << endl;
    else cout << "Vehiculul nu are o marca stabilita!" << endl;

    cout << "Suprafata Rulare: ";
    switch (V.s){
        case 0:
            cout << "teresta" << endl;
            break;
        case 1:
            cout << "acvatica" << endl;
            break;
        case 2:
            cout << "aeriana" << endl;
            break;
        case 3:
            cout << "spatiala" << endl;
            break;
    }
    cout << "Putere: " << V.putere << endl;

}

void Setare_Marca(struct Vehicul &V, char aux_marca[]){
    free(V.marca);
    V.marca=(char*)malloc((strlen(aux_marca)+1)*sizeof(char));
    strcpy(V.marca,aux_marca);
}

void Setare_Putere(struct Vehicul &V, unsigned short int p){
    V.putere = p;
}
void Setare_SuprafataRulare(struct Vehicul &V, SuprafataRulare SR){
    V.s=(SuprafataRulare)SR;
}


int main()
{
    // Teste pentru Implementare functiilor de la 2,3,4,5;

    //Vehicul Masina_1,Masina_2;
    //citire_Vehicul(Masina_1);
    //Afis_Date(Masina_1);
    //Setare_Marca(Masina_2,"Dacia");
    //Setare_Putere(Masina_2,175);
    //Setare_SuprafataRulare(Masina_2,(SuprafataRulare)0);
    //Afis_Date(Masina_2);

    int n; // lungime vector
    struct Vehicul *v;
    cout << "n=";cin >> n; cout << endl;
    v=(struct Vehicul*)malloc(n*sizeof(struct Vehicul));

    //6
    for (int i=0;i<n;i++){
        cout << "Cititi date pentru vehiculul " << i+1 << endl;
        citire_Vehicul(v[i]);
        cout << endl;
    }
    //7
    if (n==2 && strcmp(v[0].marca,v[1].marca)>0){
        struct Vehicul aux_veh;
        Setare_Marca(aux_veh,v[0].marca);
        Setare_Putere(aux_veh,v[0].putere);
        Setare_SuprafataRulare(aux_veh,v[0].s);

        Setare_Marca(v[0],v[1].marca);
        Setare_Putere(v[0],v[1].putere);
        Setare_SuprafataRulare(v[0],v[1].s);

        Setare_Marca(v[1],aux_veh.marca);
        Setare_Putere(v[1],aux_veh.putere);
        Setare_SuprafataRulare(v[1],aux_veh.s);
    }
    if (n>2){
    for (int i=0;i<n-1;i++){
            for (int j=i+1;j<n;j++){
        if (strcmp(v[i].marca,v[j].marca)>0){

                struct Vehicul aux_veh;
                Setare_Marca(aux_veh,v[i].marca);
                Setare_Putere(aux_veh,v[i].putere);
                Setare_SuprafataRulare(aux_veh,v[i].s);

                Setare_Marca(v[i],v[j].marca);
                Setare_Putere(v[i],v[j].putere);
                Setare_SuprafataRulare(v[i],v[j].s);

                Setare_Marca(v[j],aux_veh.marca);
                Setare_Putere(v[j],aux_veh.putere);
                Setare_SuprafataRulare(v[j],aux_veh.s);
            }
        }
    }
    }
    //7
    cout << "Vectorul sortat este:" << endl << endl;
    for (int i=0;i<n;i++)
        Afis_Date(v[i]);

    //8
    cout << endl << endl << "Vehiculele aeriene cu puterea mai mica de 100 sunt" << endl << endl;
    for (int i=0;i<n;i++)
        if (v[i].s==2 && v[i].putere<100)
            Afis_Date(v[i]);

    //9
    for (int i=0;i<n;i++)
       if (v[i].s==1)
            v[i].putere*=0.8;

    //10
    int nr_tereste=0,contor=0;
    struct Vehicul *v_sp_terestru;
    for (int i=0;i<n;i++)
       if (v[i].s==0)
            nr_tereste++;
    v_sp_terestru=(struct Vehicul*)malloc(nr_tereste*sizeof(struct Vehicul));
    cout << endl << endl << "Vehiculele tereste sunt" << endl << endl;
    for (int i=0;i<n;i++)
       if (v[i].s==0){
            Setare_Marca(v_sp_terestru[contor],v[i].marca);
            Setare_Putere(v_sp_terestru[contor],v[i].putere);
            Setare_SuprafataRulare(v_sp_terestru[contor],v[i].s);
            Afis_Date(v_sp_terestru[contor]);cout << endl;
            contor++;

       }

    free(v);
    free(v_sp_terestru);

    int l,c;
    cin >> l >> c;
    struct Fractie *matr;



    return 0;
}
