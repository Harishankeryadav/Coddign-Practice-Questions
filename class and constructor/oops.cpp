#include <iostream>
#include <string>
using namespace std;
class student
{
private:
    int Id;

public:
    int roll_num;
    string name;

    void check(int pass, int id)
    {
        if (pass != 123)
        {
            cout << "wrong password \n";
            return;
        }
        Id = id;
    }

    void getdata(int roll, string s)
    {
        roll_num = roll;
        name = s;
    }

    void display(int len)
    {
        cout << "Name is ";
            cout << name;
        cout << ", id is " << Id << " and roll number is " << roll_num << endl;
    }
};