// наследование c++.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <Conio.h>
#include<Windows.h>
#include <iostream>
#include <string>

using namespace std;

class MyException : public exception// класс наследник exception
{
private:
	int CodeError;// код ошибки
public:
	MyException(char *msg, int CodeError) :exception(msg)
	{
		this->CodeError = CodeError;
	}
	int Code()
	{
		return CodeError;
	}
};
class engine// двигатель
{
private:
	int power;// мощность (л.с.)
	string name;// марка двигателя
	double weight;// вес
	int probeg;// пробег
	int resurs;// ресурс двигателя
public:
	engine &operator=(const engine &other)// перегрузка опрератора =
	{
		this->power = other.power;
		this->name = other.name;
		this->weight = other.weight;
		this->probeg = other.probeg;
		this->resurs = other.resurs;
		return *this;
	}
	engine(string init_name, double weight, int power, int probeg, int resurs)// конструктор с параметрами
	{
		this->name = init_name;
		this->weight = weight;
		this->power = power;
		this->probeg = probeg;
		this->resurs = resurs;
	}
	engine(string name)
	{
		this->name = name;
		this->weight = 50;
		this->power = 100;
		this->probeg = 0;
		this->resurs = 100;
	}
	engine()// конструктор без параметров
	{
		name = "No_Name";
		weight = 10;
		power = 100;
		probeg = 0;
		resurs = 300;
	}

	// сеттеры и геттеры
	void SetName(string name)
	{
		this->name = name;
	}
	void SetWeight(double weight)
	{
		this->weight = weight;
	}
	void SetPower(int power)
	{
		this->power = power;
	}
	void SetProbeg(int probeg)
	{
		this->probeg = probeg;
	}
	void SetResurs(int resurs)
	{
		this->resurs = resurs;
	}
	string GetName()
	{
		return name;
	}
	double GetwWight()
	{
		return weight;
	}
	int GetPower()
	{
		return power;
	}
	int GetProbeg()
	{
		return probeg;
	}
	int GetResurs()
	{
		return resurs;
	}
	void Remont()// ремонт двигателя
	{
		probeg = 0;
	}
	void Read()// ввод данных
	{
		fflush(stdin);
		cout << endl << "Марка двигателя: ";
		getline(cin, name);
		if (name == "") throw exception("Введена пустая строка марки двигателя!!!");
		cout << "Вес двигателя: ";
		cin >> weight;
		if (weight <10 || weight>5000) throw exception("Введен неккоректный вес двигателя!!!");
		cout << "Мощность двигателя: ";
		cin >> power;
		if (power <10 || power>1500) throw exception("Введена неккоректная мощность двигателя!!!");
		cout << "Пробег двигателя: ";
		cin >> probeg;
		if (probeg <0 || probeg>1000000) throw exception("Введен неккоректный пробег!!!");
		cout << "Ресурс двигателя: ";
		cin >> resurs;
		if (resurs <100 || resurs>5000000) throw exception("Введен неккоректный ресурс двигателя!!!");
	}
	void Print()// вывод данных
	{
		cout << "Марка двигателя: " << name << endl;
		cout << "Мощность двигателя: " << power << endl;
		cout << "Пробег двигателя: " << probeg << endl;
		cout << "Ресурс двигателя: " << resurs << endl;
		cout << "Масса двигателя: ";
		printf("%.4lf\n", weight);
	}
	~engine()// деструктор
	{

	}
};
class technika// родительский класс всей техники
{
protected:
	int year;// год выпуска
	string name;// марка техники
	string color;// цвет техники
	double price;// цена
	int count;
public:
	technika(const technika &other)
	{
		this->year = other.year;
		this->name = other.name;
		this->color = other.color;
		this->price = other.price;
		this->count = other.count;

	}
	technika(int year, string name, string color, double price, int count)// конструктор с параметрами
	{
		this->name = name;
		this->color = color;
		this->year = year;
		this->price = price;
		this->count = count;
	}
	technika()// конструктор без параметров
	{
		name = "No_Name";
		color = "No_Color";
		year = 2020;
		price = 1000;
		count = 0;
	}
	// сеттеры и геттеры
	void SetName(string name)
	{
		this->name = name;
	}
	void SetColor(string color)
	{
		this->color = color;
	}
	void SetYear(int year)
	{
		this->year = year;
	}
	void SetPrice(double price)
	{
		this->price = price;
	}
	void SetCount(int count)
	{
		this->count = count;
	}
	string GetName()
	{
		return name;
	}
	string GetColor()
	{
		return color;
	}
	int GetYear()
	{
		return year;
	}
	double GetPrice()
	{
		return price;
	}
	int GetCount()
	{
		return count;
	}
	void Print()// функкция вывода данных
	{
		cout << endl << "Марка: " << name << endl;
		cout << "Цвет: " << color << endl;
		cout << "Год выпуска: " << year << endl;
		cout << "Цена: ";
		printf("%.4lf\n", price);
		cout<< "Количество: " << count << endl;
	}
	void Read()// функция ввода данных
	{
		fflush(stdin);
		cout << "Марка: ";
		getline(cin, name);
		if (name == "") throw exception("Введена пустая строка марки!!!");
		fflush(stdin);
		cout << "Цвет: ";
		getline(cin, color);
		if (color == "") throw exception("Введена пустая строка цвета!!!");
		cout << "Год выпуска: ";
		cin >> year;
		if (year<2000 || year>2020) throw exception("Введен неккоректный год выпуска!!!");
		cout << "Цена: ";
		cin >> price;
		if (price <= 0) throw exception("Введена неккоректная цена!!!");
		cout << "Количесвто: ";
		cin >> count;
		if (count <= 0) throw exception("Введено неккоректное количество!!!");
	}
	int Sell()
	{
		count--;
		cout << "Техника продана!" << endl;
		cout << "текущее количество: " << count << endl;
	}
};

class cars:public technika// производный класс "машины" от класса "техника"
{
private:
	engine dvs;// двигатель
	double timeToHundred;// время разгона до сотни

public:
	cars()
	{
		timeToHundred = 0;
	}
	cars(engine &dvs, double time, int year, string name, string color, double price, int count) :technika(year, 
		name, color, price, count)
	{
		this->dvs = dvs;//установка двигателя
		this->timeToHundred = time;
	}
	void SetTime(double time)
	{
		this->timeToHundred = time;
	}
	double GetTime()
	{
		return timeToHundred;
	}
	void Read()
	{
		cout << "машина:" << endl;
		technika::Read();
		cout << "время разгона до сотни: ";
		cin >> timeToHundred;
		if (timeToHundred<0 || timeToHundred>100000) throw exception("Введено неккоректное время!!!");
		dvs.Read();
	}
	void Print()
	{
		cout << "машина:" << endl;
		technika::Print();
		cout << "Время разгона до сотни: " << timeToHundred << " секунд" << endl;
		dvs.Print();
	}
	void Modern(double NewWeight, int NewPower, int NewResurs)// модернизация
	{
		if (NewWeight<10 || NewWeight>500) throw MyException("Ошибка, некорректные данные модернизации!", 3);
		if (NewPower<50 || NewPower>1500) throw MyException("Ошибка, некорректное данные модернизации!", 4);
		if (NewResurs<500 || NewResurs>500000) throw MyException("Ошибка, некорректное данные модернизации!", 5);
		dvs.SetWeight(NewWeight);
		dvs.SetPower(NewPower);
		dvs.SetResurs(NewResurs);
		dvs.Remont();
	}
	int Sell(int count)// перегрузка метода базового класса
	{
		if (this->count < count) throw exception("неккоректное количество продаваемых машин!");
		this->count -= count;
		cout << "Техника продана!" << endl;
		cout << "текущее количество: " << this->count << endl;
	}
	int Drive(cars *avto, int km);
};


int cars::Drive(cars *avto, int km)// возврат значений через указатель
{
	if (km<1) throw MyException("Ошибка, некорректное расстояние тест-драйва!", 0);
	if (km>100)throw MyException("Ошибка, некорректное расстояние тест-драйва!", 1);
	int ProbegAfterDrive;
	ProbegAfterDrive = avto->dvs.GetProbeg() + km;
	avto->dvs.SetProbeg(ProbegAfterDrive);
	return ProbegAfterDrive;
}

class plane:public technika// производный класс "самолет" от класса "техника"
{
private:
	double MaxHeight;// максимальная высота полета (в метрах)
	double HourFly;// налет в часах
public:
	plane()
	{
		MaxHeight = 10000;
		HourFly = 0;
	}
	plane(double maxheight, double hourfly, int year, string name, string color, double price, int count) :technika(year,
		name, color, price, count)
	{
		MaxHeight = maxheight;
		HourFly = hourfly;
	}
	void SetHeight(double height)
	{
		this->MaxHeight = height;
	}
	void SetHourFly(double hour)
	{
		this->HourFly = hour;
	}
	double GetHeight()
	{
		return MaxHeight;
	}
	double GetHour()
	{
		return HourFly;
	}
	void Read()
	{
		cout << "самолет:" << endl;
		technika::Read();
		cout << "максимальная высота полета: ";
		cin >> MaxHeight;
		cout << "время налета (в часах): ";
		cin >> HourFly;
	}
	void Print()
	{
		cout << "самолет:" << endl;
		technika::Print();
		cout << "максимальная высота полета: " << MaxHeight << endl;
		cout << "время налета: " << HourFly << "часов(а)" << endl;
	}
	double Fly(double hour)// функция полета на определенное количество часов
	{
		if (hour < 0) throw exception("неккоректная продолжительность полета!");
		HourFly += hour;
		return HourFly;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);// подключение русскоязычного ввода/вывода
	SetConsoleOutputCP(1251);
	//класс машина:
	engine dvs("св-01", 10, 100, 0, 400);
	cars avto(dvs, 5, 2020, "No_Name", "No_Color", 1000, 8);
	avto.Print();
	bool f;
	do{
		f = false;
		try{ avto.Read(); }
		catch (exception &ex)
		{
			cout << "Ошибка ввода: " << ex.what() << endl;
			cout << "Повторите попытку ввода!" << endl;
			f = true;
		}
	} while (f);
	printf("\nДанные после ввода:");
	avto.Print();
	int probeg=0;
	try{ probeg = avto.Drive(&avto, 10); }
	catch (MyException &ex)
	{
		cout << ex.what() << endl;
		cout << "Код ошибки: " << ex.Code() << endl;
		cout << "завершение работы программы!";
		getch();
		exit(1);
	}
	printf("\nПробег после тест-драйва: ");
	cout << probeg << endl;
	try{ avto.Modern(100, 200, 500); }
	catch (MyException &ex)
	{
		cout << ex.what() << endl;
		cout << "Код ошибки: " << ex.Code() << endl;
		cout << "завершение работы программы!";
		getch();
		exit(1);
	}
	printf("\nПосле модернизации:");
	avto.Print();
	avto.technika::Sell();// вызов перегруженного метода базового класса
	try{ avto.Sell(5); }
	catch (exception &ex)
	{
		cout << ex.what() << endl;
		cout << "завершение работы программы!";
		getch();
		exit(1);
	}
	//класс самолет
	plane pl(20000, 0, 2020, "No_Name", "No_Color", 150000, 5);
	pl.Print();
	do{
		f = false;
		try{ pl.Read(); }
		catch (exception &ex)
		{
			cout << "Ошибка ввода: " << ex.what() << endl;
			cout << "Повторите попытку ввода!" << endl;
			f = true;
		}
	} while (f);
	printf("\nДанные после ввода:");
	pl.Print();
	try{  pl.Fly(1); }
	catch (exception &ex)
	{
		cout << ex.what() << endl;
		cout << "завершение работы программы!";
		getch();
		exit(1);
	}
	cout << "Налет (в часах) после полета: " << pl.GetHour() << endl;
	pl.Sell();
	getch();
	return 0;
}

