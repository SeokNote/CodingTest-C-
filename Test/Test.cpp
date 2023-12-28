
int main()
{
    int* test = new int;
    const int* A = test; // 주소가 가르키는 값을 바꿀수 없게함
    int* const B = test; // 주소를 못바꾸게함
    const int* const C = test; // 주소를 못바꾸게함

    *B = 1;
    A = nullptr;
    *A = 2;

    C = nullptr;
    *C = 1;
    return 0;
}