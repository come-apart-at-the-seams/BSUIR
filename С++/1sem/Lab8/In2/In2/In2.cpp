// In2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <math.h>

struct tel
{
	char date[50];
	char code[6];
	char city[20];
	char time[12];
	char tariff[10];
	char num[20];
	char oun_num[25];
	
};
struct cit
{
	char city[20]="\0";
	
};
void del(char file[]) {
	std::ifstream sin;
	std::ofstream sout;
	char cha[100], st;
	int m = 0, mm = 0, line;
	std::cout << "# of line for delete is ";
	std::cin >> line;
	sout.open("Copy.txt");
	sout.close();
	sin.open(file);
	while (!sin.eof()) {
		sin >> cha;
		if (m % 7 == 0) mm = m / 7;
		if (mm == line) {
			m++;
			continue;
		}
		sout.open("Copy.txt", std::ofstream::app);
		sout << cha << ' ';
		if (m % 7 == 6) sout << '\n';
		sout.close();
		m++;

	}
	sin.close();
	sout.open(file);
	sout.close();
	sin.open("Copy.txt");
	while (sin.get(st)) {
		sout.open(file, std::ofstream::app);
		sout << st;
		sout.close();

	}
	sin.close();
}
void add(char file[]) {
	std::ifstream sin;
	std::ofstream sout;
	sout.open(file, std::ofstream::app);
	char z[100];
	std::cout << "Add :" << '\n';
	sout << '\n';
	std::cout << "date" << '\n';
	std::cin >> z;
	sout << z << ' ';
	std::cout << "code" << '\n';
	std::cin >> z;
	sout << z << ' ';
	std::cout << "city" << '\n';
	std::cin >> z;
	sout << z << ' ';
	std::cout << "time" << '\n';
	std::cin >> z;
	sout << z << ' ';
	std::cout << "tariff" << '\n';
	std::cin >> z;
	sout << z << ' ';
	std::cout << "num" << '\n';
	std::cin >> z;
	sout << z << ' ';
	std::cout << "oun_num" << '\n';
	std::cin >> z;
	sout << z << ' ';
	sout.close();
}
void input(char file[], char log[]) {
	std::ifstream sin;
	std::ofstream sout;
	sout.open(log);
	sin.open(file);
	if (!sin.is_open()) {
		std::cout << "ERROR\n" << std::endl;
	}
	else {
		std::cout << "..........." << file << " is open...........\n";
		char ch[500];
		int i = 0, n = 0;
		//создание массива структур



		while (!sin.eof()) {
			sin >> ch;
			n++;
		}
		if (n % 7 == 0)n /= 7;
		else {
			n /= 7;
			n++;
		}
		tel* arr = new tel[n];
		cit* mas = new cit[n];
		n = 0;


		//установка курсора в 0
		sin.clear();
		sin.seekg(0);
		//запись структур
		while (!sin.eof()) {
			ch[0] = 0;
			sin >> ch;
			if (i == 7) {
				i = 0;
				n++;
			}
			std::cout << ch << '\n';
			//запись в массив
			if ((ch[0] != ' ') && (ch[0] != '\0')) {
				if (i == 0) strcpy_s(arr[n].date, ch);
				else if (i == 1) strcpy_s(arr[n].code, ch);
				else if (i == 2) strcpy_s(arr[n].city, ch);
				else if (i == 3) strcpy_s(arr[n].time, ch);
				else if (i == 4) strcpy_s(arr[n].tariff, ch);
				else if (i == 5) strcpy_s(arr[n].num, ch);
				else if (i == 6) strcpy_s(arr[n].oun_num, ch);
				i++;
			}
		}
		sin.close();
		//                                         вывод и подсчёт
		int u = n;
		for (int j = 0; j < u; j++) strcpy_s(mas[j].city, arr[j].city);
		for (int j = 0; j < u; j++) {
			for (int l = j + 1; l < u; l++) {
				if (!strcmp(arr[l].city, mas[l].city)) {
					for (int w = l; w < u - 1; w++)
					{
						strcpy_s(mas[w].city, mas[w + 1].city);
					}
					u -= 1;

					if (mas[j].city == mas[l].city)
					{
						l--;
					}
				}
			}
		}




		for (int q = 0; q < u; q++) {
			int h[12], g = 0, tar;
			float t = 0, s = 0;
			i = 0;
			strcpy_s(ch, mas[q].city);
			//подсчёт времени и суммы
			for (int j = 0; j < n; j++) {
				if (!strcmp(arr[j].city, ch)) {
					int k = 0;
					while (arr[j].time[k] != '\0') {
						h[k] = arr[j].time[k] - '0';
						k++;
					}
					g = 0;
					for (int m = 0; m < k; m++) {
						g += h[m] * pow(10, k - m - 1);
					}
					t += g;
					k = 0;
					while (arr[j].tariff[k] != '\0') {
						h[k] = arr[j].tariff[k] - '0';
						k++;
					}
					tar = 0;
					for (int m = 0; m < k; m++) {
						tar += h[m] * pow(10, k - m - 1);
					}
					if (g % 60 == 0) g /= 60;
					else {
						g /= 60;
						g++;
					}
					s += tar * g;
				}

			}
			if (!sout.is_open()) {
				std::cout << "ERROR\n" << std::endl;
			}
			else {
				sout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////";
				sout << '\n';
				sout << '\n';
				sout << "Total time of calls to " << ch << " is " << t << " s or " << t / 60. << " min or " << t / 3600. << " h or " << t / 3600. / 24 << " days" << '\n';
				sout << "The total amount of money received from calls to the city of " << ch << " is " << s << " cents or " << s / 100. << " $" << '\n';
				sout << '\n';
			}
			std::cout << '\n';
			std::cout << "Total time of calls to " << ch << " is " << t << " s or " << t / 60. << " min or " << t / 3600. << " h or " << t / 3600. / 24 << " days" << '\n';
			std::cout << "The total amount of money received from calls to the city of " << ch << " is " << s << " cents or " << s / 100. << " $" << '\n';
			std::cout << '\n';


		}
	}

	sout.close();
}
void ini(char file[]) {
	std::ifstream sin;
	std::ofstream sout;
	sout.open(file, std::ofstream::app);
	sout.close();
}
int main()
{
    std::cout << "Hello World!\n";
	
	
	char file[22] = "TelephoneExchange.txt", log[25] = "TelephoneExchangeLog.txt";
	
	ini(file);
	char fun;
	std::cout << "1 - delete; 2 - add\t";
	std::cin >> fun;
	if (fun == '1') del(file);
	else if (fun == '2') add(file);
	input(file, log);
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
