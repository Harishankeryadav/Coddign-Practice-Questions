#include <iostream>
#include <climits>
using namespace std;

class stackUsingArray
{
    int *arr;
    int nextIndex;
    int capacity;

public:
    stackUsingArray(int totalsize)
    {
        arr = new int[totalsize];
        nextIndex = 0;
        capacity = totalsize;
    }

//gives the size of the array
    int size()
    {
        return nextIndex;
    }
//gives the details weather the array is empty or not
    bool isEmpty()
    {
        return nextIndex == 0;
    }
//pushes the element on top of the list 
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


//pops the element from the topmost of the list
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
//always prints the topmost element 
    int top()
    {
        return arr[nextIndex - 1];
    }
};