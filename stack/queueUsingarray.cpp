// #include <iostream>
// #include <climits>
// using namespace std;

// class queue_using_array
// {
//     int firstindex;
//     int size;
//     int *array;
//     int nextindex;
//     int arrsize = -1;

// public:
//     queue_using_array(int size)
//     {
//         array = new int(size);
//         nextindex = 0;
//         firstindex = 0;
//         this->size = size;
//     }

//     void push(int data)
//     {

//         if (arrsize == size)
//         {
//             cout << "In size double " << endl;
//             int *newarray = new int[2 * size];
//             int i = 0;
//             int j = firstindex;
//             while (firstindex < size)
//             {
//                 newarray[i] = array[j];
//                 i++;
//                 j++;
//                 firstindex++;
//             }
//             j = 0;
//             while (j < nextindex)
//             {
//                 array[i] = array[j];
//                 i++;
//                 j++;
//             }
//             firstindex = 0;
//             nextindex = size;
//             size = 2 * size;
//             delete[] array;
//             array = newarray;
//         }

//         array[nextindex] = data;
//         nextindex++;
//         // nextindex = (nextindex + 1) % arrsize;
//         // if (nextindex == -1)
//         // {
//         //     nextindex = 0;
//         // }
//         arrsize++;
//     }

//     int pop()
//     {
//         if (arrsize < 0)
//         {
//             cout << "Queue is empty ";
//             return INT_MIN;
//         }
//         int num = array[firstindex];
//         firstindex++;
//         arrsize--;
//         return num;
//     }

//     int front()
//     {
//         if (arrsize < 0)
//         {
//             cout << "Queue is empty ";
//             return INT_MIN;
//         }
//         return array[firstindex];
//     }

//     int getsize()
//     {
//         return arrsize + 1;
//     }

//     bool isEmpty()
//     {
//         return size >= 0;
//     }
// };




#include <iostream>
#include <climits>
using namespace std;

class queue_using_array
{
    int firstindex;
    int capacity;
    int *array;
    int nextindex;
    int arrsize = -1;

public:
    queue_using_array(int size)
    {
        array = new int(size);
        nextindex = 0;
        firstindex = 0;
        this->capacity = capacity;
    }

    void push(int data)
    {

        if (arrsize == capacity)
        {
            cout << "In size double " << endl;
            int *newarray = new int[2 * capacity];
            int i = 0;
            int j = firstindex;
            while (firstindex < capacity)
            {
                newarray[i] = array[j];
                i++;
                j++;
                firstindex++;
            }
            j = 0;
            while (j < nextindex)
            {
                array[i] = array[j];
                i++;
                j++;
            }
            firstindex = 0;
            nextindex = capacity;
            capacity = 2 * capacity;
            delete[] array;
            array = newarray;
        }

        if (nextindex == arrsize && arrsize != capacity)
        {
            nextindex = 0;
        }
        array[nextindex] = data;
        nextindex++;

        arrsize++;
    }

    int pop()
    {
        if (arrsize < 0)
        {
            cout << "Queue is empty ";
            return INT_MIN;
        }
        int num = array[firstindex];
        firstindex++;
        arrsize--;
        return num;
    }

    int front()
    {
        if (arrsize < 0)
        {
            cout << "Queue is empty ";
            return INT_MIN;
        }
        return array[firstindex];
    }

    int getsize()
    {
        return arrsize + 1;
    }

    bool isEmpty()
    {
        return capacity >= 0;
    }
};