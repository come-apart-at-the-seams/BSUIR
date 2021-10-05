#include <iostream>
struct shop
{
	char name[50];
	char address[50];
	int discount;
	void out(shop q) {
		std::cout << q.name << " " << q.address << " " << q.discount << "\n";
	}
};
int main()
{

	int i = 1;
	int j = 0;
	int n = 1;
	shop* mas = new shop[n];
	shop* arr = new shop[n];
	while (i == 1) {

		std::cout << "name - ";
		std::cin >> arr[j].name;
		std::cout << "Address- ";
		std::cin >> arr[j].address;
		std::cout << "% discount - ";
		std::cin >> arr[j].discount;
		std::cout << "press 1 - ";
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
			arr = new shop[n];
			for (int i = 0; i < n-1; i++) {
				strcpy_s(arr[i].name, mas[i].name);
				strcpy_s(arr[i].address, mas[i].address);
				arr[i].discount = mas[i].discount;
			}
			delete[] mas;
			mas = new shop[n];
			j++;
		}
	}

	delete[] mas;
	delete[] arr;
}