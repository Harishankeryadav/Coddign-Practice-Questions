#include <iostream>
#include <climits>
using namespace std;

template <typename T>
class stackUsingArray
{
    T *arr;
    int nextIndex;
    int capacity;

public:
    stackUsingArray()
    {
        arr = new T[4];
        nextIndex = 0;
        capacity = 4;
    }

    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    // void push(int data)
    // {

    //     if (nextIndex == capacity)
    //     {
    //         cout << "Stack is full " << endl;
    //         return;
    //     }
    //     arr[nextIndex] = data;
    //     nextIndex++;
    // }

    // dynamic memory allocation
    void push(T data)
    {
        if (nextIndex == capacity)
        {
            T *NewArray = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                NewArray[i] = arr[i];
            }
            delete[] arr;
            arr = NewArray;
        }
        arr[nextIndex] = data;
        nextIndex++;
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty " << endl;
            return 0;
        }
        nextIndex--;
        return arr[nextIndex];
    }

    T top()
    {
        return arr[nextIndex - 1];
    }
};