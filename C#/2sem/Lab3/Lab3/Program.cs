using System;

namespace Lab3
{
    class Human
    {
        public static int Human_ID = 0;
        string name, last_name, mother_name;
        int age;
        public Human()
        {
            Human_ID++;
            Add_Name();
            Add_Age();
        }
        public Human(int _age)
        {
            Human_ID++;
            Add_Name();
            age = _age;
        }
        public Human(string _name, string _last_name, string _mother_name)
        {
            Human_ID++;
            last_name = _last_name;
            name = _name;
            mother_name = _mother_name;
            Add_Age();
        } public Human(string _name, string _last_name, string _mother_name, int _age)
        {
            Human_ID++;
            last_name = _last_name;
            name = _name;
            mother_name = _mother_name;
            age = _age;
        }

        public void Add_Name(string _name, string _last_name, string _mother_name)
        {
            last_name = _last_name;
            name = _name;
            mother_name = _mother_name;
        }
        public void Add_Name()
        {
            Console.WriteLine("Введите Фамилию: ");
            last_name=Console.ReadLine();
            Console.WriteLine("Введите Имя: ");
            name = Console.ReadLine();
            Console.WriteLine("Введите Отчество: ");
            mother_name = Console.ReadLine();
        }
        public void Add_Age()
        {
            Console.WriteLine($"Введите Возраст ( {last_name} {name} {mother_name}): ");
            age = Convert.ToInt32(Console.ReadLine());
        }
        public void Add_Age(int _age)
        {
            age = _age;
        }
        public void Print_Inf()
        {
            Console.WriteLine($"ФИО: {last_name} {name} {mother_name} \n   Возраст: {age} \n   ID: {Human_ID}");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello!!!");
            Human human = new Human();
            Human human1 = new Human(33);
            Human human2 = new Human("Виктор", "Пупкин", "Добрынович");
            Human human3 = new Human("Виктор", "Кумов", "Добрынович", 23);
            human.Print_Inf();
            human1.Print_Inf();
            human2.Print_Inf();
            human3.Print_Inf();
            human.Add_Age(66);
        }
    }
}
