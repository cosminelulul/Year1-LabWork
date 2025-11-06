#include <iostream>
#include <string.h>

using namespace std;

int main()
{
   int l;
   cout << "l=" << "\n"; cin >> l;
   char sir[l];
   cin >> sir;
   for (int i=0;i<strlen(sir);i++)
        if (islower(sir[i]))
            sir[i] = toupper(sir[i]);
   cout << sir;

    return 0;
}
