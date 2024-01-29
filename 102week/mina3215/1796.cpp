#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string s;
int DP[50][2];

int main() {
	cin >> s;

	vector<vector<int>> v(28);
	v[0].push_back(0);

	char next = 'a';
	DP[0][0] = 0;
	DP[0][1] = 0;

	for (int i = 1; i <= 26; i++) {

		int now = int(next - 'a') + 1;

		//if (s == "") {
		//	std::cout << min(DP[now - 1][0], DP[now - 1][1]);
		//	break;
		//}


		for (int i = 0; i < s.size();i++) {
			if (next == s[i]) {
				v[now].push_back(i);
			}
		}
		if (v[now].empty()) {
			next++;
			DP[now][0] = DP[now - 1][0];
			DP[now][1] = DP[now - 1][1];
			continue;
		}

		int prev0 = v[now - 1][0];
		int prev1 = v[now - 1][v[now - 1].size() - 1];
		int now0 = v[now][0];
		int now1 = v[now][v[now].size() - 1];

		DP[now][0] = min(DP[now - 1][0] + abs(prev0 - now0), DP[now - 1][1] + abs(prev1 - now0));
		DP[now][1] = min(DP[now - 1][0] + abs(prev0 - now1), DP[now - 1][1] + abs(prev1 - now1));
		DP[now][0] += v[now].size() + abs(now0 - now1);
		DP[now][1] += v[now].size() + abs(now0 - now1);

		//for (int i = v[now].size()-1; i >=0 ; i--) {
		//	s.erase(v[now][i], 1);
		//}

		next++;
	}
	std::cout << min(DP[26][0], DP[26][1]);

}