#include <iostream>
#include <vector>
using namespace std;

//Задание №2 ********************************************************************************

void printv(vector<int> vec)
 {
  cout << " data [" << vec.size() << "] = {";
  for(int i = 0; i < vec.size(); i++)
   cout << "   " << vec[i] ;
  cout << "}" << endl;
 }

vector<int> sort(vector<int> vec)
 {
  int a;
  int b;
  for(int j = 0; j < vec.size(); j++)
   for (int i = 0; i < vec.size()-1; i++)
   {
    a = vec[i];
    b = vec[i+1];
    if(a > b)
    {
     vec[i+1] = a;
     vec[i] = b;
    }
   }
  return vec;
 }

void func(vector<int> vec)
{
 vector<int> pov;
 pov.clear();
 vector<int> scop = sort(vec);
 for(int i = 0; i < vec.size(); i++)
 {
  if(i == 0)
   pov.push_back(scop[i]);
  else 
   if(scop[i-1] != scop[i])
    pov.push_back(scop[i]);
 }
 printv(pov);
 cout << pov.size() << " different values ​​in a vector" << endl;
}

int main()
{
 cout << "Задание №2 ********************************************************************************" << endl;
 
 vector<int> arr = { 90, 54, 8, 11, 8, 8, 87, 2, 11, 6, 6};
 printv(arr);
  
 printv(sort(arr));
 
 func(arr);
 return 0;
}
