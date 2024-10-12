#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;

int n, h;
stack <int> a;
stack <pair<int, int>> st; // index, height
pair<int, int> ans[100004]; // cnt, index

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    // 왼쪽에 있는 건물 중 보이는 건물
    for (int i = 1; i <= n; i++) {
        cin >> h;
        a.push(h);

        if (st.size()) {
            // top의 건물 크기가 현재 건물보다 큰 경우만 남겨 놓는다.
            while (st.size()) {
                if (st.top().second <= h) {
                    st.pop();
                }
                else {
                    break;
                }
            }
            
            if (st.size()) {
                ans[i].first = st.size();
                ans[i].second = st.top().first;
            }
            st.push({i,h});
        }
        else {
            st.push({i,h});
        }
    }

    while (st.size()) {
        st.pop();
    }

    // 오른쪽에 있는 건물 중 보이는 건물
    for (int i = n; i >=1; i--) {
        h = a.top();
        a.pop();

        if (st.size()) {
            while (st.size()) {
                if (st.top().second <= h) {
                    st.pop();
                }
                else {
                    break;
                }
            }

            if (st.size()) {
                ans[i].first = ans[i].first + st.size();

                // 가장 가까운 건물의 번호 중 작은 번호로 출력
                if(ans[i].second==0 || abs(i - st.top().first)< abs(ans[i].second - i)) ans[i].second = st.top().first;
            }
            st.push({ i,h });
        }
        else {
            st.push({ i,h });
        }

  
    }

    for (int i = 1; i <= n; i++) {
        if (ans[i].first) {
            cout << ans[i].first << " " << ans[i].second << "\n";
        }
        else {
            cout << 0 << "\n";
        }
        
    }
   
    return 0;
}
