#include <iostream>
#include <crtdbg.h>
#include <typeinfo>
using namespace std;

class Parent
{
public:
	Parent()
	{
		cout << "何葛 积己" << "\n";
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
		cout << "磊侥 积己" << "\n";
		b = new int;
	}
	~Child()
	{
		cout << "磊侥 昏力" << "\n";
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