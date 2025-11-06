#include <iostream>
using namespace std;


int prod(int n){

    if (n==0)
        return 1;
    else
        return n*prod(n-1);
}


int main()
{

    int n=4,p=1;
    cout << prod(n);

    return 0;
}
