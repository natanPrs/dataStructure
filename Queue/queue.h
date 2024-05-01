typedef int typeItem;
const int max_itens = 100;

class queue
{
private:
    int front, rear;
    typeItem* structure;

public:
    queue();
    ~queue();
    bool isEmpty();
    bool isFull();
    void push(typeItem item);
    typeItem pop();
    void print();

};