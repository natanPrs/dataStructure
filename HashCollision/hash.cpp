#include <iostream>
#include "hash.h"

using namespace std;


    int Hash::hashFunction(Student student)
    {
        return (student.getId() % max_positions);
    }

    Hash::Hash(int vector_size, int max)
     {
        itensQuantity = 0;
        max_itens = max;
        max_positions = vector_size;
        structure = new Student[vector_size];
     }


    Hash::~Hash()
     {
        delete [] structure;
     }


    bool Hash::isFull()
     {
        return (itensQuantity == max_itens);
     }


    int Hash::getSize()
     {
        return (itensQuantity);
     }


    void Hash::insert(Student student)
     {
        if(isFull()){
            cout << "Hash table is full!\n";
        }else{
        int place = hashFunction(student);
        while (structure[place].getId() > 0){
            place = (place+1) % max_positions;
        }
        structure[place] = student;
        itensQuantity ++;
     }}


    void Hash::remove(Student student)
     {
        bool test = false;
        int place = hashFunction(student);
        while (structure[place].getId() != -1){
            if (structure[place].getId() == student.getId()){
                cout << student.getId() << "has been removed!\n";
                structure[place] = Student(-2, " ");
                itensQuantity --;
                test = true;
                break;
            }  
            place = (place+1) % max_positions;     
        }
        if (!test){
            cout << "The student not found!\n";
        }
     }


    void Hash::find(Student& student, bool& find)
    {
        int place = hashFunction(student);
        find = false;
        while (structure[place].getId() != -1){
            if (structure[place].getId() == student.getId()){
                find = true;
                student = structure[place];
                break;
            }
            place = (place+1) % max_positions;
        }
        

        Student temp = structure[place];
        if (student.getId() != temp.getId()){
            find = false;
        } else {
            find = true;
            student = temp;
        }

    }


    void Hash::print()
    {
        cout << "Hash Table:\n";
        for (int i=0 ; i < max_positions ; i++){
            if (structure[i].getId() > 0){
                cout << i << ":" << structure[i].getId() << " ";
                cout << structure[i].getName() << endl;
            }
        }

    }

