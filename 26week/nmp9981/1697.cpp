#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n,k;
const int maxi = 200001;
bool visit[maxi];

//입력
void input() {
	cin >> n >> k;
	memset(visit, false, sizeof(visit));
}

//숨바꼭질
void hide() {//위치, 진행 블록 개수, 방향, 이동 횟수
	queue<pair<int,int>> q;
	q.push({ n,0 });
	visit[n] = true;//방문체크

	while (!q.empty()) {
		int x = q.front().first;//현재 위치
		int sec = q.front().second;//현재 시간
		q.pop();

		//도착
		if (x == k) {
			cout << sec;
			return;
		}
		//다음지점
		if (x + 1 < maxi && visit[x + 1] == false) {
			visit[x + 1] = true;
			q.push({ x + 1,sec+1 });
		}
		if (x - 1 >= 0 && visit[x - 1] == false) {
			visit[x - 1] = true;
			q.push({ x - 1,sec + 1 });
		}
		if (x*2 < maxi && visit[x*2] == false) {
			visit[x*2] = true;
			q.push({ x*2,sec + 1 });
		}
	}
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	hide();//숨바곡질
	return 0;
}
