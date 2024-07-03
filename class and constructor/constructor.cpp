// making constructor and using initialization list. it is used to pass or change
// the data fo a constant and refrence variable

#include <iostream>
#include <string.h>
using namespace std;

class constructor
{
    const int age;

public:
    char *name;
    // passinng the value to a constant varible => this->variable(parameter)
    constructor(int age, char *name) : age(age)
    {
        // this->age = age;
        //  shallow coping, we must avoid it because it can be change and data is not safe.
        //  this->name = name;

        // deep coping.
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    // copy constructor.
    constructor(constructor const &s1) : age(s1.age)
    {
        // this->age = s1.age;
        //  shallow coping, we must avoid it because it can be change and data is not safe.
        //  this->name = s1.name;

        // deep coping.
        this->name = new char[strlen(s1.name) + 1];
        strcpy(this->name, s1.name);
    }
    void display()
    {
        cout << age << " " << name << endl;
        ;
    }
};