#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename _CharT, typename _Traits>
inline std::basic_ostream<_CharT, _Traits>&
endll(std::basic_ostream<_CharT, _Traits>& __os)
{ return flush((__os.put(__os.widen('\n'))).put(__os.widen('\n'))); }

void twendl()
{
	cout << "C ++" << endll << "I don't understand ";
	cout << endl;
}

int main()
{

 twendl();
 
 return 0;
}
