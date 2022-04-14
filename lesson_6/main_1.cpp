#include <iostream>
#include <cmath>

using namespace std;

int main()
{
 int c;
 bool q = false;
 char a[19]; 
 long long b = 0;
 while(q == false)
 {
  cin.getline(a, 19);
  c = cin.gcount();
  c = c-1;
  if (a[0] == 0x2D)
  {
   int i = 1;
   while (a[i] > 0x2f && a[i] < 0x3a)
   {
    long long f = (pow(10,c-1-i));
    f = f * (a[i]-48);
    b = b+f;
    i++;
   }
   if(a[i] != '\0')
    cout << "Please try again!!!" << endl;
   else 
   {
    b = b * -1;
    cout << b << endl;
    q= true;
   }
  }
  else
  if(a[0] > 0x2f && a[0] < 0x3a)
  {
   int i = 0;
   while (a[i] > 0x2f && a[i] < 0x3a)
   {
    long long f = (pow(10,c-1-i));
    f = f * (a[i]-48);
    b = b+f;
    i++;
   }
   if(a[i] != '\0')
   {
    cout << "Please try again!!!" << endl;
    break;
   }
   else 
   {
    cout << b << endl;
    q= true;
   }
  }
  else 
   cout << "Please try again!!!" << endl;
 }
 
 return 0;
}
