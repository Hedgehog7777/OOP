#include <iostream>
#include "ArrayInt.h"
#include <cassert> 

//Задание №1 ********************************************************************************

class ArrayInt
{
 private:
 int m_length;
 int *m_data;
 public:
 ArrayInt(): m_length(0), m_data(nullptr)
 { }
 ArrayInt(int length):
 m_length(length)
 {
  assert(length >= 0);
  if (length > 0)
  m_data = new int[length];
  else
  m_data = nullptr;
 }
 ~ArrayInt()
 {
  delete[] m_data;
 }
};





int main()
{
 std::cout << "Hello" << std::endl;
 
 
 
 
 return 0;
}
