#include<iostream>
#include<queue>
#include<string>
#include<algorithm>

using namespace std;

int T;

void Print_Ans(int N, vector<vector<string>> &v) {
	vector<string> answers;
	for (int i = 0; i < v[N].size();i++) {
		string s = v[N][i];
		int ans = 0;

		int num = 0;
		int cnt = 0;
		for (int j = s.length()-1; j >= 0; j--) {
			if (s[j] == '+') {
				ans += num;
				num = 0;
				cnt = 0;
			}
			else if (s[j] == '-') {
				ans -= num;
				num = 0;
				cnt = 0;
			}
			else if (s[j] == ' ') {
				cnt += 1;
			}
			else {
				num += (int(s[j])-int('0'))*(pow(10, cnt));
			}
		}
		ans += num;
		if (ans == 0) answers.push_back(s);
	}
	sort(answers.begin(), answers.end());
	for (auto s1 : answers) cout << s1 << '\n';
}

int main() {
	cin >> T;

	vector<vector<string>> v(10);
	
	v[1].push_back("1");

	for (int i = 2; i <= 9; i++) {
		for (int j = 0; j < v[i-1].size();j++) {
			string s1 = v[i-1][j];
			v[i].push_back(s1 + "+" +to_string(i));
			v[i].push_back(s1 + "-" + to_string(i));
			v[i].push_back(s1 + " " + to_string(i));
		}
	}
	for (int t = 0; t < T;t++) {
		int N;
		cin >> N;
		Print_Ans(N, v);
		cout << '\n';

	}

}