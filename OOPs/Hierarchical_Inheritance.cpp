#include<iostream>
using namespace std;

class A {
    public:
    void fun1() {
        cout << "fun 1 called" << endl;
    }
};

// inherit class A
class B: public A {
    public:
    void fun2() {
        cout << "fun 2 called" << endl;
    }
};

// inherit class A
class C: public A {
    public:
    void fun3() {
        cout << "fun 3 called" << endl;
    }
};
int main()
{
    A obj1;
    obj1.fun1();

    B obj2;
    obj2.fun1();
    obj2.fun2();

    C obj3;
    obj3.fun1();
    obj3.fun3();
    
    
    return 0;
}