#include <iostream>
#include "diQueue.h"
#include <cstddef>
#include <new>

using namespace std;

    diQueue::diQueue()
    {
        front = NULL;
        rear = NULL;
    }

    diQueue::~diQueue()
    {
        Node* temp;
        while (front != NULL){
            temp = front;
            front = front->next;
            delete temp;
        }
        rear = NULL;
    }

    bool diQueue::isEmpty()
    {
        return (front == NULL);
    }

    bool diQueue::isFull()
    {
        Node* temp;
        try
        {
            temp = new Node;
            delete temp;
            return false;
        }
        catch(bad_alloc exception)
        {
            return true;
        }
        
    }

    void diQueue::push(typeItem item)
    {
        if (isFull()){
            cout << "The queue is full!" << endl;
        }else {
            Node* newNode = new Node;
            newNode->value = item;
            newNode->next = NULL;
            if (front == NULL)
            {
                front = newNode;
            }else{
                rear->next = newNode;
            }
            rear = newNode;
        }
    }

    typeItem diQueue::pop()
    {
        if (isEmpty())
        {
            cout << "The queue is empty!" << endl;
            return 0;
        } else {
            Node* temp = front;
            typeItem item = front->value;
            front = front->next;
            if (front == NULL)
            {
                rear = NULL;
            }
            delete temp;
            return item;
        }
        
    }

    void diQueue::print()
    {
        Node* temp = front;
        cout << "[ ";
        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << "]\n";
    }
