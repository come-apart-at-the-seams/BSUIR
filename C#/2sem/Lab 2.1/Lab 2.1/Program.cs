//Получить текущее время и дату в двух разных форматах и вывести на экран количество нулей, единиц, …,
//девяток в их записи.
//В заданной строке поменять порядок слов на обратный (слова разделены пробелами).
//Дана строка.Найти в ней все заглавные буквы, не входящие в английский алфавит. 
using System;

namespace Lab_2._1
{
    class Program
    {
        static void Fun(int[] arr, string a)
        {
            int c = 0, b = Convert.ToInt32(a);
            if (b > 9)
            {
                c = b / 10;
                arr[c]++;
                b %= 10;
                arr[b]++;
               
            }
            else arr[b]++;
            
            
        }
        static void Main(string[] args)
        {
            
            int[] arr = new int[10] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            DateTime date = DateTime.Now;

            Console.WriteLine(date.ToString("d/M/yy H:m"));
            Fun(arr, date.ToString("dd"));
            Fun(arr, date.ToString("MM"));
            Fun(arr, date.ToString("HH"));
            Fun(arr, date.ToString("mm"));
            Fun(arr, date.ToString("yy"));
            Console.WriteLine(date.ToString("ddd, d MMM h:m tt"));
            Fun(arr, date.ToString("dd"));
            Fun(arr, date.ToString("hh"));
            Fun(arr, date.ToString("mm"));
            for (int i = 0; i < 10; i++) Console.Write(i + "\t");
            Console.WriteLine();
            for (int i = 0; i < 10; i++) Console.Write(arr[i] + "\t");
            Console.WriteLine();
            Console.WriteLine("//////////////////////////////////////////////////////////////////////////////////");





        }

    }
}
