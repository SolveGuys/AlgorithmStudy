#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;
// using ll = long long;
// const int INF = 0x7f7f7f7f;
//const int INF = 0x3f3f3f3f;

int n;
vector<int> v;
int a[1000004];
int index[1000004];
int num;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        a[i] = num;
        if (v.empty() || v.back() < num) {
            index[i] = v.size();
            v.push_back(num);
        }
        else {
            auto tmp = lower_bound(v.begin(), v.end(), num);
            index[i] = tmp - v.begin();
            *tmp = num;
        }
    }
    int len = v.size();
    cout << len <<"\n";
    vector <int> v_tmp;
    /*for (int i = 0; i < n; i++) {
        cout << index[i] << " ";
    }*/
    for (int i = n - 1; i >= 0; i--) {
        if (len < 0)break;
        if (len - 1 == index[i]) {
            v_tmp.push_back(a[i]);
            len--;
        }
    }
    reverse(v_tmp.begin(), v_tmp.end());
    for (int k : v_tmp) {
        cout << k << " ";
    }

    return 0;
}