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
 int a = m_Cards.size();
  for (int i = 0; i < a; i++)
   m_Cards.pop_back();
  
  m_Cards.clear();
 }
 
 int GetValue() const  //Возвращает сумму очков карт руки
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
  for (int i =0; i < m_Cards.size() ; i++)
  {
   total += m_Cards[i]->getValue();
  }
  
  bool containsAce = false;
  for (int i =0; i < m_Cards.size() ; i++)
  {
   if (m_Cards[i]->getValue() == Card::ace)
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
    friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);
protected:
 string m_name;
 public:
 GenericPlayer(string a) : m_name(a) {}
 
 virtual bool IsHitting() // чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
 {
  if (GetValue()<21)
  {
   return 1;
  }
  else
  {
   if  (GetValue()==21)
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
  if(GetValue()>21)
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

//Задание №3 ********************************************************************************

 class Player : public GenericPlayer
{
public:
    Player(const string& name = "") : GenericPlayer(name) { }

    virtual ~Player() { }

    virtual bool IsHitting() const
    {
        cout << m_name << ", do you want a hit? (Y/N): ";
        char response;
        cin >> response;
        return (response == 'y' || response == 'Y');
    }

    void Win() const
    {
        cout << m_name <<  " wins.\n";
    }

    void Lose() const
    {
        cout << m_name <<  " loses.\n";
    }

    void Push() const
    {
        cout << m_name <<  " pushes.\n";
    }
};

//Задание №4 ********************************************************************************


class House : public GenericPlayer
{
public:
    House(const string& name = "House") : GenericPlayer(name) { }

    virtual ~House() { }

    virtual bool IsHitting() const
    {
        return (GetValue() <= 16);
    }

    void FlipFirstCard()
    {
        if (!(m_Cards.empty()))
            m_Cards[0]->Flip();
        else
    		cout << "Нет карты для переворота!\n";
    }
};

 //Задание №5 ********************************************************************************

ostream& operator<<(ostream& os, const Card& aCard)
{
    const string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9",
                            "10", "J", "Q", "K"};
    const string SUITS[] = {"c", "d", "h", "s"};

    if (aCard.getSide())
        os << RANKS[aCard.m_value] << SUITS[aCard.m_suit];
    else
        os << "XX";

    return os;
}


int main()
{
 return 0;
}
