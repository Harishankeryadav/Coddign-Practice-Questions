/*vector is somewhat simmilar to array.
 it is dynamic in nature.




  vector<int> v;                  initialization os a vector.
  vector<int> v1(5, 1);           here we have given the size of vector and initialized each indexs with 1 default value is 0.
  vector<int> v2(v);              we are coping all the data of v into v2.

  v.push_back(5);                 it is used to push the data in.
  v.pop_back();                   it is used to pop the data.
  v.front();                      gives the topmost element
  v.rbegin();                     it gives the last elements address
  v.end();                        it gives the address of last to the next index
  v.rend();                       it gives the address of prev of first index.
  v.size();                       gives the size of the vector or total no. of element present in vector.
  v.capacity();                   gives the total capacity of the vector.

  v.clear();                      clears all the element of form the indexs and inithilizes with given or default value.
  v.at(index_no.)                 we can acces the data availabe at that index.
  v.empty()                       vector is empty or not.  0 -> false, 1 -> true.
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    cout << "Enter the element in vector" << endl;
    for (int i = 1; i <= 5; i++)
    {
        int n;
        cin >> n;
        v.push_back(n);
    }

    cout << "Element in vector are : " << endl;
    for (auto i : v)
        cout << i << " ";
    cout << endl;

    vector<int> v2(5, 1);
    for (int &i : v)
    {
        // i = 9;
        cout << i << " ";
    }
    cout << endl;

    cout << "by using at() function " << v.at(3) << endl;

    cout << "size of the vector is : " << v.size() << endl;
    cout << "capacity of the vector is : " << v.capacity() << endl;

    cout << "topmost element is(by using front function) : " << v.back() << endl;

    v.pop_back();

    cout << "topmost element element after pop_back : " << v.back() << endl;
    v.pop_back();
    v.pop_back();
    cout << "topmost element element after pop_back : " << v.back() << endl;
    cout << "size of the vector is : " << v.size() << endl;
    cout << "capacity of the vector is : " << v.capacity() << endl;

    vector<int> v1(v);
    for (int i : v1)
        /*this kind of for can only be used when the function is aumatically initialize  and it has auto-defined size also*/
        cout << i << " ";
    cout << endl;

    cout << "empty function  " << v.empty() << endl;

    cout << "size of the vector is : " << v.size() << endl;
}