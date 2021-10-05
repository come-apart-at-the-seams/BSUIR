// Dop1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>





void comp(int* arr,int n) {
	int a=1;
	for (int i = 0; i < n;i++) {
		a *= arr[i];
	}
	std::cout <<'\n'<<"composition= "<< a;
}
void output(int* arr, int n) {
	std::cout << "array is ";
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << '\t';
	}
}
void delarr(int** a,int n) {
	for (int i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
}
int main()
{
	int n,k;
	std::cout << "Vvedite n= ";
	std::cin >> n;
	std::cout << "Vvedite k= ";
	std::cin >> k;

	int** a = new int*[n];// array initialization
	for (int i = 0; i < n; i++) {
		a[i] = new int[k];
	}

	std::cout << "Vvedite massiv \n"; // array fillin'
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			std::cout << "a[" << i << "][" << j << "]= ";
			std::cin >> a[i][j];
		}
	}
		std::cout << '\n';

	int o;
	if (n > k) o = k;
	else o = n;
	int l = 0;
	for (int j = 0; j < o; j++) {
		if (a[j][j] % 2 == 0) l++;
	}
	if (l > 0) {
		int* arr = new int[l];
		int g = 0;
		for (int j = 0; j < o; j++) {
			if (a[j][j] % 2 == 0) {
				arr[g] = a[j][j];
				g++;
			}
		}
		output(arr, l);
		comp(arr, l);
		delete[] arr;
	}
	else std::cout << "error";

	delarr(a,n);
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
