#include<iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string str;	
	int N;
	cin >> str;
	str = " " + str;
	N = str.size();
	vector<vector<bool>> palindrome(N + 1, vector<bool>(N + 1, false));
	vector<int> dp(N + 1, 0);

	for (int i = 1; i <= N; i++) palindrome[i][i] = true;
	for (int i = 1; i < N; i++) if (str[i] == str[i + 1]) palindrome[i][i + 1] = true;
	for (int Len = 3; Len <= N; Len++) {
		for (int Start = 1; Start + Len - 1 <= N; Start++) {
			int End = Start + Len - 1;
			if (str[Start] == str[End] && palindrome[Start + 1][End - 1])
				palindrome[Start][End] = true;
		}
	}

	for (int End = 1; End <= N; End++) {
		dp[End] = 2e9;
		for (int Start = 1; Start <= End; Start++) {
			if (palindrome[Start][End])
				dp[End] = min(dp[End], dp[Start - 1] + 1);
		}
	}

	cout << dp[N] - 1 << '\n';

	return 0;
}
