using System;
using System.IO;

namespace _1lab_file
{
    class Program
    {
        
        static void Main(string[] args)
        {
            
            string path = @"D:\work\documents\Study\3sem\file.txt";
            string pathCom = @"D:\work\documents\Study\3sem\file.zip";
            
            InfoData info = new InfoData();

            while (true)
            {
                Console.WriteLine("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
                string command = Console.ReadLine();
                info.use(command, path, pathCom);
            }
        }
    }
}
/* 
Необходимо реализовать методы, позволяющие сохранять и читать 
данные объектов класса- коллекции из текстового и двоичного файла.
Применить при чтении / записи потоки, поддерживающие сжатие информации. 
Продемонстрировать работу с классами для объектов файловой системы 
(копирование и переименование файлов, отслеживание изменения состояния файла).
*/
