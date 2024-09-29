#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;

int n;
int a[1004];

// 1 1 2 3 6 7 30
// 1 2 3 4 7 14 15 ... 21 31

// 1 1 2 3 6 7 21 -> 42

// 1 2 3 4 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    
    if (a[0] != 1) {
        cout << 1 << "\n";
        return 0;
    }

    int top = 1;
    for (int i = 1; i < n; i++) {
        int flag = 0;
        for (int j = top; j >= 0; j--) {
            // if (i == n - 1)cout << a[i] << "\n";
            if (top + 1 == j + a[i]) {
                //cout << top << " " << a[i] << "\n";
                flag = 1;
                top += a[i];
                break;
            }
        }
        if (flag == 0) {
            break;
        }
    }

    cout << top + 1<< "\n";
   
    return 0;
}
