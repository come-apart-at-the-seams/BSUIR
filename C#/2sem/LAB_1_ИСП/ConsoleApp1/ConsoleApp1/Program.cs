using System;
// try catch 32
namespace ConsoleApp1
{
    class Players
    {
        public int money;
        public string name;
        public int points;
        public int bet;
        public Players() 
        {
            //money = 100000000;
            name = "Diller";
            points = 0;
        }
        public Players(string _name)
        {
            money = 10000;
            name = _name;
            points = 0;
            bet = 0;
        }

        public void MakeBet(Players player)
        {
            do
            {
                Console.Clear();
                Console.WriteLine( name + $", you have  {money.ToString() } $ in your bank.");
                Console.WriteLine("\nMake your bet! ");

                player.bet = Convert.ToInt32(Console.ReadLine());
            } while (player.bet < 1);
            player.money -= player.bet;
            Console.Clear();
            Console.WriteLine("Your bet is " + bet.ToString() + "$ !!! \nYou have " + money.ToString() + "$ in your bank.");
            
        }
      
        
    }
    class Program
    {
        static int quantity=0;

        static int MakeRndmA()
        {
            Random rnd = new Random();
            int a;
            a = rnd.Next(10000) % 13;
            return a;
        }
        static int MakeRndmB()
        {
            Random rnd = new Random();
            int a;
            a = rnd.Next(10000) % 4;
            return a;
        }
        
        static void MakeDesk(string[,] desk)
        {
            string num = "0";
            int y;
            for (int i = 0; i < 13; i++)
            {
                y = i + 2;
                if (y < 11) num = y.ToString();
                else if (i == 9) num = "J";
                else if (i == 10) num = "Q";
                else if (i == 11) num = "K";
                else if (i == 12) num = "A";
                desk[i, 0] = "Heart " + num;
                desk[i, 1] = "Diamond " + num;
                desk[i, 2] = "Club " + num;
                desk[i, 3] = "Spade " + num;
            }
        }

        static int DillerGame(string[,] desk, Players diller)
        {
            Console.WriteLine(".......................................................................................................................");

            int a, b;
            diller.points = 0;
            a = MakeRndmA();
            b = MakeRndmB();
            while (string.IsNullOrEmpty(desk[a, b]))
            {
                a = MakeRndmA();
                b = MakeRndmB();
            }

            do
            {
                int point = 0;
                a = MakeRndmA();
                b = MakeRndmB();
                while (string.IsNullOrEmpty(desk[a, b]))
                {
                    a = MakeRndmA();
                    b = MakeRndmB();
                }
                Console.WriteLine("Diller cart is: " + desk[a, b]);
                if (a < 9) point = a+2;
                else if (a > 8 && a < 12) point = 10;
                else
                {
                    if (diller.points >= 11) point = 1;
                    else point = 1;
                }
                
                diller.points += point;
                
            } while (diller.points <= 16);
            Console.WriteLine("(---) Diller points is: " + diller.points);
            Console.WriteLine(".......................................................................................................................");


            return diller.points;
        }
        static void MakeGame( string[,] desk, Players player, Players diller)
        {
            player.points = 0;
            int b, a, point=0;
            Console.WriteLine("Press smth to play.");
            Console.ReadKey();
            a = MakeRndmA();
            b = MakeRndmB();
            while (string.IsNullOrEmpty(desk[a, b]))
            {
                a = MakeRndmA();
                b = MakeRndmB();
            }
                
                Console.WriteLine("\nYour cart is: " + desk[a, b]);
                if (a < 9) point = a+2;
                else if (a > 8 && a < 12) point = 10;
                else point = 11;
                Console.WriteLine("Your points cart is: " + point);
                player.points += point;
                Console.WriteLine("Your points is: " + player.points);
            Console.WriteLine();

            do
            {
                Console.WriteLine(".......................................................................................................................");

                Console.WriteLine("Сlick smth to get a new card. Click  * S *  to stop. ");
                
                Console.WriteLine(".......................................................................................................................");
                Console.WriteLine();
                char s;
                s = Console.ReadKey(true).KeyChar;
                if (s == 's') break;

                a = MakeRndmA();
                b = MakeRndmB();
                if (!string.IsNullOrEmpty(desk[a, b]))
                {
                    a = MakeRndmA();
                    b = MakeRndmB();
                }

                Console.WriteLine("Your cart is: " + desk[a, b]);
                if (a < 9) point = a+2;
                else if (a > 8 && a < 12) point = 10;
                else
                {
                    if (player.points >= 11) point = 1;
                    else point = 11;
                }
                Console.WriteLine("Your points cart is: " + point);
                player.points += point;
                Console.WriteLine("Your points is: " + player.points);
                Console.WriteLine();
            } while (player.points<21);
            
            if (player.points < 21)
            {
                
                DillerGame(desk, diller);
                if (diller.points > 21)
                {
                    Console.WriteLine("||||||||||||||||||||||");
                    Console.WriteLine("||||              ||||");
                    Console.WriteLine("||||  You WIN!!!  ||||");
                    Console.WriteLine("||||              ||||");
                    Console.WriteLine("||||||||||||||||||||||");

                    player.money += 2 * player.bet;
                }
                else
                {
                    string WinLose = diller.points <= player.points ? "||||||||||||||||||||||\n||||              ||||\n||||  You WIN!!!  ||||\n||||              ||||\n||||||||||||||||||||||" : "You LOSE :(";
                    if (diller.points <= player.points) player.money += 2 * player.bet;
                    Console.WriteLine(WinLose);
                }

            }
            else if(player.points == 21)
            {
                Console.WriteLine("||||||||||||||||||||||");
                Console.WriteLine("||||              ||||");
                Console.WriteLine("||||  You WIN!!!  ||||");
                Console.WriteLine("||||              ||||");
                Console.WriteLine("||||||||||||||||||||||");
                player.money += 2 * player.bet;
            }
            else Console.WriteLine("You LOSE :(");

        }



        
        static void Main(string[] args)
        {
            string[,] desk = new string[13,4];
            MakeDesk(desk);
            Console.WriteLine("Hello!!! what is your name?");
            Players player = new Players(Console.ReadLine());
            Players diller = new Players();
            
            while (true)
            {
                if (quantity > 42)
                {
                    MakeDesk(desk);
                    quantity = 0;
                }

                player.MakeBet(player);
                MakeGame(desk, player, diller);
                Console.ReadKey();
            }
            
            
        }
    }
}
