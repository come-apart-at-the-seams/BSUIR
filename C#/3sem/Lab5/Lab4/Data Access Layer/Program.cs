using System;

namespace Data_Access_Layer
{
    class Program
    {
        static void Main(string[] args)
        {
            Options.ConnectionOptions connectionOptions = new Options.ConnectionOptions();

            DataAccessLayer dataAccessLayer = new DataAccessLayer(connectionOptions);
            Console.WriteLine("Hello World!");
            Console.ReadKey();
        }
    }
}
