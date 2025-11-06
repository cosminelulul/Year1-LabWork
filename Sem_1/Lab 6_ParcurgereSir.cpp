#include <iostream>

using namespace std;

int main()
{

    char sir[256];
    cin >> sir;
    char *p; p=&sir[0];
    while (*p!='\0'){
        cout << *p; p++;
    }
    return 0;
}
