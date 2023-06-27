#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

int n;
ll ans = 0;
const int maxi = 80001;
ll height[maxi];//높이
stack<ll> s;

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> height[i];
}
//빌딩 비교
void CompareBuilding() {
    for (int i = 0; i < n; i++) {
        while (!s.empty()) {
            if (height[i] < s.top()) break;
            s.pop();
        }
        ans += s.size();
        s.push(height[i]);
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    CompareBuilding();//빌딩 비교
    return 0;
}
