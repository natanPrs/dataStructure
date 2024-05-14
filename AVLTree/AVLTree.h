#include <iostream>
#include "Student.h"

struct Node{
    Student student;
    Node* leftSon;
    Node* rightSon;

    int balanceFactory; 
};

class AVLTree{
    private:
    Node* source;

    public:
    AVLTree(); 
    ~AVLTree(); 
    void deleteTree(Node* currentNode);
    Node* getScr();
    bool isEmpty();
    bool isFull();
    void push(Student student); 
    void pop(Student student); 
    void deleteSearch(Student student, Node*& currentNode, bool& decreases); 
    void deleteNode(Node*& currentNode, bool& decreases); 
    void getSucessor(Student& studentSucessor, Node* temp);
    void search(Student& student, bool& busca);
    void preOrder(Node* currentNode);
    void order(Node* currentNode);
    void postOrder(Node* currentNode);


    void rotateRight(Node*& tree);
    void rotateLeft(Node*& tree);  
    void rotateLeftRight(Node*& tree);
    void rotateRightLeft(Node*& tree);
    void rotate(Node*& tree);
    void recursive(Node*& currentNode, Student student, bool& increases);

};