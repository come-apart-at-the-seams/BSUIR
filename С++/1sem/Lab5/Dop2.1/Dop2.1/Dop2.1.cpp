// Dop2.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
int f(int n) {
	int k;
	if (n % 10 > 0) k = n % 10;
	else if (n == 0) k = 0;
	else k=f(n / 10);
	return k;
}
int s(int p, int q) {
	int sum=0;
	for (p; p <= q; p++) {
		sum += f(p);
	}
	return sum;
}
int main()
{
	int p,q;
	std::cout << "p= ";
	std::cin >>p;
	std::cout << "q=";
    std::cin >> q;
	std::cout << s(p,q);
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
