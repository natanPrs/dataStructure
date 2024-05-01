#include <iostream>
#include "stack.h"
using namespace std;

int main(){
    stack stack1;
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
            stack1.push(item);
        } else if (option == 2){
            item = stack1.pop();
            cout << "Removed item: " << item << endl;
        }else if(option == 3){
            stack1.print();
        }

    } while (option != 0);
    

    return 0;
}