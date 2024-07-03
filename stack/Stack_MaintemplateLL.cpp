#include <iostream>
// #include "LL_Main.cpp"
using namespace std;
template <typename T>

class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class StackUsingLL
{
    int size = 0;
    T data;
    Node<T> *head = NULL;

public:
    void push(T data)
    {
        Node<T> *NewHead = new Node<T>(data);
        NewHead->next = head;
        head = NewHead;
        size++;
    }

    T pop()
    {
        if (head == NULL)
        {
            return 0;
        }
        T num = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return num;
    }

    T top()
    {
        if (head == NULL)
        {
            return 0;
        }
        return head->data;
    }

    int getsize()
    {
        return size;
    }

    int isEmpty()
    {
        return size == 0;
    }
};