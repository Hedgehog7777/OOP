#include <iostream>
#include <cmath>

//Задание №1 ********************************************************************************

class Figure  //класс Фигура
{
 protected:
 std::string m_name;
 float m_lenght;
 float m_width;
 public:
 Figure(std::string name, float lenght, float width) : m_name(name), m_lenght(lenght), m_width(width)
 {}
 
 virtual std::string getName() const {return m_name;}
 virtual float getLenght() const {return m_lenght;}
 virtual float getWidth() const {return m_width;}
 
 virtual float  area()
 {
  return (m_lenght * m_width);
 }
};


class Circle : public Figure  //класс Круг
{
 public:
 Circle(std::string name, float lenght) : Figure(name, lenght, 0)
 {}
 std::string getName() const {return m_name;}
 float  area()
 {
  return (m_lenght * m_lenght * 3.14);
 }
};


class Parallelogram : public Figure //класс Параллелограм
{
 public:
 unsigned int m_injection;
 Parallelogram(std::string name, float lenght, float width, unsigned int injection) : Figure(name, lenght, width), m_injection(injection)
 {}
 std::string getName() const {return m_name;}
 float getLenght() const {return m_lenght;}
 float getWidth() const {return m_width;}
 virtual unsigned int getInjection() const {return m_injection;}
 float  area()
 {
  return (m_lenght * m_width * sin(m_injection*3.14/180));
 }
};


class Rectangle : public Parallelogram //класс Прямоугольник
{
 public:
 Rectangle(std::string name, float lenght, float width) : Parallelogram(name, lenght, width, 90)
 {}
 std::string getName() const {return m_name;}
 float  area()
 {
  return (m_lenght * m_width);
 }
};

class Square : public Parallelogram //класс Квадрат 
{
 public:
 Square(std::string name, float lenght) : Parallelogram(name, lenght, lenght, 90)
 {}
 std::string getName() const {return m_name;}
 float  area()
 {
  return (m_lenght * m_width);
 }
};

class Rhombus : public Parallelogram //класс Ромб
{
 public:
 Rhombus(std::string name, float lenght, unsigned int injection) : Parallelogram(name, lenght, lenght, injection)
 {}
 std::string getName() const {return m_name;}
 float  area()
 {
  return (m_lenght * m_width * sin(m_injection*3.14/180));
 }
};

void printFig(Figure &somefigure)
{
 std::cout << "area " << somefigure.getName() << " = " << somefigure.area() << std::endl;
}

//Задание №2 ********************************************************************************

class Car
{
 public:
 std::string m_company;
 std::string m_model;
 Car(std::string company, std::string model) : m_company(company), m_model(model)
 {
  std::cout << "Company: " << company << "\t\t" << "Model: " << model << std::endl;
 }
};

class PessengerCar : virtual public Car
{
 public:
 std::string m_engine;
 PessengerCar(std::string company, std::string model, std::string engine) : Car(company, model), m_engine(engine)
 {
  std::cout << "Engine: " << engine << std::endl;
 }
};

class Bus : virtual  public Car
{
 public:
 std::string m_chassis;
 Bus(std::string company, std::string model, std::string chassis) : Car(company, model), m_chassis(chassis)
 {
  std::cout << "Chassis: " << chassis << std::endl;
 }
};

class  Minivan : public PessengerCar, public Bus
{
 public:
 Minivan(std::string company, std::string model, std::string engine, std::string chassis)
 : PessengerCar(company, model, engine), Bus(company, model, chassis), Car(company, model)
 {}
};

//Задание №3 ********************************************************************************

class Fraction
{
 public:
 unsigned int m_numerator;
 unsigned int m_denominator;
 Fraction(unsigned int numerator, unsigned int denominator) 
 {
  if (denominator == 0)
  {
   m_denominator = 1;
   std::cout << "denominator = 1" << std::endl;
  }
  else
  {
   m_denominator = denominator;
  }
  m_numerator = numerator;
 }
 unsigned int getNum() const {return m_numerator;}
 unsigned int getDenom() const {return m_denominator;}
 friend Fraction operator+ (const Fraction &a1, const Fraction &a2);
 friend bool operator== (const Fraction &a1, const Fraction &a2);
};

Fraction operator+ (const Fraction &ad1, const Fraction &ad2)
{
 if (ad1.m_denominator == ad2.m_denominator)
 {
  return Fraction(ad1.m_numerator + ad2.m_numerator , ad1.m_denominator);
 }
 else
 {
  unsigned int a1 = ad1.m_numerator * ad2.m_denominator;
  unsigned int a2 = ad2.m_numerator * ad1.m_denominator;
  unsigned int b2 = ad2.m_denominator * ad1.m_denominator;
  return Fraction(a1 + a2, b2);
 }
}

bool operator== (const Fraction &ad1, const Fraction &ad2)
{
 if (ad1.m_denominator == ad2.m_denominator)
 {
  if(ad1.m_numerator == ad2.m_numerator)
  {
   std::cout << "fractions: " << ad1.m_numerator << "/" << ad1.m_denominator << " and " << ad2.m_numerator << "/" << ad2.m_denominator  << " equal" << std::endl;
   return true;
  }
  else
  {
   std::cout << "fractions: " << ad1.m_numerator << "/" << ad1.m_denominator << " and " << ad2.m_numerator << "/" << ad2.m_denominator  << " not equal" << std::endl;
   return false;
  }
 }
 else
 {
  unsigned int a1 = ad1.m_numerator * ad2.m_denominator;
  unsigned int a2 = ad2.m_numerator * ad1.m_denominator;
  if (a1 == a2)
  {
   std::cout << "fractions: " << ad1.m_numerator << "/" << ad1.m_denominator << " and " << ad2.m_numerator << "/" << ad2.m_denominator  << " equal" << std::endl;
   return true;
  }
  else
  {
   std::cout << "fractions: " << ad1.m_numerator << "/" << ad1.m_denominator << " and " << ad2.m_numerator << "/" << ad2.m_denominator  << " not equal" << std::endl;
   return false;
  }
 }
}

//Задание №4 ********************************************************************************

class Card
{
 public:
 bool m_side;
 enum Suit
 {
  Piki = 1,
  Tref = 2,
  Cherv = 3,
  Bubi = 4
 } m_suit;
 enum Value
 {
  two = 2, //2ка
  three = 3, //3ка
  four = 4, //4ка
  five = 5, //5ка
  six = 6, //6ка
  seven = 7, //7ка
  eight = 8, //8ка
  nine = 9, //9ка
  ten = 10, //10ка
  jack = 10, //валет
  lady = 10, //дама
  karol = 10, //кароль
  ace = 1 //туз
 } m_value;
 Card(bool side, int suit, int value) : m_side(side)
 {}
 
 void Flip() 
 {
  m_side = !m_side;
 }
 
 int getValue() const { return m_value;}
 bool getSide() const {return m_side;}
};


int main()
{
 std::cout << "Задание №1 ********************************************************************************" << std::endl;
 Circle circle("Circle", 2);
 Figure &rcircle = circle;
 printFig(rcircle);
 
 Parallelogram paral("Parallelogram", 7, 3, 45);
 Figure &rparal = paral;
 printFig(rparal);
 
 Rectangle rect("Rectangle", 12, 3);
 Figure &rrect = rect;
 printFig(rrect);
 
 Square square("Square", 4);
 Figure &rsquare = square;
 printFig(rsquare);
 
 Rhombus rhomb("Rhombus", 2, 45);
 Figure &rrhomb = rhomb;
 printFig(rrhomb);
 std::cout << std::endl;

 std::cout << "Задание №2 ********************************************************************************" << std::endl;
 Minivan Alphard("TOYOTA", "ALPHARD", "2GR-FE", "MNH-15W");
 std:: cout << std::endl;

 Car bmw("BMW", "X5");
 std:: cout << std::endl;

 PessengerCar harrier("TOYOTA", "HARRIER", "2GR-FE");
 std:: cout << std::endl;

 Bus hiace("TOYOTA", "HIACE", "MNH-15W");
 std::cout << std::endl;

 std::cout << "Задание №3 ********************************************************************************" << std::endl;
 Fraction a(2, 3);
 Fraction b(5, 3);
 Fraction c(4, 7);
 Fraction g(14, 6);
 std::cout << "g = " << g.getNum() << "/" << g.getDenom() << std::endl;
 Fraction d = a + b;
 std::cout << "d = " << d.getNum() << "/" << d.getDenom() << std::endl;
 Fraction e = a + c;
 std::cout << "e = " << e.getNum() << "/" << e.getDenom() << std::endl;
 d == g;
 d == e;
 std::cout << std::endl;

 return 0;
}
