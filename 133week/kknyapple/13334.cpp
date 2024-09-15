#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, h, o, d;
vector <pair<int, int>> v;
int ans, cnt;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h >> o;
        if(h < o) v.push_back({ o,h });
        else v.push_back({ h,o });
        
    }
    sort(v.begin(), v.end());
    cin >> d;

    int st, en = 0;
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto p : v) {
        st = p.first - d;
        en = p.first;

        if (p.second >= st) {
            cnt++;
            pq.push({ p.second, p.first });
        }

        while (!pq.empty()) {
            if (pq.top().first < st) {
                pq.pop();
                cnt--;
            }
            else break;
        }

        ans = max(ans, cnt);
    }

    cout << ans << "\n";

    return 0;
}
