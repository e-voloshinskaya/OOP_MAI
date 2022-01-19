#ifndef ITEM_H
#define ITEM_H

#include "triangle.h"

class Item
{
public:
    Item(const Triangle &s);
    Item(const Item &other);

    Item* Left();
    Item* Right();

    Triangle& GetTriangle();

    friend std::ostream &operator<<(std::ostream &os, const Item& item);

    virtual ~Item();

private:
    Triangle triangle;
    Item* prev;
    Item* next;
};

#endif // ITEM_H