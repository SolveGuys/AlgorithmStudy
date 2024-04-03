#include <iostream>

#define MAX 31

using namespace std;

int dp[MAX] = { 0, };

int main() {
    int N;
    cin >> N;

    dp[0] = 1;
    dp[2] = 3;

    for(int i = 4; i <= N; i+=2) {
        for(int j = 0; j < i-2; j+=2) {
            dp[i] += dp[j]*2;
        }
        dp[i] += dp[i-2] * dp[2];
    }

    cout << dp[N];
}
