#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int n,cont=0;
    cout << "n:" << "\n"; cin >> n;
    char sir[n];
    cout << "sir:" << "\n"; cin >> sir;
    char duplicate[n]; strcpy(duplicate,"");
    for (int i=0; i<strlen(sir); i++){
        char aux = sir[i];
        for (int j=i+1; j < strlen(sir); j++ )
            if (sir[j]==aux && strchr(duplicate,aux) == 0 ){
                duplicate[cont]=aux;
                cont++;
                break;
               }
    }
    duplicate[cont]='\0';
    cout << duplicate;


    return 0;
}
