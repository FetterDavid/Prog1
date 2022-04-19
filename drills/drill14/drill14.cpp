/*
    g++ drill141.cpp -o drill141g
*/
#include "../std_lib_facilities.h"
#include <stdlib.h>

class B1{
public:
    virtual void vf(){ cout << "B1::vf()\n"; }
    void f(){ cout << "B1::v()\n"; }
    virtual void pvf() = 0;
};

class D1 : public B1
{
public:
    void vf() override { cout << "D1::vf()\n"; }
    void f(){ cout << "D1::f\n"; }
    void pvf() override { cout << "D1::pvf()\n"; }
};

class D2 : public D1
{
public:
    void pvf() override { cout << "D2::pvf()\n"; }
};

class B2
{
public:
    virtual void pvf() = 0;
};

class D21 : public B2
{
public:
    void pvf() override { cout << data << endl; }
    string data;
};

class D22 : public B2
{
public:
    void pvf() override { cout << data << endl; }
    void f(B2& b2) { b2.pvf(); }
    int data;
};

int main()
try{
    /*cout << endl << "B1" << endl;
    B1 b1;
    b1.vf();
    b1.f();
    b1.pvf();*/

    cout << endl << "D1" << endl;
    D1 d1;
    d1.vf();
    d1.f();
    d1.pvf();

    cout << endl << "B1& = D1" << endl;
    B1& bd1 = d1;
    bd1.vf();
    bd1.f();
    bd1.pvf();

    cout << endl << "D2" << endl;
    D2 d2;
    d2.vf();
    d2.f();
    d2.pvf();

    cout << endl << "D22" << endl;
    D21 d21;
    d21.data = "string";

    D22 d222;
    d222.data = 101;

    D22 d22;
    d22.f(d21);
    d22.f(d222);

}catch(exception e){
    cerr << "Exception: " << e.what() << '\n';
}catch(...){
    cerr << "Exception!\n";
}