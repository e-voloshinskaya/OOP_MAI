#ifndef ITEM_H
#define ITEM_H

#include "triangle.h"
#include <memory>

class Item
{
public:
    Item(const std::shared_ptr<Triangle> t);
    Item(const std::shared_ptr<Item> other);

    std::shared_ptr<Item> Left();
    std::shared_ptr<Item> Right();
    
    void InsLeft(std::shared_ptr<Item> item);
    void InsRight(std::shared_ptr<Item> item);

    std::shared_ptr<Triangle> GetTriangle();

    friend std::ostream &operator<<(std::ostream &os, const std::shared_ptr<Item> item);

    virtual ~Item();

private:
    std::shared_ptr<Triangle> triangle;
    std::shared_ptr<Item> prev;
    std::shared_ptr<Item> next;
};

#endif // ITEM_H