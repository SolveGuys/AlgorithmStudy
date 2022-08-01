#include <iostream>

using namespace std;

void hanoi(int num, int start, int to, int end)
{
    if(num==1)
        cout << start << " " << end << "\n"; // 원판이 1개일 경우, 1번 장대에서 3번 장대로 이동
    else // 원판이 1개보다 많을 경우
    {
        // (n-1)개의 원판을 2번 장대(to)로 옮겨야 하므로 1번 장대에서 시작하여 3번 장대를 거쳐 2번 장대로 이동
        hanoi(num-1, start, end, to);
        cout << start << " " << end << "\n"; // 마지막 원판 3번 장대로 이동
        // (n-1)개의 원판들이 2번 장대로 옮겨진 상태에서 최종 목적지인 3번 장대로 이동하여야 하므로 1번 장대를 거쳐 3번 장대로 이동
        hanoi(num-1, to, start, end);
    }
}

int main()
{
    int n; // 원반 갯수
    cin >> n;
    cout << (1<<n)-1 <<"\n"; // 최소 이동 횟수 2^n-1 출력
    hanoi(n, 1, 2, 3);
    return 0;
}
