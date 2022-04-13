#include <iostream>
#include <cassert> 
using namespace std;

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

 void erase()
 {
  delete[] m_data;
  m_data = nullptr;
  m_length = 0;
 }
 
 int getLength() { return m_length; }
 
 int& operator[](int index)
 {
  assert(index >= 0 && index < m_length);
  return m_data[index];
 }

 void resize(int newLength)
 {
  if (newLength == m_length)
  return;
  if (newLength <= 0)
  {
   erase();
   return;
  }
  int *data = new int[newLength];
  if (m_length > 0)
  {
   int elementsToCopy = (newLength > m_length) ? m_length : newLength;
   for (int index=0; index < elementsToCopy ; ++index)
   data[index] = m_data[index];
  }
  delete[] m_data;
  m_data = data;
  m_length = newLength;
 }

 void insertBefore(int value, int index)
 {
  assert(index >= 0 && index <= m_length);
  int *data = new int[m_length+1];
  for (int before=0; before < index; ++before)
   data[before] = m_data[before];
  data [index] = value;
  for (int after=index; after < m_length; ++after)
   data[after+1] = m_data[after];
  delete[] m_data;
  m_data = data;
  ++m_length;
 }

 void push_back(int value) { insertBefore(value, m_length); }
 
  //Задание №1 ********************************************************************************
 
 void printv()
 {
  cout << " data [" << m_length << "] = {";
  for(int i = 0; i < m_length; i++)
   cout << "   " << m_data[i] ;
  cout << "}" << endl;
 }
 
 int pol_out(int index)
 {
  if (m_length <= 0)
  {
   cout << "ERROR!!" << endl;
   return -1;
  }
  else
  {
   // плохо понимаю зачем это нужно но вроде бы для проверки чтоб index находился от 1 до m_length
   assert(index >= 0 && index <= m_length); 
   --index;
   int *data = new int[m_length-1];
   int value;
  for (int before=0; before < index; ++before)
   data[before] = m_data[before];
  value = m_data [index];
  for (int after=index; after < m_length-1; ++after)
   data[after] = m_data[after+1];
  delete[] m_data;
  m_data = data;
  --m_length;
  return value;
  }
 }
 
 int pop_back() { return pol_out(m_length); }
 
 int pop_front() { return pol_out(1);}
 
 void sort()
 {
  int a;
  int b;
  for(int j = 0; j < m_length; j++)
   for (int i = 0; i < m_length-1; i++)
   {
    a = m_data[i];
    b = m_data[i+1];
    if(a > b)
    {
     m_data[i+1] = a;
     m_data[i] = b;
    }
   }
 }
 
};

int main()
{
 cout << "//Задание №1 ********************************************************************************" << endl;
 ArrayInt a(5);
 a.printv();
 
 a.erase();
 a.printv();
 
 a.push_back(4);
 a.push_back(3);
 a.push_back(2);
 a.push_back(1);
 a.push_back(7);
 a.printv();
 
 cout << "pop_back = " << a.pop_back() << endl;
 a.printv();
 
 cout << "pop_front = " << a.pop_front() << endl;
 a.printv();
 
 a.push_back(3);
 a.push_back(4);
 a.push_back(9);
 a.printv();
 a.sort();
 a.printv();
  
 return 0;
}
