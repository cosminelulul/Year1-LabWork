#include <iostream>

using namespace std;

void incrementare(int &a, int &b, int &c){
    a+=1;b+=2;c+=5;
}


int main()
{

    int a,b,c;
    cin >> a >> b >> c;
    incrementare(a,b,c);
    cout << "a=" << a << " " << "b=" << b << " " << "c=" << c << "\n";

    return 0;
}
