using System;


namespace Lab7
{

    class Ratio : IComparable
    {
        public string numb;
        public int n = 0, m = 0;
        public int Enter()
        {
            int trait = 0;
            Console.WriteLine("Введите рациональную дробь");
            numb = Console.ReadLine();
            if (numb.Contains('/')) 
            {
                for(int i=0;i<numb.Length; i++)
                {
                    if(numb[i]=='/') break;
                    trait++;
                }
                if ((trait == 0) || (trait == numb.Length-1)) Enter();
            }
            else Enter();

            string[] NandM = numb.Split("/");
            if (NandM.Length > 2) Enter();
            if (NandM[1]=="0") Enter();

            try
            {
                n = Convert.ToInt32(NandM[0]);
            }
            catch (FormatException)
            {
                Console.WriteLine("FormatException");
                Enter();
            }
            try
            {
                m = Convert.ToInt32(NandM[1]);
            }
            catch (FormatException)
            {
                Console.WriteLine("FormatException");
                Enter();
            }
            Console.WriteLine('\n');
            return trait;
        }
        public string Operation(Ratio num1, Ratio num2)
        {
            Console.WriteLine("+ - * /");
            
            
            char ch = Convert.ToChar(Console.ReadLine());
            switch (ch) 
            {
                case '+':
                        num1.n = (num1.n * num2.m) + (num2.n * num1.m);
                        num1.m *= num2.m;
                        break;
                case '-':
                        num1.n = (num1.n * num2.m) - (num2.n * num1.m);
                        num1.m *= num2.m;
                        break;
                case '*':
                        num1.n *= num2.n;
                        num1.m *= num2.m;
                        break;
                case '/':
                        num1.n *= num2.m;
                        num1.m *= num2.n;
                        break;
                default:
                    Console.WriteLine("Вы можете использовать: + - * /");
                    Operation(num1, num2);
                    break;

            }
            Console.WriteLine(num1.n + "/" + num1.m);
            numb = num1.n.ToString() + "/" + num1.m.ToString();      
            return numb;
        }
        public int Comparison(Ratio num1, Ratio num2)
        {
            Console.WriteLine("... ... ... ... ... ... ... ... ... ... ... ... ... ... ... ...");
            int nnn = 0;
            for (int i = 1; i < (num2.m * num1.m + 1); i++)
            {
                if (i % num2.m == 0 && i % num1.m == 0)
                {
                    nnn = i;
                    break;
                }
            }
            num1.n *= nnn;
            num2.n *= nnn;
            if (num1.n < num2.n) 
            {
                num1.n /= nnn;
                num2.n /= nnn;
                Console.WriteLine(num1.n + "/" + num1.m + " < " + num2.n + "/" + num2.m);
                return -1;
            }
            else if (num1.n > num2.n)
            {
                num1.n /= nnn;
                num2.n /= nnn;
                Console.WriteLine(num1.n + "/" + num1.m + " > " + num2.n + "/" + num2.m);
                return -1;
            }
            else
            {
                num1.n /= nnn;
                num2.n /= nnn;
                Console.WriteLine(num1.n + "/" + num1.m + " = " + num2.n + "/" + num2.m);
                return -1;
            }

        }

        public string Format(Ratio num)
        {
            int gcd = GCD(num.n, num.m);
            Console.WriteLine();
            if (gcd == 0)
            {
                Console.WriteLine("0");
                return "0";
            }
            if (num.n < num.m)
            {
                Console.WriteLine("Правильная дробь: " + num.n + "/" + num.m);
                numb = num.n.ToString() + "/" + num.m.ToString();
                return numb;

            }
            else if (num.n == num.m)
            {
                Console.WriteLine("1");
                return "1";
            }
            else
            {
                int c=0;
                while(num.n > num.m)
                {
                    num.n -= num.m;
                    c++;
                }
                Console.WriteLine();
                Console.WriteLine("Смешенная дробь: " + c + " " + num.n + "/" + num.m);
                Console.WriteLine("Неправильная дробь: " + num.n + "/" + num.m);
                numb = num.n.ToString() + "/" + num.m.ToString();
                return numb;

            }
        }
        static int GCD(int a, int b)
        {
            if (a == 0)
            {
                return 0;
            }
            else
            {
                while (b != 0)
                {
                    if (a > b)
                    {
                        a -= b;
                    }
                    else
                    {
                        b -= a;
                    }
                }

                return a;
            }
        }

        public int CompareTo(object obj)
        {
            Ratio ratio = (Ratio)obj;
            if ((this.n * ratio.m) > (ratio.n * this.m)) return 1;
            if ((this.n * ratio.m) < (ratio.n * this.m)) return -1;
           
            return 0;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            
            Ratio ratio1 = new Ratio();
            Ratio ratio2 = new Ratio();
            Ratio ratio3 = new Ratio();


            ratio1.Enter();
            ratio2.Enter();
            ratio3.Enter();

            Ratio[] ratio = new Ratio[] { ratio1, ratio2, ratio3 };

            ratio1.Operation(ratio1, ratio2);
            ratio1.Comparison(ratio1, ratio2); 
            ratio1.Format(ratio2);

            Console.WriteLine("Сортировка");
            Console.WriteLine(ratio[0].numb);
            Console.WriteLine(ratio[1].numb);
            Console.WriteLine(ratio[2].numb);
            Array.Sort(ratio);
            Console.WriteLine(); 
            Console.WriteLine(ratio[0].numb);
            Console.WriteLine(ratio[1].numb);
            Console.WriteLine(ratio[2].numb);
        }
    }
}
