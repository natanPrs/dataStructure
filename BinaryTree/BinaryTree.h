#include <iostream>
#include "student.h"

struct Node{
    Student Student;
    Node* leftSun;
    Node* rightSun;
};

class BST{
    private:
    Node* source;

    public:
    BST();
    ~BST();
    void deleteTree(Node* currentNode);
    Node* getSrc();
    bool isFull();
    bool isEmpty();
    void pop(Student student);
    void searchRemove(Student student, Node*& currentNode);
    void deleteNode(Node*& currentNode);
    void getSucessor(Student& studentSucessor, Node* temp);
    void push(Student student);
    void search(Student& student, bool search);
    void preOrder(Node* currentNode);
    void order(Node* currentNode);
    void postOrder(Node* currentNode);
 
};