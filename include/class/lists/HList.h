#include <iostream>
#include <vector>

using namespace std;

class HList
{
private:
    void *ptr;

public:
    HList() : ptr(nullptr) {}

    HList &operator=(const HList &other)
    {
        if (this != &other)
            this->ptr = other.ptr; // shallow copy of pointer
        return *this;
    }
    HList &operator=(void *other)
    {
        this->ptr = new (typeidother)(*other);

        return *this;
    }

    void *get() const { return ptr; }
};