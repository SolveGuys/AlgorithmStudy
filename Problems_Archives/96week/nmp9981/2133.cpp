#include <iostream>
using namespace std;

int n;
const int maxi = 31;
int dp[maxi];//경우의 수

//타일 개수
void Tile() {
    dp[0] = 1;
    dp[2] = 3;
    for (int i = 4; i < maxi; i += 2) {
        dp[i] += 3 * dp[i - 2];
        for (int j = i - 4; j >= 0; j -= 2) dp[i] += 2 * dp[j];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Tile();//타일 채우기
    cin >> n;
    if (n % 2 == 1) cout << 0;//홀수칸은 못채움
    else cout << dp[n];
    return 0;
}
