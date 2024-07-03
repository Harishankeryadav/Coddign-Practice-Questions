#include <iostream>
#include "oops.cpp"
using namespace std;

int main()
{
string name = {"harry"}, name1 = {"hari"};
    student s1;
    student *s2 = new student;

    s1.check(105, 65);
    s1.getdata(11, name);
    s1.display(5);
    
    s2->check(123, 66);
    (*s2).getdata(12, name1);
    s2->display(4);
}