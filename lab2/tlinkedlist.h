#ifndef TLINKEDLIST_H
#define TLINKEDLIST_H

#include "item.h"

class TLinkedList
{
public:
    TLinkedList();
    TLinkedList(const TLinkedList& other);

    size_t Length();
    bool Empty();

    const Triangle& First();
    const Triangle& Last();
    const Triangle& GetItem(size_t idx);

    void InsertFirst(const Triangle& triangle);
    void InsertLast(const Triangle& triangle);
    void Insert(const Triangle& triangle, size_t position);

    void RemoveFirst();
    void RemoveLast();
    void Remove(size_t position);

    friend std::ostream& operator<<(std::ostream& os, const TLinkedList &list);

    void Clear();
    virtual ~TLinkedList();

private:
    Item* head;
    //Item* tail;
};

#endif // TLINKEDLIST_H