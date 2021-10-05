// In3.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//



#include "iostream"

using namespace std;
void sum(char* ch1, char* ch2, char* chr)
{
	for (int i = strlen(ch1) - 1; i > 0; i--)
	{
		switch (ch1[i] + ch2[i] - 96)
		{
		case 3:
		{
			chr[i] = '1';
			ch1[i - 1]++;
			break;
		}
		case 2:
		{
			chr[i] = '0';
			ch1[i - 1]++;
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
	switch (ch1[0] + ch2[0] - 96)
	{
	case 3:
	{
		chr[0] = '1';
		chr[strlen(ch1) - 1]++;
		break;
	}
	case 2:
	{
		chr[0] = '0';
		chr[strlen(ch1) - 1]++;
		break;
	}
	case 1:
	{
		chr[0] = '1';
		break;
	}
	case 0:
	{
		chr[0] = '0';
		break;
	}
	}
	for (int i = strlen(ch1) - 1; i > 0; i--)
	{
		switch (chr[i] - 48)
		{
		case 3:
		{
			chr[i] = '1';
			chr[i - 1]++;
			break;
		}
		case 2:
		{
			chr[i] = '0';
			chr[i - 1]++;
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
}

int main()
{
	while (true)
	{
		int leng;
		char* ch1 = new char[10];
		char* ch2 = new char[10];
		char* ch11 = new char[10];
		char* ch22 = new char[10];
		char* ch3 = new char[10];
		char* chb = new char[10];
		char* chr = new char[10];
		cout << "A =  ";
		cin >> ch1;
		cout << "B =  ";
		cin >> ch2;
		int n = strlen(ch1) - strlen(ch2);
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
				for (int i = 1; i <= n; i++)
				{
					ch2[i] = '0';
					k = i;
				}
				for (int i = k + 1; i < strlen(ch1); i++)
				{
					ch2[i] = chb[i - k];
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
				for (int i = 1; i <= abs(n); i++)
				{
					ch1[i] = '0';
					k = i;
				}
				for (int i = k + 1; i < strlen(ch2); i++)
				{
					ch1[i] = chb[i - k];
				}
			}
		}
		else
		{
			leng = strlen(ch1);
		}
		for (int i = 0; i < leng; i++)
		{
			ch3[i] = '0';
		}

		cout << endl << endl << "  ";
		cout << " ( ";
		for (int i = 0; i < leng; i++)
		{
			cout << ch1[i];
		}
		cout << " ) ";
		cout << " + ";
		cout << " ( ";
		for (int i = 0; i < leng; i++)
		{
			cout << ch2[i];
		}
		cout << " ) ";
		if (ch1[0] == '+')
		{
			ch1[0] = '0';
			sum(ch1, ch3, ch11);
		}
		if (ch2[0] == '+')
		{
			ch2[0] = '0';
			sum(ch2, ch3, ch22);
		}


		if (ch1[0] == '-')
		{
			ch3[leng - 1] = '1';
			ch1[0] = '1';
			for (int i = 1; i < leng; i++)
			{
				if (ch1[i] == '1')
				{
					ch1[i] = '0';
				}
				else
				{
					ch1[i] = '1';
				}
			}
			sum(ch1, ch3, ch11);
		}
		if (ch2[0] == '-')
		{
			ch3[leng - 1] = '1';
			ch2[0] = '1';
			for (int i = 1; i < leng; i++)
			{
				if (ch2[i] == '1')
				{
					ch2[i] = '0';
				}
				else
				{
					ch2[i] = '1';
				}
			}
			sum(ch2, ch3, ch22);
		}
		cout << " = ";
		for (int i = 0; i < leng; i++)
		{
			cout << ch11[i];
		}
		cout << " + ";
		for (int i = 0; i < leng; i++)
		{
			cout << ch22[i];
		}
		sum(ch11, ch22, chr);
		cout << " = ";
		for (int i = 0; i < leng; i++)
		{
			cout << chr[i];
		}
		cout << endl << endl << endl;

	/*	delete[] ch1;
		delete[] ch2;
		delete[] ch11;
		delete[] ch22;
		delete[] ch3;
		delete[] chb;
		delete[] chr;*/
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


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
