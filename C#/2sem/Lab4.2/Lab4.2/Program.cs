using System;
using System.Runtime.InteropServices;

namespace Sleep
{
    class Program
{
    [DllImport("user32.dll")]
    static extern bool LockWorkStation();

    private static void Main(string[] args)
    {
        Console.WriteLine("Press smth");
        Console.ReadKey();
        Console.WriteLine("???");
        System.Threading.Thread.Sleep(2000);
        LockWorkStation();

    }
}
}