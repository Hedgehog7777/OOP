#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Card
{
 public:
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
  ace  //туз
 } m_value;
 private:
 bool m_side;
 public:
 Card(bool side, int suit, int value) : m_side(side)
 {}
 
 void Flip() 
 {
  m_side = !m_side;
 }
 
 int getValue() const { return m_value;}
 bool getSide() const {return m_side;}
};


class Hand
{
 protected:
 vector<Card*> m_Cards;
 
 public:
 Hand ()  {}
 virtual ~Hand()
 {
  Clear();
 }
 
 void Add(Card* pCard) //Добавляет карту в руку. Добавляет указатель на объект типа Сard в вектор m_Сards
 {
  m_Cards.push_back(pCard);
 }
 void Clear() //Очищает руку от карт. Удаляет все указатели из вектора m_Сards, устраняя все связанные с ними объекты в куче
 {
  vector<Card*>::iterator iter = m_Cards.begin();
  for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
  {
   delete *iter;
   *iter = 0;
  }
  m_Cards.clear();
 }
 
 int GetTotal()  //Возвращает сумму очков карт руки
 {
  if (m_Cards.empty())
  {
   return 0;
  }
  
  if (m_Cards[0]->getValue() == 0)
  {  
   return 0;
  }
 
  int total = 0;
  vector<Card*>::const_iterator iter;
  for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
  {
   total += (*iter)->getValue();
  }
  
  bool containsAce = false;
  for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
  {
   if ((*iter)->getValue() == Card::ace)
   {
    containsAce = true;
   }
  }

  if (containsAce && total <= 11)
  {
   total += 10;
  }
  return total;
 }
 
};

class GenericPlayer: public Hand
{
 private:
 string m_name;
 public:
 GenericPlayer(string a) : m_name(a) {}
 
 virtual bool IsHitting() // чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
 {
  if (GetTotal()<21)
  {
   return 1;
  }
  else
  {
   if  (GetTotal()==21)
   {
    return 0;
   }
   else 
   {
    Bust();
    return 0;
   }
  }
 }
 bool IsBusted() //возвращает bool значение, есть ли у игрока перебор
 {
  if(GetTotal()>21)
  {
   return 1;
  }
  else
  return 0;
 }
 void Bust() //выводит на экран имя игрока и объявляет, что у него перебор.
 {
  cout << m_name << " Player BUST!!! " << endl;
 }
};
int main()
{

 
 
 return 0;
}
