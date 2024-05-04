typedef int typeItem;

struct node
{
    typeItem valor;
    node* proximo;
};


class diStack{
    private:
    node* nodeTop;

    public:
    diStack();
    ~diStack(); 
    bool isFull();
    bool isEmpty();
    void push(typeItem item); 
    typeItem pop(); 
    void print(); 

};