#include "tlinkedlist.h"

TLinkedList::TLinkedList() : head(nullptr) {} //, tail(nullptr) {}

TLinkedList::TLinkedList(const TLinkedList &other)
{
    head = other.head;
    //tail = other.tail;
}

bool TLinkedList::Empty()
{
    return (head == nullptr);
}

size_t TLinkedList::Length()
{
    size_t size = 0;
    for (Item* i = head; i != nullptr; i = i -> next) {
        ++size;
    }
    return size;
}

const Triangle& TLinkedList::First()
{
    if (head == nullptr) {
        std::cout << "The list is empty" << std::endl;
        exit(1);
    }
    return head -> GetTriangle();
}

const Triangle& TLinkedList::Last()
{
    if (head == nullptr) {
        std::cout << "The list is empty" << std::endl;
        exit(1);
    }
    Item* pi = head;
    Item* i = head->next;

    for (; i != nullptr; i = i -> next) {
        pi = i;
    }
    return pi -> GetTriangle();
}

const Triangle& TLinkedList::GetItem(size_t idx)
{
    size_t len = this->Length();
    if (head == nullptr) {
        std::cout << "The list is empty" << std::endl;
        exit(1);
    }
    if (idx > len) {
        std::cout << "No element on position " << idx << std::endl;
        exit(1);
    }

    Item *item = head;
    for (size_t i = 1; i < idx; i++) {
        item = item->Right();
    }
    return item->GetTriangle();
}


void InsertFirst(const Triangle& triangle)
{
    Item *item = new Item(triangle);
    if (head == nullptr) {
        head = (end = item);
        return;
    }
    node->ToLeft(nullptr);
    node->ToRight(beginning);
    beginning->ToLeft(node);
    beginning = node;
}
