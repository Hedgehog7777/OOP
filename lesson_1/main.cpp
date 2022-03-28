#include <iostream>

//Задание №1 ********************************************************************************
class Power
{
 public:
 int current;
 int voltage;
 
 void set(int cur, int vol)
 {
  current = cur;
  voltage = vol;
 }
 void calculate()
 {
  int x = 1;
  for(int i = 0; i < voltage; i++)
  {
   x = x*current;
  }
  std::cout << "x = " << x << "\n" << std::endl;
 }
};	
 
//Задание №2 ********************************************************************************

class RGBA
{
 private:
 uint8_t m_red = 0;
 uint8_t m_green = 0;
 uint8_t m_blue = 0;
 uint8_t m_alpha = 255;
 
 public:
 RGBA()
 {
 }
 
 RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
 : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
 {
 }
 
 void setRed(uint8_t red) { m_red = red; }
 int getRed() { return m_red; }
 
 void setGreen(uint8_t green) { m_green = green; }
 int getGreen() { return m_green; }
 
 void setBlue(uint8_t blue) { m_blue = blue; }
 int getBlue() { return m_blue; }
 
 void setAlpha(uint8_t alpha) { m_alpha = alpha; }
 int getAlpha() { return m_alpha; }
 
 void print()
 {
  std::cout << "RGBA Red = " << static_cast<int>(m_red) << "\nRGBA Green = " << static_cast<int>(m_green) << "\nRGBA Blue = " << static_cast<int>(m_blue )<< "\nRGBA Alpha = " << static_cast<int>(m_alpha) << "\n" << std::endl;
 }
 
};	

//Задание №3 ********************************************************************************

class Stack
{
 private:
 
 int m_arr[10];
 int m_len;
 
 public:
 Stack() 
 {
 }
 
 void reset()
 {
  m_arr[10] = {0};
  m_len = -1;
 }
 
 bool push(int value)
 {
  if(m_len < 10)
  {
   m_len ++;
   m_arr[m_len] = value;
   return true;
  }
  else
  {
   return false;
  }
 }
 
 int pop()
 {
  if(m_len == -1)
  {
   std::cout << "Stack is empty" << std::endl;
   return 0;
  }
  else
  {
   int a = m_arr[m_len];
   m_len--;
   return a;
  }
 }
 
 void print()
 {
  std::cout << "(";
  if(m_len == -1)
  {
  }
  else
  {
   for (int i=0; i <= m_len; i++)
   {
    std::cout << m_arr[i] << " ";
   }
  }
  std::cout << ")" << std::endl;
 }
 
};	


//*******************************************************************************************


int main()
{

 std::cout << "//Задание №1 ***********************************************" << std::endl;

 Power Mosh; 
 Mosh.set(2, 5);
 Mosh.calculate();

 std::cout << "//Задание №2 ***********************************************" << std::endl;
 RGBA rgba;
 rgba.print();
 
 RGBA rgba1(12, 8, 74, 121);
 rgba1.print();

 std::cout << "//Задание №3 ***********************************************" << std::endl;
 
 Stack stack;
 stack.reset();
 stack.print();

 stack.push(3);
 stack.push(7);
 stack.push(5);
 stack.print();

 stack.pop();
 stack.print();

 stack.pop();
 stack.pop();
 stack.print();
 
 return 0;
}

