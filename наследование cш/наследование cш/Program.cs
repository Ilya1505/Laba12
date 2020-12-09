﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace наследование_cш
{
    class Program
    {
        static Exception ex;// исключение класса ex
        static void Main(string[] args)
        {
            Console.WriteLine("Инициализация:\n");
            engine dvs = new engine("no_name", 10, 100, 0, 1000);// конструктор со всеми параметрами
            engine dvs1 = new engine();
            cars avto = new cars("no_name", "no_color", 2020, 1000, 10, dvs, 5, 0);// конструктор со всеми параметрами
            cars avto1 = new cars("no_name", "no_color", 2020, 10000, 20, dvs1, 10, 0);
            avto = (cars)avto1.Clone();// глубокое клонирование
            AddTov(avto);// вызов метода где использ абстракт класс
            Console.WriteLine("Машина:");
            Console.WriteLine(avto);
            bool f;
            do
            {
                f = false;
                try { avto.Read(); }
                catch (FormatException ex)// обработка программного исключения
                {
                    f = true;
                    Console.WriteLine("Ошибка: " + ex.Message);
                    Console.WriteLine("Введите данные еще раз");
                }
                catch (Exception ex)// обработка пользовательского исключения
                {
                    f = true;
                    Console.WriteLine("Ошибка: " + ex.Message);
                    Console.WriteLine("Введите данные еще раз");
                }
            } while (f);
            Console.WriteLine("\nДанные после ввода:");
            Console.Write(avto);
            int probegAfterDrive = 0;
            Zapravit(avto);// вызов метода где использ интерфейс
            try { probegAfterDrive = avto.Drive(10); }
            catch (Exception ex)// обработка пользовательского исключения
            {
                Console.WriteLine("Ошибка: " + ex.Message);
                Console.WriteLine("Завершение работы программы");
                Environment.Exit(1);
            }
            Console.Write("\nПробег после тест-драйва: ");
            Console.WriteLine(probegAfterDrive);
            try { avto.Modern(100, 200, 500); }
            catch (Exception ex)// обработка пользовательского исключения
            {
                Console.WriteLine("Ошибка: " + ex.Message);
                Console.WriteLine("Завершение работы программы");
                Environment.Exit(1);
            }
            Console.WriteLine("\n\nПосле модернизации:");
            Console.Write(avto);
            avto.Sell();// вызов базового метода продажи авто
            avto.Sell(5);// вызов метода производного класса
            Console.WriteLine("Самолет:");
            plane pl = new plane("no_name", "no_color", 2020, 1000, 10, 10000, 5, 0);// конструктор со всеми параметрами
            Console.WriteLine(pl);
            do
            {
                f = false;
                try { pl.Read(); }
                catch (FormatException ex)// обработка программного исключения
                {
                    f = true;
                    Console.WriteLine("Ошибка: " + ex.Message);
                    Console.WriteLine("Введите данные еще раз");
                }
                catch (Exception ex)// обработка пользовательского исключения
                {
                    f = true;
                    Console.WriteLine("Ошибка: " + ex.Message);
                    Console.WriteLine("Введите данные еще раз");
                }
            } while (f);
            Console.WriteLine("\nДанные после ввода:");
            Console.Write(pl);
            Zapravit(pl);
            pl.Fly(1);
            Console.WriteLine("Налет (в часах) после полета: " + pl.HOURFLY);
            pl.Sell();
            Console.ReadLine();
        }
        static void AddTov(avtoShop tk)// полиморфизм
        {
            tk.addTov();
        }
        static void Zapravit(AZS tk)
        {
            tk.zapravka();
        }
        interface AZS// интерфейс
        {
            void zapravka();
        }
        abstract class avtoShop// абстрактный класс
        {
            public abstract void addTov();// абстрактный метод
        }
        class engine:ICloneable// двигатель
        {
            private string name;// марка двигателя
            public string Name
            {
                set
                {
                    name = value;
                }
                get
                {
                    return name;
                }
            }
            private Double weight;// вес
            public Double Weight
            {
                set
                {
                    weight = value;
                }
                get
                {
                    return weight;
                }
            }
            private Int32 power;// мощность (л.с.)
            public Int32 Power
            {
                set
                {
                    power = value;
                }
                get
                {
                    return power;
                }
            }
            private Int32 probeg;// пробег
            public Int32 Probeg
            {
                set
                {
                    probeg = value;
                }
                get
                {
                    return probeg;
                }
            }
            private Int32 resurs;// ресурс двигателя
            public Int32 Resurs
            {
                set
                {
                    resurs = value;
                }
                get
                {
                    return resurs;
                }
            }

            public engine(string name, Double weight, Int32 power, Int32 probeg, Int32 resurs)// конструктор со всеми параметрами
            {
                this.name = name;
                this.weight = weight;
                this.power = power;
                this.probeg = probeg;
                this.resurs = resurs;
            }
            public engine(string name)// конструктор с одним параметром
            {
                this.name = name;
                this.weight = 100;
                this.power = 500;
                this.probeg = 0;
                this.resurs = 500;
            }
            public engine()// конструктор без параметров
            {
                this.name = "no_name";
                this.weight = 10;
                this.power = 100;
                this.probeg = 0;
                this.resurs = 500;
            }
            public void Remont()// ремонт двигателя
            {
                this.probeg = 0;
            }
            public void Read()// ввод данных
            {
                Console.WriteLine("Введите марку двигателя: ");
                this.name = Console.ReadLine();
                if (name.Length == 0) throw ex = new Exception("пустая марка двигателя");// создание объекта класса Exception
                Console.WriteLine("Введите мощность двигателя: ");
                this.power = Convert.ToInt32(Console.ReadLine());
                if (power < 0 || power > 100000) throw ex = new Exception("некорректная мощность двигателя");
                Console.WriteLine("Введите пробег двигателя: ");
                this.probeg = Convert.ToInt32(Console.ReadLine());
                if (probeg < 0 || power > 1000000) throw ex = new Exception("некорректный пробег");
                Console.WriteLine("Введите ресурс двигателя: ");
                this.resurs = Convert.ToInt32(Console.ReadLine());
                if (resurs < 0 || power > 1000000) throw ex = new Exception("некорректный двигателя");
                Console.WriteLine("Введите вес двигателя: ");
                this.weight = Convert.ToDouble(Console.ReadLine());
                if (weight < 0 || weight > 1000000) throw ex = new Exception("некорректный вес двигателя");
            }
            public override string ToString()// вывод данных
            {
                string en = "";
                en += "Марка двигателя: " + name + "\n" + "Мощность двигателя: " +Convert.ToString(power)
                    + "\n" + "Пробег двигателя: " + Convert.ToString(probeg) +"\n" +
                    "Ресурс двигателя: " + Convert.ToString(resurs) + "\n" + "Вес двигателя: " + Convert.ToString(weight) + "\n";
                return en;
            }
            public object Clone()
            {
                return new engine(name, weight, power, probeg, resurs);
            }
            //public void Print()// вывод данных
            //{
            //    Console.WriteLine("Марка двигателя: " + name);
            //    Console.WriteLine("Мощность двигателя: " + power);
            //    Console.WriteLine("Пробег двигателя: " + probeg);
            //    Console.WriteLine("Ресурс двигателя: " + resurs);
            //    Console.WriteLine("Вес двигателя: " + weight);
            //}
        };
        class technica:avtoShop, AZS
        {
            protected string name;// марка авто
            public string Name// свойство класса
            {
                set
                {
                    if (value != "")
                    {
                        name = value;
                    }
                }
                get
                {
                    return name;
                }
            }
            protected string color;// цвет авто
            public string Color
            {
                set
                {
                    if (value != "")
                    { color = value; }
                }
                get
                {
                    return color;
                }
            }
            protected Int32 year;// год выпуска
            public Int32 Year
            {
                set
                {
                    year = value;
                }
                get
                {
                    return year;
                }
            }
            protected Double price;// цена
            public Double Price
            {
                set
                {
                    price = value;
                }
                get
                {
                    return price;
                }
            }
            protected int count;
            public int Count
            {
                set
                {
                    count = value;
                }
                get
                {
                    return count;
                }
            }
            protected double petrol;
            public technica(String name, String color, int yr, double pr, int co, double pt)// конструктор со всеми параметрами
            {
                this.name = name;
                this.color = color;
                this.year = yr;
                this.price = pr;
                this.petrol = pt;
            }
            public technica()// конструктор без параметров
            {
                name = "no_name";
                color = "no_color";
                year = 2000;
                price = 0;
                count = 0;
                petrol = 0;
            }

            public void Read()// функкция ввода данных
            {
                Console.WriteLine("Введите марку: ");
                name = Console.ReadLine();
                if (name.Length == 0) throw ex = new Exception("пустая строка марки");
                Console.WriteLine("Введите цвет: ");
                color = Console.ReadLine();
                if (color.Length == 0) throw ex = new Exception("пустая строка цвета");
                Console.WriteLine("Введите год выпуска: ");
                year = Convert.ToInt32(Console.ReadLine());
                if (year < 2000 || year > 2020) throw ex = new Exception("неккоректный год выпуска");
                Console.WriteLine("Введите цену: ");
                price = Convert.ToDouble(Console.ReadLine());
                if (price < 1 || price > 10000000) throw ex = new Exception("неккоректная цена");
                Console.WriteLine("Введите количество: ");
                count = Convert.ToInt32(Console.ReadLine());
                if (count < 0) throw ex = new Exception("неккоректное количество");
            }
            public override string ToString()// функция вывода данных
            {
                string tk;
                tk = "Марка: " + name + "\n" + "Цвет: " + color + "\n" + "Год выпуска: "
                        + year + "\n" + "Цена: " + price + "\n" + "Количество: " + count + "\n";
                return tk;
            }
            public int Sell()
            {
                count--;
                Console.WriteLine("Техника продана!");
                Console.WriteLine("текущее количество: " + count);
                return count;
            }
            public override void addTov()// перегрузка абстрактной функции
            {
                count++;
                Console.WriteLine("Добавлена 1 новая техника");
            }
            //public void OutputCars()// функция вывода данных
            //{
            //    Console.WriteLine("Марка машины: " + name);
            //    Console.WriteLine("Цвет машины: " + color);
            //    Console.WriteLine("Год выпуска машины: " + year);
            //    Console.WriteLine("Цена: " + price);
            //    dvs.Print();
            //}
            public void zapravka()
            {
                if (petrol == 0)
                {
                    petrol += 100;
                    Console.WriteLine("Бак полностью заправлен");
                }
                else Console.WriteLine("100л залить нельзя, бак не пустой");
            }
        };
        class cars : technica,AZS,ICloneable
        {
            private engine dvs;// двигатель
            public engine Dvs
            {
                set { dvs = value; }
                get { return dvs; }
            }
            private double timeToHundred;// время разгона до сотни
            public double TimeToHundred
            {
                set { timeToHundred = value; }
                get { return timeToHundred; }
            }
            public cars()
            {
                timeToHundred = 0;
                dvs = new engine();
            }
            public cars(string name, string color, int year, double price,
                int count, engine dvs, double time, double petrol)
                : base(name, color, year, price, count, petrol)// вызов конструктора базового класса
            {
                this.dvs = dvs;//установка двигателя
                this.timeToHundred = time;
            }
            public void Read()
            {
                base.Read();
                Console.WriteLine("Введите время разгона до сотни: ");
                timeToHundred = Convert.ToDouble(Console.ReadLine());
                if (timeToHundred < 1 || timeToHundred > 10000000) throw ex = new Exception("неккоректное время разгона");
                dvs.Read();
            }
            public override string ToString()// функция вывода данных
            {
                string avto;
                avto = "Марка: " + name + "\n" + "Цвет: " + color + "\n" + "Год выпуска: "
                        + year + "\n" + "Цена: " + price + "\n" + "Количество: " + count + "\n" + "Время разгона до сотни: " + timeToHundred + "\n";
                return avto + dvs.ToString();
            }
            public int Drive(int km)// тест-драйв
            {
                if (km < 0 || km > 100) throw ex = new Exception("некорректное расстояние тест-драйва");
                return dvs.Probeg = dvs.Probeg + km;
            }
            public void Modern(Double NewWeight, Int32 NewPower, Int32 NewResurs)// модернизация
            {
                if (NewWeight < 0 || NewWeight > 15000 ||
                    NewPower < 0 || NewPower > 15000 || NewResurs < 0 || NewResurs > 1000000)
                {
                    ex = new Exception("некорректные данные модернизации");
                }
                dvs.Weight = NewWeight;
                dvs.Power = NewPower;
                dvs.Resurs = NewResurs;
                dvs.Remont();
            }
            public int Sell(int count)// перегрузка метода базового класса
            {
                this.count -= count;
                Console.WriteLine("Техника продана!");
                Console.WriteLine("текущее количество: " + this.count);
                return this.count;
            }
            public override void addTov()// перегрузка абстрактной функции
            {
                count += 3;
                Console.WriteLine("Добавлено 3 новые машины");
            }
            public void zapravka()
            {
                if (petrol <= 90)
                {
                    petrol += 10;
                    Console.WriteLine("Залито 10л бензина");
                }
                else Console.WriteLine("10л залить нельзя, бак почти полный");
            }
            public object Clone()
            {
                cars c = new cars(name, color, year, price, count, dvs, timeToHundred, petrol);
                dvs = (engine)dvs.Clone();
                return c;
            }
        };
        class plane : technica,AZS
        {
            private double MaxHeight;// максимальная высота полета (в метрах)
            public double MAXHEIGHT
            {
                set { MaxHeight = value; }
                get { return MaxHeight; }
            }
            private double HourFly;// налет в часах
            public double HOURFLY
            {
                set { HourFly = value; }
                get { return HourFly; }
            }
            public plane(String name, String color, int year, double price,
                int count, double maxheight, double hourfly, double petrol)
                : base(name, color, year, price, count, petrol)
            {
                MaxHeight = maxheight;
                HourFly = hourfly;
            }
            public plane()
            {
                MaxHeight = 10000;
                HourFly = 0;
            }
            public override string ToString()// функция вывода данных
            {
                string plane;
                plane = "Марка: " + name + "\n" + "Цвет: " + color + "\n" + "Год выпуска: "
                        + year + "\n" + "Цена: " + price + "\n" + "Количество: " + count + "\n"
                        + "Максимальная высота полета: " + MaxHeight + "\n" + "Время налета в часах: " + HourFly + "\n";
                return plane;
            }
            public void Read()
            {
                base.Read();
                Console.WriteLine("Введите максимальную высоту полета: ");
                MaxHeight = Convert.ToDouble(Console.ReadLine());
                if (MaxHeight < 0 || MaxHeight> 100000) throw ex = new Exception("неккоректное высота");
                Console.WriteLine("Введите время налета(в часах): ");
                HourFly= Convert.ToDouble(Console.ReadLine());
                if (HourFly< 0) throw ex = new Exception("неккоректное время");
            }
            public double Fly(double hour)// функция полета на определенное количество часов
            {
                petrol -= 50;
                HourFly += hour;
                return HourFly;
            }
            public override void addTov()// перегрузка абстрактной функции
            {
                count += 2;
                Console.WriteLine("Добавлено 2 новых самолета");
            }
            public void zapravka()
            {
                if(petrol<=50)
                {
                    petrol+=50;
                    Console.WriteLine("Залито 50л бензина");
                }
                else Console.WriteLine("50л залить нельзя");
            }
        };
    }
}
