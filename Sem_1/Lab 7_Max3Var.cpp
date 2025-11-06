#include <iostream>

using namespace std;

int maxi(int a, int b , int c){

    int d=a;
    if (d<b || d<c)
        if (b>c)
            d=b;
        else d=c;
    return d;
}

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    cout << maxi(a,b,c);

    return 0;
}
