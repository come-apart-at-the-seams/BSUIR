﻿// In1.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
int main()
{
//	char o,h;
//	int c,p,s=0,d;	
	//std::cout << ' '<< ' ' << 3 << '\r';
	//std::cout << ' ' << 2 << '\r';
	//std::cout << 1 << '\r';
	//std::cout << '\n';
	std::cout << "Vvedite dliny =";
	int per,h=0,i = 0;
	std::cin >> i;
    std::cout << "Vvedite chislo v 7 sisteme chislenia( !!! Dla starta nazmite simvl neprenadlezashiy [0;7] ) ";
	char c,d;

	std::cin >> c;
	while (/*c < 55 && c>47*/i>=0) {
		per = c - 48;
		h += per * pow(7, i-1);
		std::cin >> c;
		i--;
	}
	//std::cout << h;
	std::cout << '\n';
	int hh=h;
	i = 0;
	while (hh != 0) {
		hh /= 12;
		i++;
	}
	while (h!=0) {
		per = h % 12;
		if (per < 10) d = per + '0';
		if (per > 9) d = per+'A'-10;
		h /= 12;
		for (int j = 0; j < i; j++) std::cout << ' ';
		std::cout << d << '\r';
		i--;
	}
//	std::cout << '\n';
//	std::cout << c;

//	std::cin >> c;
//	p = c; 
//	if (c < 7) d = c;
//	if (c < 66) d = c / 10 * 7 + c%10;

//	std::cout << "\t 1" <<  '\r'; std::cout << '2';
/*	while (d != 0) {
		p = d % 12;
		d /=12;
		if (c!=0) std::cout << ' '<< p << '\r';
		if (c == 0) std::cout << ' ' << p;
	}*/


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
