// Dop1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
	int m, n,k,s=0,kols=0;
	std::cout << "KoJl-Bo cTPok= ";
	std::cin >> n;
	std::cout<< '\n' << "KoJl-Bo cTJl6oB= ";
	std::cin >> m;
	int* mas_k = new int[n];
	int** arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = rand() % 2;
			std::cout << arr[i][j] << '\t';
		}
		std::cout <<'\n';
	}
	std::cout << '\n';
	for (int i = 0; i < n; i++) {
		k = 1;
		for (int j = 0; j < n; j++) {
			if (j == n - 1) break;
			if (arr[i][j] == arr[i][j + 1]) {
				k++;
			}
		}
		mas_k[i] = k;
		if (s < mas_k[i]) s = mas_k[i];
		std::cout << mas_k[i] << '\n';
	}
	for (int i = 0; i < n; i++) {
		if (s == mas_k[i]) std::cout << '\n'<<"nomer stroki = "<< i;
		if (s == mas_k[i]) kols++;
	}
	std::cout << '\n' << "kol-vo strok c odinakovoy dlinnoy posledov = " << kols<< '\n';


	for (int i = 0; i < n; i++) delete[] arr[i];
	delete[] arr;
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
