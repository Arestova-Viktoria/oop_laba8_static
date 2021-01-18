using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_laba8_cs
{
    class Icecream
    {
        private static int id_gener = 1;
        private int id;
        private String name;
        private String country;
        private int massa;
        private int milk;
        private int expiration_date;
        private int chocolate;
        private Date date_post;
        public String Name
        {
            get
            {
                return name;
            }
            set
            {
                name = value;
            }
        }
        public String Country
        {
            get
            {
                return country;
            }
            set
            {
                country = value;
            }
        }

        public int Massa
        {
            get
            {
                return massa;
            }
            set
            {
                massa = value;
            }
        }

        public int Milk
        {
            get
            {
                return milk;
            }
            set
            {
                milk = value;
            }
        }
        public int Expiration_date
        {
            get
            {
                return expiration_date;
            }
            set
            {
                expiration_date = value;
            }
        }
        public int Chocolate
        {
            get
            {
                return chocolate;
            }
            set
            {
                chocolate = value;
            }
        }
        public int Number
        {
            get
            {
                return date_post.Day;
            }
            set
            {
                date_post.Day = value;
            }
        }

        public Icecream()
        {
            this.date_post = new Date();
        }
        public String Read_String()
        {
            String str = Console.ReadLine();
            return str;
        }
        public int Read_Int()
        {
            int n = Convert.ToInt32(Console.ReadLine());
            return n;
        }
        public void Init(String nazv, int mas, int sod_milk, int ex_date, int ch, String count, int x, int y, int k)
        {
            name = nazv;
            massa = mas;
            milk = sod_milk;
            expiration_date = ex_date;
            chocolate = ch;
            date_post.Init(x, y, k);
            country = count;
        }
        public void Display()
        {
            Console.WriteLine($"Name: {name} ");
            Console.WriteLine($"Massa: {massa} ");
            Console.WriteLine($"milk: {milk} ");
            Console.WriteLine($"expiration_date: {expiration_date} ");
            Console.WriteLine($"chocolate: {chocolate} ");
            date_post.Display();
            Console.WriteLine($"Country: {country} ");
        }
        public int Add(Icecream ice1, Icecream ice2)
        {
            Icecream ice3 = new Icecream();
            ice3.massa = ice1.massa + ice2.massa;
            return ice3.massa;
        }
        public void output_date_postavk()
        {
            date_post.output_date_postavk();
        }
        public void Country_output()
        {
            Console.WriteLine($"Country: {country}");
        }
        public int one(Icecream icecream)
        {
            return icecream.massa + 100;
        }
        public int two()
        {
            return one(this);
        }
        //перегрузка оператора + с помощью свойства Massa
        public static Icecream operator +(Icecream ice1, Icecream ice2)
        {
            return new Icecream { Massa = ice1.massa + ice2.massa };
        }

        //перегрузка оператора ++ с помощью свойства Massa
        public static Icecream operator ++(Icecream ice1)
        {
            return new Icecream { Massa = ice1.massa + 1 };
        }

        //создание уникального ID с помощью статической переменной id_generator
        public int get_id()
        {
            id = id_gener++;
            return id;
        }
        //статический метод для получения значения текущего ID без создания объекта класса
        public static int get_id_now()
        {
            return id_gener;
        }
    }
}
