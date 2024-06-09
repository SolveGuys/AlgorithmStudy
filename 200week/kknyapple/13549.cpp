#include <iostream>
#include <deque>

using namespace std;

int n, k;
int vv[100001];

void go(int here) {
    deque<int> q;
    q.push_back(here);
    vv[here] = 1;

    while (!q.empty()) {
        int num = q.front();
        q.pop_front();

        if (num == k) {
            return;
        }

        if (num * 2 <= 100000 && vv[num * 2] == 0) {
            q.push_front(num * 2);
            vv[num * 2] = vv[num];
        }
        if (num + 1 <= 100000 && vv[num + 1] == 0) {
            q.push_back(num + 1);
            vv[num + 1] = vv[num] + 1;
        }
        if (num - 1 >= 0 && vv[num - 1] == 0) {
            q.push_back(num - 1);
            vv[num - 1] = vv[num] + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    go(n);

    cout << vv[k] - 1 << "\n";

    return 0;
}
