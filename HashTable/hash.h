#include "student.h"

class Hash{
    private:    
    int hashFunction(Student student);
        int max_itens;
        int max_positions;
        int itensQuantity;
        Student* structure;

    public:
    Hash(int vector_size, int max);
    ~Hash();
    bool isFull();
    int getSize();
    void insert(Student student);
    void remove(Student student);
    void find(Student& student, bool& find);
    void print();

};