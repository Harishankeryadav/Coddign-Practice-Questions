#include <iostream>
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
        next = NULL;
    }
};

template <typename T>
class queue
{
    T size = 0;
    Node<T> *head = NULL;
    Node<T> *tail = NULL;

public:
    void enqueue(T data)
    {
        Node<T> *NewNode = new Node<T>(data);
        if (head == NULL)
        {
            head = NewNode;
            tail = NewNode;
        }
        else
        {
            tail->next = NewNode;
            tail = NewNode;
        }
        size++;
    }

    T front()
    {
        if (head == NULL)
        {
            return 0;
        }
        return head->data;
    }

    T dequeue()
    {
        if (head == NULL)
        {
            return 0;
        }
        size--;
        T num = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        return num;
    }

    int getsize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }
};