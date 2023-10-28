#include<bits/stdc++.h>

using namespace std;

string s1, s2;

int main() {
	cin >> s1;
	cin >> s2;
	
	int s1_len = s1.length();
	int s2_len = s2.length();

	string s;

	int start = 1;
	int ans = 0;

	for (int i = 0; i < s1_len; i++) {
		for (int j = start; j <= s1_len - i; j++) {
			s = s1.substr(i, j);
			if (s2.find(s) != string::npos) {
				start = s.length();
				ans = start;
			}
			else {
				break;
			}
		}
	}
	
	cout << ans;
	return 0;
}