#include "tlinkedlist.h"

TLinkedList::TLinkedList() : head(nullptr), tail(nullptr) {}

TLinkedList::TLinkedList(const TLinkedList &other)
{
    head = other.head;
    tail = other.tail;
}

bool TLinkedList::Empty()
{
    return (head == nullptr);
}

size_t TLinkedList::Length()
{
    size_t size = 0;
    for (Item* i = head; i != nullptr; i = i->Right()) {
        ++size;
    }
    return size;
}

const Triangle& TLinkedList::First()
{
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        exit(1);
    }
    return head -> GetTriangle();
}

const Triangle& TLinkedList::Last()
{
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        exit(1);
    }
    Item* pi = head;
    Item* i = head->Right();

    for (; i != nullptr; i = i -> Right()) {
        pi = i;
    }
    return pi -> GetTriangle();
}

const Triangle& TLinkedList::GetItem(size_t idx)
{
    size_t len = Length();
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        exit(1);
    }
    if (idx > len) {
        std::cout << "No element on position " << idx << std::endl;
        exit(1);
    }

    Item* item = head;
    for (size_t i = 1; i < idx; ++i) {
        item = item->Right();
    }
    return item->GetTriangle();
}


void TLinkedList::InsertFirst(const Triangle& triangle)
{
    Item* item = new Item(triangle);
    if (head == nullptr) {
        head = item;
        tail = item;
        return;
    } // важно, или будет обращение к nullptr -> prev
    //item->InsLeft(nullptr);
    item->InsRight(head);
    head->InsLeft(item);
    head = item;
}


void TLinkedList::InsertLast(const Triangle& triangle)
{
    Item* item = new Item(triangle);
    if (head == nullptr) {
        head = item;
        tail = item;
        return;
    }
    tail->InsRight(item);
    item->InsLeft(tail);
    //item->InsRight(nullptr);
    tail = item;
}

void TLinkedList::Insert(const Triangle& triangle, size_t position)
{
    size_t len = Length();
    if (position > len + 1) {
        std::cout << "No such position" << std::endl;
        return;
    }
    if (position == 1) {
        InsertFirst(triangle);
        return;
    }
    if (position == len + 1) {
        InsertLast(triangle);
        return;
    }
    Item* item = new Item(triangle);
    Item* curr = head;
    for (size_t i = 1; i < position; ++i) {
        curr = curr->Right();
    }
    Item* prev = curr->Left();
    prev->InsRight(item);
    curr->InsLeft(item);
    item->InsLeft(prev);
    item->InsRight(curr);
}

void TLinkedList::RemoveFirst()
{
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }
    Item* item = head;
    head = head->Right();
    head->InsLeft(nullptr);
    delete item;
}

void TLinkedList::RemoveLast()
{
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }
    Item* item = tail;
    tail = tail->Left();
    tail->InsRight(nullptr);
    delete item;
}

void TLinkedList::Remove(size_t position)
{
    size_t len = Length();
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    if (position > len) {
        std::cout << "No such position" << std::endl;
        return;
    }
    if (position == 1) {
        RemoveFirst();
        return;
    }
    if (position == len) {
        RemoveLast();
        return;
    }
    Item* item = head;
    for (size_t i = 1; i < position; ++i) {
        item = item->Right();
    }
    Item* left = item->Left();
    Item* right = item->Right();
    left->InsRight(right);
    right->InsLeft(left);
    delete item;
}

std::ostream &operator<<(std::ostream &os, const TLinkedList &list)
{
    if (list.head == nullptr) {
        os << "List is empty";
        return os;
    }
    for (Item* i = list.head; i != nullptr; i = i->Right()) {
        if (i->Right() != nullptr)
            os << i->GetTriangle().Area() << " -> ";
        else
            os << i->GetTriangle().Area();
    }
    return os;
}


void TLinkedList::Clear()
{
    while (head != nullptr) {
        RemoveFirst();
    }
}

TLinkedList::~TLinkedList()
{
    while (head != nullptr) {
        RemoveFirst();
    }
}

