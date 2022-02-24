#include "tlinkedlist.h"
//#include "tlinkedlist.cpp"
int main(void)
{
  TLinkedList<Triangle> l;
  
  Point a1(-3, -1);
  Point b1(3, 0);
  Point c1(4, 8);
  Point a2(0, 0);
  Point b2(2, 3);
  Point c2(-2, 6);
  Point a3(1, 0);
  Point b3(0.5, 1);
  Point c3(2, 1);

  std::shared_ptr<Triangle> t1(new Triangle (a1, b1, c1));
  std::shared_ptr<Triangle> t2(new Triangle (a2, b2, c2));
  std::shared_ptr<Triangle> t3(new Triangle (a3, b3, c3));
  
  std::cout << l << std::endl;
  
  std::cout << "Length: " << l.Length() << std::endl;
  l.Insert(t1, 1);
  std::cout << l << std::endl;
  l.Insert(t1, 3);
  l.Insert(t2, 2);
  std::cout << l << std::endl;
  
  l.InsertLast(t1);
  std::cout << l << std::endl;
  l.Insert(t3, 4);
  std::cout << l << std::endl;
  std::cout << "Length: " << l.Length() << std::endl;
  l.Insert(t3, 3);
  std::cout << l << std::endl;
  l.Insert(t2, 6);
  std::cout << l << std::endl;
  l.Insert(t2, 1);
  std::cout << l << std::endl;
  l.InsertFirst(t3);
  std::cout << l << std::endl;
  
  l.Remove(9);
  l.Remove(5);
  std::cout << l << std::endl;
  std::cout << "Length: " << l.Length() << std::endl;
  l.Remove(l.Length());
  std::cout << l << std::endl;
  l.RemoveFirst();
  std::cout << l << std::endl;
  std::cout << "Length: " << l.Length() << std::endl;
  l.RemoveLast();
  std::cout << l << std::endl;
  l.InsertFirst(t3);
  std::cout << l << std::endl;
  std::cout << *l.First() << std::endl;
  std::cout << *l.Last() << std::endl;
  std::cout << *l.GetItem(1) << std::endl;
  std::cout << *l.GetItem(2) << std::endl;
  std::cout << *l.GetItem(3) << std::endl;
  std::cout << *l.GetItem(4) << std::endl;
  l.Clear();
  std::cout << l << std::endl;
  std::cout << "Length: " << l.Length() << std::endl;
  
  return 0;
}
