#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
int DP[2501], Palindrome[2501][2501];
string s;

void make_Palindrome() {
	for (int i = 1;i <= s.size();i++) Palindrome[i][i] = 1;
	for (int i = 1;i < s.size() ;i++) {
		if (s[i-1] == s[i]) Palindrome[i][i + 1] = 1;
	}
	for (int i = 3; i <= s.size(); i++) {
		for (int start = 1; start + i - 1 <= s.size(); start++) {
			int end = start + i - 1;
			if (s[start-1] == s[end-1] && Palindrome[start + 1][end - 1])
				Palindrome[start][end] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	for (int i = 0; i <=s.size() ;i++) {
		DP[i] = i;
	}
	
	make_Palindrome();

	for (int end = 1; end <= s.size();end++) {
		DP[end] = 2e9;
		for (int start = 1; start <= end; start++) {
			if (Palindrome[start][end] == true)
				DP[end] = min(DP[end], DP[start - 1] + 1);
		}                     
	}
	cout << DP[s.size()];

	return 0;
}