package com.company;
import java.text.ParseException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        engine dvs = new engine("no_name", 10, 100, 0, 1000);// конструктор со всеми параметрами
        cars avto = new cars("no_name", "no_color", 2020, 1000, dvs);// конструктор со всеми параметрами
        int probeg=0;
        avto.OutputCars();
        boolean f;
        do {
            f=false;
            try {
                avto.PutCars();
            }catch (NumberFormatException ex) {//обработка программного исключения
                f=true;
                System.out.println("Ошибка: " + ex);
                System.out.println("Введите данные еще раз!");
            }catch (MyExceptionRead ex) {//обработка пользовательского исключения
                f = true;
                System.out.println("Ошибка: " + ex);
                System.out.println("Введите данные еще раз!");
            }
        }while (f);
        System.out.println(System.lineSeparator()+"Данные после ввода: ");
        avto.OutputCars();
        try{probeg=avto.Drive(10);}
        catch(MyExceptionOther ex)
        {
            System.out.println("Ошибка: "+ex);
            System.out.println("Завершение работы программы!");
            System.exit(1);
        }
        System.out.println(System.lineSeparator()+"Пробег после тест-драйва: ");
        System.out.println(probeg+" КМ"+System.lineSeparator());
        try{avto.Modern(100, 200, 500);}
        catch(MyExceptionOther ex)
        {
            System.out.println("Ошибка: "+ex);
            System.out.println("Завершение работы программы!");
            System.exit(1);
        }
        System.out.println("После модернизации: ");
        avto.OutputCars();
        // массив объектов
        engine []arrayE = new engine[2];
        for(int i=0;i<arrayE.length;i++)
        {
            arrayE[i] = new engine("no_name");// массив объектов созданных через конструктор с одним параметром
        }
        cars []arrayC = new cars[2];
        for(int i=0; i<arrayC.length;i++)
        {
            arrayC[i]=new cars(arrayE[i]);// массив объектов созданных через конструктор с одним параметром
        }
        for(int i=0; i<arrayC.length;i++)
        {
            System.out.println(System.lineSeparator()+"машина "+(i+1));
            arrayC[i].OutputCars();
        }
        for(int i=0; i<arrayC.length;i++)
        {	System.out.println(System.lineSeparator()+"машина "+(i+1));
            do {
                f=false;
                try {
                    arrayC[i].PutCars();
                }catch (NumberFormatException ex) {
                    f=true;
                    System.out.println("Ошибка: " + ex);
                    System.out.println("Введите данные еще раз!");
                }catch (MyExceptionRead ex) {
                    f = true;
                    System.out.println("Ошибка: " + ex);
                    System.out.println("Введите данные еще раз!");
                }
            }while (f);
        }
        System.out.println(System.lineSeparator()+"Данные после ввода: ");
        for(int i=0; i<arrayC.length;i++)
        {	System.out.println(System.lineSeparator()+"машина "+(i+1));
            arrayC[i].OutputCars();
        }
        System.out.println(System.lineSeparator()+"Пробег после тест-драйва: ");
        for(int i=0; i<arrayC.length;i++)
        {
            try{probeg=arrayC[i].Drive(10);}
            catch(MyExceptionOther ex)
            {
                System.out.println("Ошибка: "+ex);
                System.out.println("Завершение работы программы!");
                System.exit(1);
            }
            System.out.println(System.lineSeparator()+"машина "+(i+1));
            System.out.println(probeg+" КМ");
        }
        for(int i=0; i<arrayC.length;i++)
        {
            try{arrayC[i].Modern(100, 200, 500);}
            catch(MyExceptionOther ex)
            {
                System.out.println("Ошибка: "+ex);
                System.out.println("Завершение работы программы!");
                System.exit(1);
            }
        }
        System.out.println(System.lineSeparator()+"После модернизации: ");
        for(int i=0; i<arrayC.length;i++)
        {	System.out.println(System.lineSeparator()+"машина "+(i+1));
            arrayC[i].OutputCars();
        }
    }
};
class MyExceptionRead extends Exception// класс исключений при чтении данных, наследник общего класса Exception
{
    private int Code;
    MyExceptionRead(int Code)
    {
        this.Code=Code;
    }
    public String toString()
    {
        switch (Code)
        {
            case 1: return "некорректный ввод марки авто";
            case 2: return "некорректный ввод цвета авто";
            case 3: return "некорректный ввод года выпуска авто";
            case 4: return "некорректный ввод цены авто";
            case 5: return "некорректный ввод марки двигателя";
            case 6: return "некорректный ввод мощности";
            case 7: return "некорректный ввод пробега";
            case 8: return "некорректный ввод ресурса двигателя";
            case 9: return "некорректный ввод веса двигателя";
            default: return "неизвестная ошибка";
        }

    }
}
class MyExceptionOther extends Exception// класс исключений при тест-драйве и модернизации, наследник общего класса Exception
{   private int Code;
    MyExceptionOther(int Code)
    {
        this.Code=Code;
    }
    public String toString()
    {
        if(Code==1) return "некорректное расстояние тест-драйва!";
        if(Code==2) return "введены некорректные параметры модернизации";
        return "неизвестная ошибка";
    }
}
class engine// двигатель
{
    private String name=new String();// марка двигателя
    private double weight;// вес
    private int power;// мощность (л.с.)
    private int probeg;// пробег
    private int resurs;// ресурс двигателя

    public engine(String name, double weight, int power, int probeg, int resurs)// конструктор со всеми параметрами
    {
        this.name=name;
        this.weight = weight;
        this.power = power;
        this.probeg = probeg;
        this.resurs = resurs;
    }
    public engine(String name)// конструктор с одним параметром
    {
        this.name=name;
        this.weight = 10;
        this.power = 100;
        this.probeg = 0;
        this.resurs = 1000;
    }
    public engine()// конструктор без параметров
    {
        name="no_name";
        weight = 10;
        power = 100;
        probeg = 0;
        resurs = 1000;
    }
    // сеттеры и геттеры
    public void SetName(String name)
    {
        this.name=name;
    }
    public void SetWeight(double weight)
    {
        this.weight = weight;
    }
    public void SetPower(int power)
    {
        this.power = power;
    }
    public void SetProbeg(int probeg)
    {
        this.probeg = probeg;
    }
    public void SetResurs(int resurs)
    {
        this.resurs = resurs;
    }
    public String GetName()
    {
        return name;
    }
    public double GetwWight()
    {
        return weight;
    }
    public int GetPower()
    {
        return power;
    }
    public int GetProbeg()
    {
        return probeg;
    }
    public int GetResurs()
    {
        return resurs;
    }
    public void Remont()// ремонт двигателя
    {
        probeg = 0;
    }
    public void Read() throws NumberFormatException, MyExceptionRead// ввод данных
    {
        Scanner read = new Scanner(System.in);
        System.out.println("Введите марку двигателя: ");
        name=read.nextLine();
        if(name.trim().length()==0) throw new MyExceptionRead(5);// создание пользовательского исключения, принимает код ошибки
        System.out.println("Введите мощность двигателя: ");
        power=Integer.parseInt(read.nextLine());
        if(power<50||power>1500) throw new MyExceptionRead(6);
        System.out.println("Введите пробег двигателя: ");
        probeg=Integer.parseInt(read.nextLine());
        if(probeg<0||probeg>1000000) throw new MyExceptionRead(7);
        System.out.println("Введите ресурс двигателя: ");
        resurs=Integer.parseInt(read.nextLine());
        if(resurs<0||resurs>1000000) throw new MyExceptionRead(8);
        System.out.println("Введите вес двигателя: ");
        weight=Double.parseDouble(read.nextLine());
        if(weight<10||weight>10000) throw new MyExceptionRead(9);
    }
    public void Print()// вывод данных
    {
        System.out.println("Марка двигателя: " + name);
        System.out.println("Мощность двигателя: " + power);
        System.out.println("Пробег двигателя: " + probeg);
        System.out.println("Ресурс двигателя: " + resurs);
        System.out.println("Вес двигателя: " + weight);
    }
};

class cars// класс авто
{
    private String name=new String();// марка авто
    private String color=new String();// цвет авто
    private int year;// год выпуска
    private double price;// цена
    private engine dvs;// двигатель
    public cars(String name, String color, int yr, double pr, engine dvs)// конструктор со всеми параметрами
    {
        this.name=name;
        this.color=color;
        this.year = yr;
        this.price = pr;
        this.dvs = dvs;//установка двигателя
    }
    public cars(engine dvs)// конструктор с одним параметром
    {
        this.name="no_name";
        this.color="no_color";
        this.year = 2020;
        this.price = 10000;
        this.dvs=dvs;
    }
    public cars()// конструктор без параметров
    {
        this.dvs = new engine();
        name="no_name";
        color="no_color";
        year = 2000;
        price = 0;
    }
    // сеттеры и геттеры
    public void SetName(String name)
    {
        this.name=name;
    }
    public void SetYear(int year)
    {
        this.year = year;
    }
    public void SetPrice(double price)
    {
        this.price = price;
    }
    public String GetName()
    {
        return name;
    }
    public String GetColor()
    {
        return color;
    }
    public int GetYear()
    {
        return year;
    }
    public double GetPrice()
    {
        return price;
    }
    public void PutCars() throws NumberFormatException, MyExceptionRead // выброс двух исключений в фунцкию Main
    {
        Scanner read = new Scanner(System.in);
        System.out.println("Введите марку машины: ");
        name=read.nextLine();
        if(name.trim().length()==0) throw new MyExceptionRead(1);
        System.out.println("Введите цвет машины: ");
        color=read.nextLine();
        if(color.trim().length()==0) throw new MyExceptionRead(2);
        System.out.println("Введите год выпуска машины: ");
        year=Integer.parseInt(read.nextLine());
        if(year<2000||year>2020) throw new MyExceptionRead(3);
        System.out.println("Введите цену машины: ");
        price=Double.parseDouble(read.nextLine());
        if(price<1||price>1000000) throw new MyExceptionRead(4);
        dvs.Read();
    }
    public void OutputCars()// функция вывода данных
    {
        System.out.println("Марка машины: " + name);
        System.out.println("Цвет машины: " + color);
        System.out.println("Год выпуска машины: " + year);
        System.out.println("Цена: " + price);
        dvs.Print();
    }
    public int Drive(int km) throws MyExceptionOther// тест-драйв
    {
        int probeg;
        if(km<0||km>100) throw new MyExceptionOther(1);
        probeg=dvs.GetProbeg()+km;
        dvs.SetProbeg(probeg);
        return probeg;
    }
    public void Modern(double NewWeight, int NewPower, int NewResurs) throws  MyExceptionOther// модернизация
    {if(NewWeight<0||NewWeight>1500||
            NewPower<0||NewPower>1500||NewResurs<10||NewResurs>1000000) throw new MyExceptionOther(2);
        dvs.SetWeight(NewWeight);
        dvs.SetPower(NewPower);
        dvs.SetResurs(NewResurs);
        dvs.Remont();
    }
};