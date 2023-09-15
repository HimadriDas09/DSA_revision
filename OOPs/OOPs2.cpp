#include<iostream>
using namespace std;

class Human{
    protected:
    int height;
    int weight;

    private:
    int age;

    int getAge() {
        return this->age;
    }

    void setAge(int age) {
        this->age = age;
    }
};

// inheriting Human class
class Male : public Human{
    public:
    string color;

    void sleep() {
        cout << "Male Sleeping" << endl;
    }
    
    /* for mode of child class to be protected: inherited data members being public, protected are inherited as protected, while private members are inherited as private 
    
    But for super class members as private, with any mode, we cannot access them even within sub class 

    int getAge() {
        return this->age;
    }
    age is inaccessible
    */

    int getHeight() {
        return this->height;
    }

    void changeHeight(int height) {
        this->height = height;
    }
};  

int main()
{
    Male m1;
    m1.changeHeight(180);
    cout << m1.height << endl; 
    cout << m1.getHeight() << endl;


    return 0;
}