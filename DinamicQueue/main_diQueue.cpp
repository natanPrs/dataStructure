#include <iostream>
#include "diQueue.h"
using namespace std;

int main(){
    diQueue fila1;
    int opcao;
    typeItem item;

    cout << "queue generator:\n";

    do
    {
        cout << "Enter 0 for stop program.\n";
        cout << "Enter 1 for insert a element.\n";
        cout << "Enter 2 for remove a element.\n";
        cout << "Enter 3 for print queue.\n";
        cin >> opcao;

        if (opcao == 1){
           cout << "Enter the item.";
           cin >> item;
           fila1.push(item);

        } else if (opcao == 2){
            item = fila1.pop();
            cout << "This element has been removed: " << item << endl;

        } else if (opcao == 3){
            fila1.print();
        }
        
    } while (opcao != 0);
    

}