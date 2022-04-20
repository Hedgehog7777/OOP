#include <iostream>


class DivisionByZero
{
private:
	std::string m_message;
public:
	DivisionByZero(std::string message = "") : m_message(message) {}
	const std::string& getMessage() const { return m_message; }
};

namespace my
{

template <typename T>
double div(T a, T b)
{
	if (b == 0)
		throw DivisionByZero("Деление на ноль!");

	return a / b;
}

}


int main()
{
 try
	{
		double result = my::div(10, 0);
		std::cout << result << std::endl;
	}
	catch (const DivisionByZero& e)
	{
		std::cerr << e.getMessage() << std::endl;
	}

}
