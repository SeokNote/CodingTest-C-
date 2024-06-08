#include <iostream>
#include <vector>

class A
{
public : 
    void operator =(A& a)
    {
        std::cout << "&" << std::endl;
    }


    void operator =(A&& a)
    {
        std::cout << "&&" << std::endl;
    }


    A()
    {
        std::cout << "C" << std::endl;
    }

    A(A& a)
    {
        std::cout << "&" << std::endl;
    }

    A(A&& a)
    {
        std::cout << "&&" << std::endl;
    }

    ~A()
    {
        std::cout << "D" << std::endl;
    }
};

A Func1(A a)
{
    return a;
}

A Func2(A& a)
{
    return a;
}

A Test()
{
    A Return;
    return Return;
}

int main()
{
    //A Return;
    //Return = Test();

    A a; // C
    A b(a); // &
    A c;
    c = Func1(b);
    
    A d(
        Func2(c)
    );
    
    return 0;
}