#include "item.h"

template <class T>
Item<T>::Item(const std::shared_ptr<T> o)
{
    this->object = o;
    this->next = nullptr;
    this->prev = nullptr;
}

template <class T>
Item<T>::Item(const std::shared_ptr< Item<T> > other)
{
    this->object = other->object;
    this->next = other->next;
    this->prev = other->prev;
}

template <class T>
std::shared_ptr< Item<T> > Item<T>::Left()
{
    return this->prev;
}

template <class T>
std::shared_ptr< Item<T> > Item<T>::Right()
{
    return this->next;
}

template <class T>
void Item<T>::InsLeft(std::shared_ptr< Item<T> > item)
{
    this->prev = item;
}

template <class T>
void Item<T>::InsRight(std::shared_ptr< Item<T> > item)
{
    this->next = item;
}

template <class T>
std::shared_ptr<T> Item<T>::GetTriangle()
{
    return this->object;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const std::shared_ptr< Item<T> > item)
{
    os << item->object << std::endl;
    return os;
}

template <class T>
Item<T>::~Item() {}