// Dop1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
void copy(char arr[], char arr_copy[]) {
	int i = 0;
	for ( i = 0; arr[i] != '\0'; i++) {
		arr_copy[i] = arr[i];
	}
	arr_copy[i++] = '\0';
}
int main()
{
	char str[101], str_copy[101];
	gets_s(str);
	int i = 0;
	
	for (i = 0; str[i]!='\0'; i++) {
		str_copy[i] = str[i];
	}
	str_copy[i++] = '\0';
	i = 0;
	for (i = 0; str[i] != '\0'; i++) {
			if (str[i] > 64 && str[i] < 91) { //CAPSLK
				if (str[i] == 'C') { 
					if (str[i+1] == 'e' || str[i+1] == 'i' || str[i+1] == 'y') str[i] = 'S'; 
					else str[i] = 'K'; }
				if (str[i] == 'Q') { 
					str[i] = 'K';
					if (str[i+1] == 'u') str[i+1] = 'v'; 
				}
				if (str[i] == 'W') { str[i] = 'V'; }
				if (str[i] == 'X') {
					str[i] = 'K';
					str[i + 1] = 's';
					for (int j = i + 1; str[j] != '\0'; j++) {
						str[j + 1] = str_copy[j];
					}
				}
				if (str[i] == 'P' && str[i + 1] == 'h') {
					str[i] = 'F';
					if (str[i + 2] == '\0') str[i + 1] = '\0';
					for (int j = i + 2; str[j] != '\0'; j++) {
						str[j - 1] = str_copy[j];
						if (str[j + 1] == '\0') str[j] = '\0';
					}
				}
				if (str[i] == 'O' && str[i + 1] == 'o') {
					str[i] = 'U';
					if (str[i + 2] == '\0') str[i + 1] = '\0';
					for (int j = i + 2; str[j] != '\0'; j++) {
						str[j - 1] = str_copy[j];
						if (str[j + 1] == '\0') str[j] = '\0';
					}
				}
				if (str[i] == 'E' && str[i + 1] == 'e') {
					str[i] = 'I';
					if (str[i + 2] == '\0') str[i + 1] = '\0';
					for (int j = i + 2; str[j] != '\0'; j++) {
						str[j - 1] = str_copy[j];
						if (str[j + 1] == '\0') str[j] = '\0';
					}
				}
				if (str[i] == 'T' && str[i + 1] == 'h') {
					str[i] = 'Z';
					if (str[i + 2] == '\0') str[i + 1] = '\0';
					for (int j = i + 2; str[j] != '\0'; j++) {
						str[j - 1] = str_copy[j];
						if (str[j + 1] == '\0') str[j] = '\0';
					}
				}
				if (str[i] == 'Y' && str[i + 1] == 'o' && str[i + 2] == 'u') {
					str[i] = 'U';
					if (str[i + 3] == '\0') str[i + 1] = '\0';
					for (int j = i + 3; str[j] != '\0'; j++) {
						str[j - 2] = str_copy[j];
						if (str[j + 1] == '\0') str[j - 1] = '\0';
					}
				}
				if (str[i] == str[i + 1]) {
					if (str[i + 2] == '\0') str[i + 1] = '\0';
					for (int j = i + 2; str[j] != '\0'; j++) {
						str[j - 1] = str_copy[j];
						if (str[j + 1] == '\0') str[j] = '\0';
					}
				}
				if (str[i] == str[i - 1]) {
					if (str[i + 1] == '\0') str[i] = '\0';
					for (int j = i + 1; str[j] != '\0'; j++) {
						str[j - 1] = str_copy[j];
						if (str[j + 1] == '\0') str[j] = '\0';
					}
				}
				copy(str, str_copy);

			}
			if (str[i] > 96 && str[i] < 123) { //  little
				if (str[i] == 'c') {
					if (str[i + 1] == 'e' || str[i + 1] == 'i' || str[i + 1] == 'y') str[i] = 's';
					else str[i] = 'k';
				}
				if (str[i] == 'q') {
					str[i] = 'k';
					if (str[i + 1] == 'u') str[i + 1] = 'v';
				}
				if (str[i] == 'w') { str[i] = 'v'; }
				if (str[i] == 'x') {
					str[i] = 'k';
					str[i + 1] = 's';
					for (int j = i+1; str[j]!='\0'; j++) {
						str[j+1] = str_copy[j];
					}
				}
				if (str[i] == 'p' && str[i + 1] == 'h') {
					str[i] = 'f';
					if (str[i + 2] == '\0') str[i + 1] = '\0';
					for (int j = i + 2; str[j] != '\0'; j++) {
						str[j - 1] = str_copy[j];
						if (str[j + 1] == '\0') str[j] = '\0';
					}
				}
				if (str[i] == 'o' && str[i + 1] == 'o') {
					str[i] = 'u';
					if (str[i + 2] == '\0') str[i + 1] = '\0';
					for (int j = i + 2; str[j] != '\0'; j++) {
						str[j - 1] = str_copy[j];
						if (str[j + 1] == '\0') str[j] = '\0';
					}
				}
				if (str[i] == 'e' && str[i + 1] == 'e') {
					str[i] = 'i';
					if (str[i + 2] == '\0') str[i + 1] = '\0';
					for (int j = i + 2; str[j] != '\0'; j++) {
						str[j - 1] = str_copy[j];
						if (str[j + 1] == '\0') str[j] = '\0';
					}
				}
				if (str[i] == 't' && str[i + 1] == 'h') {
					str[i] = 'z';
					if (str[i + 2] == '\0') str[i + 1] = '\0';
					for (int j = i + 2; str[j] != '\0'; j++) {
						str[j - 1] = str_copy[j];
						if (str[j + 1] == '\0') str[j] = '\0';
					}
				}
				if (str[i] == 'y' && str[i + 1] == 'o'&& str[i + 2] == 'u') {
					str[i] = 'u';
					if (str[i + 3] == '\0') str[i + 1] = '\0';
					for (int j = i + 3; str[j] != '\0'; j++) {
						str[j - 2] = str_copy[j];
						if (str[j + 1] == '\0') str[j-1] = '\0';
					}
				}
				if (str[i] == str[i + 1]) {
					if (str[i + 2] == '\0') str[i + 1] = '\0';
					for (int j = i + 2; str[j] != '\0'; j++) {
						str[j - 1] = str_copy[j];
						if (str[j + 1] == '\0') str[j] = '\0';
					}
				}
				if (str[i] == str[i - 1]) {
					if (str[i + 1] == '\0') str[i] = '\0';
					for (int j = i + 1; str[j] != '\0'; j++) {
						str[j - 1] = str_copy[j];
						if (str[j + 1] == '\0') str[j] = '\0';
					}
				}
				copy(str, str_copy);
			} 
	}
	for (int j = 0; str[j] != '\0'; j++) {
		std::cout << str[j];
	}

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
