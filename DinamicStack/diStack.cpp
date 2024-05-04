#include <iostream>
#include "diStack.h"
#include <cstddef>

using namespace std;

    diStack::diStack()
    {
        nodeTop = NULL;
    }

    diStack::~diStack()
    {
        node* nodeTemp;
        while (nodeTop != NULL){
            nodeTemp = nodeTop;
            nodeTop = nodeTop->proximo;
            delete nodeTemp;
        }
    }

    bool diStack::isFull()
    {
        node* newNode;
        try{
            newNode = new node;
            delete newNode;
            return false;
        } catch(bad_alloc exception){
            return true;
        }
    }

    bool diStack::isEmpty()
    {
        return (nodeTop == NULL);
    }

    void diStack::push(typeItem item) //push
    {
        if (isFull()){
            cout << "The stack is full!" << endl;
        } else {
            node* newNode = new node;
            newNode->valor = item;
            newNode->proximo = nodeTop;
            nodeTop = newNode;
        }
    }

    typeItem diStack::pop() //pop
    {
        if (isEmpty()){
            cout << "Stack is empty!" << endl;
        } else {
            node* nodeTemp;
            nodeTemp = nodeTop;
            typeItem item = nodeTop->valor;
            nodeTop = nodeTop->proximo;
            delete nodeTemp;
            return item;
        }
    }

    void diStack::print()
    {
        cout << "Stack: [ ";
        node* nodeTemp = nodeTop;
        while (nodeTemp != NULL){
            cout << nodeTemp->valor << " ";
            nodeTemp = nodeTemp->proximo;
        }

        cout << "]\n";
    }