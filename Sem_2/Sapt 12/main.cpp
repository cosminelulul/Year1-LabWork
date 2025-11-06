#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
using namespace std;

class Produs{
public:
    //Produs() = default;
    //virtual void citire() = 0;
    virtual void afis(fstream &f) const = 0;
    virtual int getPret() = 0;
    virtual ~Produs(){
    };
};

class produs_software:public Produs { //PS
protected:
    int pret = 0;
public:
    produs_software() = default;
    produs_software(int price):pret(price){};
    produs_software(const produs_software &prod){
        *this = prod;
    }
    void afis(fstream &f) const override{
        f << pret;
    }
    int getPret() override{
        return pret;
    }
    friend ostream& operator<<( ostream& dev, produs_software &p){
        dev << p.pret;
        return dev;
    }
};

class Piesa:public Produs{
    char cod[6];
    int pret = 0;
public:
    Piesa() = default;
    Piesa(char id[6],int price):pret(price){
        strcpy(cod,id);
    };
    void afis(fstream &f) const override{
        f << cod << " " << pret;
    }
    int getPret() override{
        return pret;
    }

};

class modul_hardware:public Produs { //MH
protected:
    vector<Piesa> vec; // vector piese
    int pm = 0;            // pret manopera pe ora
    int nr_ore = 0;        // ore dezvoltare
    // pret = suma preturilor pieselor+pm*nr_ore
public:
    modul_hardware() = default;
    modul_hardware(vector<Piesa>v,int cpm, int nr):vec(v),pm(cpm),nr_ore(nr){};
    virtual void afis(fstream &f) const override{
        for (int i = 0; i<vec.size();i++){
            vec[i].afis(f); f << " ";
            }
        f << pm << " " << nr_ore;
    }

    virtual int getPret() override{
        int sum_price;
        for (int i = 0; i<vec.size();i++)
            sum_price +=vec[i].getPret();
        return (sum_price + pm * nr_ore);
    }
};


class produs_mixt: public modul_hardware { //PM
    produs_software ps;
    vector<string> functionalitati;
    // pret = pret ps+pret MH
public:
    produs_mixt() = default;
    produs_mixt(produs_software p, vector<string> cev,vector<Piesa> vec2, int cpm, int nr):modul_hardware(vec2,cpm,nr),ps(p),functionalitati(cev){};
    void afis(fstream &f) const override{
        modul_hardware::afis(f); f << " "; ps.afis(f); f << " ";
        for (int i = 0; i<functionalitati.size();i++){
            f << functionalitati[i] << " ";
        }
    }
    int getPret() override{
        return ( modul_hardware::getPret() + ps.getPret());
    }
};



int main()
{

    vector<Produs*> v(6);

    produs_software prod_soft(344);
    produs_software prod_soft2(1005);

    Piesa p1("00001",500);Piesa p2("00002",45); Piesa p3("00003",700);
    Piesa p4("00004",125);Piesa p5("00005",435); Piesa p6("00006",790);

    vector<Piesa>vec;     vector<Piesa>vec2;
    vec.push_back(p1);    vec2.push_back(p4);
    vec.push_back(p2);    vec2.push_back(p5);
    vec.push_back(p3);    vec2.push_back(p6);

    modul_hardware mh1(vec,35,5);
    modul_hardware mh2(vec2,55,4);

    vector<string> vec3; vector<string> vec4;
    vec3.push_back("functie 1");     vec4.push_back("functie 4");
    vec3.push_back("functie 2");     vec4.push_back("functie 5");
    vec3.push_back("functie 3");     vec4.push_back("functie 6");

    produs_mixt pm1(prod_soft,vec4,vec2,70,6);
    produs_mixt pm2(prod_soft2,vec3,vec,205,2);

    v[0] = &prod_soft;
    v[1] = &mh1;
    v[2] = &pm1;
    v[3] = &pm2;
    v[4] = &mh2;
    v[5] = &prod_soft2;

    int total_sum = 0;
    for (int i = 0 ; i<v.size();i++){
        total_sum += v[i]->getPret();
    }

    cout << "suma incasata este: " << total_sum << endl;

    fstream f("file.txt",ios::out);

    vector<Produs*>::iterator it=v.begin();
    for (it=v.begin(); it!=v.end(); it++){
        f << "PRODUS " << ": ";
        (*it)->afis(f);
        f << endl;
    }

    for (it=v.begin(); it!=v.begin()+2; it++)
        v.erase(it);


    it = v.begin();
    produs_software prod_soft3(3555);
    v.insert(*it,prod_soft3);

    int indice_max_pret = 0,max_pret = 0;
    for (int i = 0 ; i<v.size();i++){
        if (v[i]->getPret() > max_pret) {
            indice_max_pret = i;
            max_pret = v[i]->getPret();
        }
    }
    cout << "Produs cu pret max:" << indice_max_pret << "     "; v[indice_max_pret]->afis();


    return 0;
}
