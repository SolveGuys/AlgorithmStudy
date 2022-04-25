#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int s,add;
const int maxi = 2001;
bool dp[maxi][maxi];//방문여부

//입력
void input() {
	cin >> s;
	memset(dp, false, sizeof(dp));
}

//알파벳 조합
void bfs() {
	queue<pair<int, pair<int, int>>> q;//시간,현재 이모티콘 개수, 추가량
	q.push({ 0,{1,0} });
	dp[1][0] = true;//현재 이모티콘 개수, 추가량에서의 방문여부

	while (!q.empty()) {
		int sec = q.front().first;//시간
		int imog = q.front().second.first;//현재 이모티콘 개수
		int add = q.front().second.second;//추가량
		q.pop();

		//종료
		if (imog == s) {
			cout << sec;
			return;
		}

		//복사
		if (dp[imog][imog] == false && imog<maxi) {
			dp[imog][imog] = true;
			q.push({ sec + 1,{imog,imog} });//클립보드에 저장
		}
		//붙여넣기
		if (dp[imog+add][add] == false && add>0 && imog+add<maxi) {//붙여넣기는 1개 이상
			q.push({ sec + 1,{imog + add,add} });
			dp[imog + add][add] = true;
		}
		//삭제
		if (imog > 1 && dp[imog - 1][add] == false) {
			q.push({ sec + 1, { imog - 1,add } });
			dp[imog - 1][add] = true;
		}
	}
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	bfs();//이모티콘 복붙
	return 0;
}
