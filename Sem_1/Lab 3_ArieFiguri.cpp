#include <iostream>

using namespace std;

float returArie(int x1, int x2, int x3, int y1, int y2, int y3){
    int d1,d2;
    d1 = x1 * y2 * 1 + x2 * y3 * 1 + x3 * y1 * 1;
    d2 = 1 * y2 * x3 + 1* y3 * x1 + 1* y1 * x2;
    return 1 / 2.0 * (d1 - d2);
}

int main()
{
    int x1,x2,x3,x4,y1,y2,y3,y4;
    int a,b,c,d;
    int x,y,z;
    //13//
    cout << "ex 13 " << endl;
    a=4;b=3;

    cout << a / b << endl;
    cout << a/ float(b) << endl;

    //16
    cout << "ex 16 " << endl;

    cin >> x;
    (x % 2 == 0)?
        cout << 1 << endl:
    (x % 2 == 1 && x % 3 == 0 )?
            cout << 1  << endl:
    cout << 0 <<  endl;

    //17
    cout << "ex 17 " << endl;
    cin >> a >> b >> c >> d;

    (a >= 0 && b > 0)?
        cout << "fractia a/b pozitiva"  << endl:
    cout << "fractia a/b negativa" << endl;


    (c >= 0 && d > 0)?
        cout << "fractia c/d pozitiva" << endl:
    cout << "fractia c/d negativa"<< endl;

    ( a/b > c/d)?
        cout << "a/b > c/d" << endl:
    cout << "c/d > a/b" << endl;

    //20
    cout << "ex 20 " << endl;
    cin >> x >> y >> z;
    int c1,c2;
    c1 = x >= y;
    c2= z < x || z << y;
    (c1 == 1 && c2 == 1)?
        cout << "DA" << endl:
    cout << "NU" << endl;

    //BONUS EX 4
    cout << "ex 4 BONUS" << endl;

    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    int d1,d2;
    d1 = x1 * y2 * 1 + x2 * y3 * 1 + x3 * y1 * 1;
    d2 = 1 * y2 * x3 + 1* y3 * x1 + 1* y1 * x2;
    (d1 - d2 == 0)?
        cout << "nu formeaza triunghi" << endl:
    cout << "formeaza triunghi" << endl;

    //BONUS EX 5
    cout << "ex 5 BONUS" << endl;
    float a123,a124,a234,a134;

    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    cin >> x4 >> y4;

    a123=returArie(x1,x2,x3,y1,y2,y3);
    a124=returArie(x1,x2,x4,y1,y2,y4);
    a234=returArie(x2,x3,x4,y2,y3,y4);
    a134=returArie(x1,x3,x4,y1,y3,y4);

    float atotal= a124 + a234 + a134;

    (atotal - a123 < 0.01 )?
        cout << "(" << x4 << "," << y4 << ")" << "apartine triunghiului" << endl:
    cout << "(" << x4 << "," << y4 << ")" << "NU apartine triunghiului" << endl;



    return 0;
}
