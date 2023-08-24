#include <iostream>
using namespace std;

template <typename T>
class pair
{
public:
    T first;
    T second;
    pair(T first, T second)
    {
        this->first = first;
        this->second = second;
    }
};