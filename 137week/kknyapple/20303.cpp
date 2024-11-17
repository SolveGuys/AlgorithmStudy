#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;
// using ll = long long;
// const int INF = 0x7f7f7f7f;
const int INF = 0x3f3f3f3f;

int n, m, k;
vector<int>adj[30004];
pair<int, int> v[30004];
int candy[30004];
bool visited[30004];
int a, b;
// int d[30004][3004];
int d[30004];
int graph_num = 1;

pair<int, int> go(int cur) {
    int sum = candy[cur];
    int cnt = 1;
    visited[cur] = true;

    for (int nxt : adj[cur]) {
        if (visited[nxt]) continue;
        auto result = go(nxt);
        sum+= result.second;
        cnt += result.first;
    }

    return {cnt, sum};
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> candy[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        auto result = go(i);
        v[graph_num].first = result.first; //  친구 수
        v[graph_num].second = result.second; // 사탕 개수
        graph_num++;
    }

    /*for (int i = 1; i <= graph_num - 1; i++) {
        for (int j = 1; j <= k - 1; j++) {
            d[i][j] = d[i - 1][j];
            if (j >= v[i].first) {
                d[i][j] = max(d[i][j], d[i - 1][j - v[i].first] + v[i].second);
            }
        }
    }

    cout << d[graph_num - 1][k - 1] << "\n";*/

    for (int i = 1; i < graph_num; i++) {
        for (int j = k - 1; j >= v[i].first; j--) { // 뒤에서부터 갱신
            d[j] = max(d[j], d[j - v[i].first] + v[i].second);
        }
    }

    cout << d[k - 1] << "\n";

    return 0;
}