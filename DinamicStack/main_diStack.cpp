#include <iostream>
#include "diStack.h"
using namespace std;

int main(){
    diStack pilha1;
    typeItem item;
    int option;
    cout << "Stack generator:\n";

    do
    {
        cout << "0 to stop program!\n";
        cout << "1 to push element!\n";
        cout << "2 to pop element!\n";
        cout << "3 to print stack!\n";
        cin >> option;
        if (option == 1){
            cout << "enter the element:\n";
            cin >> item;
            pilha1.push(item);
        } else if (option == 2){
            item = pilha1.pop();
            cout << "This elemente has been removed: " << item << endl;
        }else if(option == 3){
            pilha1.print();
        }

    } while (option != 0);
    

    return 0;
}