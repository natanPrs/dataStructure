#include "student.h"


    Student::Student()
    {
        id = -1;
        name = " ";
    }

    Student::Student(int i, string n)
    {
        id = i;
        name = n;
    }

    int Student::getId()
    {
        return id;
    }

    string Student::getName()
    {
        return name;
    }