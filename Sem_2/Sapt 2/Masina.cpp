#include "Masina.h"
#include <iostream>
#include <string.h>

using namespace std;


Masina::Masina(const char *marca,const char nr_inmatriculare[], const double p):pret(p){
    if (marca != NULL){
        this->marca = new char[strlen(marca)+1];
        strcpy(this->marca, marca);
    } else this->marca = NULL;
    strcpy(this->nr_inmatriculare,nr_inmatriculare);
    //this->pret=pret;

}

Masina::Masina(const Masina&car):Masina(car.marca, car.nr_inmatriculare, car. pret){
   /* if (car.marca != NULL){
        marca = new char[strlen(car.marca)+1];
        strcpy(marca,car.marca);
    } else marca = NULL;
    strcpy(nr_inmatriculare,car.nr_inmatriculare);
    pret=car.pret;*/

}

 Masina::~Masina(){
    delete[]marca;
 }

void Masina::afisare() const{

    if ( marca != NULL) cout << marca << "  ";
    else cout << "NULL  ";
    cout << nr_inmatriculare << "   ";
    cout << pret << endl;

 }

 void Masina::copie(const Masina&car){

    delete[]marca;
    if (car.marca != NULL){
        marca = new char[strlen(car.marca)+1];
        strcpy(marca,car.marca);
    } else marca = NULL;
    strcpy(nr_inmatriculare,car.nr_inmatriculare);
    pret=car.pret;

 }

 double Masina::getPret() const{
    return pret;
 }

 void Masina::citire() {

    char aux_marca[10];
    cin >> aux_marca;
    marca = new char[strlen(aux_marca)+1];
    strcpy(marca,aux_marca);
    cin >> nr_inmatriculare;
    cin >> pret;

 }

 char* Masina::getNrInt(){
    return nr_inmatriculare;
 }

 char* Masina::getMarca(){
    return marca;
 }

