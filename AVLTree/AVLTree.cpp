#include <iostream>
#include <cstddef>
#include "AVLTree.h" 

using namespace std;

    AVLTree::AVLTree() 
    {
        source = NULL;
    }

    AVLTree::~AVLTree() 
    {
        deleteTree(source);
    }

    void AVLTree::deleteTree(Node* currentNode)
    {
        if (currentNode != NULL){
            deleteTree(currentNode->leftSon);

            deleteTree(currentNode->rightSon);

            delete currentNode;
        }
    }

    Node* AVLTree::getScr()
    {
        return source;
    }

    bool AVLTree::isEmpty()
    {
        return (source == NULL);
    }

    bool AVLTree::isFull()
    {
        try{
            Node* temp = new Node;
            delete temp;
            return false;
        } catch(bad_alloc exception){
            return true;
        }
    }

    void AVLTree::push(Student student) 
    {
        bool increases;
        recursive(source, student, increases);
    }

    void AVLTree::recursive(Node*& currentNode, Student student, bool& increases)
    { 
        if (currentNode == NULL) {
            currentNode = new Node;
            currentNode->rightSon = NULL;
            currentNode->leftSon = NULL;
            currentNode->student = student;
            currentNode->balanceFactory = 0;
            increases = true;
            return;
        }  
        if (student.getId() < currentNode->student.getId()) {
            recursive(currentNode->leftSon, student, increases);
            if (increases){
                currentNode->balanceFactory-=1;   
            } 
        } else {
            recursive(currentNode->rightSon, student, increases);
            if (increases){
                currentNode->balanceFactory+=1;
            }    
        } 
        rotate(currentNode);

        if (increases && currentNode->balanceFactory == 0){
            increases = false;
        }
    }

    void AVLTree::pop(Student student) 
    {
        bool diminuiu;
        deleteSearch(student, source, diminuiu);
    }

    void AVLTree::deleteSearch(Student student, Node*& currentNode, bool& diminuiu)
    { 
        if (student.getId() < currentNode->student.getId()){
            deleteSearch(student, currentNode->leftSon, diminuiu);
            if (diminuiu){
                currentNode->balanceFactory+=1;
            }
        } else if (student.getId() > currentNode->student.getId()){
            deleteSearch(student, currentNode->rightSon, diminuiu);
            if (diminuiu){
                currentNode->balanceFactory-=1;
            }
        } else{
            deleteNode(currentNode, diminuiu);
        }
        if (currentNode != NULL){
            rotate(currentNode);
            if (diminuiu && currentNode->balanceFactory != 0){
                diminuiu = false;
            }
        }
    }

    void AVLTree::deleteNode(Node*& currentNode, bool& diminuiu)
    {
        Node* temp = currentNode;
        if (currentNode->leftSon == NULL){
            currentNode = currentNode->rightSon;
            diminuiu = true;
            delete temp;
        } else if (currentNode->rightSon == NULL){
            currentNode = currentNode->leftSon;
            diminuiu = true;
            delete temp;
        } else{
            Student studentSucessor;
            getSucessor(studentSucessor, currentNode);
            currentNode->student = studentSucessor;
            deleteSearch(studentSucessor, currentNode->rightSon, diminuiu);
            if (diminuiu){
                currentNode->balanceFactory-=1;
            }
        }
    }

    void AVLTree::getSucessor(Student& studentSucessor, Node* temp)
    {
        temp = temp->rightSon;
        while (temp->leftSon != NULL){
            temp = temp->leftSon;
        }
        studentSucessor = temp->student;
    }

    void AVLTree::search(Student& student, bool& busca)
    {
        busca = false;
        Node* currentNode = source;
        while (currentNode != NULL){
            if (student.getId() < currentNode->student.getId()){
                currentNode = currentNode->leftSon;
            } else if (student.getId() > currentNode->student.getId()){
                currentNode = currentNode->rightSon;
            } else{
                busca = true;
                student = currentNode->student;
                break;
            }
        }
    }

    void AVLTree::preOrder(Node* currentNode)
    {
        if (currentNode != NULL){
            cout << currentNode->student.getName() << ": ";
            cout << currentNode->student.getId() << endl;

            preOrder(currentNode->leftSon);

            preOrder(currentNode->rightSon);
        }
    }

    void AVLTree::order(Node* currentNode)
    {
        if (currentNode != NULL){
            order(currentNode->leftSon);

            cout << currentNode->student.getName() << ": ";
            cout << currentNode->student.getId() << endl;

            order(currentNode->rightSon);            
        }
    }

    void AVLTree::postOrder(Node* currentNode)
    {
        if (currentNode != NULL){
            postOrder(currentNode->leftSon);

            postOrder(currentNode->rightSon);

            cout << currentNode->student.getName() << ": ";
            cout << currentNode->student.getId() << endl;            
        }
    }





    void AVLTree::rotateRight(Node*& parent) 
    {
        Node* novoparent = parent->leftSon;
        parent->leftSon = novoparent->rightSon;
        novoparent->rightSon = parent;
        parent = novoparent;
    }

    void AVLTree::rotateLeft(Node*& parent) 
    {
        Node* novoparent = parent->rightSon;
        parent->rightSon = novoparent->leftSon;
        novoparent->leftSon = parent;
        parent = novoparent;
    }

    void AVLTree::rotateLeftRight(Node*& parent)
    {
        Node* son = parent->leftSon;
        rotateLeft(son);
        parent->leftSon = son;
        rotateRight(parent);
    }


    void AVLTree::rotateRightLeft(Node*& parent)
    {
        Node* son = parent->rightSon;
        rotateRight(son);
        parent->rightSon = son;
        rotateLeft(parent);
    }


    void AVLTree::rotate(Node*& parent)
    {
        Node* son;
        Node* grandson; 

        if (parent->balanceFactory == -2){ 

        son = parent->leftSon;

        if (son->balanceFactory == -1){ 
            parent->balanceFactory = 0;
            son->balanceFactory = 0;
            rotateRight(parent);
        } else if (son->balanceFactory == 0){ 
            parent->balanceFactory = -1;
            son->balanceFactory = 1;
            rotateRight(parent);
        } else if (son->balanceFactory == 1){ 
            grandson = son->rightSon;
            if (grandson->balanceFactory == -1){
                parent->balanceFactory = 1;
                son->balanceFactory = 0;
            } else if (grandson->balanceFactory == 0){
                parent->balanceFactory = 0;
                son->balanceFactory = 0;                
            } else if (grandson->balanceFactory == 1){
                parent->balanceFactory = 0;
                son->balanceFactory = -1;                
            }
            grandson->balanceFactory = 0; 
            rotateRightLeft(parent);            
        }



        } else if(parent->balanceFactory == 2){ 
            son = parent->rightSon;
            if (son->balanceFactory == 1) { 
                parent->balanceFactory = 0;
                son->balanceFactory = 0;
                rotateLeft(parent);
            } else if (son->balanceFactory == 0){          
                parent->balanceFactory = 1;
                son->balanceFactory = -1;
                rotateLeft(parent);
            } else if (son->balanceFactory == -1){ 
                grandson = son->leftSon;
                if (grandson->balanceFactory == -1){
                    parent->balanceFactory =  0;
                    son->balanceFactory = 1; 
                } else if (grandson->balanceFactory == 0){
                    parent->balanceFactory =  0;
                    son->balanceFactory = 0; 
                } else if (grandson->balanceFactory == 1){
                    parent->balanceFactory =  -1;
                    son->balanceFactory = 0; 
                }
                grandson->balanceFactory = 0;
                rotateRightLeft(parent);
            }
        }
    }                  