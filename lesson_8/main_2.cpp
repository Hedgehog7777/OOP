#include <iostream>

class Ex
{
public:
	double m_x;

	Ex(double x) : m_x(x) {};
};

class Bar
{
private:
	double m_y;
public:
	Bar(double y = 0.0) : m_y(y) {}
	void set(double a)
	{
		if ((m_y + a) > 100)
			throw Ex(a * m_y);
		else
			m_y = a;
	}
};

int main()
{

Bar a;
	int b;

	try
	{
		while (true)
		{
			std::cin >> b;
			if (b == 0)
				break;
			a.set(b);
		}
	}
	catch (const Ex& e)
	{
		std::cout << e.m_x << std::endl;
	}
	
}
