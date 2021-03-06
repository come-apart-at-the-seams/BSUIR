// in2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// 0 1 2 3 4 5 6 7

#include <iostream>
#include <math.h>
#include <conio.h>

bool fun(float* arr, int m, int n) {
	if (n == m) return sin(arr[m]) > 0;
	return (fun(arr, m, (m + n) / 2)) | (fun(arr, (n + m) / 2 + 1, n));
}
int main()
{
/*	//загрузка DLL
	HINSTANCE load;
	load = LoadLibrary(L"DLL3121.dll");
	//получение указателя на функцию
	// pfsum – произвольное имя
	typedef double(__stdcall* pfsum)(float, int, int);
	pfsum fun;
	// функция API Windows GetProcAddress используется для
	//получения указателя на функцию, где
	//load – указатель на загруженный модуль DLL
	//f1 – имя функции
	fun = (pfsum)GetProcAddress(load, "fun");*/

	int n,m;
    std::cout << "N=";
	std::cin >> n;
	m = n / 2;
	float *arr =new float[n];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
		arr[i] *= 3.14 / 180;
	}
	std::cout <<".....0 or 1..... \t"<< fun(arr,0, n);

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
