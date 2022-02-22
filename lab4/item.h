#ifndef ITEM_H
#define ITEM_H

#include "triangle.h"
#include <memory>


template <class T>
class Item
{
public:
    Item(const std::shared_ptr<T> o);
    Item(const std::shared_ptr< Item<T> > other);

    std::shared_ptr< Item<T> > Left();
    std::shared_ptr< Item<T> > Right();

    void InsLeft(std::shared_ptr< Item<T> > item);
    void InsRight(std::shared_ptr< Item<T> > item);

    std::shared_ptr<T> GetTriangle();

    template <class I>
    friend std::ostream &operator<<(std::ostream &os, const std::shared_ptr< Item<T> > item);

    virtual ~Item();

private:
    std::shared_ptr<T> object;
    std::shared_ptr< Item<T> > prev;
    std::shared_ptr< Item<T> > next;
};

#endif // ITEM_H
