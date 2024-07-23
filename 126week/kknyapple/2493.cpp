#include <iostream>
#include <stack>
using namespace std;

int n, h;
int a[500004];
stack <pair<int, int>> st;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <=n; i++) {
		cin >> h;
		while (!st.empty()) {
			if (st.top().second > h) {
				a[i] = st.top().first;
				break;
			}
			else {
				st.pop();
			}
		}

		st.push({ i,h });
	}

	for (int i = 1; i <=n; i++) {
		cout << a[i] << ' ';
	}
	cout << "\n";

	return 0;
}
