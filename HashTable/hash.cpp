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
        int place = hashFunction(student);
        structure[place] = student;
        itensQuantity ++;
     }


    void Hash::remove(Student student)
     {
        int place = hashFunction(student);
        if (structure[place].getId() != -1){
            structure[place] = Student(-1, " ");
            itensQuantity --;
        }
     }


    void Hash::find(Student& student, bool& find)
    {
        int place = hashFunction(student);
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
            if (structure[i].getId() != -1){
                cout << i << ":" << structure[i].getId() << " ";
                cout << structure[i].getName() << endl;
            }
        }

    }

