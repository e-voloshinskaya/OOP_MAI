Item::Item(const Triangle &t)
{
    this->triangle = t;
    this->next = nullptr;
    this->prev = nullptr;
}

Item::Item(const Item &other)
{
    this->triangle = other.triangle;
    this->next = other.next;
    this->prev = other.prev;
}

Item *Item::Left()
{
    return this->prev;
}

Item *Item::Right()
{
    return this->next;
}

Triangle& Item::GetTriangle()
{
    return this->triangle;
}

std::ostream &operator<<(std::ostream &os, const Item &item)
{
    os << item.triangle << std::endl;
    return os;
}

Item::~Item() {}