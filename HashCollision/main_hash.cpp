#include <iostream>
#include "hash.h"

using namespace std;

int main(){
    cout << "Generator hash\n";
    int vector_size;
    int max_elements;
    cout << "Enter the hash size:\n";
    cin >> vector_size;
    cout << "Enter the max elements\n";
    cin >> max_elements;
    cout << "The factor charge is: " << (float)max_elements / (float)vector_size << endl;
    Hash findHash(vector_size, max_elements);
    int option;
    int id;
    string name;
    bool find;

    do
    {
        cout << "Enter 0 to stop the code\n";
        cout << "Enter 1 to insert a element\n";
        cout << "Enter 2 to remove a element\n";
        cout << "Enter 3 to find a element\n";
        cout << "Enter 4 to print a element\n";
        cin >> option;

        if (option == 1){
            cout << "Which ID do you want to insert for the student?\n";
            cin >> id;
            cout << "What is the student`s name?\n";
            cin >> name;
            Student student(id, name);
            findHash.insert(student);
        } else if (option == 2) {
            cout << "Which student do you want remove?";
            cin >> id;
            Student student(id, " ");
            findHash.remove(student);
        } else if (option == 3){   
            cout << "Which student do you want to meet?";
            cin >> id;
            Student student(id, " ");
            findHash.find(student, find);
            if (find){
                cout << "Student found!\n";
                cout << "ID: " << student.getId() << endl;
                cout << "Name: " << student.getName() << endl;
            }else {
                cout << "Student not found!\n";
            }
        }    
        else if (option == 4){
            findHash.print();
        }
    } while (option != 0);
    
    

    return 0;
}