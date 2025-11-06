#include <iostream>
using namespace std;


int main(){

    //VARIABILE
    char car;
    int n,x,y,z,w,s=0,p=1;
    int pdo=p,pwhile=p,tn;


    //EX 6
    cin >> car;
    //cout << int('s') << " " << int('p') << " " << int('x') << endl;
    //115 //112 //120

    switch(int(car)){
    case 115:
        cout << "Introduce n" << endl;
        cin >> n;
        for(int i=1;i<=n;i++)
            s+=i;
        cout << "Suma=" << s << endl;
        break;
    case 112:
        cout << "Introduce n" << endl;
        cin >> n;
        for(int i=1;i<=n;i++)
            p*=i;
        cout << "Produsul=" << p << endl;
        break;
    case 120:
        cout << "Introduce n" << endl;
        cin >> n;
        (n%2==0)?
            cout << "n=" << n << " este par" << endl:
        cout << "n=" << n << " este impar" << endl;
        break;
    default:
        cout << "aceasta nu este o comanda valida" << endl;
        break;
    }

    //EX 9
    cout << "n!=0; n=" << endl;
    cin >> n; p = 1;
    tn=n;


    cout << "varianta for" << endl;
    for (int i = 1 ; i <= n; i++){
            cout << "x(" << i << ")=";cin >> x;cout << endl;
            p*=x;
            }
    cout << "varianta while" << endl;
    while (n>0) {
            cout << "x(" << n << ")=";cin >> x;cout << endl;
            pwhile*=x;
            n--;
        }
    n=tn;
    cout << "varianta do" << endl;
    do{
        cout << "x(" << n << ")=";cin >> x;cout << endl;
        pdo*=x;
        n--;
    }while (n>0);
    cout << "p(for)=" << p << " p(while)=" << pwhile << " p(do)=" << pdo << endl;


    //EX 13
    x=0;y=1;z=0;w=0;

    for (int i=1 ; i<=6 ; i++){
        cout << "Scrie n" << endl;
        cin >> n;
        x+=n;y*=n;
        (n%2==0)?
            z++:
        w++;
    }

    cout << "x=" << x << endl;
    cout << "y=" << y << endl;
    cout << "z=" << z << endl;
    cout << "w=" << w << endl;


    //EX 17
    cout << "n=" << endl;
    cin >> n;
    s=0;
    for (int i=1;i<n;i++){
        if (i%7!=0)
            s+=i;
        else continue;
    }
    cout << "s=" << s << endl;

    //EX 19
    cout << "n=" << endl;
    cin >> n;

    s=0;
    for (int i=1;i<n;i++){
        s+=i;
        if (s%11==0)
            break;
    }
    cout << "s=" << s << endl;


    //EX 4
    for (int i=100; i <= 999; i++){

        int nrdiv=2;

        for (int j=2;j<i/2;j++)
            if (i%j==0){
                nrdiv++;
                    if (nrdiv==7)
                        break;
            }

        if (nrdiv>=7)
            cout << i << " ";


    }

}
