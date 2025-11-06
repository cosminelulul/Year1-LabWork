#include "Imobil.h"
#include <iostream>
using namespace std;

void Imobil::SetImbunatatiri(string *vect, int &dim){

    delete[]this->imbunatatiri;
    this->nr = dim;

    if (vect!=NULL){
        imbunatatiri = new string[dim];
        for (int i = 0; i<dim;i++)
            imbunatatiri[i] = vect[i];
    }else imbunatatiri=NULL;
}

bool Imobil::CheckOras(string oras_cerut){
    return (adr.GetOras() == oras_cerut);


}

bool operator==(const Imobil&imob1,const Imobil&imob2){

    if (imob1.adr==imob2.adr && imob1.nr==imob2.nr){
        for (int i=0;i<imob1.nr;i++)
            if (imob2.imbunatatiri[i]!=imob1.imbunatatiri[i])
               return false;

    }else return false;
    return true;

}

bool operator != (const Imobil&imob1, const Imobil&imob2){

    return !(imob1==imob2);
}


Imobil::Imobil(){
    nr=0;
    imbunatatiri = NULL;
}

Imobil::Imobil(const Adresa&cadr, int dim, string *vect):adr(cadr),nr(dim){
    imbunatatiri = NULL;
    SetImbunatatiri(vect, dim);
}

Imobil::Imobil(const Imobil&Imob):Imobil(Imob.adr,Imob.nr,Imob.imbunatatiri){}

Imobil& Imobil::operator=(const Imobil&Imob){

    adr = Imob.adr;
    nr = Imob.nr;
    SetImbunatatiri(Imob.imbunatatiri,nr);

    return *this;
}

Imobil::~Imobil(){
    delete[]imbunatatiri;
}


ostream& operator<<(ostream&dev, const Imobil &Imob) {
        dev << endl;
        dev << "Adresa este:" << Imob.adr;
        dev << Imob.nr << " Imbunatatiri: ";
        for (int i=0;i<Imob.nr;i++)
            dev << Imob.imbunatatiri[i] << " ";
        dev << endl;
        return dev;
}

istream& operator>>(istream&dev,  Imobil&Imob){

    dev >> Imob.adr;
    dev >> Imob.nr;
    delete[]Imob.imbunatatiri;

    if (Imob.nr > 0){
        Imob.imbunatatiri = new string[Imob.nr];
        for (int i=0;i<Imob.nr;i++)
            dev >> Imob.imbunatatiri[i];
    }

    return dev;
}
