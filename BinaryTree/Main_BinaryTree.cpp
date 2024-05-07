#include <iostream>
#include "binaryTree.h"

using namespace std;

int main(){
    BST studentTree;
    int option, id, prt;
    string name;
    bool search;

    do
    {
        cout << "Enter 0 to stop program.\n";
        cout << "Enter 1 to insert an element.\n";
        cout << "Enter 2 to remove element.\n";
        cout << "Enter 3 to search for an element.\n";
        cout << "Enter 4 to print the Tree.\n";
        cin >> option;

        if (option == 1){
            cout << "Enter the student name: \n";
            cin >> name;
            cout << "Enter the student ID: \n";
            cin >> id;
            Student student(id, name);

            if (studentTree.isFull()){
                cout << "The Tree is full!";
            }else{
                studentTree.push(student);
            }
            
        }else if (option == 2){
            cout << "Enter the student ID: \n";
            cin >> id;
            Student student(id, " ");
            studentTree.pop(student);
        }else if (option == 3){
            cout << "Enter the student ID: \n";
            cin >> id;
            Student student(id, " ");
            studentTree.search(student, search);
            if (search){
                cout << "Student Found!\n";
                cout << "The student ID is: " << student.getId() << endl;
                cout << "The student name is: " << student.getName() << endl;
            } else {
                cout << "Student not found!\n";
            }
            
        }else if (option == 4){
            cout << "Enter 1 to print in pre order!\n";
            cout << "Enter 2 to print in order!\n";
            cout << "Enter 3 to print in post order!\n";
            cin >> prt;
            if (prt == 1){
                studentTree.preOrder(studentTree.getSrc());
            }else if (prt == 2){
                studentTree.order(studentTree.getSrc());
            }else if (prt == 3){
                studentTree.postOrder(studentTree.getSrc());
            }else {
                cout << "Invalid option!" << endl;
            }
            
        }
        
        
    } while (option != 0);
    

};