#include <iostream>
//
//class Parent
//{
//public:
//    virtual void OutPut()
//    {
//        std::cout << "부모 클래스 ";
//    };
//    int a;
//};
//
//
//class Child : public Parent
//{
//private:
//    int b;
//public:
//    const int OutPut()
//    {
//        b = 10;
//    }
//
//};
//
//struct Test
//{
//    char* pC = nullptr;
//    int A = 0;
//    char b = 0;
//    char C = 0;
//
//};
//
//void func(int _Value)
//{
//
//}


int main()
{
    //Parent* P = new Parent();
    //Child P;
    //Test T;
    //std::cout << sizeof(T);
    int num1 = 1;



    int&& num2(10);

    num2 -= 1;

    int& num3 = num1;

    num1 =- 1;
    // num2 1
    // num3 0
    
    return 0;
}
//OutPut : 20