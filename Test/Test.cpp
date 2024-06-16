#include <iostream>
#include <crtdbg.h>
#include <typeinfo>
using namespace std;

class Parent
{
public:
	Parent()
	{
		cout << "�θ� ����" << "\n";
		a = new int;
	}

	~Parent()
	{
		delete a;
	}
protected:
	int* a = nullptr;
};

class Child : public Parent
{
public:
	Child()
	{
		cout << "�ڽ� ����" << "\n";
		b = new int;
	}
	~Child()
	{
		cout << "�ڽ� ����" << "\n";
		delete b;
	}
	int* b = nullptr;


};

int main()
{

	Parent* ParentPtr = new Child();
	std::cout << typeid(ParentPtr).name() << "\n";
	std::cout << typeid(*ParentPtr).name() << "\n";
	delete ParentPtr;

	return 0;
}