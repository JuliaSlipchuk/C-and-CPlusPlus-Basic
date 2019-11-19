
#include "pch.h"
#include <iostream>

// якщо приберемо ';' - отримаємо помилку під час компіляції 'expected a ';''
// якщо змінимо ім'я методу main на якесь інше - отримаємо помилку про те, що немає точки входу програми (main такою є)
int main()
{
	std::cout << "Hello World! \n";
	std::cout << "Hello \n C++!";

	return 0;
}
