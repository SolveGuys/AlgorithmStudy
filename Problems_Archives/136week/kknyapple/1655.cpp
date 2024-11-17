#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;
using ll = long long;

int n, num;
priority_queue <int> mx;
priority_queue<int, vector<int>, greater<int>> mn;

// 1 2 4 7 9
// 1 2 4 | 7 9 => 4
//  (mx) | (mn)

// num = 3
// 1 2 4 | 3 7 9 -> 1 2 3 | 4 7 9

// num = 10
// 1 2 3 10 | 4 7 9 -> 1 2 3 4 | 7 9 10

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;

        if (mx.size() == mn.size() ||mx.empty()) {
            mx.push(num);
        }
        else {
            mn.push(num);
        }
        if (mx.size() && mn.size()) {
            if (mx.top() > mn.top()) {
                int tmp1 = mx.top();
                int tmp2 = mn.top();

                mx.pop();
                mn.pop();

                mx.push(tmp2);
                mn.push(tmp1);
            }
        }
        cout << mx.top() << "\n";
    }
    
    return 0;
}
