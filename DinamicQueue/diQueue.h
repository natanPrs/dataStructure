typedef int typeItem;


struct Node
{
    typeItem value;
    Node* next;
};

class diQueue
{   
    private:
    Node* front;
    Node* rear;

    public:
    diQueue();
    ~diQueue();
    bool isEmpty();
    bool isFull();
    void push(typeItem item);
    typeItem pop();
    void print();

};

