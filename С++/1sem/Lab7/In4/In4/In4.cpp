// In4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
int len(char str[]) {
	int a = 0;
	while (str[a] != '\0') a++;
	return a;
}
void output(char c[]) {
	int a = 0;
	while (c[a] != '\0') {
		std::cout << c[a];
		a++;
	}
	std::cout << '\n';
}
void revers(char c[], int lc) {
	char cs[1000];
	for (int i = 0; i < lc; i++) {
		cs[i] = c[lc - 1 - i];
	}
	for (int i = 0; i < lc; i++) {
		c[i] = cs[i];
	}
	c[lc] = '\0';

}
void f1(char x[], char a[], int i) {
	int j = i + 1;
	if (x[j] == '1') {
		if (a[j] < '9' && a[j] >= '0') a[j] = a[j] + 1;
		else if (a[j] == '9') a[j] = 'a';
		else if (a[j] == 'a') a[j] = 'b';
		else if (a[j] == 'b') f1(x, a, j);
	}
	else if (x[j] == '2') {
		if (a[j] < '8' && a[j] >= '0') a[j] = a[j] + 2;
		else if (a[j] == '8') a[j] = 'a';
		else if (a[j] == '9') a[j] = 'b';
		else if (a[j] == 'a') {
			a[j] = '0';
			f1(x, a, j);
		}
		else if (a[j] == 'b') {
			a[j] = '1';
			f1(x, a, j);
		}
	}
	else if (x[j] == '3') {
		if (a[j] < '7' && a[j] >= '0') a[j] = a[j] + 3;
		else if (a[j] == '7') a[j] = 'a';
		else if (a[j] == '8') a[j] = 'b';
		else if (a[j] == '9') {
			a[j] = '0';
			f1(x, a, j);
		}
		else if (a[j] == 'a') {
			a[j] = '1';
			f1(x, a, j);
		}
		else if (a[j] == 'b') {
			a[j] = '2';
			f1(x, a, j);
		}
	}
	else if (x[j] == '4') {
		if (a[j] < '6' && a[j] >= '0') a[j] = a[j] + 4;
		else if (a[j] == '6') a[j] = 'a';
		else if (a[j] == '7') a[j] = 'b';
		else if (a[j] == '8') {
			a[j] = '0';
			f1(x, a, j);
		}
		else if (a[j] == '9') {
			a[j] = '1';
			f1(x, a, j);
		}
		else if (a[j] == 'a') {
			a[j] = '2';
			f1(x, a, j);
		}
		else if (a[j] == 'x') {
			a[j] = '3';
			f1(x, a, j);
		}
	}
	else if (x[j] == '5') {
		if (a[j] < '5' && a[j] >= '0') a[j] = a[j] + 5;
		else if (a[j] == '5') a[j] = 'a';
		else if (a[j] == '6') a[j] = 'b';
		else if (a[j] == '7') {
			a[j] = '0';
			f1(x, a, j);
		}
		else if (a[j] == '8') {
			a[j] = '1';
			f1(x, a, j);
		}
		else if (a[j] == '9') {
			a[j] = '2';
			f1(x, a, j);
		}
		else if (a[j] == 'a') {
			a[j] = '3';
			f1(x, a, j);
		}
		else if (a[j] == 'b') {
			a[j] = '4';
			f1(x, a, j);
		}
	}
	else if (x[j] == '6') {
		if (a[j] < '4' && a[j] >= '0') a[j] = a[j] + 6;
		else if (a[j] == '4') a[j] = 'a';
		else if (a[j] == '5') a[j] = 'b';
		else if (a[j] == '6') {
			a[j] = '0';
			f1(x, a, j);
		}
		else if (a[j] == '7') {
			a[j] = '1';
			f1(x, a, j);
		}
		else if (a[j] == '8') {
			a[j] = '2';
			f1(x, a, j);
		}
		else if (a[j] == '9') {
			a[j] = '3';
			f1(x, a, j);
		}
		else if (a[j] == 'a') {
			a[j] = '4';
			f1(x, a, j);
		}
		else if (a[j] == 'b') {
			a[j] = '5';
			f1(x, a, j);
		}
	}
	else if (x[j] == '7') {
		if (a[j] < '3' && a[j] >= '0') a[j] = a[j] + 7;
		else if (a[j] == '3') a[j] = 'a';
		else if (a[j] == '4') a[j] = 'b';
		else if (a[j] == '5') {
			a[j] = '0';
			f1(x, a, j);
		}
		else if (a[j] == '6') {
			a[j] = '1';
			f1(x, a, j);
		}
		else if (a[j] == '7') {
			a[j] = '2';
			f1(x, a, j);
		}
		else if (a[j] == '8') {
			a[j] = '3';
			f1(x, a, j);
		}
		else if (a[j] == '9') {
			a[j] = '4';
			f1(x, a, j);
		}
		else if (a[j] == 'a') {
			a[j] = '5';
			f1(x, a, j);
		}
		else if (a[j] == 'b') {
			a[j] = '6';
			f1(x, a, j);
		}
	}
	else if (x[j] == '8') {
		if (a[j] < '2' && a[j] >= '0') a[j] = a[j] + 8;
		else if (a[j] == '2') a[j] = 'a';
		else if (a[j] == '3') a[j] = 'b';
		else if (a[j] == '4') {
			a[j] = '0';
			f1(x, a, j);
		}
		else if (a[j] == '5') {
			a[j] = '1';
			f1(x, a, j);
		}
		else if (a[j] == '6') {
			a[j] = '2';
			f1(x, a, j);
		}
		else if (a[j] == '7') {
			a[j] = '3';
			f1(x, a, j);
		}
		else if (a[j] == '8') {
			a[j] = '4';
			f1(x, a, j);
		}
		else if (a[j] == '9') {
			a[j] = '5';
			f1(x, a, j);
		}
		else if (a[j] == 'a') {
			a[j] = '6';
			f1(x, a, j);
		}
		else if (a[j] == 'b') {
			a[j] = '7';
			f1(x, a, j);
		}
	}
	else if (x[j] == '9') {
		if (a[j] < '1' && a[j] >= '0') a[j] = a[j] + 9;
		else if (a[j] == '1') a[j] = 'a';
		else if (a[j] == '2') a[j] = 'b';
		else if (a[j] == '3') {
			a[j] = '0';
			f1(x, a, j);
		}
		else if (a[j] == '4') {
			a[j] = '1';
			f1(x, a, j);
		}
		else if (a[j] == '5') {
			a[j] = '2';
			f1(x, a, j);
		}
		else if (a[j] == '6') {
			a[j] = '3';
			f1(x, a, j);
		}
		else if (a[j] == '7') {
			a[j] = '4';
			f1(x, a, j);
		}
		else if (a[j] == '8') {
			a[j] = '5';
			f1(x, a, j);
		}
		else if (a[j] == '9') {
			a[j] = '6';
			f1(x, a, j);
		}
		else if (a[j] == 'a') {
			a[j] = '7';
			f1(x, a, j);
		}
		else if (a[j] == 'b') {
			a[j] = '8';
			f1(x, a, j);
		}
	}
	else if (x[j] == 'a') {
	if (a[j] == '0') a[j] = 'a';
	else if (a[j] == '1') a[j] = 'b';
	else if (a[j] == '2') {
		a[j] = '0';
		f1(x, a, j);
	}
	else if (a[j] == '3') {
		a[j] = '1';
		f1(x, a, j);
	}
	else if (a[j] == '4') {
		a[j] = '2';
		f1(x, a, j);
	}
	else if (a[j] == '5') {
		a[j] = '3';
		f1(x, a, j);
	}
	else if (a[j] == '6') {
		a[j] = '4';
		f1(x, a, j);
	}
	else if (a[j] == '7') {
		a[j] = '5';
		f1(x, a, j);
	}
	else if (a[j] == '8') {
		a[j] = '6';
		f1(x, a, j);
	}
	else if (a[j] == '9') {
		a[j] = '7';
		f1(x, a, j);
	}
	else if (a[j] == 'a') {
		a[j] = '8';
		f1(x, a, j);
	}
	else if (a[j] == 'b') {
		a[j] = '9';
		f1(x, a, j);
	}
	}
	else if (x[j] == 'b') {
	if (a[j] == '0') a[j] = 'b';
	else if (a[j] == '1') a[j] = '0';
	else if (a[j] == '2') {
		a[j] = '1';
		f1(x, a, j);
	}
	else if (a[j] == '3') {
		a[j] = '2';
		f1(x, a, j);
	}
	else if (a[j] == '4') {
		a[j] = '3';
		f1(x, a, j);
	}
	else if (a[j] == '5') {
		a[j] = '4';
		f1(x, a, j);
	}
	else if (a[j] == '6') {
		a[j] = '5';
		f1(x, a, j);
	}
	else if (a[j] == '7') {
		a[j] = '6';
		f1(x, a, j);
	}
	else if (a[j] == '8') {
		a[j] = '7';
		f1(x, a, j);
	}
	else if (a[j] == '9') {
		a[j] = '8';
		f1(x, a, j);
	}
	else if (a[j] == 'a') {
		a[j] = '9';
		f1(x, a, j);
	}
	else if (a[j] == 'b') {
		a[j] = 'a';
		f1(x, a, j);
	}
	}
	else {
		a[j] = '1';
		a[j + 1] = '\0';
	}
}
void f2(char x[], char a[], int i) {
	int j = i + 1;
	if (a[j] == '0') {
		if (a[j] <= '9' && a[j] >= '0') a[j] = a[j];
		else if (a[j] == 'a' || a[j] == 'b') a[j] = a[j];
		else  a[j] = x[j];
	}
	else if (a[j] == '1') {
		if (a[j] <= '9' && a[j] > '1') a[j] = a[j] - 1;
		else if (a[j] == 'a') a[j] = '9';
		else if (a[j] == 'b') a[j] = 'a';
		else if (a[j] == '0') {
			a[j] = 'b';
			f2(x, a, j);
		}
		else  a[j] = x[j];
	}
	else if (a[j] == '2') {
		if (a[j] <= '9' && a[j] > '2') a[j] = a[j] - 2;
		else if (a[j] == 'a') a[j] = '8';
		else if (a[j] == 'b') a[j] = '9';
		else if (a[j] == '0') {
			a[j] = 'a';
			f2(x, a, j);
		}
		else if (a[j] == '1') {
			a[j] = 'b';
			f2(x, a, j);
		}
		else if (a[j] == '2') {
			a[j] = '0';
			f2(x, a, j);
		}
		else  a[j] = x[j];
	}
	else if (a[j] == '3') {
		if (a[j] <= '9' && a[j] > '3') a[j] = a[j] - 3;
		else if (a[j] == 'a') a[j] = '7';
		else if (a[j] == 'b') a[j] = '8';
		else if (a[j] == '0') {
			a[j] = '9';
			f2(x, a, j);
		}
		else if (a[j] == '1') {
			a[j] = 'a';
			f2(x, a, j);
		}
		else if (a[j] == '2') {
			a[j] = 'b';
			f2(x, a, j);
		}
		else if (a[j] == '3') {
			a[j] = '0';
			f2(x, a, j);
		}
		else  a[j] = x[j];
	}
	else if (a[j] == '4') {
		if (a[j] <= '9' && a[j] > '4') a[j] = a[j] - 4;
		else if (a[j] == 'a') a[j] = '6';
		else if (a[j] == 'b') a[j] = '7';
		else if (a[j] == '0') {
			a[j] = '8';
			f2(x, a, j);
		}
		else if (a[j] == '1') {
			a[j] = '9';
			f2(x, a, j);
		}
		else if (a[j] == '2') {
			a[j] = 'a';
			f2(x, a, j);
		}
		else if (a[j] == '3') {
			a[j] = 'b';
			f2(x, a, j);
		}
		else if (a[j] == '4') {
			a[j] = '0';
			f2(x, a, j);
		}
		else  a[j] = x[j];
	}
	else if (a[j] == '5') {
		if (a[j] <= '9' && a[j] > '5') a[j] = a[j] - 5;
		else if (a[j] == 'a') a[j] = '5';
		else if (a[j] == 'b') a[j] = '6';
		else if (a[j] == '0') {
			a[j] = '7';
			f2(x, a, j);
		}
		else if (a[j] == '1') {
			a[j] = '8';
			f2(x, a, j);
		}
		else if (a[j] == '2') {
			a[j] = '9';
			f2(x, a, j);
		}
		else if (a[j] == '3') {
			a[j] = 'a';
			f2(x, a, j);
		}
		else if (a[j] == '4') {
			a[j] = 'b';
			f2(x, a, j);
		}
		else if (a[j] == '5') {
			a[j] = '0';
			f2(x, a, j);
		}
		else  a[j] = x[j];
	}
	else if (a[j] == '6') {
		if (a[j] <= '9' && a[j] > '6') a[j] = a[j] - 6;
		else if (a[j] == 'a') a[j] = '4';
		else if (a[j] == 'b') a[j] = '5';
		else if (a[j] == '0') {
			a[j] = '6';
			f2(x, a, j);
		}
		else if (a[j] == '1') {
			a[j] = '7';
			f2(x, a, j);
		}
		else if (a[j] == '2') {
			a[j] = '8';
			f2(x, a, j);
		}
		else if (a[j] == '3') {
			a[j] = '9';
			f2(x, a, j);
		}
		else if (a[j] == '4') {
			a[j] = 'a';
			f2(x, a, j);
		}
		else if (a[j] == '5') {
			a[j] = 'b';
			f2(x, a, j);
		}
		else if (a[j] == '6') {
			a[j] = '0';
			f2(x, a, j);
		}
		else  a[j] = x[j];
	}
	else if (a[j] == '7') {
		if (a[j] <= '9' && a[j] > '7') a[j] = a[j] - 7;
		else if (a[j] == 'a') a[j] = '3';
		else if (a[j] == 'b') a[j] = '4';
		else if (a[j] == '0') {
			a[j] = '5';
			f2(x, a, j);
		}
		else if (a[j] == '1') {
			a[j] = '6';
			f2(x, a, j);
		}
		else if (a[j] == '2') {
			a[j] = '7';
			f2(x, a, j);
		}
		else if (a[j] == '3') {
			a[j] = '8';
			f2(x, a, j);
		}
		else if (a[j] == '4') {
			a[j] = '9';
			f2(x, a, j);
		}
		else if (a[j] == '5') {
			a[j] = 'a';
			f2(x, a, j);
		}
		else if (a[j] == '6') {
			a[j] = 'b';
			f2(x, a, j);
		}
		else if (a[j] == '7') {
			a[j] = '0';
			f2(x, a, j);
		}
		else  a[j] = x[j];
	}
	else if (a[j] == '8') {
		if (a[j] <= '9' && a[j] > '8') a[j] = a[j] - 8;
		else if (a[j] == 'a') a[j] = '2';
		else if (a[j] == 'b') a[j] = '3';
		else if (a[j] == '0') {
			a[j] = '4';
			f2(x, a, j);
		}
		else if (a[j] == '1') {
			a[j] = '5';
			f2(x, a, j);
		}
		else if (a[j] == '2') {
			a[j] = '6';
			f2(x, a, j);
		}
		else if (a[j] == '3') {
			a[j] = '7';
			f2(x, a, j);
		}
		else if (a[j] == '4') {
			a[j] = '8';
			f2(x, a, j);
		}
		else if (a[j] == '5') {
			a[j] = '9';
			f2(x, a, j);
		}
		else if (a[j] == '6') {
			a[j] = 'a';
			f2(x, a, j);
		}
		else if (a[j] == '7') {
			a[j] = 'b';
			f2(x, a, j);
		}
		else if (a[j] == '8') {
			a[j] = '0';
			f2(x, a, j);
		}
		else  a[j] = x[j];
	}
	else if (a[j] == '9') {
		if (a[j] == 'a') a[j] = '1';
		else if (a[j] == 'b') a[j] = '2';
		else if (a[j] == '0') {
			a[j] = '3';
			f2(x, a, j);
		}
		else if (a[j] == '1') {
			a[j] = '4';
			f2(x, a, j);
		}
		else if (a[j] == '2') {
			a[j] = '5';
			f2(x, a, j);
		}
		else if (a[j] == '3') {
			a[j] = '6';
			f2(x, a, j);
		}
		else if (a[j] == '4') {
			a[j] = '7';
			f2(x, a, j);
		}
		else if (a[j] == '5') {
			a[j] = '8';
			f2(x, a, j);
		}
		else if (a[j] == '6') {
			a[j] = '9';
			f2(x, a, j);
		}
		else if (a[j] == '7') {
			a[j] = 'a';
			f2(x, a, j);
		}
		else if (a[j] == '8') {
			a[j] = 'b';
			f2(x, a, j);
		}
		else if (a[j] == '9') {
			a[j] = '0';
			f2(x, a, j);
		}
		else  a[j] = x[j];
	}
	else if (a[j] == 'a') {
		if (a[j] == 'a') a[j] = '0';
		else if (a[j] == 'b') a[j] = '1';
		else if (a[j] == '0') {
			a[j] = '2';
			f2(x, a, j);
		}
		else if (a[j] == '1') {
			a[j] = '3';
			f2(x, a, j);
		}
		else if (a[j] == '2') {
			a[j] = '4';
			f2(x, a, j);
		}
		else if (a[j] == '3') {
			a[j] = '5';
			f2(x, a, j);
		}
		else if (a[j] == '4') {
			a[j] = '6';
			f2(x, a, j);
		}
		else if (a[j] == '5') {
			a[j] = '7';
			f2(x, a, j);
		}
		else if (a[j] == '6') {
			a[j] = '8';
			f2(x, a, j);
		}
		else if (a[j] == '7') {
			a[j] = '9';
			f2(x, a, j);
		}
		else if (a[j] == '8') {
			a[j] = 'a';
			f2(x, a, j);
		}
		else if (a[j] == '9') {
			a[j] = 'b';
			f2(x, a, j);
		}
		else if (a[j] == 'a') {
			a[j] = '0';
			f2(x, a, j);
		}
		else  a[j] = x[j];
	}
	else if (a[j] == 'b') {
		if (a[j] == 'b') a[j] = '0';
		else if (a[j] == '0') {
			a[j] = '1';
			f2(x, a, j);
		}
		else if (a[j] == '1') {
			a[j] = '2';
			f2(x, a, j);
		}
		else if (a[j] == '2') {
			a[j] = '3';
			f2(x, a, j);
		}
		else if (a[j] == '3') {
			a[j] = '4';
			f2(x, a, j);
		}
		else if (a[j] == '4') {
			a[j] = '5';
			f2(x, a, j);
		}
		else if (a[j] == '5') {
			a[j] = '6';
			f2(x, a, j);
		}
		else if (a[j] == '6') {
			a[j] = '7';
			f2(x, a, j);
		}
		else if (a[j] == '7') {
			a[j] = '8';
			f2(x, a, j);
		}
		else if (a[j] == '8') {
			a[j] = '9';
			f2(x, a, j);
		}
		else if (a[j] == '9') {
			a[j] = 'a';
			f2(x, a, j);
		}
		else if (a[j] == 'a') {
			a[j] = 'b';
			f2(x, a, j);
		}
		else if (a[j] == 'b') {
			a[j] = '0';
			f2(x, a, j);
		}
		else  a[j] = x[j];

	}
	



}
void sum(char x[], char a[],int lenx, int lena) {
	if (lenx > lena) lena = lenx;
	int k = 0;
	for (int i = 0; i < lena; i++) {
		k++;
		if (x[i] == '0') {
			if (a[i] <= '9' && a[i] >= '0') a[i] = a[i];
			else if (a[i] =='a' || a[i] == 'b') a[i] = a[i];
			else  a[i] = x[i];
		}
		else if (x[i] == '1') {
			if (a[i] < '9' && a[i]>='0') a[i] = a[i] + 1;
			else if (a[i] == '9') a[i] = 'a';
			else if (a[i] == 'a') a[i] = 'b';
			else if (a[i] == 'b') {
				a[i] = '0';
				f1(x, a, i);
			}
			else  a[i] = x[i];
		}
		else if (x[i] == '2') {
			if (a[i] < '8' && a[i] >= '0') a[i] = a[i] + 2;
			else if (a[i] == '8') a[i] = 'a';
			else if (a[i] == '9') a[i] = 'b';
			else if (a[i] == 'a') {
				a[i] = '0';
				f1(x, a, i);
			}
			else if (a[i] == 'b') {
				a[i] = '1';
				f1(x, a, i);
			}
			else  a[i] = x[i];
		}
		else if (x[i] == '3') {
			if (a[i] < '7' && a[i] >= '0') a[i] = a[i] + 3;
			else if (a[i] == '7') a[i] = 'a';
			else if (a[i] == '8') a[i] = 'b';
			else if (a[i] == '9') {
				a[i] = '0';
				f1(x, a, i);
			}
			else if (a[i] == 'a') {
				a[i] = '1';
				f1(x, a, i);
			}
			else if (a[i] == 'b') {
				a[i] = '2';
				f1(x, a, i);
			}
			else  a[i] = x[i];
		}
		else if (x[i] == '4') {
			if (a[i] < '6' && a[i] >= '0') a[i] = a[i] + 4;
			else if (a[i] == '6') a[i] = 'a';
			else if (a[i] == '7') a[i] = 'b';
			else if (a[i] == '8') {
				a[i] = '0';
				f1(x, a, i);
			}
			else if (a[i] == '9') {
				a[i] = '1';
				f1(x, a, i);
			}
			else if (a[i] == 'a') {
				a[i] = '2';
				f1(x, a, i);
			}
			else if (a[i] == 'x') {
				a[i] = '3';
				f1(x, a, i);
			}
			else  a[i] = x[i];
		}
		else if (x[i] == '5') {
			if (a[i] < '5' && a[i] >= '0') a[i] = a[i] + 5;
			else if (a[i] == '5') a[i] = 'a';
			else if (a[i] == '6') a[i] = 'b';
			else if (a[i] == '7') {
				a[i] = '0';
				f1(x, a, i);
			}
			else if (a[i] == '8') {
				a[i] = '1';
				f1(x, a, i);
			}
			else if (a[i] == '9') {
				a[i] = '2';
				f1(x, a, i);
			}
			else if (a[i] == 'a') {
				a[i] = '3';
				f1(x, a, i);
			}
			else if (a[i] == 'b') {
				a[i] = '4';
				f1(x, a, i);
			}
			else  a[i] = x[i];
		}
		else if (x[i] == '6') {
			if (a[i] < '4' && a[i] >= '0') a[i] = a[i] + 6;
			else if (a[i] == '4') a[i] = 'a';
			else if (a[i] == '5') a[i] = 'b';
			else if (a[i] == '6') {
				a[i] = '0';
				f1(x, a, i);
			}
			else if (a[i] == '7') {
				a[i] = '1';
				f1(x, a, i);
			}
			else if (a[i] == '8') {
				a[i] = '2';
				f1(x, a, i);
			}
			else if (a[i] == '9') {
				a[i] = '3';
				f1(x, a, i);
			}
			else if (a[i] == 'a') {
				a[i] = '4';
				f1(x, a, i);
			}
			else if (a[i] == 'b') {
				a[i] = '5';
				f1(x, a, i);
			}
			else  a[i] = x[i];
		}
		else if (x[i] == '7') {
			if (a[i] < '3' && a[i] >= '0') a[i] = a[i] + 7;
			else if (a[i] == '3') a[i] = 'a';
			else if (a[i] == '4') a[i] = 'b';
			else if (a[i] == '5') {
				a[i] = '0';
				f1(x, a, i);
			}
			else if (a[i] == '6') {
				a[i] = '1';
				f1(x, a, i);
			}
			else if (a[i] == '7') {
				a[i] = '2';
				f1(x, a, i);
			}
			else if (a[i] == '8') {
				a[i] = '3';
				f1(x, a, i);
			}
			else if (a[i] == '9') {
				a[i] = '4';
				f1(x, a, i);
			}
			else if (a[i] == 'a') {
				a[i] = '5';
				f1(x, a, i);
			}
			else if (a[i] == 'b') {
				a[i] = '6';
				f1(x, a, i);
			}
			else  a[i] = x[i];
		}
		else if (x[i] == '8') {
			if (a[i] < '2' && a[i] >= '0') a[i] = a[i] + 8;
			else if (a[i] == '2') a[i] = 'a';
			else if (a[i] == '3') a[i] = 'b';
			else if (a[i] == '4') {
				a[i] = '0';
				f1(x, a, i);
			}
			else if (a[i] == '5') {
				a[i] = '1';
				f1(x, a, i);
			}
			else if (a[i] == '6') {
				a[i] = '2';
				f1(x, a, i);
			}
			else if (a[i] == '7') {
				a[i] = '3';
				f1(x, a, i);
			}
			else if (a[i] == '8') {
				a[i] = '4';
				f1(x, a, i);
			}
			else if (a[i] == '9') {
				a[i] = '5';
				f1(x, a, i);
			}
			else if (a[i] == 'a') {
				a[i] = '6';
				f1(x, a, i);
			}
			else if (a[i] == 'b') {
				a[i] = '7';
				f1(x, a, i);
			}
		}
		else if (x[i] == '9') {
			if (a[i] < '1' && a[i] >= '0') a[i] = a[i] + 9;
			else if (a[i] == '1') a[i] = 'a';
			else if (a[i] == '2') a[i] = 'b';
			else if (a[i] == '3') {
				a[i] = '0';
				f1(x, a, i);
			}
			else if (a[i] == '4') {
				a[i] = '1';
				f1(x, a, i);
			}
			else if (a[i] == '5') {
				a[i] = '2';
				f1(x, a, i);
			}
			else if (a[i] == '6') {
				a[i] = '3';
				f1(x, a, i);
			}
			else if (a[i] == '7') {
				a[i] = '4';
				f1(x, a, i);
			}
			else if (a[i] == '8') {
				a[i] = '5';
				f1(x, a, i);
			}
			else if (a[i] == '9') {
				a[i] = '6';
				f1(x, a, i);
			}
			else if (a[i] == 'a') {
				a[i] = '7';
				f1(x, a, i);
			}
			else if (a[i] == 'b') {
				a[i] = '8';
				f1(x, a, i);
			}
			else  a[i] = x[i];
		}
		else if (x[i] == 'a') {
		if (a[i] == '0' && a[i] >= '0') a[i] = 'a';
		else if (a[i] == '1') a[i] = 'b';
		else if (a[i] == '2') {
			a[i] = '0';
			f1(x, a, i);
		}
		else if (a[i] == '3') {
			a[i] = '1';
			f1(x, a, i);
		}
		else if (a[i] == '4') {
			a[i] = '2';
			f1(x, a, i);
		}
		else if (a[i] == '5') {
			a[i] = '3';
			f1(x, a, i);
		}
		else if (a[i] == '6') {
			a[i] = '4';
			f1(x, a, i);
		}
		else if (a[i] == '7') {
			a[i] = '5';
			f1(x, a, i);
		}
		else if (a[i] == '8') {
			a[i] = '6';
			f1(x, a, i);
		}
		else if (a[i] == 'a9') {
			a[i] = '7';
			f1(x, a, i);
		}
		else if (a[i] == 'a') {
			a[i] = '8';
			f1(x, a, i);
		}
		else if (a[i] == 'b') {
			a[i] = '9';
			f1(x, a, i);
		}
		}
		else if (x[i] == 'b') {
		if (a[i] == '0') a[i] = 'b';
		else if (a[i] == '1') a[i] = '0';
		else if (a[i] == '2') {
			a[i] = '1';
			f1(x, a, i);
		}
		else if (a[i] == '3') {
			a[i] = '2';
			f1(x, a, i);
		}
		else if (a[i] == '4') {
			a[i] = '3';
			f1(x, a, i);
		}
		else if (a[i] == '5') {
			a[i] = '4';
			f1(x, a, i);
		}
		else if (a[i] == '6') {
			a[i] = '5';
			f1(x, a, i);
		}
		else if (a[i] == '7') {
			a[i] = '6';
			f1(x, a, i);
		}
		else if (a[i] == '8') {
			a[i] = '7';
			f1(x, a, i);
		}
		else if (a[i] == 'a9') {
			a[i] = '8';
			f1(x, a, i);
		}
		else if (a[i] == 'a') {
			a[i] = '9';
			f1(x, a, i);
		}
		else if (a[i] == 'b') {
			a[i] = 'a';
			f1(x, a, i);
		}
		else  a[i] = x[i];
		}
	}
	a[k] = '\0';
}
void raz(char x[], char a[], int lenx, int lena) {
	if (lenx > lena) lena = lenx;
	int k = 0;
	for (int i = 0; i < lena; i++) {
		k++;
		if (x[i] == '0') {
			if (x[i] <= '9' && x[i] >= '0') x[i] = x[i];
			else if (x[i] == 'a' || x[i] == 'b') x[i] = x[i];
			else  x[i] = x[i];
		}
		else if (a[i] == '1') {
			if (x[i] <= '9' && x[i] > '1') x[i] = x[i] - 1;
			else if (x[i] == 'a') x[i] = '9';
			else if (x[i] == 'b') x[i] = 'a';
			else if (x[i] == '0') {
				x[i] = 'b';
				f2(x, a, i);
			}
			else  x[i] = x[i];
		}
		else if (a[i] == '2') {
			if (x[i] <= '9' && x[i] > '2') x[i] = x[i] - 2;
			else if (x[i] == 'a') x[i] = '8';
			else if (x[i] == 'b') x[i] = '9';
			else if (x[i] == '0') {
				x[i] = 'a';
				f2(x, a, i);
			}
			else if (x[i] == '1') {
				x[i] = 'b';
				f2(x, a, i);
			}
			else if (x[i] == '2') {
				x[i] = '0';
				f2(x, a, i);
			}
			else  x[i] = x[i];
		}
		else if (a[i] == '3') {
			if (x[i] <= '9' && x[i] > '3') x[i] = x[i] - 3;
			else if (x[i] == 'a') x[i] = '7';
			else if (x[i] == 'b') x[i] = '8';
			else if (x[i] == '0') {
				x[i] = '9';
				f2(x, a, i);
			}
			else if (x[i] == '1') {
				x[i] = 'a';
				f2(x, a, i);
			}
			else if (x[i] == '2') {
				x[i] = 'b';
				f2(x, a, i);
			}
			else if (x[i] == '3') {
				x[i] = '0';
				f2(x, a, i);
			}
			else  x[i] = x[i];
		}
		else if (a[i] == '4') {
			if (x[i] <= '9' && x[i] > '4') x[i] = x[i] - 4;
			else if (x[i] == 'a') x[i] = '6';
			else if (x[i] == 'b') x[i] = '7';
			else if (x[i] == '0') {
				x[i] = '8';
				f2(x, a, i);
			}
			else if (x[i] == '1') {
				x[i] = '9';
				f2(x, a, i);
			}
			else if (x[i] == '2') {
				x[i] = 'a';
				f2(x, a, i);
			}
			else if (x[i] == '3') {
				x[i] = 'b';
				f2(x, a, i);
			}
			else if (x[i] == '4') {
				x[i] = '0';
				f2(x, a, i);
			}
			else  x[i] = x[i];
		}
		else if (a[i] == '5') {
			if (x[i] <= '9' && x[i] > '5') x[i] = x[i] - 5;
			else if (x[i] == 'a') x[i] = '5';
			else if (x[i] == 'b') x[i] = '6';
			else if (x[i] == '0') {
				x[i] = '7';
				f2(x, a, i);
			}
			else if (x[i] == '1') {
				x[i] = '8';
				f2(x, a, i);
			}
			else if (x[i] == '2') {
				x[i] = '9';
				f2(x, a, i);
			}
			else if (x[i] == '3') {
				x[i] = 'a';
				f2(x, a, i);
			}
			else if (x[i] == '4') {
				x[i] = 'b';
				f2(x, a, i);
			}
			else if (x[i] == '5') {
				x[i] = '0';
				f2(x, a, i);
			}
			else  x[i] = x[i];
		}
		else if (a[i] == '6') {
			if (x[i] <= '9' && x[i] > '6') x[i] = x[i] - 6;
			else if (x[i] == 'a') x[i] = '4';
			else if (x[i] == 'b') x[i] = '5';
			else if (x[i] == '0') {
				x[i] = '6';
				f2(x, a, i);
			}
			else if (x[i] == '1') {
				x[i] = '7';
				f2(x, a, i);
			}
			else if (x[i] == '2') {
				x[i] = '8';
				f2(x, a, i);
			}
			else if (x[i] == '3') {
				x[i] = '9';
				f2(x, a, i);
			}
			else if (x[i] == '4') {
				x[i] = 'a';
				f2(x, a, i);
			}
			else if (x[i] == '5') {
				x[i] = 'b';
				f2(x, a, i);
			}
			else if (x[i] == '6') {
				x[i] = '0';
				f2(x, a, i);
			}
			else  x[i] = x[i];
		}
		else if (a[i] == '7') {
			if (x[i] <= '9' && x[i] > '7') x[i] = x[i] - 7;
			else if (x[i] == 'a') x[i] = '3';
			else if (x[i] == 'b') x[i] = '4';
			else if (x[i] == '0') {
				x[i] = '5';
				f2(x, a, i);
			}
			else if (x[i] == '1') {
				x[i] = '6';
				f2(x, a, i);
			}
			else if (x[i] == '2') {
				x[i] = '7';
				f2(x, a, i);
			}
			else if (x[i] == '3') {
				x[i] = '8';
				f2(x, a, i);
			}
			else if (x[i] == '4') {
				x[i] = '9';
				f2(x, a, i);
			}
			else if (x[i] == '5') {
				x[i] = 'a';
				f2(x, a, i);
			}
			else if (x[i] == '6') {
				x[i] = 'b';
				f2(x, a, i);
			}
			else if (x[i] == '7') {
				x[i] = '0';
				f2(x, a, i);
			}
			else  x[i] = x[i];
		}
		else if (a[i] == '8') {
			if (x[i] <= '9' && x[i] > '8') x[i] = x[i] - 8;
			else if (x[i] == 'a') x[i] = '2';
			else if (x[i] == 'b') x[i] = '3';
			else if (x[i] == '0') {
				x[i] = '4';
				f2(x, a, i);
			}
			else if (x[i] == '1') {
				x[i] = '5';
				f2(x, a, i);
			}
			else if (x[i] == '2') {
				x[i] = '6';
				f2(x, a, i);
			}
			else if (x[i] == '3') {
				x[i] = '7';
				f2(x, a, i);
			}
			else if (x[i] == '4') {
				x[i] = '8';
				f2(x, a, i);
			}
			else if (x[i] == '5') {
				x[i] = '9';
				f2(x, a, i);
			}
			else if (x[i] == '6') {
				x[i] = 'a';
				f2(x, a, i);
			}
			else if (x[i] == '7') {
				x[i] = 'b';
				f2(x, a, i);
			}
			else if (x[i] == '8') {
				x[i] = '0';
				f2(x, a, i);
			}
			else  x[i] = x[i];
		}
		else if (a[i] == '9') {
			if (x[i] == 'a') x[i] = '1';
			else if (x[i] == 'b') x[i] = '2';
			else if (x[i] == '0') {
				x[i] = '3';
				f2(x, a, i);
			}
			else if (x[i] == '1') {
				x[i] = '4';
				f2(x, a, i);
			}
			else if (x[i] == '2') {
				x[i] = '5';
				f2(x, a, i);
			}
			else if (x[i] == '3') {
				x[i] = '6';
				f2(x, a, i);
			}
			else if (x[i] == '4') {
				x[i] = '7';
				f2(x, a, i);
			}
			else if (x[i] == '5') {
				x[i] = '8';
				f2(x, a, i);
			}
			else if (x[i] == '6') {
				x[i] = '9';
				f2(x, a, i);
			}
			else if (x[i] == '7') {
				x[i] = 'a';
				f2(x, a, i);
			}
			else if (x[i] == '8') {
				x[i] = 'b';
				f2(x, a, i);
			}
			else if (x[i] == '9') {
				x[i] = '0';
				f2(x, a, i);
			}
			else  x[i] = x[i];
		}
		else if (a[i] == 'a') {
			if (x[i] == 'a') x[i] = '0';
			else if (x[i] == 'b') x[i] = '1';
			else if (x[i] == '0') {
				x[i] = '2';
				f2(x, a, i);
			}
			else if (x[i] == '1') {
				x[i] = '3';
				f2(x, a, i);
			}
			else if (x[i] == '2') {
				x[i] = '4';
				f2(x, a, i);
			}
			else if (x[i] == '3') {
				x[i] = '5';
				f2(x, a, i);
			}
			else if (x[i] == '4') {
				x[i] = '6';
				f2(x, a, i);
			}
			else if (x[i] == '5') {
				x[i] = '7';
				f2(x, a, i);
			}
			else if (x[i] == '6') {
				x[i] = '8';
				f2(x, a, i);
			}
			else if (x[i] == '7') {
				x[i] = '9';
				f2(x, a, i);
			}
			else if (x[i] == '8') {
				x[i] = 'a';
				f2(x, a, i);
			}
			else if (x[i] == '9') {
				x[i] = 'b';
				f2(x, a, i);
			}
			else if (x[i] == 'a') {
				x[i] = '0';
				f2(x, a, i);
			}
			else  x[i] = x[i];
		}
		else if (a[i] == 'b') {
			if (x[i] == 'b') x[i] = '0';
			else if (x[i] == '0') {
				x[i] = '1';
				f2(x, a, i);
			}
			else if (x[i] == '1') {
				x[i] = '2';
				f2(x, a, i);
			}
			else if (x[i] == '2') {
				x[i] = '3';
				f2(x, a, i);
			}
			else if (x[i] == '3') {
				x[i] = '4';
				f2(x, a, i);
			}
			else if (x[i] == '4') {
				x[i] = '5';
				f2(x, a, i);
			}
			else if (x[i] == '5') {
				x[i] = '6';
				f2(x, a, i);
			}
			else if (x[i] == '6') {
				x[i] = '7';
				f2(x, a, i);
			}
			else if (x[i] == '7') {
				x[i] = '8';
				f2(x, a, i);
			}
			else if (x[i] == '8') {
				x[i] = '9';
				f2(x, a, i);
			}
			else if (x[i] == '9') {
				x[i] = 'a';
				f2(x, a, i);
			}
			else if (x[i] == 'a') {
				x[i] = 'b';
				f2(x, a, i);
			}
			else if (x[i] == 'b') {
				x[i] = '0';
				f2(x, a, i);
			}
			else  x[i] = x[i];
		}

	}
	x[k] = '\0';
}


void copy(char x[], char xx[]) {
	int i = 0;
	while (x[i] != '\0') {
		xx[i] = x[i];
		i++;
	}
	xx[i] = x[i];
}
int main()
{
	std::cout << "0 1 2 3 4 5 6 7 8 9 x e\n";
    std::cout << "x,a\n";
	char x[500], a[500], aa[500], xx[500];
	std::cin>> x;
	std::cin >> a;
	copy(a, aa);
	copy(x, xx);
	int lenx = len(x), lena = len(a);
	revers(x, lenx); revers(a, lena);
	sum(x, a, lenx, lena);
	revers(a, len(a));
	std::cout << '\n';
	output(a);
	lenx = len(xx);
	lena = len(aa);
	revers(xx, lenx); revers(aa, lena);
	raz(xx, aa, lenx, lena);
	revers(xx, len(xx));
	std::cout << '\n';
	output(xx);

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
