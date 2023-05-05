#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
const int maxi = 1000001;
ll cost[maxi];//비용
vector<ll> num;

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//max
inline int max(int x, int y) {
    return x > y ? x : y;
}

//입력
void input() {
    memset(cost, 0, sizeof(cost));
    cin >> n;
    for (int i = 0; i < n; i++) cin >> cost[i];
}

//판매
void Sell() {
    int sell = cost[n - 1];//파는 가격
    ll total = 0;//총 비용
    for (int i = n-2; i >=0; i--) {
        if (cost[i] < sell) total += (sell - cost[i]);//팔기
        else sell = cost[i];//사기
    }
    cout << total<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        input();//입력
        Sell();//판매
    }
    return 0;
}
