using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Compression;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace Lab2_Extract
{
    public class Monitoring
    {
        public static string TargetDirectory { get; set; }
        public static byte[] key { get; set; } = new byte[16];
        public static byte[] iv { get; set; } = new byte[16];

        const string SourceDirectory = @"D:\work\documents\Study\3sem\ИСП"
                                        + @"\SourceDirectory";
        const string SpecialDirectory = @"D:\work\documents\Study\3sem\ИСП"
                                        + @"\SpecialDirectory";
       // const string TargetDirectory = @"D:\work\documents\Study\3sem\ИСП"
       //                                 + @"\TargetDirectory";

        public static List<string> list = new List<string>();
        public static List<string> pathList = new List<string>();
        private static List<string> stringList = new List<string>();

        public static void Update()
        {          

            //string[] settings = ConfigManager.Call_Parser(SpecialDirectory + @"\111.json");
            string[] settings = ConfigManager.Call_Parser(SpecialDirectory + @"\111.xml");
            makeSettings(settings);

            using (FileStream file = new FileStream(SpecialDirectory + @"\Update.txt",
                                        FileMode.OpenOrCreate))
            {
                using (StreamReader reader = new StreamReader(file))
                {
                    string line;
                    while ((line = reader.ReadLine()) != null)
                    {
                        list.Add(line);
                    }
                }
            }

            string[] yDirs = Directory.GetDirectories(SourceDirectory);
            
            foreach (string yDir in yDirs)
            {
                string[] mDirs = Directory.GetDirectories(yDir);

                foreach (string mDir in mDirs)
                {
                    string[] dDirs = Directory.GetDirectories(mDir);
                    
                    foreach(string dDir in dDirs)
                    {
                        string[] files = Directory.GetFiles(dDir);

                        foreach (var file in files)
                        {
                            pathList.Add(file);
                        }
                    }
                }
            }

            list.Sort();
            pathList.Sort();

            foreach (string path in pathList)
            {
               
                if (!list.Contains(path))
                {
                    // Console.WriteLine("HETTY ");
                    //moveToSpecial(path);
                    Encrypt(path, key, iv);
                    compress(path);
                    moveToTarget(path, TargetDirectory);
                    decompress(path, TargetDirectory);
                    Decrypt(path, TargetDirectory, key, iv);
                    AddToUpdate(path);
                }
            }
        
        }

        public static void AddToUpdate(string path)
        {
            using(StreamWriter writer = new StreamWriter(SpecialDirectory + @"\Update.txt", true))
            {
                writer.WriteLine(path);
            }                
        }

        public static void Encrypt(string path, byte[] key, byte[] iv)
        {
            string ePath = SpecialDirectory + path.Substring(path.LastIndexOf('\\'));

            //byte[] key = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16 };
            //byte[] iv = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16 };
            
            using (FileStream fileStream = new FileStream(path, FileMode.OpenOrCreate))
            using (FileStream fileEStream = new FileStream(ePath, FileMode.OpenOrCreate))
            using (AesCryptoServiceProvider AES = new AesCryptoServiceProvider())
                    {
                        AES.Key = key;
                        AES.IV = iv;
                        using (CryptoStream csEncrypt = new CryptoStream(fileEStream, AES.CreateEncryptor(), CryptoStreamMode.Write))
                        {
                            fileStream.CopyTo(csEncrypt);
                        }
                    }

        }
        
        public static void Decrypt(string path, string TargetDirectory, byte[] key, byte[] iv)
        {
            string archPath = TargetDirectory + "\\archive" + path.Substring(path.LastIndexOf('\\'));
            string dePath = TargetDirectory + path.Substring(path.LastIndexOf('\\'));

            //byte[] key = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16 };
            //byte[] iv = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16 };

            using (FileStream fsFileIn = File.OpenRead(dePath))
            using (FileStream fsFileOut = new FileStream(archPath, FileMode.Create))
            using (AesCryptoServiceProvider cryptAlgorithm = new AesCryptoServiceProvider())
            {
                cryptAlgorithm.Key = key;
                cryptAlgorithm.IV = iv;
                using (CryptoStream csEncrypt = new CryptoStream(fsFileIn, cryptAlgorithm.CreateDecryptor(), CryptoStreamMode.Read))
                {
                    csEncrypt.CopyTo(fsFileOut);
                }
            }

            delete(dePath);
        }

        static void copy(string path, string pathMove)
        {
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

        static void delete(string path)
        {
            File.Delete(path);
        }

        static void moveToTarget(string path, string TargetDirectory)
        {
            path = SpecialDirectory + path.Substring(path.LastIndexOf('\\'));
            path = path.Substring(0, path.Length - 4) + ".zip";
            string pathMove = TargetDirectory + path.Substring(path.LastIndexOf('\\'));
            
            
            copy(path, pathMove);
            delete(path);

        }

        static void compress(string path)
        {
            path = SpecialDirectory + path.Substring(path.LastIndexOf('\\'));
            string pathCom = path.Substring(0, path.Length - 4) + ".zip";

            using (FileStream fileStream = new FileStream(path, FileMode.OpenOrCreate))
            {
                using (FileStream comStream = new FileStream(pathCom, FileMode.Create))
                {
                    using (GZipStream stream = new GZipStream(comStream, CompressionMode.Compress))
                    {
                        fileStream.CopyTo(stream); // копируем байты из одного потока в другой
                        
                    }
                }
            }
            delete(path);
        }

        static void decompress(string path, string TargetDirectory)
        {
            path = TargetDirectory + path.Substring(path.LastIndexOf('\\'));
            string pathCom = path.Substring(0, path.Length - 4) + ".zip";
            using (FileStream comFile = new FileStream(pathCom, FileMode.OpenOrCreate))
            {
                using (FileStream file = new FileStream(path, FileMode.OpenOrCreate))
                {
                    using (GZipStream stream = new GZipStream(comFile, CompressionMode.Decompress))
                    {
                        stream.CopyTo(file);
                        
                    }
                }
            }
            delete(pathCom);
        }

        static void makeSettings(string[] settings)
        {
            TargetDirectory = settings[0];
            

            for (int i = 1; i < 17; i++)
            {
                key[i - 1] = Convert.ToByte(settings[i]);
                
            }

            for (int i = 17; i < 32; i++)
            {
                key[i - 17] = Convert.ToByte(settings[i]);
                
            }
        }
    }
}
