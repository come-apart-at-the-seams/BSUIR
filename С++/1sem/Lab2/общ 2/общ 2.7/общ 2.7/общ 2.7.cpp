// общ 2.7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>

int main()
{
	float a, b, c, x;
    std::cout << "a,b,c \n";
	std::cin >> a >> b >> c;
	c = pow(b, 2) - 4 * a * c;
	if (c >= 0)
	{
		x = (-b + pow(c, 0.5)) / (2 * a);
		if (x < 0) std::cout << "E/R";
		else {
			x = pow(x, 0.5);
			std::cout << x << '\t'<< -x << '\t';
		}
		c = (-b - pow(c, 0.5)) / (2 * a);
		if (c < 0) std::cout << "E/R";
		else {
			c = pow(c, 0.5);
			std::cout << c <<'\t'<< -c;
		}
	}
	else std::cout << "ERROR";
	c = pow(b, 2) - 4 * a * (c-2*a);
	x = (-b + pow(c, 0.5)) / (2 * a);
	c= pow(x, 2) - 4;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
