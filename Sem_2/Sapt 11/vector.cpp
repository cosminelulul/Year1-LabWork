#include <assert.h>
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class vector
{
    int dim;
    T* buf;
public:
    vector();
    vector(int, T*);
    vector(int d):dim(d){
    buf = new T[dim];
    };
    vector(const vector&);
    vector & operator=(const vector &);
    ~vector();
    T& operator[](int i) const;
    int getDim() const;

    friend ostream & operator << (ostream & dev,  vector & v)
    {
        dev << "Vector:" <<endl;
        dev << "Nr Elem:" << v.dim << endl;
        if (v.buf!=NULL)
            for(int i = 0; i < v.dim; i++)
            {
                dev << v.buf[i];//am nevoie de op<< pt T
                if(i < v.dim-1)
                    dev << ",   ";
                else
                    dev << "." << endl;
            }
        dev<<endl;
        return dev;
    }

    friend const vector<T> operator+( const vector<T>&v1, const vector<T>&v2){

        int dim = (v1.dim + v2.dim);
        vector<T> vector_concat(dim);
        for (int i = 0;i < v1.dim;i++)
            vector_concat[i] = v1[i];
        for (int i = 0;i < v2.dim;i++)
            vector_concat[v1.dim+i] = v2[i];

        return vector_concat;
    }
    vector<T>& operator+=( const vector<T>&v2){

        vector<T> vector_concat(dim);
        vector_concat = (*this+v2);
        *this = vector_concat;
        return *this;
    }

    vector<T> getSet(){

        int nondup = dim;
        for (int i = 0; i < dim;i++)
            for (int j = i+1; j < dim;j++)
                if ( (*this)[i] == (*this)[j] )
                    nondup--;


        vector<T>vector_modif(nondup);
        int k = 0;
        for (int i = 0; i < dim;i++){
            bool cond = true;
            for (int j = i+1; j < dim;j++)
                if ( (*this)[i] == (*this)[j] ) cond = false;
            if (cond == true){
                vector_modif[k] = (*this)[i];
                k++;
            }

        }
        return vector_modif;
    }

};

template <typename T>
vector<T>::vector( )
{
    dim=0;
    buf=NULL;
}

template <typename T>
vector<T>::vector(int d, T*b)
{
    dim=d;
    if (b==NULL) buf = NULL;
    else
    {
        buf=new T[dim]; //constr fara param in T
        for (int i=0; i<dim; i++)
            buf[i]=b[i]; //op= in T
    }
}


template <typename T>
vector<T>::vector(const vector<T>& v)
{
    dim=v.dim;
    if (v.buf==NULL) buf=NULL;
    else
    {
        buf=new T[dim]; //constr fara param in T
        for (int i=0; i<dim; i++)
            buf[i]=v.buf[i]; //op= in T
    }
}


template <typename T>
vector<T>::~vector()
{
    delete [] buf; //destr in T
}

template <typename T>
vector<T>&  vector<T>::operator=(const vector &v)
{
    dim=v.dim;
    if (buf!=NULL) delete [] buf; //destr in T
    if (v.buf==NULL) buf=NULL;
    else
    {
        buf=new T[dim]; //constr fara param in T
        for (int i=0; i<dim; i++)
            buf[i]=v.buf[i]; //op= in T
    }
    return *this;
}

template <typename T>
T& vector<T>::operator[](int i) const
{
    assert ((i>-1 && i<dim));
    return buf[i];  //constr de copiere in T
}

template <typename T>
int vector<T>::getDim() const
{
    return dim;
}

class complex
{
    double re,im;
public:
    complex(double r=0,double i=0):re(r),im(i)
    {
    }

    friend ostream& operator<<(ostream &d,complex x)
    {

        d<<x.re<<" j"<<x.im;
        return d;
    }

};

template <typename X, typename Y = double>
class pereche{
    X elem1;
    Y elem2 = 1;
    public:
        pereche() = default;
        pereche(const X &e1, const Y &e2):elem1(e1),elem2(e2){};
        friend ostream& operator<<(ostream &d,const pereche &x){
            d << x.elem1 <<"  si " << x.elem2<<endl;
            return d;
        }
        friend istream& operator>>(istream &d,pereche &x){
            d >> x.elem1 >> x.elem2;
            return d;
    }
};

class Student{
    string nume = "NoName";
    string grupa = "1300";
public:
    Student() = default;
    Student(string name,string group):nume(name),grupa(group){};
    friend ostream& operator<<(ostream &d,const Student &stud){
            d << stud.nume << " " << stud.grupa;
            return d;
        }
    friend istream& operator>>(istream &d,Student &stud){
            d >> stud.nume >> stud.grupa;
            return d;
    }

};

int main()
{

    /*complex *b=new complex[2];
    b[0]=complex(1,2);
    b[1]=complex(2,2);
    vector<complex> v(2,b);
    cout<<v;

    //cout<<v[0];

    v[1]=complex(5,5);
    cout<<v;

    vector<complex> v1(v);
    cout<<v1;

    v=v1;
    cout<<v;
    */

    cout << "/////////////////////////////////////////////////////////////////////////////////" << endl;

    int vect1[2] = {1,2};
    string vect2[3] = {"Am","inca","ore"};

    vector<int>test_v(2,vect1);
    cout << test_v;

    vector<string>test_v2(3,vect2);
    cout << test_v2;

    int vectplustest1[5] = {1,2,3,4,5};
    int vectplustest2[3] = {6,7,8};
    int vectplustest3[3] = {11,12,13};
    int vectplustest4[8] = {10,11,11,12,13,14,15,15};

    vector<int>adunaretest1(5,vectplustest1);
    vector<int>adunaretest2(3,vectplustest2);
    vector <int>adunaretest3(8);
    vector<int>adunaretest4(3,vectplustest3);
    vector<int>vectDupeTest1(8,vectplustest4);
    vector<int>vectDupeTest2;
    adunaretest3 = (adunaretest1+adunaretest2);
    cout << adunaretest3;
    adunaretest4+=adunaretest2;
    cout << adunaretest4;
    vectDupeTest2 = vectDupeTest1.getSet();
    cout << vectDupeTest2;


    int n = 4;
    vector<pereche<Student,double>> catalog(n);
    //cout << catalog;
    cout << "/////////////////////////////////vector afisare//////////////////////////////////" << endl;
    for (int i = 0;i<n;i++)
        cout << catalog[i];
    cout << "/////////////////////////////////vector citire//////////////////////////////////" << endl;
    for (int i = 0;i<n;i++)
        cin >> catalog[i];
    cout << "/////////////////////////////////vector afisare//////////////////////////////////" << endl;
    for (int i = 0;i<n;i++)
        cout << catalog[i];
   // cout << catalog;

    return 0;
}




