// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
struct shop
{
	char name[50];
	char name2[50];
	char name3[50];
	char address[50];
	int house;
	int discount;
	void out(shop q) {
		std::cout << q.name << " " << q.name2 << " " << q.name3 << " " << q.address << " " << q.house << " " << q.discount << "\n";
	}
};
void sort1(shop* arr, int n) // сортировка вставками
{
	int* mi = new int[n];
	for (int i = 0; i < n; i++) {
		mi[i] = arr[i].name[0] - 'a';
	}
	shop b;
	int bi;
	//char b[50]; // временная переменная для хранения значения элемента сортируемого массива
	int a; // индекс предыдущего элемента
	for (int i = 1; i < n; i++)
	{
		bi = mi[i];
		b = arr[i];
		//strcpy_s(b,arr[i].name); // инициализируем временную переменную текущим значением элемента массива
		a = i - 1; // запоминаем индекс предыдущего элемента массива
		while (a >= 0 && mi[a]>bi) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
		{
			arr[a + 1] = arr[a]; // перестановка элементов массива
			mi[a + 1] = mi[a];
			//strcpy_s(arr[a].name, b);
			arr[a] = b;
			mi[a] = bi;
			a--;
		}
	}
}


void sort(shop * arr, int length) // сортировка вставками
{
	int a, b, c; // временная переменная для хранения значения элемента сортируемого массива
	for (int i = 1; i < length; i++)
	{
		b = arr[i].name[0]-'a';
		a = i - 1; 
		c = arr[a].name[0] - 'a'; // запоминаем индекс предыдущего элемента массива
		while (a>= 0 && c > b) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
		{
			strcpy_s(arr[a+1].name, arr[a].name); // перестановка элементов массива
			c = b;
			a--;
		}
	}
}
void out(shop * arr,int n){
	for (int i = 0; i < n; i++) arr[i].out(arr[i]);
}
void pro(shop* arr, int n) {
	for (int i = 0; i < n; i++) {
		if (arr[i].discount == 5) arr[i].out(arr[i]);
	}
}
int main()
{
	shop *arr=new shop[1];
	shop* mas = new shop[1];
	int k = 0, n= 1, j;
	
	do {
		j = n - 1;
		std::cout << "name - ";
		std::cin >> arr[j].name;
		std::cout << "name2 - ";
		std::cin >> arr[j].name2;
		std::cout << "name3 - ";
		std::cin >> arr[j].name3;
		std::cout << "Address- ";
		std::cin >> arr[j].address;
		std::cout << "House- ";
		std::cin >> arr[j].house;
		std::cout << "% discount - ";
		std::cin >> arr[j].discount;
		std::cout << "press 1 - ";
		std::cin >> k;
		if (k == 1) {
			for (int i = 0; i < n; i++) {
				strcpy_s(mas[i].name, arr[i].name);
				strcpy_s(mas[i].name2, arr[i].name2);
				strcpy_s(mas[i].name3, arr[i].name3);
				strcpy_s(mas[i].address, arr[i].address);
				mas[i].house = arr[i].house;
				mas[i].discount = arr[i].discount;
			}
			n++;
			delete[] arr;
			arr = new shop[n];
			n--;
			for (int i = 0; i < n; i++) {
				strcpy_s(arr[i].name, mas[i].name);
				strcpy_s(arr[i].name2, mas[i].name2);
				strcpy_s(arr[i].name3, mas[i].name3);
				strcpy_s(arr[i].address, mas[i].address);
				arr[i].house = mas[i].house;
				arr[i].discount = mas[i].discount;
			}
			n++;
			delete[] mas;
			mas = new shop[n];

		}
		std::cout << '\n';
	} while (k == 1);
	std::cout << '\n';
	out(arr,n);
	
	sort1(arr, n);

	std::cout << " 5% "<< '\n'; 
	pro(arr, n);
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
