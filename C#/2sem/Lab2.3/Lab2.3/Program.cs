using System;
using System.Numerics;

namespace Lab2._3
{
    class Program
    {
        static void Fun(BigInteger a, BigInteger b, BigInteger n, BigInteger i)
        {
            if (a % 2 == 0)
            {
                if (b % 2 == 0)
                {
                    i = ((b - a) / 2) + 1;
                }
                else
                {
                    i = ((b - a - 1) / 2) + 1;
                    b--;
                }
            }
            else
            {
                if (b % 2 == 0)
                {
                    i = ((b - a - 1) / 2) + 1;
                    a++;
                }
                else
                {
                    i = (b - a) / 2;
                    b--;
                    a++;
                }
            }
            BigInteger ac = new BigInteger(ulong.MaxValue);
            for (;i>0; i--)
            {
                ac = a;
                
                while (ac > 1)
                {
                    if (ac % 2 == 0)
                    {
                        ac /= 2;
                        n++;
                    }
                    else break;
                }
                Console.WriteLine($"i= {i}, n= {n}, a= {a}");
                a += 2;
                
            }
            Console.WriteLine($"Answer , n= {n}");

        }
        static void Main(string[] args)
        {
            BigInteger a = new BigInteger(ulong.MaxValue);
            BigInteger b = new BigInteger(ulong.MaxValue);
            BigInteger i = new BigInteger(ulong.MaxValue);
            BigInteger n = new BigInteger(ulong.MaxValue);
            i = 0;
            Console.WriteLine("Enter a: ");
            a= BigInteger.Parse(Console.ReadLine());
            Console.WriteLine("Enter b: ");
            b = BigInteger.Parse(Console.ReadLine());
            n = 0;
            if (a < b)
            {
                Fun(a, b, n, i);
            }
            else Console.WriteLine("ERROR 911 ");
            
        }
    }
}
