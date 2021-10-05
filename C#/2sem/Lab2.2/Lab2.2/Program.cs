using System;
using System.Text;

namespace Lab2._2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите str: ");
            StringBuilder StrB = new StringBuilder("");
            StringBuilder StrB2 = new StringBuilder("");
            string Str;
            Str= Console.ReadLine();
            StrB.Insert(0 ,Str);
            int ii = 0, g =0, i= StrB.Length-1;
            Console.WriteLine($"Начальная строка: {StrB}");
            for (int j = StrB.Length-1; j >= 0; j--) { 
                
                if (StrB[i]==' ')
                {
                    StrB2.Insert(0, StrB);
                    StrB2.Remove(0, StrB2.Length-ii);
                    StrB.Insert(g, StrB2);
                    g += ii;
                    StrB.Insert(g, " ");
                    g++;
                    
                    StrB.Remove(StrB.Length - ii-1, ii+1);
                    StrB2.Remove(0, ii);
                    
                    i = StrB.Length;
                    ii = -1;
                }
                ii++;
                i--;
            }
            Console.WriteLine($"Конечная строка: {StrB}");

        }
    }
}
