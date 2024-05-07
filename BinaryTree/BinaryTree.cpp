#include <iostream>
#include <cstddef>
#include "binaryTree.h"

using namespace std;

    BST::BST()
    {
        source = NULL;
    }

    BST::~BST()
    {
        deleteTree(source);
    }

    void BST::deleteTree(Node* currentNode)
    {
        if (currentNode != NULL){
            deleteTree(currentNode->leftSun);
            deleteTree(currentNode->rightSun);

            delete currentNode;
        }
        
    }

    Node* BST::getSrc()
    {
        return source;
    }

    bool BST::isFull()
    {
        try
        {
            Node* temp = new Node;
            delete temp;
            return false;
        }
        catch(bad_alloc exception)
        {
            return true;
        }
    }

    bool BST::isEmpty()
    {
        return (source == NULL);
    }

    
    void BST::push(Student student)
    {
        if (isFull()){
           cout << "The Tree is full, element not inserted.\n";
        }else {
            Node* newNode = new Node;
            newNode->Student = student;
            newNode->leftSun = NULL;
            newNode->rightSun = NULL;
            if (source == NULL){
                source = newNode;
            }else{
                Node* temp = source;
                while (temp != NULL){
                    if (student.getId() < temp->Student.getId()){
                        if (temp->leftSun == NULL){
                            temp->leftSun = newNode;
                            break;
                        }else{
                            temp = temp->leftSun;
                        }
                        
                    }else {
                        if (temp->rightSun == NULL){
                            temp->rightSun = newNode;
                            break;
                        }else{
                            temp = temp->rightSun;
                        }
                        
                    }
                    
                }
                
            }
            


        }
        
    }

    void BST::pop(Student student)
    {
        searchRemove(student, source);
    }  

    void BST::searchRemove(Student student, Node*& currentNode)
    {
        if (student.getId() < currentNode->Student.getId()){
            searchRemove(student, currentNode->leftSun);
        } else if (student.getId() > currentNode->Student.getId()){
            searchRemove(student, currentNode->rightSun);
        }else {
            deleteNode(currentNode);
        }
        
        
    }
    void BST::deleteNode(Node*& currentNode)
    {
        Node* temp = currentNode;
        if (currentNode->leftSun == NULL){
            currentNode = currentNode->rightSun;
            delete temp;
        }else if (currentNode->rightSun == NULL){
            currentNode = currentNode->leftSun;
            delete temp;
        }else{
            Student studentSucessor;
            getSucessor(studentSucessor, currentNode);
            currentNode->Student = studentSucessor;
            searchRemove(studentSucessor, currentNode->rightSun);

        }
        
        
    }
    void BST::getSucessor(Student& studentSucessor, Node* temp)
    {
        temp = temp->rightSun;
        while (temp->leftSun != NULL){
            temp = temp->leftSun;
        }
        studentSucessor = temp->Student;
    }

    void BST::search(Student& student, bool& search)
    {
        search = false;
        Node* currentNode = source;
        while (currentNode != NULL){
            if (student.getId() < currentNode->Student.getId()){
                currentNode = currentNode->leftSun;
            }else if(student.getId() > currentNode->Student.getId()){
                currentNode = currentNode->rightSun;
            }else{
                search = true;
                student = currentNode->Student;
                break;
            }
            
        }
        
    }

    void BST::preOrder(Node* currentNode)
    {
        if (currentNode != NULL){
            cout << currentNode->Student.getName() << " : ";
            cout << currentNode->Student.getId() << endl;

            preOrder(currentNode->leftSun);
            preOrder(currentNode->rightSun);

        }
        
    }  
    
    void BST::order(Node* currentNode)
    {
        if (currentNode != NULL)
        {
            order(currentNode->leftSun);
        
            cout << currentNode->Student.getName() << " : ";
            cout << currentNode->Student.getId() << endl;

            order(currentNode->rightSun);
        }
        
    }

    void BST::postOrder(Node* currentNode)
    {
        if (currentNode != NULL){
            postOrder(currentNode->leftSun);
            postOrder(currentNode->rightSun);

            cout << currentNode->Student.getName() << " : ";
            cout << currentNode->Student.getId() << endl;
        }
        
    }
