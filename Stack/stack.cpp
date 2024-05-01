#include <iostream>
#include "stack.h"
using namespace std;

    stack::stack(){
        size = 0;
        structure = new typeItem[max_itens];
    }

    stack::~stack(){
        delete [] structure;
    }

    bool stack::isFull(){
        return(size == max_itens);
    }

    bool stack::isEmpty(){
        return(size == 0);
    }

    void stack::push(typeItem item){ 
        if (isFull()){
            cout << "Stack is full!" << endl;
        }else{
            structure[size] = item;
            size++;
        }
    }

    typeItem stack::pop(){ 
        if(isEmpty()){
            cout << "Stack is empty!";
        }else {
            size --;
            return structure[size];
        }
    }
    void stack::print(){
        cout << "stack: [";
        for (int i = 0; i < size; i++){
            cout << structure[i] << " ";
            cout << "]";
        }
        
    }

    int stack::whichSize(){
        return size;
    }

