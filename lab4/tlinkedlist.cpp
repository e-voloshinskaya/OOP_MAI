#include "tlinkedlist.h"

template <class T> //needed before all definitions of functions out of class definition
TLinkedList<T>::TLinkedList() : head(nullptr), tail(nullptr) {}

template <class T>
TLinkedList<T>::TLinkedList(const TLinkedList &other)
{
    head = other.head;
    tail = other.tail;
}

template <class T>
bool TLinkedList<T>::Empty()
{
    return (head == nullptr);
}

template <class T>
size_t TLinkedList<T>::Length()
{
    size_t size = 0;
    for (std::shared_ptr<Item<T>> i = head; i != nullptr; i = i->Right()) {
        ++size;
    }
    return size;
}

template <class T>
const std::shared_ptr<T> TLinkedList<T>::First()
{
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        exit(1);
    }
    return head -> GetTriangle();
}

template <class T>
const std::shared_ptr<T> TLinkedList<T>::Last()
{
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        exit(1);
    }
    std::shared_ptr< Item<T> > pi = head;
    std::shared_ptr< Item<T> > i = head->Right();

    for (; i != nullptr; i = i -> Right()) {
        pi = i;
    }
    return pi -> GetTriangle();
}

template <class T>
const std::shared_ptr<T> TLinkedList<T>::GetItem(size_t idx)
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

    std::shared_ptr< Item<T> > item = head;
    for (size_t i = 1; i < idx; ++i) {
        item = item->Right();
    }
    return item->GetTriangle();
}

template <class T>
void TLinkedList<T>::InsertFirst(const std::shared_ptr<T> object)
{
    std::shared_ptr<Item<T>> item(new Item<T>(object));
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

template <class T>
void TLinkedList<T>::InsertLast(const std::shared_ptr<T> object)
{
    std::shared_ptr<Item<T>> item(new Item<T>(object));
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

template <class T>
void TLinkedList<T>::Insert(const std::shared_ptr<T> object, size_t position)
{
    size_t len = Length();
    if (position > len + 1) {
        std::cout << "No such position" << std::endl;
        return;
    }
    if (position == 1) {
        InsertFirst(object);
        return;
    }
    if (position == len + 1) {
        InsertLast(object);
        return;
    }
    std::shared_ptr<Item<T>> item(new Item<T>(object));
    std::shared_ptr<Item<T>> curr = head;
    for (size_t i = 1; i < position; ++i) {
        curr = curr->Right();
    }
    std::shared_ptr<Item<T>> prev = curr->Left();
    prev->InsRight(item);
    curr->InsLeft(item);
    item->InsLeft(prev);
    item->InsRight(curr);
}

template <class T>
void TLinkedList<T>::RemoveFirst()
{
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
        return;
    }
    std::shared_ptr<Item<T>> item = head;
    head = head->Right();
    head->InsLeft(nullptr);
}

template <class T>
void TLinkedList<T>::RemoveLast()
{
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
        return;
    }
    std::shared_ptr<Item<T>> item = tail;
    tail = tail->Left();
    tail->InsRight(nullptr);
}

template <class T>
void TLinkedList<T>::Remove(size_t position)
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
    std::shared_ptr<Item<T>> item = head;
    for (size_t i = 1; i < position; ++i) {
        item = item->Right();
    }
    std::shared_ptr<Item<T>> left = item->Left();
    std::shared_ptr<Item<T>> right = item->Right();
    left->InsRight(right);
    right->InsLeft(left);
}

template <class T> //also needed before friend
std::ostream &operator<<(std::ostream &os, const TLinkedList<T> &list)
{
    if (list.head == nullptr) {
        os << "List is empty";
        return os;
    }
    for (std::shared_ptr<Item<T>> i = list.head; i != nullptr; i = i->Right()) {
        if (i->Right() != nullptr)
            os << i->GetTriangle()->Area() << " -> ";
        else
            os << i->GetTriangle()->Area();
    }
    return os;
}

template <class T>
void TLinkedList<T>::Clear()
{
    while (head != nullptr) {
        RemoveFirst();
    }
}

template <class T>
TLinkedList<T>::~TLinkedList()
{
    while (head != nullptr) {
        RemoveFirst();
    }
}
