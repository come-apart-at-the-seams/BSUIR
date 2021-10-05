using System;

namespace Lab3
{
    public interface IRunSpeed
    {
        void RunSpeed(int Speed);
    }
    public interface IBenchPress
    {
        void BenchPress(int WeightBenchPress);
    }
    struct discipline
    {
        public double Sprint_100, Sprint_200, Sprint_400, Sprint_60;
        public double Long_Jump, High_Jump;
        public void Print()
        {
            Console.WriteLine("Рекорд 60 метрового спринта: " + Sprint_60);

            Console.WriteLine("Рекорд 100 метрового спринта: " + Sprint_100);

            Console.WriteLine("Рекорд 200 метрового спринта: " + Sprint_200);

            Console.WriteLine("Рекорд 400 метрового спринта: " + Sprint_400);

            Console.WriteLine("Максимальная длина прыжка: " + Long_Jump);

            Console.WriteLine("Максимальная высота прыжка: " + High_Jump);
        }
    }
    enum Leagues { NBA, FIBA, BAL, EuroCup };
    abstract class Human
    {
        public static int Human_ID = 0;
        public string name, last_name, mother_name;
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
        }
        public Human(string _name, string _last_name, string _mother_name, int _age)
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
            last_name = Console.ReadLine();
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
    class Sportsman : Human, IComparable
    {
        protected double Height, Weight = 0;
        protected bool Master_of_Sport, Education;
        protected Sportsman() : base()
        {
            Console.WriteLine("Введите рост: ");
            Height = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Введите вес: ");
            Weight = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Явлется ли мастером спорта? (1 - да; 2 - нет)  ");
            Master_of_Sport = yes_or_no();
            Console.WriteLine("Имеет ли высшее образование? (1 - да; 2 - нет)  ");
            Education = yes_or_no();

        }
        bool yes_or_no()
        {
            bool b = false;
            char a = Convert.ToChar(Console.ReadLine());
            if (a == '1') { b = true; }
            else if (a == '2') { b = false; }
            else
            {
                Console.WriteLine("Некорректное значение. Повторите ввод: ");
                yes_or_no();
            }
            return b;
        }
        protected void Print_Sportsman()
        {
            Console.WriteLine("Рост: " + Height);

            Console.WriteLine("Вес: " + Weight);

            Console.WriteLine("Явлется мастером спорта: " + Master_of_Sport);

            Console.WriteLine("Имеет высшее образование: " + Education);
        }
        public int CompareTo(object Object)
        {
            Sportsman sportsman = (Sportsman)Object;
            if (this.Weight < sportsman.Weight) return -1;
            if (this.Weight > sportsman.Weight) return 1;
            else return 0;
        }
    }
    class Master_Boxin : Sportsman, IBenchPress
    {
        public int Number_Of_Victories = 0, Number_Of_Lesions = 0, Number_Of_Battles = 0;
        public string Weight_Category;
        public string Weight_Category_Fun()
        {
            if (Weight < 48) Weight_Category = "minimumweight";
            else if (Weight < 49) Weight_Category = "light flyweight";
            else if (Weight < 51) Weight_Category = "flyweight";
            else if (Weight < 52) Weight_Category = "super flyweight";
            else if (Weight < 53.5) Weight_Category = "bantamweight";
            else if (Weight < 55) Weight_Category = "super bantamweight";
            else if (Weight < 57) Weight_Category = "featherweight";
            else if (Weight < 59) Weight_Category = "super featherweight";
            else if (Weight < 61) Weight_Category = "lightweight";
            else if (Weight < 63.5) Weight_Category = "super lightweight";
            else if (Weight < 67) Weight_Category = "welterweight";
            else if (Weight < 70) Weight_Category = "super welterweight";
            else if (Weight < 72.5) Weight_Category = "middleweight";
            else if (Weight < 76) Weight_Category = "super middleweight";
            else if (Weight < 79) Weight_Category = "light heavyweight";
            else if (Weight < 91) Weight_Category = "light heavyweight";
            else Weight_Category = "heavyweight";
            return Weight_Category;
        }
        public Master_Boxin() : base()
        {
            Weight_Category_Fun();
            Console.WriteLine("Введите количество боёв: ");
            Number_Of_Battles = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите количество побед: ");
            Number_Of_Victories = Convert.ToInt32(Console.ReadLine());
            Number_Of_Lesions = Number_Of_Battles - Number_Of_Victories;
            BenchPress(WeightBenchPress);
        }
        int WeightBenchPress = 0;
        public void BenchPress(int WeightBenchPress)
        {
            Console.WriteLine("Жим лёжа: ");
            WeightBenchPress = Convert.ToInt32(Console.ReadLine());
        }
        public void Print()
        {
            Console.WriteLine("\n\nБоксёр");
            Print_Inf();
            Print_Sportsman();
            Console.WriteLine("Весовая категория: " + Weight_Category);
            Console.WriteLine("Количество боёв: " + Number_Of_Battles);
            Console.WriteLine("Количество побед: " + Number_Of_Victories);
            Console.WriteLine("Количество поражений: " + Number_Of_Lesions);
            Console.WriteLine("Жим лёжа: " + WeightBenchPress);

        }
    }
    class Master_Basketball : Sportsman, IBenchPress, IRunSpeed
    {
        int Point;
        Leagues leagues;
        public Master_Basketball(Leagues leagues) : base()
        {
            Console.WriteLine("Введите количество очков за всё время: ");
            Point = Convert.ToInt32(Console.ReadLine());
            this.leagues = leagues;
            BenchPress(WeightBenchPress);
            RunSpeed(Speed);
        }
        int WeightBenchPress = 0, Speed=0;
        public void BenchPress(int WeightBenchPress)
        {
            Console.WriteLine("Жим лёжа: ");
            WeightBenchPress = Convert.ToInt32(Console.ReadLine());
        }
        public void RunSpeed(int Speed)
        {
            Console.WriteLine("Скорость бега: ");
            Speed= Convert.ToInt32(Console.ReadLine());
        }
        public void Print()
        {
            Console.WriteLine("\n\nБаскетболист");
            Print_Inf();
            Print_Sportsman();
            Console.WriteLine("Количество очков за всё время: " + Point);
            Console.WriteLine("Лига: " + leagues);
            Console.WriteLine("Жим лёжа: " + WeightBenchPress);
            Console.WriteLine("Скорость бега: " + Speed);
        }
    }
    class Master_Athletics : Sportsman
    {
        discipline record;
        public Master_Athletics() : base()
        {

            Console.WriteLine("Введите рекорд 60 метрового спринта: ");
            record.Sprint_60 = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Введите рекорд 100 метрового спринта: ");
            record.Sprint_100 = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Введите рекорд 200 метрового спринта: ");
            record.Sprint_200 = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Введите рекорд 400 метрового спринта: ");
            record.Sprint_400 = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Введите максимальную длину прыжка: ");
            record.Long_Jump = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Введите максимальную высоту прыжка: ");
            record.High_Jump = Convert.ToDouble(Console.ReadLine());
        }
        int Speed=0;
        public void RunSpeed(int Speed)
        {
            Console.WriteLine("Скорость бега: ");
            Speed = Convert.ToInt32(Console.ReadLine());
        }
        public void Print()
        {
            Console.WriteLine("\n\nАтлет");
            Print_Inf();
            Print_Sportsman();
            record.Print();
            Console.WriteLine("Скорость бега: " + Speed);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Master_Athletics athlet = new Master_Athletics() { name="Петя" , last_name="Атлетов", mother_name="Никитич"};

            Master_Basketball basket = new Master_Basketball(Leagues.NBA) { name = "Федя", last_name = "Корзиночкин", mother_name = "Ильич" };

            Master_Boxin boxin = new Master_Boxin() { name = "Добрыня", last_name = "Ударов", mother_name = "Кузьмич" };

            athlet.Print();
            basket.Print();
            boxin.Print();
            Sportsman[] SportArray = new Sportsman[] { athlet, basket, boxin };
            Console.WriteLine();
            Console.WriteLine(SportArray[0]);
            Console.WriteLine(SportArray[1]);
            Console.WriteLine(SportArray[2]);
            Array.Sort(SportArray);
            Console.WriteLine();
            Console.WriteLine(SportArray[0]);
            Console.WriteLine(SportArray[1]);
            Console.WriteLine(SportArray[2]);
            

        }
    }
}
