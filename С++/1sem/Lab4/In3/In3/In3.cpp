// In3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
	int n,smax,smin,max,min;
    std::cout << "n=";
	std::cin >> n;
	float **arr = new float*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new float[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << "arr[" << i << "][" << j << "]=";
			std::cin>> arr[i][j];
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	min = arr[0][0];
	max = min;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] < min) {
				min = arr[i][j];
				smin = i;
			}
			if (arr[i][j] > max) {
				max = arr[i][j];
				smax = i;
			}
		}

	}
	if (smax != smin) {
		int* mmin = new int[n];
		int* mmax = new int[n];
		for (int j = 0; j < n; j++) {
			mmax[j] = arr[smax][j];
			mmin[j] = arr[smin][j];
		}
		for (int j = 0; j < n; j++) {
			arr[smin][j] = mmax[j];
			arr[smax][j] = mmin[j];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				std::cout << arr[i][j] << '\t';
			}
			std::cout << '\n';
		}
	}
	else std::cout << "CTPoka = CToJl6y";


	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
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
