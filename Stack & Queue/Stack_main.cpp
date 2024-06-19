#include <iostream>
#include <climits>
using namespace std;

class stackUsingArray
{
    int *arr;
    int nextIndex;
    int capacity;

public:
    stackUsingArray()
    {
        arr = new int[4];
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
    void push(int data)
    {
        if (nextIndex == capacity)
        {
            int *NewArray = new int[2 * capacity];
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

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty " << endl;
            return INT_MIN;
        }
        nextIndex--;
        return arr[nextIndex];
    }

    int top()
    {
        return arr[nextIndex - 1];
    }
};