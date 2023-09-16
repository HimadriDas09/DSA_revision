#include<iostream>
using namespace std;

class A {
    public:
    void func() { cout << " func of A called " << endl; }
};

class B {
    public:
    void func() { cout << " func of B called " << endl; }
};

// inheritance ambiguity
class C: public A, public B {
    
};
 
int main()
{
    C obj;
    obj.A::func();
    obj.B::func();
    return 0;
}