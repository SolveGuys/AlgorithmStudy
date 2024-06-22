#include <bits/stdc++.h>
using namespace std;
int n, a, b, len, lis[504];
vector<pair<int, int>> v;

void solution() {
    int DP[504];
    int max_V = 0;
   
    for (int i = 0; i < n; i++) {
        DP[i] = 1;
        for (int j = 1; j < i; j++) {
            if (v[i].second > v[j].second)
                DP[i] = max(DP[i], DP[j] + 1);
        }
        max_V = max(max_V, DP[i]);
    }

}

// 증가하는 가장 긴 부분 수열
// first 기준 정렬, second로 가장 긴 부분 수열 찾기. 

// 1. DP => O(n^2)
// 2, LIS lower_bound 쓰는 방법.  => O(nlogn)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({ a, b });
    }
    
    sort(v.begin(), v.end());
    
    for (int i = 0; i < v.size(); i++) {
        auto it = lower_bound(lis, lis + len, v[i].second);
        if (*it == 0) len++;
        *it = v[i].second;
        for (auto iter = lis; iter != lis + len; iter++) {
            cout << *iter << ' ';
        }
        cout << '\n';
    }
    cout << n - len << "\n";
    return 0;
}
