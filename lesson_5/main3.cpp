#include <iostream>
#include <string>
using namespace std;

template <class T>
class Pair
{
 private:
 string m_a;
 T m_b;
 public:
 Pair (string a, T b) : m_a(a), m_b(b) {}
 
 string getA() const { return m_a; }
 
 T getB() const { return m_b; }
 
};


template < typename T>
class StringValuePair: public Pair<T>
{
 private:
 string m_a;
 T m_b;
 public:
 StringValuePair (string a , T b) : Pair<T> (a, b)//, m_c(a), m_d(b) 
 { 
  m_a = this->getA();
  m_b = this->getB();
 }
 
 string first() const { return m_a; }
 
 T second() const { return m_b; }
 
};

int main()
{

 StringValuePair<int> svp("Amazing", 7);
 std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
 
 return 0;
}
