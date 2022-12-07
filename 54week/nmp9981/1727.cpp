#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m,matchSize;
const int maxi = 1001;
vector<int> man; vector<int>woman;//성격
int diff[maxi][maxi];//차이
int match[maxi][maxi];//매치도

//min
inline int min(int x, int y) {
	return x > y ? y : x;
}
//abs
inline int abs(int x) {
	return x > 0 ? x : -x;
}
//입력
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		man.push_back(a);
	}
	for (int j = 0; j < m; j++) {
		int b; cin >> b;
		woman.push_back(b);
	}
	sort(man.begin(), man.end());//정렬
	sort(woman.begin(), woman.end());
}
//성격차
void Character() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) diff[i][j] = abs(man[i-1] - woman[j-1]);
	}
}
//매치
void Match() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == j) match[i][j] = match[i-1][j-1]+diff[i][j];//확정 매칭
			else if (i < j) match[i][j] = min(match[i][j - 1], match[i - 1][j - 1] + diff[i][j]);//여자가 솔로
			else if (i > j) match[i][j] = min(match[i - 1][j], match[i - 1][j - 1] + diff[i][j]);//남자가 솔로
		}
	}
}
//결과
void Result() {
	int ans = match[n][m];
	if (n < m) {
		for (int i = n + 1; i <= m; i++) {
			if (ans > match[n][i]) ans = match[n][i];
		}
	}
	else if (n > m) {
		for (int i = m + 1; i <= n; i++) {
			if (ans > match[i][m]) ans = match[i][m];
		}
	}
	cout << ans;
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
    input();//입력
	Character();//성격차
	Match();//매치
	Result();//결과
	return 0;
}
