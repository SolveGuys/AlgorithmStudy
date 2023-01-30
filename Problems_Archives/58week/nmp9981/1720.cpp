#include <iostream>
using namespace std;

int n;
const int maxi = 31;
int tile[maxi];//타일을 놓는 경우의 수

//경우의 수 구하기
void Case(int x) {
    //전체 경우의 수
    tile[1] = 1; tile[2] = 3;
    for (int i = 3; i < maxi; i++) tile[i] = tile[i - 1] + 2 * tile[i - 2];

    if (x < 3) tile[x] = tile[x];
    else if (x % 2 == 1) tile[x] = (tile[x] + tile[x / 2]) / 2;//홀수
    else if (x % 2 == 0) tile[x] = (tile[x] + tile[x/2]+2 * tile[(x - 2) / 2]) / 2;//짝수

    cout << tile[x];//출력
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);
  
    int n; cin >> n;//입력
    Case(n);//경우의 수 구하기
    return 0;
}
