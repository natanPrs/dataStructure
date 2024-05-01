#include <iostream>
#include "queue.h"
using namespace std;

int main(){
    queue queue1;
    int option;
    typeItem item;

    cout << "queue generator:\n";

    do
    {
        cout << "Enter 0 for stop program.\n";
        cout << "Enter 1 for insert a element.\n";
        cout << "Enter 2 for remove a element.\n";
        cout << "Enter 3 for print queue.\n";
        cin >> option;

        if (option == 1){
           cout << "Enter item.";
           cin >> item;
           queue1.push(item);

        } else if (option == 2){
            item = queue1.pop();
            cout << "This element has been removed: " << item << endl;

        } else if (option == 3){
            queue1.print();
        }
        
    } while (option != 0);
    

}