using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Compression;
using System.Security.Cryptography.X509Certificates;
using System.Text;

namespace _1lab_file
{
    class InfoData
    {
    
        public List<string> list = new List<string>();

        string readLine()
        {
            Console.WriteLine("Enter your line: ");
            string str = Console.ReadLine();
            return str;
        }

         void addToList()
        {
            list.Add(readLine());
        }

         void readFromFile(string path)
        {
            using (FileStream file = new FileStream(path, FileMode.OpenOrCreate))
            {
                using (StreamReader stream = new StreamReader(file))
                {
                    string line;
                    while ((line = stream.ReadLine()) != null)
                    {
                        Console.WriteLine(line);
                    }
                }
            }
            
        }

         void addToFile(string path)
        {
            using (FileStream file = new FileStream(path, FileMode.Append))
            {
                using (StreamWriter stream = new StreamWriter(file))
                {
                    foreach (string line in list)
                    {
                        stream.Write(line + '\n');
                    }
                }
            }
        }

         void compress(string path, string pathCom)
        {
            using (FileStream fileStream = new FileStream(path, FileMode.OpenOrCreate))
            {
                using (FileStream comStream = new FileStream(pathCom, FileMode.Create))
                {
                    using (GZipStream stream = new GZipStream(comStream, CompressionMode.Compress))
                    {
                        fileStream.CopyTo(stream); // копируем байты из одного потока в другой
                        Console.WriteLine("Сжатие файла {0} завершено. Исходный размер: {1}  сжатый размер: {2}.",
                            path, fileStream.Length.ToString(), comStream.Length.ToString());
                    }
                }               
            }
        }

         void decompress(string path, string pathCom)
        {
            using (FileStream comFile = new FileStream(pathCom, FileMode.OpenOrCreate))
            {
                using(FileStream file = new FileStream(path, FileMode.OpenOrCreate))
                {
                    using (GZipStream stream = new GZipStream(comFile, CompressionMode.Decompress))
                    {
                        stream.CopyTo(file);
                        Console.WriteLine("Восстановлен файл: {0}", file);
                    }
                }
            }
        }

         void copy(string path)
        {
            Console.WriteLine("Enter path: ");
            string pathMove ="D:" + Console.ReadLine() + @"\file.txt";
            Console.WriteLine(pathMove);
            if (path != pathMove) 
            {
                using (FileStream file = new FileStream(path, FileMode.OpenOrCreate))
                {
                    using (FileStream newFile = new FileStream(pathMove, FileMode.OpenOrCreate))
                    {
                        file.CopyTo(newFile);
                    }
                }
            }
            
        }

         void delete(string path)
        {
            File.Delete(path);
        }

         void move(string path)
        {
            copy(path);
            delete(path);

        }

         public void use(string command, string path, string pathCom)
        {
            switch (command)
            {
                case "list":
                    Console.WriteLine("Add to list...\n");
                    addToList();
                    break;
                case "read":
                    Console.WriteLine("Read from file...\n");
                    readFromFile(path);
                    break;
                case "add":
                    Console.WriteLine("Add to file...\n");
                    addToFile(path);
                    break;
                case "com":
                    Console.WriteLine("Compressing file...\n");
                    compress(path, pathCom);
                    break;
                case "decom":
                    Console.WriteLine("Decompressing file...\n");
                    decompress(path, pathCom);
                    break;
                case "copy":
                    Console.WriteLine("Copy file...\n");
                    copy(path);
                    break;
                case "move":
                    Console.WriteLine("Move file...\n");
                    move(path);
                    break;
                case "del":
                    Console.WriteLine("Delete file...\n");
                    delete(path);
                    break;
                default:
                    Console.WriteLine("....Uncorect comand....\n" +
                        "Commands: \n" +
                        "list\n" +
                        "add\n" +
                        "read\n" +
                        "com\n" +
                        "decom\n" +
                        "copy\n" +
                        "move\n" +
                        "del\n"
                        );
                    break;
            }
        }


   
    }
}
