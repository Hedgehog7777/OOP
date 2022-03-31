#include <iostream>
#include <string>

//Задание №1 ********************************************************************************

unsigned int count = 0;

class Person
{
 public:
 std::string m_name;
 bool m_gender;
 unsigned int m_age;
 unsigned int m_weight;
 
 Person(std::string name , bool gender, unsigned int age, unsigned int weight)
 : m_name(name), m_gender(gender), m_age(age), m_weight(weight)
 {
 }
 
 void printP() 
 {
  std::cout << "Person: " << m_name << std::endl; 
  if(m_gender)
  {
   std::cout<< "Gender: Women" << std::endl;
  }
  else
  {
   std::cout<< "Gender: Men" << std::endl;
  } 
  std::cout << "Age = " <<  m_age << "\n" << "Weight = " << m_weight << std::endl;
 }
  
 void setName(std::string name) {m_name = name;}
 std::string getName() const {return m_name;}
 
 void setGender(bool gender) {m_gender = gender;}
 bool getGender() const {return m_gender;}
 
 void setAge(int age) {m_age = age;}
 int getAge() const {return m_age;}
 
 void setWeight(int weight) {m_weight = weight;}
 int getWeight() const {return m_weight;}

};

class Student : public Person
{
 public:
 int m_year;
 
 Student(std::string name , bool gender, unsigned int age, unsigned int weight, int year)
 : Person(name, gender, age, weight), m_year(year)
 {
 count += 1;
 }
  
 void printS()
 {
  printP();
  std::cout << "Year of study = " << m_year << std::endl;  
  std::cout << "Student couunter = " << count << "\n" << std::endl;
 }
 
 void setYear(int year) {m_year = year;}
 int getYear() const {return m_year;}
 
 void UpYear()
 {
  setYear(getYear() + 1);
 }

};

//Задание №2 ********************************************************************************

class Fruit
{
 public:
 std::string m_name;
 std::string m_color;
 
 Fruit(std::string name, std::string color)
 :m_name(name), m_color(color)
 {
 }
 
 void setName(std::string name) {m_name = name;}
 std::string getName() const {return m_name;}
  
 void setColor(std::string color) {m_color = color;}
 std::string getColor() const {return m_color;}
  
};

class Apple : public Fruit
{
 std::string name = "apple";
 public:
 Apple(std::string color)
 :Fruit("apple", color)
 {
 }
};

class Banana : public Fruit
{
 public:
 Banana()
 :Fruit("banana", "yellow")
 {
 }
};

class GrannySmith : public Apple
{
 public:
 GrannySmith()
 :Apple("green")
 {
  setName("Granny Smith apple");
 }
};

//Задание №3 ********************************************************************************

/* Наверное для игры я бы создал базовый класс самой игры и два или более в зависимости от количества игроков производных из нее класа 
из которых выходили классы карт которые находятся на руках игроков и дилеера и еще наверное отдельный класс колоды карт 
*/
int main()
{
 std::cout << "Задание №1 ********************************************************************************" << std::endl;
 Student Momo("MOMO", 1, 26, 78, 1990);
 Momo.printS();
 Momo.UpYear();
 Momo.printS();
 
 Student Anton("Anton", 0, 22, 65, 2020);
 Anton.printS();
 
 Student Totoro("Totoro", 0, 16, 100, 1988);
 Totoro.printS();
 
 std::cout << "Задание №2 ********************************************************************************" << std::endl;
 Apple a("red");
 Banana b;
 GrannySmith c;
 std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
 std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
 std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";



 return 0;
}
