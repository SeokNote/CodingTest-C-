#include <string>
#include <vector>

using namespace std;

//최대 공약수 최소 공배수 구하기
int gcd(int a, int b) // a > b
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
int main()
{
    int a = gcd(3, 9);
    return 0;
}
//if (n > m)
//{
//    if (n % m == 0)
//    {
//        answer.push_back(m);
//        answer.push_back((m * n) / m);
//    }
//    else
//    {
//        answer.push_back(n % m);
//        answer.push_back((m * n) / (n % m));
//    }
//}
//else if (n < m)
//{
//    if (m % n == 0)
//    {
//        answer.push_back(n);
//        answer.push_back((m * n) / n);
//    }
//    else
//    {
//        answer.push_back(m % n);
//        answer.push_back((m * n) / (m % n));
//    }
//}
//else if (n == m)
//{
//    answer.push_back(n);
//    answer.push_back(n);
//}