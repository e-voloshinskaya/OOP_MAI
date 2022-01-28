#include "item.h"

Item::Item(const std::shared_ptr<Triangle> t)
{
    this->triangle = t;
    this->next = nullptr;
    this->prev = nullptr;
}

Item::Item(const std::shared_ptr<Item> other)
{
    this->triangle = other->triangle;
    this->next = other->next;
    this->prev = other->prev;
}

std::shared_ptr<Item> Item::Left()
{
    return this->prev;
}

std::shared_ptr<Item> Item::Right()
{
    return this->next;
}

void Item::InsLeft(std::shared_ptr<Item> item)
{
    this->prev = item;
}

void Item::InsRight(std::shared_ptr<Item> item)
{
    this->next = item;
}

std::shared_ptr<Triangle> Item::GetTriangle()
{
    return this->triangle;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<Item> item)
{
    os << item->triangle << std::endl;
    return os;
}

Item::~Item() {}