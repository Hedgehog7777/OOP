#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Pair
{
 private:
 T1 m_a;
 T2 m_b;
 public:
 Pair (T1 a, T2 b) : m_a(a), m_b(b) {}
 
 T1 first() const { return m_a; }
 
 T2 second() const { return m_b; }
 
};

int main()
{

Pair<int, double> p1(6, 7.8);
 cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

 const Pair<double, int> p2(3.4, 5);
 cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
 
return 0;
}
