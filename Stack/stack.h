typedef int typeItem;
const int max_itens = 100;

class stack{
    private:
    int size;
    typeItem* structure;

    public:
    stack();
    ~stack(); 
    bool isFull();
    bool isEmpty();
    void push(typeItem item); 
    typeItem pop(); 
    void print(); 
    int whichSize();

};