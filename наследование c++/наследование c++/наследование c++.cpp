// ������������ c++.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <Conio.h>
#include<Windows.h>
#include <iostream>
#include <string>

using namespace std;

class MyException : public exception// ����� ��������� exception
{
private:
	int CodeError;// ��� ������
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
class engine// ���������
{
private:
	int *power;// �������� (�.�.)
	string name;// ����� ���������
	double weight;// ���
	int probeg;// ������
	int resurs;// ������ ���������
public:
	engine &operator=(const engine &other)// ���������� ���������� =
	{
		if (power != nullptr)// �������� �� �� ������� �������� ���������
			delete power;
		power = new int;
		*this->power = *other.power;
		this->name = other.name;
		this->weight = other.weight;
		this->probeg = other.probeg;
		this->resurs = other.resurs;
		return *this;
	}
	engine(const engine &other)// ����������� � ������ ������������
	{
		this->power = other.power;// ������ ����������� ������ ����������
		this->name = other.name;
		this->weight = other.weight;
		this->probeg = other.probeg;
		this->resurs = other.resurs;
	}
	engine(string init_name, double weight, int power, int probeg, int resurs)// ����������� � �����������
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
	engine()// ����������� ��� ����������
	{
		this->power = new int;
		name = "No_Name";
		weight = 10;
		*power = 100;
		probeg = 0;
		resurs = 300;
	}

	// ������� � �������
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
	void Remont()// ������ ���������
	{
		probeg = 0;
	}
	void Read()// ���� ������
	{
		fflush(stdin);
		cout << endl << "����� ���������: ";
		getline(cin, name);
		if (name == "") throw exception("������� ������ ������ ����� ���������!!!");
		cout << "��� ���������: ";
		cin >> weight;
		if (weight <10 || weight>5000) throw exception("������ ������������ ��� ���������!!!");
		cout << "�������� ���������: ";
		cin >> *power;
		if (*power <10 || *power>1500) throw exception("������� ������������ �������� ���������!!!");
		cout << "������ ���������: ";
		cin >> probeg;
		if (probeg <0 || probeg>1000000) throw exception("������ ������������ ������!!!");
		cout << "������ ���������: ";
		cin >> resurs;
		if (resurs <100 || resurs>5000000) throw exception("������ ������������ ������ ���������!!!");
	}
	void Print()// ����� ������
	{
		cout << "����� ���������: " << name << endl;
		cout << "�������� ���������: " << *power << endl;
		cout << "������ ���������: " << probeg << endl;
		cout << "������ ���������: " << resurs << endl;
		cout << "����� ���������: ";
		printf("%.4lf\n", weight);
	}
	~engine()// ����������
	{

	}
};
class cars// ����� ����
{
public:
	int *year;// ��� �������
	string name;// ����� ����
	string color;// ���� ����
	double price;// ����
	engine dvs;// ���������
public:
	cars(const cars &other)// ������������ � �������� ������������
	{
		this->year = new int;
		*this->year = *other.year;
		this->name = other.name;
		this->color = other.color;
		this->price = other.price;
		this->dvs = other.dvs;// ���������� ��������� ������������

	}
	cars(int year, string name, string color, double price, engine &dvs)// ����������� � �����������
	{
		this->year = new int;
		this->name = name;
		this->color = color;
		*this->year = year;
		this->price = price;
		this->dvs = dvs;//��������� ���������
	}
	cars(int price)// ����������� � ����� ����������
	{
		this->year = new int;
		this->name = "No_Name";
		this->color = "No_Color";
		*(this->year) = 2020;
		this->price = price;
	}
	cars()// ����������� ��� ����������
	{
		this->year = new int;
		name = "No_Name";
		color = "No_Color";
		*year = 2020;
		price = 1000;

	}
	// ������� � �������
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
	void OutputCars()// �������� ������ ������
	{
		cout << endl << "����� ������: " << name << endl;
		cout << "���� ������: " << color << endl;
		cout << "��� �������: " << *year << endl;
		cout << "���� ������: ";
		printf("%.4lf\n", price);
		dvs.Print();
	}
	void PutCars()// ������� ����� ������
	{
		fflush(stdin);
		cout << endl << " ���� ������" << endl;
		cout << "����� ������: ";
		getline(cin, name);
		if (name == "") throw exception("������� ������ ������ ����� ����!!!");
		fflush(stdin);
		cout << "���� ������: ";
		getline(cin, color);
		if (color == "") throw exception("������� ������ ������ ����� ����!!!");
		cout << "��� ������� ������: ";
		cin >> *year;
		if (*year<2000 || *year>2020) throw exception("������ ������������ ��� ������� ����!!!");
		cout << "����: ";
		cin >> price;
		if (price <= 0) throw exception("������� ������������ ���� ����!!!");
		dvs.Read();
	}
	void Modern(double NewWeight, int NewPower, int NewResurs)// ������������
	{
		if (NewWeight<10 || NewWeight>500) throw MyException("������, ������������ ������ ������������!", 3);
		if (NewPower<50 || NewPower>1500) throw MyException("������, ������������ ������ ������������!", 4);
		if (NewResurs<500 || NewResurs>500000) throw MyException("������, ������������ ������ ������������!", 5);
		dvs.SetWeight(NewWeight);
		dvs.SetPower(NewPower);
		dvs.SetResurs(NewResurs);
		dvs.Remont();
	}
	friend void Drive(cars *avto, int km);// ����-�����, ������������� ������� ��� ������ car
	~cars()
	{
	}
};

void Drive(cars *avto, int km)// ������� �������� ����� ���������
{
	if (km<1) throw MyException("������, ������������ ���������� ����-������!", 0);
	if (km>100)throw MyException("������, ������������ ���������� ����-������!", 1);
	int ProbegAfterDrive;
	ProbegAfterDrive = avto->dvs.GetProbeg() + km;
	avto->dvs.SetProbeg(ProbegAfterDrive);
}

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);// ����������� �������������� �����/������
	SetConsoleOutputCP(1251);
	system("color F0");
	engine dvs("��-01", 10, 100, 0, 400);
	cars avto(2020, "No_Name", "No_Color", 1000, dvs);
	cout << "������ 1:";
	avto.OutputCars();
	bool f;
	do{
		f = false;
		try{ avto.PutCars(); }
		catch (exception &ex)
		{
			cout << "������ �����: " << ex.what() << endl;
			cout << "��������� ������� �����!" << endl;
			f = true;
		}
	} while (f);
	printf("\n������ ����� �����:");
	avto.OutputCars();
	try{ Drive(&avto, 10); }
	catch (MyException &ex)
	{
		cout << ex.what() << endl;
		cout << "��� ������: " << ex.Code() << endl;
		cout << "���������� ������ ���������!";
		getch();
		exit(1);
	}
	printf("\n����� ����-������:");
	avto.OutputCars();
	try{ avto.Modern(100, 200, 500); }
	catch (MyException &ex)
	{
		cout << ex.what() << endl;
		cout << "��� ������: " << ex.Code() << endl;
		cout << "���������� ������ ���������!";
		getch();
		exit(1);
	}
	printf("\n����� ������������:");
	avto.OutputCars();
	//������ � ��������
	cars avtoArray[3] = { 1000, 2000, 3000 };
	for (int i = 0; i < 3; i++)
	{
		cout << endl << "������ " << i + 1;
		avtoArray[i].OutputCars();
	}
	for (int i = 0; i < 3; i++)
	{
		cout << endl << "������ " << i + 1;
		do{
			f = false;
			try{ avtoArray[i].PutCars(); }
			catch (exception &ex)
			{
				cout << "������ �����: " << ex.what() << endl;
				cout << "��������� ������� �����!" << endl;
				f = true;
			}
		} while (f);
	}
	printf("\n������ ����� �����:\n");
	for (int i = 0; i < 3; i++)
	{
		cout << endl << "������ " << i + 1;
		avtoArray[i].OutputCars();
	}
	for (int i = 0; i < 3; i++)
	{
		try{ Drive(&avtoArray[i], 10); }
		catch (MyException &ex)
		{
			cout << ex.what() << endl;
			cout << "��� ������: " << ex.Code() << endl;
			cout << "���������� ������ ���������!";
			getch();
			exit(1);
		}
	}
	printf("����� ����-������:\n");
	for (int i = 0; i < 3; i++)
	{
		cout << endl << "������ " << i + 1;
		avtoArray[i].OutputCars();
	}
	for (int i = 0; i < 3; i++)
	{
		try{ avtoArray[i].Modern(100, 200, 500); }
		catch (MyException &ex)
		{
			cout << ex.what() << endl;
			cout << "��� ������: " << ex.Code() << endl;
			cout << "���������� ������ ���������!";
			getch();
			exit(1);
		}
	}
	printf("����� ������������:\n");
	for (int i = 0; i < 3; i++)
	{
		cout << endl << "������ " << i + 1;
		avtoArray[i].OutputCars();
	}
	getch();
	return 0;
}

