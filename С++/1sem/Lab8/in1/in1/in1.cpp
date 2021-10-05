

#include <iostream>
struct shop
{
	char name[50];
	char address[50];
	int discount;
	void out(shop q) {
		std::cout << q.name <<" " << q.address << " " << q.discount << "\n";
	}
};
int main()
{
	setlocale(LC_ALL, "rus");

	int i = 1;
	int j = 0;
	int n = 1;
	shop* mas = new shop[n];
	shop* arr = new shop[n];
	while (i == 1) {
		
		std::cout << "Введите ФИО - ";
		std::cin >> arr[n].name;
		std::cout << "Введите адрес - ";
		std::cin >> arr[n].address;
		std::cout << "Введите % скидки - ";
		std::cin >> arr[n].discount;
		std::cout << "Чтобы продолжить нажмите 1 ";
		std::cin >> i;
		if (i == 1) {
			n++;
			for (int i = 0; i < n; i++) {
				strcpy_s(mas[i].name, arr[i].name);
				strcpy_s(mas[i].address, arr[i].address);
				mas[i].discount = arr[i].discount;
			}
			delete[] arr;
			n++;
			shop* arr = new shop[n];
			for (int i = 0; i < n; i++) {
				strcpy_s(arr[i].name, mas[i].name);
				strcpy_s(arr[i].address, mas[i].address);
				arr[i].discount = mas[i].discount;
			}
			delete[] mas;
			shop* mas = new shop[n];
		}
	}

	delete[] mas;
 	delete[] arr;
}

