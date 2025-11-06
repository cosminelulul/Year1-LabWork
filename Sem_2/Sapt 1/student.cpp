#include "student.h"
#include <string.h>
#include <iostream>

using namespace std;


//Metode de aplicare ineficiente:

void  Student::init(){

    id = 0;
    nume = NULL;
    strcpy(gr,"0000");
    for (int i=0;i<6;i++)
        note_sem_I[i]=0;

}

void Student::afisare() const {
    cout << "ID: " <<  id << endl;
    cout << "Nume:";
    if (nume != NULL) cout << nume;
    cout << endl;
    cout << "Grupa: " << gr << endl;
    cout << "Notele sem I: ";
    for (int i=0;i<6;i++)
        cout << note_sem_I[i] << " ";
    cout << endl;

}

void Student::citire(){

    cout << "ID:"; cin >> id;

    char aux_nume[25];
    cout << "Nume:"; cin >> aux_nume;
    nume = new char[strlen(aux_nume)+1];
    strcpy(nume,aux_nume);

    cout << "Gr:"; cin >> gr;

    cout << "Note sem I";
    for (int i=0;i<6;i++)
        cin >> note_sem_I[i];

}

void Student::modificare(char modgr[]){
    strcpy(gr,modgr);
}

void Student::modificare(const Student &c){

    // id
    id = c.id;

    // nume
    delete[]nume;
    nume = NULL;
    if (c.nume!=NULL){
        nume = new char[strlen(c.nume)+1];
        strcpy(nume,c.nume);
    }

    // gr
    strcpy(gr,c.gr);

    //note sem I
    for (int i=0;i<6;i++)
        note_sem_I[i] = c.note_sem_I[i];

}

void Student::modificare(int poz, int nota){
    note_sem_I[poz] = nota;
}

double Student::gpa(){
    int suma=0;
    for (int i=0;i<6;i++)
       suma+=note_sem_I[i];
    return double(suma/6.0);
}

