#ifndef TITERATOR_H
#define TITERATOR_H

#include "item.h"

template <class T>
class TIterator {
public:
    TIterator(std::shared_ptr< Item<T> > n)
    {
        node = n;
    }

    std::shared_ptr<T> operator*() const
    {
        return node->GetTriangle();
    }

    std::shared_ptr<T> operator->() const
    {
        return node->GetTriangle();
    }

    std::shared_ptr< Item<T> > get()
    {
        return node;
    }

    void operator++()
    {
        node = node->Right();
    }

    void operator--()
    {
        node = node->Left();
    }

    TIterator<T> operator++(int)
    {
        TIterator<T> iter(*this);
        ++(*this);
        return iter;
    }

    TIterator<T> operator--(int)
    {
        TIterator<T> iter(*this);
        --(*this);
        return iter;
    }

    bool operator==(TIterator<T> const &i)
    {
        return node == i.node;
    }

    bool operator!=(TIterator<T> const &i)
    {
        return !(*this == i);
    }

private:
    std::shared_ptr< Item<T> > node; // node или itemt?
};

#endif // TITERATOR_H