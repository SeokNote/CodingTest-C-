#include <stdio.h>
#include <iostream>
int num[9];
int visited[9];

void solution(int _Start, int _End) {
    if (_Start == _End) {
        for (int i = 0; i < _End; i++) {
            std::cout << num[i] << " ";
        }
        std::cout << '\n';
        return;
    }

    for (int i = 0; i < _End; i++) {
        if (visited[i] != true) {
            visited[i] = true;
            num[_Start] = i + 1;
            solution(_Start + 1,_End);
            visited[i] = false;
        }
    }
   
}

int main() {
    int N;
    std::cin >> N;
    solution(0,N);
}