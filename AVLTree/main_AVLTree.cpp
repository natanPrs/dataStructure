#include <iostream>
#include "AVLTree.h" 

using namespace std;

int main(){
    AVLTree StudentTree; 
    int option, id, prt;
    string name;
    bool search = false;

    do{
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
        if (StudentTree.isFull()){
            cout << "The Tree is full!\n";
        } else{            
            StudentTree.push(student);
        }
        } else if (option == 2){
            cout << "Enter the student ID: \n";
            cin >> id;
            Student student(id, " ");
            StudentTree.pop(student);
        } else if (option == 3){
            cout << "Enter the student ID: \n";
            cin >> id;
            Student student(id, " ");
            StudentTree.search(student, search);
            if (search){
                cout << "Student Found!\n";
                cout << "The student name is: " << student.getName() << endl;
                cout << "The student ID is: " << student.getId() << endl;
            } else{
                cout << "Student not found!\n";
            }           
        } else if (option == 4){
            cout << "Enter 1 to print in pre order!\n";
            cout << "Enter 2 to print in order!\n";
            cout << "Enter 3 to print in post order!\n";
            cin >> prt;
            if (prt == 1){
                StudentTree.preOrder(StudentTree.getScr());
            } else if (prt == 2){
                StudentTree.order(StudentTree.getScr());
            } else{
                StudentTree.postOrder(StudentTree.getScr());
            }                   
        }
    } while (option != 0);

    return 0;
}