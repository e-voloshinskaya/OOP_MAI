// loading ALL files, containing templates, is essential
#include "item.h"
#include "item.cpp" //essential as well
#include "tlinkedlist.h"
#include "tlinkedlist.cpp"
//#include "titerator.h"

//creating instances of the defined in '...'.h templates
template class Item<Triangle>;
//template class TIterator<Triangle>;
template class TLinkedList<Triangle>;
template std::ostream& operator<<(std::ostream &os, const TLinkedList<Triangle> &list);