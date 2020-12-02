package com.company;
import java.text.ParseException;
import java.util.Scanner;
public class Main {
    public static void main(String[] args)
    {
        engine dvs = new engine("no_name", 10, 100, 0, 1000);// конструктор со всеми параметрами
        cars avto = new cars("no_name", "no_color", 2020, 1000, 10, dvs,5);// конструктор со всеми параметрами
        int probeg=0;
        System.out.println(avto);
        boolean f;
        do {
            f=false;
            try {
                avto.Read();
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
        System.out.println(avto);
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
        System.out.println(avto);
        avto.Sell();// вызов базового метода продажи авто
        avto.Sell(5);// вызов метода производного класса
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
            case 1: return "некорректный ввод марки";
            case 2: return "некорректный ввод цвета";
            case 3: return "некорректный ввод года выпуска";
            case 4: return "некорректный ввод цены";
            case 5: return "некорректный ввод марки двигателя";
            case 6: return "некорректный ввод мощности";
            case 7: return "некорректный ввод пробега";
            case 8: return "некорректный ввод ресурса двигателя";
            case 9: return "некорректный ввод веса двигателя";
            case 10:return "некорректный ввод количества";
            case 11:return "некорректный ввод времени разгона";
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
    public String toString()// вывод данных
    {
        String en;
        en="Марка двигателя: " + name+"\n"+"Мощность двигателя: " + power+"\n"+"Пробег двигателя: " + probeg+
            "\n"+"Ресурс двигателя: " + resurs+"\n"+"Вес двигателя: " + weight+"\n";
        return en;
    }
};

class technika// класс авто
{
    protected String name=new String();// марка авто
    protected String color=new String();// цвет авто
    protected int year;// год выпуска
    protected double price;// цена
    protected int count;// количество авто
    public technika(String name, String color, int yr, double pr, int co)// конструктор со всеми параметрами
    {
        this.name=name;
        this.color=color;
        this.year = yr;
        this.price = pr;
        this.count = co;
    }
    public technika()// конструктор без параметров
    {
        name="no_name";
        color="no_color";
        year = 2000;
        price = 0;
        count=0;
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
    public void SetCount(int count)
    {
        this.count = count;
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
    public int GetCount()
    {
        return count;
    }
    public void PutT() throws NumberFormatException, MyExceptionRead // выброс двух исключений в фунцкию Main
    {
        Scanner read = new Scanner(System.in);
        System.out.println("Введите марку техники: ");
        name=read.nextLine();
        if(name.trim().length()==0) throw new MyExceptionRead(1);
        System.out.println("Введите цвет: ");
        color=read.nextLine();
        if(color.trim().length()==0) throw new MyExceptionRead(2);
        System.out.println("Введите год выпуска: ");
        year=Integer.parseInt(read.nextLine());
        if(year<2000||year>2020) throw new MyExceptionRead(3);
        System.out.println("Введите цену: ");
        price=Double.parseDouble(read.nextLine());
        if(price<1||price>1000000) throw new MyExceptionRead(4);
        System.out.println("Введите количество: ");
        count=Integer.parseInt(read.nextLine());
        if(count<0) throw new MyExceptionRead(10);
    }
    public String toString()// функция вывода данных
    {   String tk;
    tk="Марка: "+name+"\n"+"Цвет: "+color+"\n"+"Год выпуска: "
            +year+"\n"+"Цена: "+price+"\n"+"Количество: "+count+"\n";
    return tk;
    }
    public int Sell()
    {
        count--;
        System.out.println("Техника продана!");
        System.out.println("текущее количество: "+count);
        return count;
    }
};
class cars extends technika
{
    private engine dvs;// двигатель
    private double timeToHundred;// время разгона до сотни

    public cars()
    {
        timeToHundred = 0;
        dvs = new engine();
    }
    public cars(String name, String color, int year, double price, int count, engine dvs, double time)
    {
        super(name, color, year, price, count);
        this.dvs = dvs;//установка двигателя
        this.timeToHundred = time;
    }
    public void SetTime(double time)
    {
        this.timeToHundred = time;
    }
    public double GetTime()
    {
        return timeToHundred;
    }
    public void Read() throws NumberFormatException, MyExceptionRead
    {
        Scanner read = new Scanner(System.in);
        System.out.println("Введите марку авто: ");
        name=read.nextLine();
        if(name.trim().length()==0) throw new MyExceptionRead(1);
        System.out.println("Введите цвет: ");
        color=read.nextLine();
        if(color.trim().length()==0) throw new MyExceptionRead(2);
        System.out.println("Введите год выпуска: ");
        year=Integer.parseInt(read.nextLine());
        if(year<2000||year>2020) throw new MyExceptionRead(3);
        System.out.println("Введите цену: ");
        price=Double.parseDouble(read.nextLine());
        if(price<1||price>1000000) throw new MyExceptionRead(4);
        System.out.println("Введите количество: ");
        count=Integer.parseInt(read.nextLine());
        if(count<0) throw new MyExceptionRead(10);
        System.out.println("Введите время разгона до сотни: ");
        timeToHundred=Double.parseDouble(read.nextLine());
        if(timeToHundred<1||timeToHundred>10000) throw new MyExceptionRead(11);
        dvs.Read();
    }
    public String toString()// функция вывода данных
    {
        String avto;
        avto="Марка: "+name+"\n"+"Цвет: "+color+"\n"+"Год выпуска: "
                +year+"\n"+"Цена: "+price+"\n"+"Количество: "+count+"\n"+"Время разгона до сотни: "+timeToHundred+"\n";
        return avto+dvs.toString();
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
    {
        if(NewWeight<0||NewWeight>1500||
            NewPower<0||NewPower>1500||NewResurs<10||NewResurs>1000000) throw new MyExceptionOther(2);
        dvs.SetWeight(NewWeight);
        dvs.SetPower(NewPower);
        dvs.SetResurs(NewResurs);
        dvs.Remont();
    }
    public int Sell(int count)// перегрузка метода базового класса
    {
        this.count -= count;
        System.out.println("Техника продана!");
        System.out.println("текущее количество: " + this.count);
        return this.count;
    }
};
class plane extends technika
{
  private double MaxHeight;// максимальная высота полета (в метрах)
  private double HourFly;// налет в часах

  public plane(String name, String color, int year, double price, int count, double maxheight, double hourfly)
  {
    super(name, color, year, price, count);
    MaxHeight = maxheight;
    HourFly = hourfly;
  }
  public plane()
  {
      MaxHeight=10000;
      HourFly=0;
  }
  public void SetHeight(double height)
  {
      this.MaxHeight = height;
  }
  public void SetHourFly(double hour)
  {
      this.HourFly = hour;
  }
  public double GetHeight()
  {
      return MaxHeight;
  }
  double GetHour()
  {
      return HourFly;
  }
  public String toString()// функция вывода данных
  {
      String plane;
      plane="Марка: "+name+"\n"+"Цвет: "+color+"\n"+"Год выпуска: "
              +year+"\n"+"Цена: "+price+"\n"+"Количество: "+count+"\n"
              +"Максимальная высота полета: "+MaxHeight+"\n"+"Время налета в часах: "+HourFly+"\n";
      return plane;
  }
  public void Read() throws NumberFormatException, MyExceptionRead
  {
      Scanner read = new Scanner(System.in);
      System.out.println("Введите марку авто: ");
      name=read.nextLine();
      if(name.trim().length()==0) throw new MyExceptionRead(1);
      System.out.println("Введите цвет: ");
      color=read.nextLine();
      if(color.trim().length()==0) throw new MyExceptionRead(2);
      System.out.println("Введите год выпуска: ");
      year=Integer.parseInt(read.nextLine());
      if(year<2000||year>2020) throw new MyExceptionRead(3);
      System.out.println("Введите цену: ");
      price=Double.parseDouble(read.nextLine());
      if(price<1||price>1000000) throw new MyExceptionRead(4);
      System.out.println("Введите количество: ");
      count=Integer.parseInt(read.nextLine());
      if(count<0) throw new MyExceptionRead(10);
      System.out.println("Введите максимальную высоту полета: ");
      MaxHeight=Double.parseDouble(read.nextLine());
      System.out.println("Введите время налета в часах: ");
      MaxHeight=Double.parseDouble(read.nextLine());
  }

  public double Fly(double hour)// функция полета на определенное количество часов
  {
      HourFly += hour;
      return HourFly;
  }
};