#include<iostream>
#include<cstring>
using namespace std;

class Hero {
    
    int health;

    public:
    char level;
    char* name;
    static int timeToComplete; /* static members belongs to a class and not to it's objects, i.e unique to a particular class */

    // default constructor
    Hero() {
        cout << "Default Constructor called!" << endl;
        name = new char[100];
    }

    // parameterized constructor
    Hero(int health) {
        cout << "Parameterized Constructor called!" << endl;
        cout << "this -> " << this << endl;
        this->health = health;
    }
    Hero(int health, char level) {
        this->health = health;
        this->level = level;
    }

    // copy contructor
    Hero(Hero &temp) {
        cout << "Copy Constructor called!" << endl;

        // deep copy : i.e not assigning reference but storing at a new memory location
        char* ch = new char[strlen(temp.name)];
        strcpy(ch, temp.name);
        this->name = ch;

        this->health = temp.health;
        this->level = temp.level;
    }

    void print() {
        cout << " [ name: " << this->name << ", "; 
        cout << "level : " << this->level << ", ";
        cout << "health : " << this->health << " ] " << endl;
        cout << endl;
    } 

    // getters and setters
    void setHealth(int h) {
        health = h;
    }

    int getHealth() {
        return health;
    }

    void setLevel(char ch) {
        level = ch;
    }

    char getLevel() {
        return level;
    }

    void setName(char* name) {
        strcpy(this->name, name);
    }

    // static function : can only access static members
    static int random() {
       return timeToComplete;
    }

    ~Hero() {
        cout << "destructor called" << endl;
    }
};

// initialization of static member
/* data_type class_name :: field_name = value; */
int Hero::timeToComplete = 5;

int main()
{
    cout << Hero::timeToComplete << endl;

    cout << Hero::random() << endl;




    // Hero a, b;
    // /* we can BUT it's not recommended to access static members via object of class */
    // cout << a.timeToComplete << endl;

    // a.timeToComplete = 10;
    // cout << a.timeToComplete << endl;
    // cout << b.timeToComplete << endl;




    // Hero hero1;
    // hero1.setHealth(12);
    // hero1.setLevel('D');
    // char name[10] = "himadri";
    // hero1.setName(name);

    // // hero1.print();

    // Hero hero2 = hero1; // using copy contructor
    // // hero2.print();

    // // changing property values of hero1, since default copy constructor is used to copy hero1 into hero2, which uses shallow copy, so changing hero1 will change hero2 too

    // hero1.name[0] = 'N';
    // hero1.print();

    // hero2.print();

    // // using copy assignment operator
    // hero1 = hero2;

    // hero1.print();

    // hero2.print();




    // Hero S(78, 'A');
    // S.print();

    // // copy contructor
    // Hero R(S);
    // R.print();





    // statically creating obj
    // Hero ramesh;

    // Hero suresh(78);

    // /* this contains the address of the cur object */
    // cout << "Cur object address : " << &suresh << endl;

    // Hero rajesh(100);
    // cout << "Cur object address : " << &rajesh << endl;


    // cout << "size: " << sizeof(ramesh) << endl;
    /* padding and greedy algorithm: reason why even though 1 char and 1 int is present in object, yet the size of object is 8 instead of 5 */

    // ramesh.setHealth(78);
    // ramesh.setLevel('B');

    // cout << "ramesh's health : " << ramesh.getHealth() << endl; 
    // cout << "ramesh's level : " << ramesh.getLevel() << endl;

    // // dynamically creating obj
    // Hero* b = new Hero; 
    // // 2 ways to access public properties
    // (*b).setHealth(90);
    // cout << "b's health : " << (*b).getHealth() << endl;

    // b->setLevel('C');
    // cout << "b's level : " << b->getLevel() << endl;

    return 0;
}