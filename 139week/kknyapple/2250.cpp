#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;
// using ll = long long;
const int INF = 0x7f7f7f7f;
// const int INF = 0x3f3f3f3f;

int n, p, a, b;
int l[10004], r[10004]; // 왼쪽 노드, 오른쪽 노드
int pos[10004]; // pos[노드번호] = 위치
int len;
int par[10004];

int ans = 1, ans_level = 1;
int cur_level = 1;

// 중위순회로 위치 저장
void go(int cur) {
    if (l[cur] != -1) go(l[cur]);
    pos[cur] = ++len;
    if (r[cur] != -1) go(r[cur]);
}

void bfs(int cur) {
    queue <pair<int, int>> q;
    q.push({ cur, 1 });

    int lev = 1;
    int mn = INF, mx = 0;
    while (!q.empty()) {
        tie(cur, lev) = q.front();
        q.pop();

        int nxt1 = l[cur];
        int nxt2 = r[cur];

        if (cur_level != lev) { // 다음 레벨에 도달했을 때
            cur_level = lev;
            if (mx!=0 && mn!=INF && ans < mx - mn + 1) {
                ans = mx - mn + 1; // 최대 레벨 너비 저장
                ans_level = lev;
            }
            // 해당 레벨 너비 초기화
            mx = 0;
            mn = INF;
        }

        // 현재 레벨 위치의 min, max 값 저장
        if (nxt1 != -1) {
            q.push({ nxt1, lev + 1 });
            mn = min(pos[nxt1], mn);
            mx = max(pos[nxt1], mx);
        }
        if (nxt2 != -1) {
            q.push({ nxt2, lev + 1 });
            mn = min(pos[nxt2], mn);
            mx = max(pos[nxt2], mx);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p >> a >> b;
        l[p] = a;
        r[p] = b;
        par[a] = p;
        par[b] = p;
    }

    // root 찾기
    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (par[i] == 0) {
            root = i;
            break;
        }
    }

    go(root);
    bfs(root);

    cout << ans_level << " " << ans << "\n";

    return 0;
}
