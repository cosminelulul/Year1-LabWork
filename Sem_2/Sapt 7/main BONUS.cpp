#include <iostream>
#include <string.h>
#include "mystring.h"
using namespace std;

ostream& operator<<(ostream& dev, const MyString& str){
    dev << "Sirul este: ";
    if (str.buf!=NULL){
        dev << str.buf << endl;
        dev << "Lungimea sirului este: " << str.l << endl;
    }else{
        dev << "Sirul este: " <<  str.buf << endl;
        dev << "Lungimea sirului este: " << str.l << endl;
    }
    return dev;
}

istream& operator>>(istream& dev, MyString& str){
    char str_aux[256];
    cin >> str_aux;
    str.l = strlen(str_aux);
    str.buf = new char[str.l+1];
    strcpy(str.buf,str_aux);
    return dev;
}


bool operator==(const MyString &str1, const MyString &str2){
    //daca strcmp returneaza 0, nu are rost sa verific daca au aceiasi lungime
    if (strcmp(str1.buf,str2.buf)==0)
        return 1;
    else return 0;
}

bool operator!=(const MyString &str1, const MyString &str2){
    return !(str1==str2);
}




const MyString operator+(const MyString& str1, const MyString& str2){

    MyString retr;
    retr.l = str1.l + str2.l;
    if (retr.l !=0 ){
        retr.buf = new char[retr.l+1];
        strcpy(retr.buf,str1.buf);
        strcat(retr.buf,str2.buf);
    }
    return retr;
}


int main()
{
    MyString str1("sapun");
    //MyString str1;
    MyString str2("caine");
    MyString str3("pasare");
    MyString str4("cainepasare");
    MyString str5=(str2+str3);
    str1+=str2;
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str2+str3 << endl;
    if (str5==str4)
        cout << 1;
    else cout << 0;
    cout << endl << "Functia lookFor: " << str1.lookFor('a') << endl;
    for (int i=0;i<5;i++)
        cout << str1[i];

    return 0;
}
