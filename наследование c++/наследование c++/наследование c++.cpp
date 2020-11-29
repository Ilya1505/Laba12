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
	int power;// �������� (�.�.)
	string name;// ����� ���������
	double weight;// ���
	int probeg;// ������
	int resurs;// ������ ���������
public:
	engine &operator=(const engine &other)// ���������� ���������� =
	{
		this->power = other.power;
		this->name = other.name;
		this->weight = other.weight;
		this->probeg = other.probeg;
		this->resurs = other.resurs;
		return *this;
	}
	engine(string init_name, double weight, int power, int probeg, int resurs)// ����������� � �����������
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
	engine()// ����������� ��� ����������
	{
		name = "No_Name";
		weight = 10;
		power = 100;
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
		cin >> power;
		if (power <10 || power>1500) throw exception("������� ������������ �������� ���������!!!");
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
		cout << "�������� ���������: " << power << endl;
		cout << "������ ���������: " << probeg << endl;
		cout << "������ ���������: " << resurs << endl;
		cout << "����� ���������: ";
		printf("%.4lf\n", weight);
	}
	~engine()// ����������
	{

	}
};
class technika// ������������ ����� ���� �������
{
protected:
	int year;// ��� �������
	string name;// ����� �������
	string color;// ���� �������
	double price;// ����
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
	technika(int year, string name, string color, double price, int count)// ����������� � �����������
	{
		this->name = name;
		this->color = color;
		this->year = year;
		this->price = price;
		this->count = count;
	}
	technika()// ����������� ��� ����������
	{
		name = "No_Name";
		color = "No_Color";
		year = 2020;
		price = 1000;
		count = 0;
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
	void PrintT()// �������� ������ ������
	{
		cout << endl << "�����: " << name << endl;
		cout << "����: " << color << endl;
		cout << "��� �������: " << year << endl;
		cout << "����: ";
		printf("%.4lf\n", price);
		cout<< "����������: " << count << endl;
	}
	void ReadT()// ������� ����� ������
	{
		fflush(stdin);
		cout << "�����: ";
		getline(cin, name);
		if (name == "") throw exception("������� ������ ������ �����!!!");
		fflush(stdin);
		cout << "����: ";
		getline(cin, color);
		if (color == "") throw exception("������� ������ ������ �����!!!");
		cout << "��� �������: ";
		cin >> year;
		if (year<2000 || year>2020) throw exception("������ ������������ ��� �������!!!");
		cout << "����: ";
		cin >> price;
		if (price <= 0) throw exception("������� ������������ ����!!!");
		cout << "����������: ";
		cin >> count;
		if (count <= 0) throw exception("������� ������������ ����������!!!");
	}
	int Sell()
	{
		count--;
		cout << "������� �������!" << endl;
		cout << "������� ����������: " << count << endl;
	}
};

class cars:public technika// ����������� ����� "������" �� ������ "�������"
{
private:
	engine dvs;// ���������
	double timeToHundred;// ����� ������� �� �����

public:
	cars()
	{
		timeToHundred = 0;
	}
	cars(engine &dvs, double time, int year, string name, string color, double price, int count) :technika(year, 
		name, color, price, count)
	{
		this->dvs = dvs;//��������� ���������
		this->timeToHundred = time;
	}
	void Read()
	{
		cout << "������:" << endl;
		ReadT();
		cout << "����� ������� �� �����: ";
		cin >> timeToHundred;
		if (timeToHundred<0 || timeToHundred>100000) throw exception("������� ������������ �����!!!");
		dvs.Read();
	}
	void Print()
	{
		cout << "������:" << endl;
		PrintT();
		cout << "����� ������� �� �����: " << timeToHundred << " ������" << endl;
		dvs.Print();
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
	void Drive(cars *avto, int km);
};


void cars::Drive(cars *avto, int km)// ������� �������� ����� ���������
{
	if (km<1) throw MyException("������, ������������ ���������� ����-������!", 0);
	if (km>100)throw MyException("������, ������������ ���������� ����-������!", 1);
	int ProbegAfterDrive;
	ProbegAfterDrive = avto->dvs.GetProbeg() + km;
	avto->dvs.SetProbeg(ProbegAfterDrive);
}

class plane:public technika// ����������� ����� "�������" �� ������ "�������"
{
private:
	double MaxLength;// ������������ ������ ������ (� ������)
	double HourFly;// ����� � �����
public:
	plane()
	{
		MaxLength = 10000;
		HourFly = 0;
	}
	plane(double maxlength, double hourfly, int year, string name, string color, double price, int count) :technika(year,
		name, color, price, count)
	{
		MaxLength = maxlength;
		HourFly = hourfly;
	}
	void Read()
	{
		cout << "�������:" << endl;
		ReadT();
		cout << "������������ ������ ������: ";
		cin >> MaxLength;
		cout << "����� ������ (� �����): ";
		cin >> HourFly;
	}
	void Print()
	{
		cout << "�������:" << endl;
		PrintT();
		cout << "������������ ������ ������: " << MaxLength << endl;
		cout << "����� ������: " << HourFly << "�����(�)" << endl;
	}
	double Fly(double hour)// ������� ������ �� ������������ ���������� �����
	{
		if (hour < 0) throw exception("������������ ����������������� ������!");
		HourFly += hour;
		return HourFly;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);// ����������� �������������� �����/������
	SetConsoleOutputCP(1251);
	//����� ������:
	engine dvs("��-01", 10, 100, 0, 400);
	cars avto(dvs, 5, 2020, "No_Name", "No_Color", 1000, 8);
	avto.Print();
	bool f;
	do{
		f = false;
		try{ avto.Read(); }
		catch (exception &ex)
		{
			cout << "������ �����: " << ex.what() << endl;
			cout << "��������� ������� �����!" << endl;
			f = true;
		}
	} while (f);
	printf("\n������ ����� �����:");
	avto.Print();
	try{ avto.Drive(&avto, 10); }
	catch (MyException &ex)
	{
		cout << ex.what() << endl;
		cout << "��� ������: " << ex.Code() << endl;
		cout << "���������� ������ ���������!";
		getch();
		exit(1);
	}
	printf("\n����� ����-������:");
	avto.Print();
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
	avto.Print();
	avto.Sell();
	//����� �������
	getch();
	return 0;
}

