using namespace std;
long long gcd(long long a, long long b) // a > b
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
long long solution(int w, int h) {

    long long gcdvalue = 1;
    if (w < h)
    {
        gcdvalue = gcd(h, w);
    }
    else
    {
        gcdvalue = gcd(w, h);
    }
    long long gcdw = w / gcdvalue;
    long long gcdh = h / gcdvalue;
    long long nullrect = gcdw + gcdh - 1;
    long long ratio = w / gcdw;
    long long size = (long long)h * (long long)w;
    long long answer = size - ratio * nullrect;
    return answer;
}