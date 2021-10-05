// Dop@.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
	int n,sum,sum2;
	std::cout << "VveDiTe n= ";
	std::cin >> n;
	int* pr1 = new int [n+1];
	int* pr2 = new int[n];
	int** mas = new int*[n];
	int** arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		mas[i] = new int[n];
	}
	if (n != 2) {
		if (n % 2 != 0) { //нечетный квадарат
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					arr[i][j] = 1 + ((i + 1 + j + ((n - 1) / 2)) % n) * n + ((i + 2 * (j + 1) + 2) % n);
				}
			}
		}
		if (n % 2 == 0 && n % 4 != 0) { //четный не делящийся на 4 квадрат

			for (int i = 0; i < n / 2; i++) { //1 четв
				for (int j = 0; j < n / 2; j++) {
					arr[i][j] = 1 + ((i + 1 + j + 1 - 1 + ((n / 2 - 1) / 2)) % (n / 2)) * (n / 2) + ((i + 2 * (j + 1) + 2) % (n / 2));
				}
			}
			for (int i = 0; i < n / 2; i++) {//2 четв
				for (int j = n / 2; j < n; j++) {
					arr[i][j] = 19 + ((i + 1 + j + 1 - 1 + ((n / 2 - 1) / 2)) % (n / 2)) * (n / 2) + ((i + 2 * (j + 1) + 2) % (n / 2));
				}
			}
			for (int i = n / 2; i < n; i++) {//3 четв
				for (int j = 0; j < n / 2; j++) {
					arr[i][j] = 28 + ((i + 1 + j + 1 - 1 + ((n / 2 - 1) / 2)) % (n / 2)) * (n / 2) + ((i + 2 * (j + 1) + 2) % (n / 2));
				}
			}
			for (int i = n / 2; i < n; i++) {//4 четв
				for (int j = n / 2; j < n; j++) {
					arr[i][j] = 10 + ((i + 1 + j + 1 - 1 + ((n / 2 - 1) / 2)) % (n / 2)) * (n / 2) + ((i + 2 * (j + 1) + 2) % (n / 2));
				}
			}
			for (int i = 0; i < n; i++) { //копирование массива
				for (int j = 0; j < n; j++) {
					mas[i][j] = arr[i][j];
				}
			}
			int a;
			a = n / 4;
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < a; j++) {
					arr[i][j] = mas[n / 2 + i][j];
					arr[n / 2 + i][j] = mas[i][j];
					arr[n / 2 - a + i][j] = mas[n - a + i][j];
					arr[n - a + i][j] = mas[n / 2 - a + i][j];
				}
			}
			for (int j = 0; j < a - 1; j++) {
				for (int i = 0; i < n / 2; i++) {
					arr[i][n - 1 - j] = mas[n / 2 + i][n - 1 - j];
					arr[n / 2 + i][n - 1 - j] = mas[i][n - 1 - j];
				}
			}
			int k;
			k = (n - 2) / 4;
			for (int i = 0; i < k; i++) {
				arr[(n / 2 - 1) / 2][(n / 2 - 1) / 2 - k + 1 + i] = mas[(n / 2 - 1) / 2 + n / 2][(n / 2 - 1) / 2 - k + 1 + i];
				arr[(n / 2 - 1) / 2 + n / 2][(n / 2 - 1) / 2 - k + 1 + i] = mas[(n / 2 - 1) / 2][(n / 2 - 1) / 2 - k + 1 + i];
			}
		}
		if (n % 4 == 0) { //четный делящийся на 4 квадрат
			int k = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					arr[i][j] = n * n - k;
					k++;
				}
			}
			for (int i = 0; i < n; i++) { //копирование массива
				for (int j = 0; j < n; j++) {
					mas[i][j] = arr[i][j];
				}
			}
			k = n / 4;
			for (int i = 0; i < k; i++) {
				for (int j = 0; j < k; j++) {
					arr[i][j] = mas[n - 1 - i][n - 1 - j];
					arr[n - 1 - i][n - 1 - j] = mas[i][j];
					arr[n - 1 - i][j] = mas[i][n - 1 - j];
					arr[i][n - 1 - j] = mas[n - 1 - i][j];
				}
			}
			int a;
			k = n / 4;
			a = n / 2;
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < a; j++) {
					arr[k + i][k + j] = mas[k - 1 + a - i][k - 1 + a - j];
				}
			}
		}


		//вывод и массивы проверки
		for (int i = 0; i < n; i++) { //заполнение массива проверки 
			sum2 = 0;
			sum = 0;
			for (int j = 0; j < n; j++) {
				sum2 = sum2 + arr[j][i];
				sum = arr[i][j] + sum;
			}
			pr2[i] = sum2;
			pr1[i] = sum;
		}
		pr1[n] = 0;
		pr2[n] = 0;
		for (int i = 0; i < n; i++) {
			pr1[n] = arr[i][i] + pr1[n];
		}
		for (int i = 0; i < n; i++) {
			pr2[n] = arr[n - i - 1][n - i - 1] + pr2[n];
		}
		for (int i = -1; i < n; i++) { //вывод массивов проверки и квадрата
			if (i == -1) {
				for (int j = 0; j <= n; j++) {
					std::cout << "=" << pr2[j] << '\t';
				}
				std::cout << '\n';
			}
			else {
				for (int j = 0; j < n; j++) {
					std::cout << arr[i][j] << '\t';
				}

				std::cout << "= " << pr1[i] << '\n';
			}
			if (i == n - 1) {
				for (int j = 0; j < n; j++) std::cout << '\t';
				std::cout << "=" << pr1[n] << '\n';
			}
		}
	}
	else std::cout << "APPLICAION ERROR CODE: 2";
	std::cout << '\n';
	std::cout << '\n';
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
		delete[] mas[i];
	}
	delete[] arr;
	delete[] mas;
	delete[] pr2;
	delete[] pr1;
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
