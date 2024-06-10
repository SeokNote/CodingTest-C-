#include <iostream>
#include <crtdbg.h>

using namespace std;

class Parent
{
public:
	Parent()
	{
		cout << "何葛 积己" << "\n";
		Fuc();
		a = new int;
	}

	virtual ~Parent()
	{
		delete a;
	}
	virtual void Fuc()
	{

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
	~Child() override
	{
		cout << "磊侥 昏力" << "\n";
		delete b;
	}
	int* b = nullptr;


};

int main()
{
	{
		//int* a = new int;
		Parent* ParentPtr = new Parent();
		//delete ParentPtr;
		//delete a;
	}
	 _CrtDumpMemoryLeaks();
	//delete ParentPtr;



	return 0;
}