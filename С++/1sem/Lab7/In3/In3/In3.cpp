// In3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
int len(char str[]) {
	int a=0;
	while (str[a] != '\0') a++;
	return a;
}
void pr(char c[], int i) {
	if (c[0] == '-') {
		c[0] = '1';
	}
	else {
		char cc[500];
		cc[0] = '0';
		for (int j = 1; j <= i; j++) {
			cc[j] = c[j-1];
		}
		
		for (int j = 0; j <= i; j++) {
			c[j] = cc[j];
			c[j + 1] = '\0';
		}
	}
}
void obr(char c[], int i) {
	if (c[0] == '1') {
		for (int j = 1; j < i; j++) {
			if (c[j] == '0') c[j] = '1';
			else if (c[j] == '1') c[j] = '0';
		}
	}
	
}
void output(char c[]) {
	int a=0;
	while (c[a] != '\0') {
		std::cout << c[a];
		a++;
	}
	std::cout << '\n';
}
void dop(char a[], int la) {
	int i = 0;
	int e = 0, t = 1;
	for (int j = 0; j < la; j++) {

		if (a[j] > 47 && a[j] < 58)e = a[j] - '0';
		else e = 0;
		t += e;
		if (t == 0) a[j] = '0';
		else if (t == 1) { a[j] = '1'; t = 0; }
		else if (t % 2 == 0 && t > 1) {

			if (e == 1) { t--; a[j] = '0'; }
			if (e == 0) { t--; a[j] = '0'; }
		
		}
		else if (t % 2 == 1 && t > 1) {
			a[j] = '0';
			if (e == 1)t--;
			if (e == 0)t--;
		}
		i++;
	}
	while (t > 0) {
		if (t == 1) { a[i] = '1'; t = 0; }
		else if (t % 2 == 0 && t > 1) {
			a[i] = '0';
			t--;
		}
		else if (t % 2 == 1 && t > 1) {
			a[i] = '0';
			t -= 2;
		}
		i++;
	}
	a[i] = '\0';
}
void sum(char a[], char b[], int la, int lb, char sc[]) {
	int i = 0;
	if (la > lb) lb = la;
	int e = 0, r = 0, t=0;
		for (int j = 0; j < lb; j++) {
			/*if (a[j] == '1' && b[j] == '1') {
				sc[i] = '0';
				if (a[j - 1] == 0 || a[j - 1] == 1) a[j - 1]++;
				else a[j-2]++;
			}
			if
			else if ((a[j] == '1' && b[j] == '0') || (a[j] == '0' && b[j] == '1')) {
				sc[i] = '1';
			}
			else if (a[j] == '0' && b[j] == '0') {
				sc[i] = '0';
			}
			i++;*/

			if (a[j] > 47 && a[j] < 58)e = a[j] - '0';
			else e = 0;
			if (b[j] > 47 && b[j] < 58)r = b[j]-'0';
			else r = 0;
			t += e + r;
			if (t == 0) sc[j] = '0';
			else if (t == 1) { sc[j] = '1'; t = 0; }
			else if (t % 2 == 0 && t > 1) {
				
				if (e + r == 1) { t-=2; sc[j] = '1'; }
				if (e + r == 0) { t --; sc[j] = '0'; }
				if (e + r == 2) { t--; sc[j] = '0'; }
			}
			else if (t % 2 == 1 && t > 1) {
				if (e + r == 1) { t -= 2; sc[j] = '1'; }
				if (e + r == 0) { t-=2; sc[j] = '1'; }
				if (e + r == 2) { t-=2; sc[j] = '1'; }
			}
			i++;
		}
		while (t > 0) {
				if (t == 1) { sc[i] = '1'; t = 0; }
				else if (t % 2 == 0 && t > 1) {
					sc[i] = '0';
					t--;
				}
				else if (t % 2 == 1 && t > 1) {
					sc[i] = '1';
					t-=2;
				}
				i++;
		}
	sc[i] = '\0';
}
void revers(char c[],int lc) {
	char cs[1000];
	for (int i = 0; i < lc; i++) {
		cs[i] = c[lc - 1 - i];
	}
	for (int i = 0; i < lc; i++) {
		c[i] = cs[i];
	}
	c[lc] = '\0';
	
}
void dooppr(char a[], int la) {
	int i = 0;
	int e = 0, t = 11;
	for (int j = 0; j < la; j++) {

		e = a[j] - '0';
		t += e;
		if (t == 0) a[j] = '0';
		else if (t == 1) { a[j] = '1'; t = 0; }
		else if (t % 2 == 0 && t > 1) {

			if (e == 1) { t--; a[j] = '0'; }
			if (e == 0) { t--; a[j] = '0'; }

		}
		else if (t % 2 == 1 && t > 1) {
			a[j] = '0';
			if (e == 1)t--;
			if (e == 0)t--;
		}
		i++;
	}
	while (t > 0) {
		if (t == 1) { a[i] = '1'; t = 0; }
		else if (t % 2 == 0 && t > 1) {
			a[i] = '0';
			t--;
		}
		else if (t % 2 == 1 && t > 1) {
			a[i] = '0';
			t -= 2;
		}
		i++;
	}
	a[i] = '\0';
}
void doppr(char a[], int la, char sc[]) {
	char b[6] = "1";
	int lb = 6;
	int i = 0;
	if (la > lb) lb = la;
	int e = 0, r = 0, t = 0;
	for (int j = 0; j < lb; j++) {

		if (a[j] > 47 && a[j] < 58)e = a[j] - '0';
		else e = 0;
		if (b[j] > 47 && b[j] < 58)r = b[j] - '0';
		else r = 0;
		t += e + r;
		if (t == 0) sc[j] = '0';
		else if (t == 1) { sc[j] = '1'; t = 0; }
		else if (t % 2 == 0 && t > 1) {

			if (e + r == 1) { t -= 2; sc[j] = '1'; }
			if (e + r == 0) { t--; sc[j] = '0'; }
			if (e + r == 2) { t--; sc[j] = '0'; }
		}
		else if (t % 2 == 1 && t > 1) {
			if (e + r == 1) { t -= 2; sc[j] = '1'; }
			if (e + r == 0) { t -= 2; sc[j] = '1'; }
			if (e + r == 2) { t -= 2; sc[j] = '1'; }
		}
		i++;
	}
	while (t > 0) {
		if (t == 1) { sc[i] = '1'; t = 0; }
		else if (t % 2 == 0 && t > 1) {
			sc[i] = '0';
			t--;
		}
		else if (t % 2 == 1 && t > 1) {
			sc[i] = '1';
			t -= 2;
		}
		i++;
	}
	sc[i] = '\0';
}
void dppr(char a[], int la,char c[]){
	int i = 0 ,l=la;
	
	if (a[l] == '1') { c[l] = '0'; }
	else {
		while (a[l - i] != '1') {
			c[l - i] = '1';
			i++;
		}
		c[l - i] = '0';
	}
	for (int j = 0; j <l-i; j++) {
		c[j] = a[j];
	}
	c[la] = '\0';

}
void obrpr(char c[], int i) {
	for (int j = 0; j < i; j++) {
			if (c[j] == '0') c[j] = '1';
			else if (c[j] == '1') c[j] = '0';
	}

}
int main()
{
	char a[500],b[500],sc[1000],c[1000];
	
	std::cout << "Vvod a,b \n";
	std::cin >> a;
	std::cin >> b;
	if (b[0]=='-' && a[0]== '-'){
		pr(a, len(a));
		pr(b, len(b));
		obr(a, len(a));
		obr(b, len(b));
	
		revers(a, len(a));
		revers(b, len(b));
		dop(a, len(a));
		dop(b, len(b));
	

		int la = len(a), lb = len(b);
		sum(a, b, la, lb, sc);
		revers(sc, len(sc));
		dppr(sc, len(sc), c);
		obr(c, len(c));
		output(c);
	}
	else if (a[0] == '-') {
		pr(a, len(a));
		pr(b, len(b));
		obr(a, len(a));
		revers(a, len(a));
		revers(b, len(b));
		dop(a, len(a));
		int la = len(a), lb = len(b);
		sum(a, b, la, lb, sc);
		revers(sc, len(sc));
		dppr(sc, len(sc), c);
		obr(c, len(c));
		output(c);
		
	}
	else if (b[0] == '-') {
		pr(a, len(a));
		pr(b, len(b));
		obr(b, len(b));
		revers(a, len(a));
		revers(b, len(b));
		dop(b, len(b));
		int la = len(a), lb = len(b);
		sum(a, b, la, lb, sc);
		revers(sc, len(sc));
		dppr(sc, len(sc), c);
		obr(c, len(c));
		output(c);
	}
	else {
		pr(a, len(a));
		pr(b, len(b));
		revers(a, len(a));
		revers(b, len(b));
		int la = len(a), lb = len(b);
		sum(a, b, la, lb, sc); revers(sc, len(sc));
		output(sc);
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
