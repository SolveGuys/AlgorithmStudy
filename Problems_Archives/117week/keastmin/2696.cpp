#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		int N;
		int M;
		vector<int> res;
		priority_queue<int, vector<int>, less<int>> l_q;
		priority_queue<int, vector<int>, greater<int>> g_q;

		cin >> N;
		cin >> M;
		res.push_back(M);

		for (int i = 2; i <= N; i++) {
			int a;
			cin >> a;

			if (M < a) g_q.push(a);
			else l_q.push(a);

			if (i % 2 == 1) {
				if (g_q.size() > l_q.size()) {
					l_q.push(M);
					M = g_q.top();
					g_q.pop();
				}
				else if (g_q.size() < l_q.size()) {
					g_q.push(M);
					M = l_q.top();
					l_q.pop();
				}

				res.push_back(M);
			}

			//cout << M << '\n';

		}

		cout << res.size() << '\n';
		for (int i = 1; i <= res.size(); i++) {
			cout << res[i - 1];
			if (i % 10 == 0) cout << '\n';
			else cout << ' ';
		}
		cout << '\n';
	}

	return 0;
}
