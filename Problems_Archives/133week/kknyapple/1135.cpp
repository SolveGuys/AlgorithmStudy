#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, num;
vector <int> v[52];

int go(int cur) {
    vector<int> times;
    for (auto p : v[cur]) {
        times.push_back(go(p));
    }

    sort(times.rbegin(), times.rend());

    int max_time = 0;

    for (int i = 0; i < times.size(); i++) {
        max_time = max(max_time, times[i] + i + 1);
    }

    return max_time;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num == -1) continue;
        v[num].push_back(i);
    }

    cout << go(0) << "\n";



    return 0;
}
