#include <iostream>
#include <string.h>
#include "mystring.h"
#include <assert.h>
using namespace std;

MyString::MyString(){
    buf = NULL;
    l = 0;
}

MyString::MyString(char *strbuf){

    l = strlen(strbuf);
    if (l != NULL){
        buf = new char[l+1];
        strcpy(buf,strbuf);
    }

}

MyString::MyString(const MyString&str):MyString(str.buf){
};

MyString& MyString::operator=(const MyString&str){

    l = str.l;
    if (l != NULL){
        buf = new char[l];
        strcpy(buf,str.buf);
    }

}

MyString::~MyString(){
    delete[]buf;
}

MyString& MyString::operator+=(const MyString &str){

    if ( l == 0) // daca lungimea sirlui este 0, se atribuie atributele sirului s
        *this=str;
    else {
        char aux[(l+strlen(str.buf))+1];
        l=strlen(aux);
        strcpy(aux,buf);
        strcat(aux,str.buf);
        delete[]buf;
        buf = new char[l+1];
        strcpy(buf,aux);

        // COD Vechi
        /*
        char aux[l+1];
        strcpy(aux,buf);
        l += strlen(str.buf);
        delete[]buf;
        buf = new char[l+1];
        strcpy(buf,aux);
        strcat(buf,str.buf);
        */

    }
    return *this;
};

char& MyString::operator[](int i){
    assert (i >= 0 && i < this->l);
    return this -> buf[i];

}

int MyString::lookFor(char c)const {
    int car=0;
    if (l==0) // daca lungimea sirului este 0 returneaza automat 0
        return 0;
    else{
        for (int i=0;i<l;i++)
            if (buf[i]==c)
                car++;
        return car;
    }
}
