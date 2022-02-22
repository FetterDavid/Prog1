/*
    g++ drill14.cpp -o drill14
*/
#include "../../source/std_lib_facilities.h"
#include <stdlib.h>

class B1{
public:
    virtual void vf(){
        cout << "B1::vf()\n";
    }
    virtual void pvf(){
        cout << "B1::pvf()\n";
    }
    void f(){
        cout << "B1::f()\n";
    }
};

class D1 : public B1{
public:
    void vf(){
        cout << "D1::vf()\n";
    }

    void f(){
        cout << "D1::f()\n";
    }
};

class D2 : public D1{
public:
    void pvf(){
        cout << "D2::pvf()\n";
    }
};

int main()
{
    B1 b1;
    b1.vf();
    b1.f();
    b1.pvf();

    cout << "\n";

    D1 d1;
    d1.vf();
    d1.f();
    d1.pvf();

    cout << "\n";

    B1& b2 = d1;
    b2.vf();
    b2.f();
    b2.pvf();

    cout << "\n";

    D2 d2;
    d2.vf();
    d2.f();
    d2.pvf();

    return 0;
}
