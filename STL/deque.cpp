/*Deque is two way data structure, here we are able to acces the data from front and end both
it is also dynamic in nature.

deque<data_type> class_name;         ->how to initialie.

d.push-back()                        -> both used to push the data in deque at last.
d.push-front()                        -> both used to push the data in deque from front.
d.begin()                            -> to fint the element present at first index.
d.last()                             -> element at last index
d.at()                               -> this function is used to find the element present at that index
d.size()                             -> total number of deque.
d.max_size()                         -> total size of deque / capacity.
d.erase(from where to, where)        -> used to erase the data, we have to specify the range
*/

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> d;

    cout << "Enter the element in vector" << endl;
    for (int i = 1; i <= 5; i++)
    {
        int n;
        cin >> n;
        d.push_back(n);
    }

    cout << "element present at first index " << d.front() << endl;
    cout << " element present at last index " << d.back() << endl;

    d.pop_back();
    cout << "element present at first index " << d.front() << endl;
    cout << " element present at last index " << d.back() << endl;

    d.pop_front();
    cout << "element present at first index " << d.front() << endl;
    cout << " element present at last index " << d.back() << endl;

    cout << "all elements are : ";
    for (int i = 0; i < d.size(); i++)
        cout << d[i] << " ";
    cout << endl;
    int n;
    cout << "enter the data to push at front " << endl;
    cin >> n;
    d.push_front(n);
    cout << "element present at first index " << d.front() << endl;
    cout << " element present at last index " << d.back() << endl;

    cout << "size of the deque is " << d.size() << endl;
    cout << "tota capacity of the deque " << d.max_size() << endl;

    cout << "all elements are : ";
    for (int i = 0; i < d.size(); i++)
        cout << d[i] << " ";
    cout << endl;

    cout << "empty or not " << d.empty() << endl;
    cout << "after erasing the data " << endl;
    d.erase(d.begin() + 1, d.begin() + 3);

    for (int i : d)
        cout << i << " ";
    cout << endl;
    cout << "all elements are : ";
    for (int i = 0; i < d.size(); i++)
        cout << d[i] << " ";
    cout << endl;
}