// In3.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
int len(char str[]) {
	int a = 0;
	while (str[a] != '\0') a++;
	return a;
}

void priam(char a[], int l_a, char b[], int l_b) {
	if (a[0] == '-') a[0] = '1';
	else {
		char mas[50];
		for (int i = 0; i < l_a; i++) {
			mas[i] = a[i];
		}
		for (int i = 0; i < l_a; i++) {
			a[i + 1] = mas[i];
		}
		a[0] = '0';
	}
	if (b[0] == '-') b[0] = '1';
	else {
		char mas[50];
		for(int i=0; i<l_b;i++){
			mas[i] = b[i];
		}
		for(int i=0; i<l_b;i++){
			b[i+1] = mas[i];
		}
		b[0] = '0';
	}

}
void obrat(char a[], int l_a, char b[], int l_b) {
	if (a[0] == '1') {
		for (int i = 1; i < l_a; i++) {
			if (a[i] == '1') a[i] = '0';
			else a[i] = '1';
		}
	}
	if (b[0] == '1') {
		for (int i = 1; i < l_b; i++) {
			if (b[i] == '1') b[i] = '0';
			else b[i] = '1';
		}
	}
}
void dop(char a[], int la) {
	int i = 0;
	int e = 0, t = 1;
	if (a[0] == '1') {
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
}
int sum(char aa[], char bb[], int la, int lb, char sc[]) {
	int i = 0;
	//if (la > lb) lb = la;
	int d;
	char a[50], b[50];
	if (la > lb) {
		d = la - lb;
		for (int i = 0; i < la; i++) {
			b[i + d] = bb[i];
			a[i] = aa[i];
		}
		for (int i = 0; i < d; i++) {
			b[i] = '0';
		}
		lb = la;
	}
	else if (la < lb) {
		d = lb - la;
		for (int i = 0; i < lb; i++) {
			a[i + d] = aa[i];
			b[i] = bb[i];
		}
		for (int i = 0; i < d; i++) {
			a[i] = '0';

		}

		la = lb;
	}
	else {
		for (int i = 0; i < lb; i++) {
			a[i] = aa[i];
			b[i] = bb[i];
		}
	}
	int e = 0, r = 0, t = 0;
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
	return lb;
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
void suum(char aa[], int l_a, char bb[], int l_b, char res[]) {
	char a[50], b[50];
	int d;
	if (l_a > l_b) {
		d = l_a - l_b;
		for (int i = 0; i < l_a; i++) {
			b[i + d] = bb[i];
			a[i] = aa[i];
		}
		for (int i = 0; i < d; i++) {
			b[i] = '0';
		}
		l_b = l_a;
	}
	else if (l_a < l_b) {
		d = l_b - l_a;
		for (int i = 0; i < l_b; i++) {
			a[i + d] = aa[i];
			b[i] = bb[i];
		}
		for (int i = 0; i < d; i++) {
			a[i] = '0';

		}

		l_a = l_b;
	}
	else {
		for (int i = 0; i < l_b; i++) {
			a[i] = aa[i];
			b[i] = bb[i];
		}
	}
	// уравниваем длину
	
	char cs[1000];
	for (int i = 0; i < l_a; i++) {
		cs[i] = a[l_a - 1 - i];
	}
	for (int i = 0; i < l_a; i++) {
		a[i] = cs[i];
	}
	for (int i = 0; i < l_a; i++) {
		cs[i] = b[l_a - 1 - i];
	}
	for (int i = 0; i < l_a; i++) {
		b[i] = cs[i];
	}
	b[l_a] = '\0';
	a[l_a] = '\0';
	//переворот

	int mem=0;
	for (int i = 0; i <= l_a; i++) {
		if (i == l_a) {
			if (mem == 0)res[i] = '0';
			else if (mem == 1) { res[i] = '1'; mem = 0; }
			else if (mem > 1) { res[i] = '0'; mem -= 1; }
		}
		else if ((a[i] == '0') && (b[i] == '0')) {
			if (mem == 0)res [i]= '0';
			else if (mem == 1) { res[i] = '1'; mem = 0; }
			else if (mem > 1){ res[i] = '0'; mem -= 1; }
		}
		else if ((a[i] == '0') && (b[i] == '1')) {
			if (mem == 0)res[i] = '1';
			else if (mem == 1) { res[i] = '0'; mem = 1; }
			else if (mem > 1) { res[i] = '1'; mem -= 1; }
		}
		else if ((b[i] == '0') && (a[i] == '1')) {
			if (mem == 0)res[i] = '1';
			else if (mem == 1) { res[i] = '0'; mem = 1; }
			else if (mem > 1) { res[i] = '1'; mem -= 1; }
		}
		else if ((b[i] == '1') && (a[i] == '1')) {
			if (mem == 0) { res[i] = '0'; mem = 1; }
			else if (mem == 1) { res[i] = '1'; mem = 1; }
			else if (mem > 1) { res[i] = '1'; mem -= 1; }
		}
	}

	for (int i = 0; i <= l_a; i++) {
		cs[i] = res[l_a - i];
	}
	for (int i = 0; i <= l_a; i++) {
		res[i] = cs[i];
	}
	if (res[l_a] == '0' || res[l_a] == '1') {
		res[l_a + 1] = '\0';
	//return l_a + 1;
	}
	else {
		res[l_a] = '\0';
		//return l_a;
	}

}
void copy(char acha[], char achar[]) {
	for (int i = 0; i < 50; i++) acha[i] = achar[i];
}

int main()
{
	char achar[50], bchar[50], res[50], acha[50], bcha[50], cchar[50];
	cchar[0] = '1';
	cchar[1] = '\0';
	int l_a, l_b,l_c=1;
	std::cout << "A, B\n";
	std::cin >> achar;
	std::cin >> bchar;

	l_a = len(achar);
	l_b = len(bchar);
	priam(achar, l_a, bchar, l_b);
	obrat(achar, l_a, bchar, l_b);
	//dop(achar, l_a); dop(bchar, l_b);
	//revers(achar, l_a);	revers(bchar, l_b);
	if(achar[0]=='1') suum(achar, l_a, cchar, l_c, acha);
	else copy(acha, achar);
	if(bchar[0]=='1') suum(bchar, l_a, cchar, l_c, bcha);
	else copy(bcha, bchar);
	//перевод в дополн код
	suum(acha, l_a,bcha,  l_b, res);
	std::cout << "\n res  " << res;
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
