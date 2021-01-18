using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_laba8_cs
{
    class Program
    {
        static void Main(string[] args)
        {
            Icecream ice = new Icecream();
            String str_1 = "Lakomka";
            String str_2 = "Russia";
            int m = 250;
            int mil = 100;
            int ex = 60;
            int ch = 1;
            int x = 12;
            int y = 10;
            int k = 2020;

            //жемонстрация работы со свойствами
            ice.Name = "Lakomka";
            ice.Country = "Russia";
            Console.WriteLine($"Name: {ice.Name}");
            ice.Number = 35;
            Console.WriteLine($"Day: {ice.Number}");
            ice.Number = 12;
            Console.WriteLine($"Day: {ice.Number} \n");

            //демонстрация работы с массивом любых объектов
            object[] myArrayObject = new object[2];
            myArrayObject[0] = "This is C Sharp";
            myArrayObject[1] = 7;

            //демонстрация работы с массивом класса Icecream
            Icecream[] myIcecreamsObject = new Icecream[2];
            myIcecreamsObject[0] = new Icecream();
            myIcecreamsObject[0].Init(str_1, m, mil, ex, ch, str_2, x, y, k);
            myIcecreamsObject[0].Display();

            //демонстрация возврата значения через параметры out и ref
            int f1 = 7;
            int s;

            IncrementRef(ref f1);
            Sum(f1, 5, out s);
            Console.WriteLine($"f1 + f2 = {s}");

            //демоснтрация использования this
            ice.Init(str_1, m, mil, ex, ch, str_2, x, y, k);
            Console.WriteLine(ice.two());

            //демонстрация перегрузки операторов + ++
            Icecream ice_2 = new Icecream();
            str_1 = "Fixiki";
            str_2 = "Russia";
            m = 120;
            mil = 90;
            ex = 75;
            ch = 0;
            x = 31;
            y = 12;
            k = 2020;
            ice_2.Init(str_1, m, mil, ex, ch, str_2, x, y, k);
            Icecream ice_3 = new Icecream();
            ice_3 = ice + ice_2;
            Console.WriteLine($"Сумма двух объектов класса Icecream = {ice_3.Massa}");
            Console.WriteLine($"Префиксная инкрементация: {(++ice).Massa}");
            Console.WriteLine($"Постфиксная инкрементация: {(ice++).Massa}");

            
            Console.ReadKey();
        }

        public static void Sum(int f1, int v, out int s)
        {
            s = f1 + v;
        }

        public static void IncrementRef(ref int f1)
        {
            f1++;
            Console.WriteLine($"New argument: {f1}");
        }
    }
}
