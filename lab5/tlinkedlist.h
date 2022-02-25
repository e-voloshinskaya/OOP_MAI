#ifndef TLINKEDLIST_H
#define TLINKEDLIST_H

#include "item.h"
#include "titerator.h"

template <class T>
class TLinkedList
{
public:
    TLinkedList();
    TLinkedList(const TLinkedList<T>& other);

    size_t Length();
    bool Empty();

    TIterator<T> IFirst() const;
    TIterator<T> ILast() const;
    const std::shared_ptr<T> First();
    const std::shared_ptr<T> Last();
    const std::shared_ptr<T> GetItem(size_t idx);

    void InsertFirst(const std::shared_ptr<T> object);
    void InsertLast(const std::shared_ptr<T> object);
    void Insert(const std::shared_ptr<T> object, size_t position);

    void RemoveFirst();
    void RemoveLast();
    void Remove(size_t position);

    template <class F> //friend function needs its own template for sharing private fields
    friend std::ostream& operator<<(std::ostream& os, const TLinkedList<F> &list);

    void Clear();
    virtual ~TLinkedList();

private:
    std::shared_ptr< Item<T> > head;
    std::shared_ptr< Item<T> > tail;
};

#endif // TLINKEDLIST_H