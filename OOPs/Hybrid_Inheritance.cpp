#include<iostream>
using namespace std;

/* combination of diff types of inheritance */
class A {
    public:
    void funA(){ cout << "funA called" << endl; } 
};

class D {
    public:
    void funD(){ cout << "funD called" << endl; } 
};

// B and C inherit from A : Hierarchical Inheritance
class B: public A {
    public:
    void funB(){ cout << "funB called" << endl; } 
};

// C inherit from A,D : multiple inheritance
class C: public A, public D {
    public:
    void funC(){ cout << "funC called" << endl; } 
};



int main()
{
    C objc;
    objc.funC();
    objc.funD();
    objc.funA();
    
    return 0;
}