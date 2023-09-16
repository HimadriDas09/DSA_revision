#include<iostream>
using namespace std;

class A {
    public:

    void sayHello(char name, int n) {
        cout << "say hello" << endl;
    }
    // method overloading: application of compile time polymorphism
    void sayHello(string name) {
        cout << "say hello " << name << endl;
    }
};

class B {
    public:
    int a;
    int b;

    int add() {
        return a+b;
    }

    // operator overloading on +
    void operator + (B &obj) {
        int value2 = obj.a;
        int value1 = this->a;

        cout << "output " << value1-value2 << endl;
    }
};

class Animal {
    public:
    void speak() {
        cout << "speaking" << endl;
    }
};

class Dog: public Animal {
    public:
    // method overriding (for this Inheritance is MUST): application of runtime polymorphism
    void speak() {
        cout << "barking" << endl;
    }
};

int main()
{
    Dog d;
    d.speak();

    // B obj1, obj2;
    // obj1.a = 4;
    // obj2.a = 7;
    // // opertor overloading : application of compile time polymorphism
    // obj1+obj2;

    // A obj;
    // obj.sayHello('g', 23);
    // obj.sayHello("himadri das");

    return 0;
}