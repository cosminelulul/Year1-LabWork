#include "Persoana.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


Persoana::Persoana()
{
    nume = "John";
    prenume = "Doe";
    CNP = "0000000000000";
    student = 0;
}

Persoana::Persoana(const string atr_nume,const string atr_prenume, const string atr_CNP, bool atr_cond)
{
    nume = atr_nume;
    prenume = atr_prenume;
    CNP = atr_CNP;
    student = atr_cond;

}

bool Persoana::eStudent()const
{
    return student;
}

string Persoana::getDataNastere() const
{
    return CNP.substr(1,6);
}

bool Persoana::eFemeie() const
{

    char id = CNP.at(0);
    if (id == '2' || id == '4' || id == '6')
        return true;
    return false;
}

bool Persoana::eCNPValid() const
{
    if (CNP.size() == 13)
        return true;
    else return false;

}

int Persoana::getNrPrenume() const
{
    if (prenume.find('-')==string::npos)
        return 1;
    else
    {

        int gasiri=1;
        int poz=prenume.find('-',0);
        while (poz!=string::npos)
        {
            gasiri++;
            poz=prenume.find('-',poz+1);
        }
        return gasiri;
    }

    /*
    Varianta simpla :)
    string p = prenume;
    int loc=0;
    while (loc =p.find("-")!=string::npos){
        gasiri++;
        p.substr(loc+1);

    */
}

string* Persoana::getPrenumeList()const
{

    string *lista;
    int nr_prenume = this->getNrPrenume();
    lista = new string[nr_prenume+1];

    int cur_poz=prenume.find('-',0);
    int prev_poz = 0;
    int i = 0;

    while (prev_poz != string::npos)
    {
        lista[i]=prenume.substr(prev_poz+(i>=1),cur_poz-prev_poz-(i>=1));
        i++;
        prev_poz = cur_poz;
        cur_poz=prenume.find('-',cur_poz+1);
    }


    return lista;
}

string Persoana::getNumePrenume()const
{
    return (nume+" "+prenume);
}

void Persoana::setNumePrenume(string str)
{
    int poz = str.find(' ');
    nume = str.substr(0,poz-1);
    prenume = str.substr(poz+1,str.size());


}

