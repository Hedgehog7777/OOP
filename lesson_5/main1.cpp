#include <iostream>
using namespace std;

template <typename T>
class Pair1
{
 private:
 T m_a;
 T m_b;
 public:
 Pair1 (T a, T b) : m_a(a), m_b(b) {}
 
 T first() const { return m_a; }
 
 T second() const { return m_b; }
 
};

int main()
{
  
 Pair1<int> p1(6, 9);
 cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

 const Pair1<double> p2(3.4, 7.8);
 cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
 
 return 0;
}
