#include <iostream>
#include "student.h"

using namespace std;


int main()
{
    Student *s;
    int n;

    cin >> n;
    s = new Student[n];

    for (int i=0;i<n;i++)
        s[i].init();

    // ex 1

    for (int i=0;i<n;i++)
        s[i].citire();

    // ex 2
    for (int i=0;i<n;i++)
        s[i].afisare();


    // ex 3
    int index; char cgr[5];
    cin >> index;
    cin >> cgr;
    s[index].modificare(cgr);

    // ex 6

    for (int i=0;i<n;i++)
        if ( s[i].gpa() > s[i+1].gpa() ){
            Student aux;
            aux.modificare(s[i]);
            s[i].modificare(s[i+1]);
            s[i+1].modificare(aux);
        }

    for (int i=0;i<n;i++){
        s[i].afisare();
    }


    delete[]s;
    s=NULL;

    return 0;
}
