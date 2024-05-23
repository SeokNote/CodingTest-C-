#include <iostream>

int main()
{
    //N채의 집이 있는 마을.
    //우물의 좌표 x,y 
    //30만 
    //1억
    int N;
    double xsum = 0;
    double ysum = 0;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        double x, y;
        std::cin >> x >> y;
        xsum += x;
        ysum += y;
    }
    double answerx = xsum / N;
    double answery = ysum / N;
    std::cout << std::fixed;
    std::cout.precision(4);
    std::cout << answerx << " " << answery;
    return 0;
}