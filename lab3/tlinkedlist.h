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

    const std::shared_ptr<Triangle> First();
    const std::shared_ptr<Triangle> Last();
    const std::shared_ptr<Triangle> GetItem(size_t idx);

    void InsertFirst(const std::shared_ptr<Triangle> triangle);
    void InsertLast(const std::shared_ptr<Triangle> triangle);
    void Insert(const std::shared_ptr<Triangle> triangle, size_t position);

    void RemoveFirst();
    void RemoveLast();
    void Remove(size_t position);

    friend std::ostream& operator<<(std::ostream& os, const TLinkedList &list);

    void Clear();
    virtual ~TLinkedList();

private:
    std::shared_ptr<Item> head;
    std::shared_ptr<Item> tail;
};

#endif // TLINKEDLIST_H