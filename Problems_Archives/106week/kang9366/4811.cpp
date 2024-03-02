#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int N;
    ll dp[31][31];

    for(int i = 1; i <= 30; i++) dp[0][i] = 1;

    for(int w = 1; w <= 30; w++) {
        for(int h = 0; h <= 30; h++) {
            if(h==0) dp[w][h] = dp[w-1][1];
            else dp[w][h] = dp[w][h-1] + dp[w-1][h+1];
        }
    }

    while(true) {
        cin >> N;
        if(N==0) return 0;
        cout << dp[N][0] << endl;
    }
}
