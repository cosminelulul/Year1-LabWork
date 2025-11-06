#include <iostream>
#include <cmath>
using namespace std;

double delta(int a,int b,int c){
    float delta=(b*b)-4*a*c;
    return delta;
}

void sol_ec_II(int a, int b,int c,float &x1,float &x2){
    x1=((0-b)+sqrt(delta(a,b,c)));
    x2=((0-b)-sqrt(delta(a,b,c)));
}

int main()
{
    int a,b,c;
    float x1,x2;
    cout << "Introduce parametrii unei functii de forma ax2+bx+c" << endl;
    cin >> a >> b >> c;
    sol_ec_II(a,b,c,x1,x2);
    cout << "x1=" << x1 << " " << "x2=" << x2;

    return 0;
}
