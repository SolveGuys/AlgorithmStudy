#include <iostream>
#include <algorithm>
using namespace std;

int n,ans,cnt;
char color[4] = {'C','P','Y','Z'};
const int maxi = 51;
string candy[maxi];//사탕 배열

//축이동
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> candy[i];
}

//사탕개수세기
int cnt_candy() {
	int candycnt = 1;
	//가로
	for (int i = 0; i < n; i++) {
		cnt = 1;
		for (int j = 1; j < n; j++) {
			if (candy[i][j - 1] == candy[i][j]) cnt++;
			else {
				candycnt = max(candycnt, cnt);
				cnt = 1;
			}
			candycnt = max(candycnt, cnt);//끝부분
		}
	}
	//세로
	for (int j = 0; j < n; j++) {
		cnt = 1;
		for (int i = 1; i < n; i++) {
			if (candy[i-1][j] == candy[i][j]) cnt++;
			else {
				candycnt = max(candycnt, cnt);
				cnt = 1;
			}
			candycnt = max(candycnt, cnt);//끝부분
		}
	}
	return candycnt;
}

int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	//가로바꾸기
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			swap(candy[i][j], candy[i][j - 1]);//자리바꾸기
			ans = max(ans, cnt_candy());
			swap(candy[i][j], candy[i][j - 1]);//원래대로
		}
	}
	//세로바꾸기
	for (int j = 0; j < n; j++) {
		for (int i = 1; i < n; i++) {
			swap(candy[i][j], candy[i-1][j]);//자리바꾸기
			ans = max(ans, cnt_candy());
			swap(candy[i][j], candy[i-1][j]);//원래대로
		}
	}
	cout << ans;//출력
	return 0;
}
