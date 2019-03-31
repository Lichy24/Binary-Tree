/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;

  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
    
  ariel::Tree mytree;
  
  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_THROWS(threetree.left(6))
  .CHECK_OK    (threetree.print())

  .CHECK_EQUAL (mytree.size(),0)
  .CHECK_OK (mytree.insert(155))
  .CHECK_THROWS (mytree.insert(155))
  .CHECK_EQUAL (mytree.size() , 1)
  .CHECK_EQUAL (mytree.contains(5) , false)
  .CHECK_EQUAL (mytree.contains(155) , true)
  .CHECK_THROWS (mytree.parent(155))
  .CHECK_THROWS (mytree.left(155))
  .CHECK_THROWS (mytree.right(155))
  .CHECK_OK (mytree.insert(50))
  .CHECK_OK (mytree.insert(250))
  .CHECK_OK (mytree.insert(150))
  .CHECK_OK (mytree.insert(220))
  .CHECK_OK (mytree.insert(230))
  .CHECK_EQUAL (mytree.size() , 6)
  .CHECK_OK (mytree.insert(20))
  .CHECK_OK (mytree.insert(70))
  .CHECK_EQUAL (mytree.left(50) , 20 )
  .CHECK_EQUAL (mytree.right(50) , 150 )
  .CHECK_OK(mytree.remove(150))
  .CHECK_EQUAL (mytree.right(50) , 70 )
  .CHECK_EQUAL (mytree.root(), 155)
  .CHECK_OK (mytree.remove(155))
  .CHECK_THROWS (mytree.remove(155))
  .CHECK_EQUAL (mytree.left(250) , 230)
  .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}