// in4.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "iostream"

using namespace std;

void Diff(char*, char*, char*);
int isNumber(char ch)
{
	switch (ch)
	{
	case 'b':
	{
		return 11;
		break;
	}
	case 'a':
	{
		return 10;
		break;
	}
	case '9':
	{
		return 9;
		break;
	}
	case '8':
	{
		return 8;
		break;
	}
	case '7':
	{
		return 7;
		break;
	}
	case '6':
	{
		return 6;
		break;
	}
	case '5':
	{
		return 5;
		break;
	}
	case '4':
	{
		return 4;
		break;
	}
	case '3':
	{
		return 3;
		break;
	}
	case '2':
	{
		return 2;
		break;
	}
	case '1':
	{
		return 1;
		break;
	}
	case '0':
	{
		return 0;
		break;
	}
	}
}
void Sum(char* ch1, char* ch2, char* chr)
{
	bool doubleNeg = false;
	if (ch1[0] == '-' && ch2[0] == '-')
	{
		int leng;
		doubleNeg = true;
		leng = strlen(ch1);
		for (int i = 0; i < strlen(ch1) - 1; i++)
		{
			ch1[i] = ch1[i + 1];
		}
		ch1[leng] = '\0';
		leng = strlen(ch2);
		for (int i = 0; i < strlen(ch2) - 1; i++)
		{
			ch2[i] = ch2[i + 1];
		}
		ch2[leng] = '\0';
	}
	if (ch1[0] == '-' && ch2[0] != '-')
	{
		int leng;
		leng = strlen(ch1);
		for (int i = 0; i < strlen(ch1) - 1; i++)
		{
			ch1[i] = ch1[i + 1];
		}
		ch1[leng - 1] = '\0';
		Diff(ch2, ch1, chr);
		return;
	}
	if (ch1[0] != '-' && ch2[0] == '-')
	{
		int leng;
		leng = strlen(ch2);
		for (int i = 0; i < strlen(ch2) - 1; i++)
		{
			ch2[i] = ch2[i + 1];
		}
		ch2[leng - 1] = '\0';
		Diff(ch1, ch2, chr);
		return;
	}
	char* chb = new char[10];
	int leng = 0;
	int n = strlen(ch1) - strlen(ch2);
	leng = strlen(ch1) - doubleNeg;
	if (n)
	{
		if (n > 0)
		{
			leng = strlen(ch1);
			int k = 0;
			for (int i = 0; i < strlen(ch2); i++)
			{
				chb[i] = ch2[i];
			}
			for (int i = 0; i < n; i++)
			{
				ch2[i] = '0';
				k = i;
			}
			for (int i = k + 1; i < leng; i++)
			{
				ch2[i] = chb[i - k - 1];
			}
		}
		else
		{
			leng = strlen(ch2);
			int k = 0;
			for (int i = 0; i < strlen(ch1); i++)
			{
				chb[i] = ch1[i];
			}
			for (int i = 0; i < abs(n); i++)
			{
				ch1[i] = '0';
				k = i;
			}
			for (int i = k + 1; i < leng; i++)
			{
				ch1[i] = chb[i - k - 1];
			}
		}
	}
	int buffleng;
	buffleng = leng;
	leng = strlen(ch1) + 1;
	for (int i = 0; i < strlen(ch2); i++)
	{
		chb[i] = ch2[i];
	}
	ch2[0] = '0';
	for (int i = 1; i < leng; i++)
	{
		ch2[i] = chb[i - 1];
	}
	for (int i = 0; i < strlen(ch1); i++)
	{
		chb[i] = ch1[i];
	}
	ch1[0] = '0';
	for (int i = 1; i < leng; i++)
	{
		ch1[i] = chb[i - 1];
	}

	//////////////////////////////////////
	leng = buffleng + 1;
	cout << endl << "    ";
	if (doubleNeg)
	{
		cout << "-";
	}
	for (int i = 1; i < leng; i++)
	{
		cout << ch1[i];
	}
	cout << "  " << "+" << "  ";
	if (doubleNeg)
	{
		cout << "(-";
		for (int i = 1; i < leng; i++)
		{
			cout << ch2[i];
		}
		cout << ")";
	}
	else
		for (int i = 1; i < leng; i++)
		{
			cout << ch2[i];
		}
	for (int i = leng - 1; i >= 0; i--)
	{
		int a;
		int b;
		a = isNumber(ch1[i]);
		//cout<<endl<<"a: "<<a;
		b = isNumber(ch2[i]);
		//cout<<endl<<"b: "<<b;
		switch (a + b)
		{
		case 23:
		{
			chr[i] = 'b';
			ch1[i - 1]++;
			break;
		}
		case 22:
		{
			chr[i] = 'a';
			ch1[i - 1]++;
			break;
		}
		case 21:
		{
			chr[i] = '9';
			ch1[i - 1]++;
			break;
		}
		case 20:
		{
			chr[i] = '8';
			ch1[i - 1]++;
			break;
		}
		case 19:
		{
			chr[i] = '7';
			ch1[i - 1]++;
			break;
		}
		case 18:
		{
			chr[i] = '6';
			ch1[i - 1]++;
			break;
		}
		case 17:
		{
			chr[i] = '5';
			ch1[i - 1]++;
			break;
		}
		case 16:
		{
			chr[i] = '4';
			ch1[i - 1]++;
			break;
		}
		case 15:
		{
			chr[i] = '3';
			ch1[i - 1]++;
			break;
		}
		case 14:
		{
			chr[i] = '2';
			ch1[i - 1]++;
			break;
		}
		case 13:
		{
			chr[i] = '1';
			ch1[i - 1]++;
			break;
		}
		case 12:
		{
			chr[i] = '0';
			ch1[i - 1]++;
			break;
		}
		case 11:
		{
			chr[i] = 'b';
			break;
		}
		case 10:
		{
			chr[i] = 'a';
			break;
		}
		case 9:
		{
			chr[i] = '9';
			break;
		}
		case 8:
		{
			chr[i] = '8';
			break;
		}
		case 7:
		{
			chr[i] = '7';
			break;
		}
		case 6:
		{
			chr[i] = '6';
			break;
		}
		case 5:
		{
			chr[i] = '5';
			break;
		}
		case 4:
		{
			chr[i] = '4';
			break;
		}
		case 3:
		{
			chr[i] = '3';
			break;
		}
		case 2:
		{
			chr[i] = '2';
			break;
		}
		case 1:
		{
			chr[i] = '1';
			break;
		}
		case 0:
		{
			chr[i] = '0';
			break;
		}
		}
	}
	cout << "  " << "=" << "  ";
	if (doubleNeg)
	{
		cout << "-";
	}
	for (int i = 0; i < leng; i++)
	{
		if (!(!i && chr[0] == '0'))
		{
			cout << chr[i];
		}
	}
}
void Diff(char* ch1, char* ch2, char* chr)
{
	char* chb = new char[10];
	bool greater;
	bool doubleNeg;
	int leng;
	int n = strlen(ch1) - strlen(ch2);
	greater = true;
	doubleNeg = false;
	if (ch1[0] == '-' && ch2[0] == '-')
	{
		leng = strlen(ch2);
		doubleNeg = true;
		for (int i = 0; i < leng; i++)
		{
			ch2[i] = ch2[i + 1];
			ch2[i + 1] = '\0';
		}
		Sum(ch2, ch1, chr);
		return;
	}
	if (ch1[0] != '-' && ch2[0] == '-')
	{
		for (int i = 0; i < strlen(ch2) + 1; i++)
		{
			ch2[i] = ch2[i + 1];
		}
		Sum(ch1, ch2, chr);
		return;
	}

	if (ch1[0] == '-' && ch2[0] != '-')
	{
		leng = strlen(ch2);
		ch2[leng + 1] = '\0';
		for (int i = leng; i > 0; i--)
		{
			ch2[i] = ch2[i - 1];
		}
		ch2[0] = '-';
		Sum(ch1, ch2, chr);
		return;
	}
	leng = strlen(ch1);
	if (n)
	{
		if (n > 0)
		{
			leng = strlen(ch1);
			int k = 0;
			for (int i = 0 + doubleNeg; i < strlen(ch2); i++)
			{
				chb[i] = ch2[i];
			}
			for (int i = 0 + doubleNeg; i < n + doubleNeg; i++)
			{
				ch2[i] = '0';
				k = i;
			}
			for (int i = k + 1; i < leng; i++)
			{
				ch2[i] = chb[i - k - 1 + doubleNeg];
			}
		}
		else
		{
			leng = strlen(ch2);
			int k = 0;
			for (int i = 0 + doubleNeg; i < strlen(ch1); i++)
			{
				chb[i] = ch1[i];
			}
			for (int i = 0 + doubleNeg; i < abs(n) + doubleNeg; i++)
			{
				ch1[i] = '0';
				k = i;
			}
			for (int i = k + 1; i < leng; i++)
			{
				ch1[i] = chb[i - k - 1 + doubleNeg];
			}
		}
	}
	
	for (int i = 0 + doubleNeg; i < leng; i++)
	{
		int a;
		int b;
		a = isNumber(ch1[i]);
		//cout<<endl<<"a: "<<a;
		b = isNumber(ch2[i]);
		//cout<<endl<<"b: "<<b;
		if (a < b)
		{
			greater = false;
			break;
		}
		if (a > b)
		{
			greater = true;
			break;
		}
	}

	if (!greater && !doubleNeg)
	{
		for (int i = 0; i < leng; i++)
		{
			chb[i] = ch2[i];
			ch2[i] = ch1[i];
			ch1[i] = chb[i];
		}
	}

	cout << endl << "    ";
	for (int i = 0; i < leng; i++)
	{
		cout << ch1[i];
	}
	cout << "  " << "-" << "  ";
	for (int i = 0; i < leng; i++)
	{
		cout << ch2[i];
	}
	for (int i = 0; i < leng; i++)
	{
		chb[i] = '0';
	}
	for (int i = leng - 1; i >= 0; i--)
	{
		int a;
		int b;
		a = isNumber(ch1[i]);
		//cout<<endl<<"a: "<<a;
		b = isNumber(ch2[i]);
		//cout<<endl<<"b: "<<b;
		switch (a - b)
		{
		case -11:
		{
			chr[i] = '1';
			int k = 1;
			while (!isNumber(ch1[i - k]))
			{
				if (k > 0)
				{
					ch1[i - k] = 'b';
				}
				k++;
			}
			ch1[i - k]--;
			break;
		}
		case -10:
		{
			chr[i] = '2';
			int k = 1;
			while (!isNumber(ch1[i - k]))
			{
				if (k > 0)
				{
					ch1[i - k] = 'b';
				}
				k++;
			}
			ch1[i - k]--;
			break;
		}
		case -9:
		{
			chr[i] = '3';
			int k = 1;
			while (!isNumber(ch1[i - k]))
			{
				if (k > 0)
				{
					ch1[i - k] = 'b';
				}
				k++;
			}
			ch1[i - k]--;
			break;
		}
		case -8:
		{
			chr[i] = '4';
			int k = 1;
			while (!isNumber(ch1[i - k]))
			{
				if (k > 0)
				{
					ch1[i - k] = 'b';
				}
				k++;
			}
			ch1[i - k]--;
			break;
		}
		case -7:
		{
			chr[i] = '5';
			int k = 1;
			while (!isNumber(ch1[i - k]))
			{
				if (k > 0)
				{
					ch1[i - k] = 'b';
				}
				k++;
			}
			ch1[i - k]--;
			break;
		}
		case -6:
		{
			chr[i] = '6';
			int k = 1;
			while (!isNumber(ch1[i - k]))
			{
				if (k > 0)
				{
					ch1[i - k] = 'b';
				}
				k++;
			}
			ch1[i - k]--;
			break;
		}
		case -5:
		{
			chr[i] = '7';
			int k = 1;
			while (!isNumber(ch1[i - k]))
			{
				if (k > 0)
				{
					ch1[i - k] = 'b';
				}
				k++;
			}
			ch1[i - k]--;
			break;
		}
		case -4:
		{
			chr[i] = '8';
			int k = 1;
			while (!isNumber(ch1[i - k]))
			{
				if (k > 0)
				{
					ch1[i - k] = 'b';
				}
				k++;
			}
			ch1[i - k]--;
			break;
		}
		case -3:
		{
			chr[i] = '9';
			int k = 1;
			while (!isNumber(ch1[i - k]))
			{
				if (k > 0)
				{
					ch1[i - k] = 'b';
				}
				k++;
			}
			ch1[i - k]--;
			break;
		}
		case -2:
		{
			chr[i] = 'a';
			int k = 1;
			while (!isNumber(ch1[i - k]))
			{
				if (k > 0)
				{
					ch1[i - k] = 'b';
				}
				k++;
			}
			ch1[i - k]--;
			break;
		}
		case -1:
		{
			chr[i] = 'b';
			int k = 1;
			while (!isNumber(ch1[i - k]))
			{
				if (k > 0)
				{
					ch1[i - k] = 'b';
				}
				k++;
			}
			ch1[i - k]--;
			break;
		}
		case 11:
		{
			chr[i] = 'b';
			break;
		}
		case 10:
		{
			chr[i] = 'a';
			break;
		}
		case 9:
		{
			chr[i] = '9';
			break;
		}
		case 8:
		{
			chr[i] = '8';
			break;
		}
		case 7:
		{
			chr[i] = '7';
			break;
		}
		case 6:
		{
			chr[i] = '6';
			break;
		}
		case 5:
		{
			chr[i] = '5';
			break;
		}
		case 4:
		{
			chr[i] = '4';
			break;
		}
		case 3:
		{
			chr[i] = '3';
			break;
		}
		case 2:
		{
			chr[i] = '2';
			break;
		}
		case 1:
		{
			chr[i] = '1';
			break;
		}
		case 0:
		{
			chr[i] = '0';
			break;
		}
		}
	}
	cout << "  " << "=" << "  ";
	if (!greater)
	{
		cout << "-";
	}
	int negNoll;
	bool wasNum;
	negNoll = 0;
	wasNum = false;
	for (int i = 0; i < leng; i++)
	{
		if ((chr[i] != '0') || leng == 1 + negNoll || wasNum)
		{
			cout << chr[i];
			wasNum = true;
		}
		else
		{
			negNoll++;
		}
	}
}




int main()
{
	char* ch1 = new char[10];
	char* ch2 = new char[10];
	char* chb = new char[10];
	char* chr = new char[10];
	bool check = true;
	while (check)
	{
		int leng = 0;
		cout << endl << " + or - " << endl;
		char c;
		cin >> c;
		switch (c)
		{
		case '+':
		{
			cout << endl << "First number =  ";
			cin >> ch1;
			cout << endl << "Second number = ";
			cin >> ch2;
			Sum(ch1, ch2, chr);
			break;
		}
		case '-':
		{
			cout << endl << "First number =  ";
			cin >> ch1;
			cout << endl << "Second number = ";
			cin >> ch2;
			Diff(ch1, ch2, chr);
			break;
		}
		case 'q':
		{
			check = false;
			break;
		}
		default:
		{
			continue;
		}
		}
		cout << endl;
	}
	cout << endl << endl << endl;
	return 0;
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
