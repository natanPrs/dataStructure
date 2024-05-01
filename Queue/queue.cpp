#include <iostream>
#include "queue.h"
using namespace std;

    queue::queue()
    {
        front = 0;
        rear = 0;
        structure = new typeItem[max_itens];
    }

    queue::~queue()
    {
        delete [] structure;
    }

    bool queue::isEmpty()
    {
        return(front == rear);
    }

    bool queue::isFull()
    {
        return(rear - front == max_itens);
    }

    void queue::push(typeItem item)
    {
        if (isFull()){
            cout << "queue cheia!\n";
        }else {
            structure[rear % max_itens] = item;
            rear++;
        }
    }

    typeItem queue::pop()
    {
        if(isEmpty()){
            cout << "queue empty!\n";
        }else {
            front++;
            return structure[(front-1) % max_itens];
  
        }
    }

    void queue::print()
    {
        cout << "queue: [";
        for (int i = front; i < rear; i++)
        {
            cout << structure[i % max_itens] << " ";
        }
        cout << "]\n";
    }
