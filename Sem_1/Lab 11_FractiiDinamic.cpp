#include <iostream>

using namespace std;

struct Fractie{
    int numitor,numarator;
};

void alocarea_Matricei(struct Fractie **&m, int l, int c){
    m=(struct Fractie**)malloc(l*sizeof(struct Fractie));
    for (int i=0;i<l;i++){
        m[i]=(struct Fractie*)calloc(c,sizeof(struct Fractie));
    }
}

void citirea_Matricei(struct Fractie **&m, int l, int c){

    for (int i=0;i<l;i++)
        for (int j=0;j<c;j++){
            cout << "Pentru valorea matricei matr[" << i+1 << "]" << "[" << j+1 << "] cititi fractia:" ;
            cin >> m[i][j].numarator >> m[i][j].numitor;
        }
}

void afisarea_Matricei(struct Fractie **&m, int l, int c){

    cout << endl << endl << "Matricea este egala cu:" << endl;
    for (int i=0;i<l;i++){
        for (int j=0;j<c;j++)
            cout << m[i][j].numarator << '/' << m[i][j].numitor << " ";
        cout << endl;
    }

}

double Raport(struct Fractie f){
    return (double)f.numarator/f.numitor;
}

int main()
{
    int m,n;
    cin >> m >> n;
    struct Fractie **matr;
    alocarea_Matricei(matr,m,n);
    citirea_Matricei(matr,m,n);
    afisarea_Matricei(matr,m,n);

    struct Fractie *v;
    v=(struct Fractie*)malloc(m*sizeof(struct Fractie));
    int contor=0;
    for (int i=0;i<m;i++){
        v[contor]=matr[i][i];
            contor++;
    }
    for (int i=0;i<m-1;i++)
        for (int j=i+1;j<m;j++){
            if (Raport(v[i])>Raport(v[j])){

                struct Fractie f_aux;
                f_aux.numarator=v[i].numarator;
                f_aux.numitor=v[i].numitor;

                v[i].numarator=v[j].numarator;
                v[i].numitor=v[j].numitor;

                v[j].numarator=f_aux.numarator;
                v[j].numitor=f_aux.numitor;


            }
        }

    cout << endl << endl<< "Vectorul sortat cu elementele de pe diag prin sunt:" << endl << endl;
    for (int i=0;i<m;i++)
        cout << v[i].numarator << '/' << v[i].numitor << " ";



    return 0;
}
