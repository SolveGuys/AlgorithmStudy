#include<iostream>
#include<vector>

using namespace std;

void checkDFS(vector<int> &num, vector<int> &s, int x, int &level) {
	s[x] = level;
	int next = num[x];
	if ( s[next] == level )return;
	checkDFS(num, s, next, level);
}

void DFS(vector<int> &num, vector<int> &s,  int x, int &level) {
	s[x] = level;
	int next = num[x];
	if ( s[next] == level ) {
		int _level = -level;
		checkDFS(num, s, x, _level);
	}
	else if(s[next] == 0 ) {
		DFS(num, s, next, level);
	}
	else {
		return;
	}


}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T,n;
	cin >> T;
	for ( int i = 0; i < T; i++ ) {
		cin >> n;
		int level = -1;
		vector<int> num(n + 1);
		vector<int> s(n + 1, 0);
		vector<bool> check(n + 1, 0);
		for ( int j = 1; j < n + 1; j++ ) {
			cin >> num[j];
		}
		for ( int j = 1; j < n + 1; j++ ) {
			if ( s[j] == 0 )DFS(num, s, j, level);
			level--;
		}
		int ans = 0;
		for ( int j = 1; j < n + 1; j++ ) {
			if ( s[j] < 0 )ans++;
		}
		cout << ans << '\n';
	}

	return 0;
}