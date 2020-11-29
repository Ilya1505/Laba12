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
	int *power;// мощность (л.с.)
	string name;// марка двигателя
	double weight;// вес
	int probeg;// пробег
	int resurs;// ресурс двигателя
public:
	engine &operator=(const engine &other)// перегрузка опрератора =
	{
		if (power != nullptr)// проверка на не нулевое значение указателя
			delete power;
		power = new int;
		*this->power = *other.power;
		this->name = other.name;
		this->weight = other.weight;
		this->probeg = other.probeg;
		this->resurs = other.resurs;
		return *this;
	}
	engine(const engine &other)// конструктор с мелким копированием
	{
		this->power = other.power;// мелкое копирование адреса одинаковые
		this->name = other.name;
		this->weight = other.weight;
		this->probeg = other.probeg;
		this->resurs = other.resurs;
	}
	engine(string init_name, double weight, int power, int probeg, int resurs)// конструктор с параметрами
	{
		this->power = new int;
		this->name = init_name;
		this->weight = weight;
		*this->power = power;
		this->probeg = probeg;
		this->resurs = resurs;
	}
	engine(string name)
	{
		this->power = new int;
		this->name = name;
		this->weight = 50;
		*this->power = 100;
		this->probeg = 0;
		this->resurs = 100;
	}
	engine()// конструктор без параметров
	{
		this->power = new int;
		name = "No_Name";
		weight = 10;
		*power = 100;
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
		*this->power = power;
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
		return *power;
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
		cin >> *power;
		if (*power <10 || *power>1500) throw exception("Введена неккоректная мощность двигателя!!!");
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
		cout << "Мощность двигателя: " << *power << endl;
		cout << "Пробег двигателя: " << probeg << endl;
		cout << "Ресурс двигателя: " << resurs << endl;
		cout << "Масса двигателя: ";
		printf("%.4lf\n", weight);
	}
	~engine()// деструктор
	{

	}
};
class cars// класс авто
{
public:
	int *year;// год выпуска
	string name;// марка авто
	string color;// цвет авто
	double price;// цена
	engine dvs;// двигатель
public:
	cars(const cars &other)// коннструктор с глубоким копированием
	{
		this->year = new int;
		*this->year = *other.year;
		this->name = other.name;
		this->color = other.color;
		this->price = other.price;
		this->dvs = other.dvs;// перегрузка оператора присваивания

	}
	cars(int year, string name, string color, double price, engine &dvs)// конструктор с параметрами
	{
		this->year = new int;
		this->name = name;
		this->color = color;
		*this->year = year;
		this->price = price;
		this->dvs = dvs;//установка двигателя
	}
	cars(int price)// конструктор с одним параметром
	{
		this->year = new int;
		this->name = "No_Name";
		this->color = "No_Color";
		*(this->year) = 2020;
		this->price = price;
	}
	cars()// конструктор без параметров
	{
		this->year = new int;
		name = "No_Name";
		color = "No_Color";
		*year = 2020;
		price = 1000;

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
		*this->year = year;
	}
	void SetPrice(double price)
	{
		this->price = price;
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
		return *year;
	}
	double GetPrice()
	{
		return price;
	}
	void OutputCars()// функкция вывода данных
	{
		cout << endl << "Марка машины: " << name << endl;
		cout << "Цвет машины: " << color << endl;
		cout << "Год выпуска: " << *year << endl;
		cout << "Цена машины: ";
		printf("%.4lf\n", price);
		dvs.Print();
	}
	void PutCars()// функция ввода данных
	{
		fflush(stdin);
		cout << endl << " Ввод данных" << endl;
		cout << "Марка машины: ";
		getline(cin, name);
		if (name == "") throw exception("Введена пустая строка марки авто!!!");
		fflush(stdin);
		cout << "Цвет машины: ";
		getline(cin, color);
		if (color == "") throw exception("Введена пустая строка цвета авто!!!");
		cout << "Год выпуска машины: ";
		cin >> *year;
		if (*year<2000 || *year>2020) throw exception("Введен неккоректный год выпуска авто!!!");
		cout << "Цена: ";
		cin >> price;
		if (price <= 0) throw exception("Введена неккоректная цена авто!!!");
		dvs.Read();
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
	friend void Drive(cars *avto, int km);// тест-драйв, дружественная функция для класса car
	~cars()
	{
	}
};

void Drive(cars *avto, int km)// возврат значений через указатель
{
	if (km<1) throw MyException("Ошибка, некорректное расстояние тест-драйва!", 0);
	if (km>100)throw MyException("Ошибка, некорректное расстояние тест-драйва!", 1);
	int ProbegAfterDrive;
	ProbegAfterDrive = avto->dvs.GetProbeg() + km;
	avto->dvs.SetProbeg(ProbegAfterDrive);
}

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);// подключение русскоязычного ввода/вывода
	SetConsoleOutputCP(1251);
	system("color F0");
	engine dvs("св-01", 10, 100, 0, 400);
	cars avto(2020, "No_Name", "No_Color", 1000, dvs);
	cout << "машина 1:";
	avto.OutputCars();
	bool f;
	do{
		f = false;
		try{ avto.PutCars(); }
		catch (exception &ex)
		{
			cout << "Ошибка ввода: " << ex.what() << endl;
			cout << "Повторите попытку ввода!" << endl;
			f = true;
		}
	} while (f);
	printf("\nДанные после ввода:");
	avto.OutputCars();
	try{ Drive(&avto, 10); }
	catch (MyException &ex)
	{
		cout << ex.what() << endl;
		cout << "Код ошибки: " << ex.Code() << endl;
		cout << "завершение работы программы!";
		getch();
		exit(1);
	}
	printf("\nПосле тест-драйва:");
	avto.OutputCars();
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
	avto.OutputCars();
	//Работа с массивом
	cars avtoArray[3] = { 1000, 2000, 3000 };
	for (int i = 0; i < 3; i++)
	{
		cout << endl << "Машина " << i + 1;
		avtoArray[i].OutputCars();
	}
	for (int i = 0; i < 3; i++)
	{
		cout << endl << "Машина " << i + 1;
		do{
			f = false;
			try{ avtoArray[i].PutCars(); }
			catch (exception &ex)
			{
				cout << "Ошибка ввода: " << ex.what() << endl;
				cout << "Повторите попытку ввода!" << endl;
				f = true;
			}
		} while (f);
	}
	printf("\nДанные после ввода:\n");
	for (int i = 0; i < 3; i++)
	{
		cout << endl << "Машина " << i + 1;
		avtoArray[i].OutputCars();
	}
	for (int i = 0; i < 3; i++)
	{
		try{ Drive(&avtoArray[i], 10); }
		catch (MyException &ex)
		{
			cout << ex.what() << endl;
			cout << "Код ошибки: " << ex.Code() << endl;
			cout << "завершение работы программы!";
			getch();
			exit(1);
		}
	}
	printf("После тест-драйва:\n");
	for (int i = 0; i < 3; i++)
	{
		cout << endl << "Машина " << i + 1;
		avtoArray[i].OutputCars();
	}
	for (int i = 0; i < 3; i++)
	{
		try{ avtoArray[i].Modern(100, 200, 500); }
		catch (MyException &ex)
		{
			cout << ex.what() << endl;
			cout << "Код ошибки: " << ex.Code() << endl;
			cout << "завершение работы программы!";
			getch();
			exit(1);
		}
	}
	printf("После модернизации:\n");
	for (int i = 0; i < 3; i++)
	{
		cout << endl << "Машина " << i + 1;
		avtoArray[i].OutputCars();
	}
	getch();
	return 0;
}

