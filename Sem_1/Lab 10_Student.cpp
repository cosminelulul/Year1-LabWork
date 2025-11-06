#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct Student{

    char *nume;
    int note[4];

};

void CitDateStudenti(struct Student *v, int cont){

    // nume

    char aux_nume[30];
    cout << "Cititi numele studentului:" << endl;
    cin >> aux_nume;
    v[cont].nume=(char*)malloc((strlen(aux_nume)+1)*sizeof(char));
    strcpy(v[cont].nume,aux_nume);

    cout << "Cititi numele studentului:" << endl;
    for (int i=0;i<4;i++){
        cout << "Cititi nota nr" << i+1 << ":" << endl;
        cin >> v[cont].note[i];
    }
}

double ReturMedie(struct Student *v,int cont){

    int s=v.note[0]+v.note[1]+v.note[2]+v.note[3]+v.note[4];
    return (s/5.0)

}

void sortare(struct Student *&v , int n){

    int auxi;
    for (int i=0;i<n-1;i++){
        auxi=i;
        for (int j=i+1;j<n;j++)
            if (ReturMedie(v,j)<ReturMedie(v,auxi))
                auxi=j;

        char aux_nume=v[auxi].nume;
        int auxv[4];
        for (int i=0;i<4;i++){
            auxv[i]=v[auxi].note[i];
        }

        v[auxi].nume= v[i].nume;
        for (int i=0;i<4;i++){
            v[auxi].note[i]=v[i].note[i];
        }

        v[i].nume= nume;
        for (int i=0;i<4;i++){
            v[i].note[i]=auxv[i];
        }
    }
}



int main()
{

    int n; cout << "n:";
    cin >> n;
    struct Student *v;
    v=(struct Student*)malloc(n*sizeof(struct Student));

    for (int j=0;j<n;j++)
        CitDateStudenti(v,j);

     int media_max=0,media_aux,contor_student=0;
     for (int i=0;i<n;i++){

        media_aux=ReturMedie(v,i);
        if (media_max<media_aux){
            contor_student=i;
            media_max=media_aux;
        }

     }

     cout << "Studentul cu cea mai mare medie este:" << endl;
     cout << v[contor_student].nume << "cu media " << media_max;



    return 0;
}
