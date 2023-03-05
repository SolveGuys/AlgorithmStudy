#include <iostream>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

//동전
struct coin {
	int firstPosX, firstPosY, secondPosX, secondPosY,Count;
};
int n,m;
const int maxi = 25;
string world[maxi];//지도
bool firstVisit[maxi][maxi];//방문여부
bool secondVisit[maxi][maxi];
queue<coin> q;
int dx[4] = { -1,1,0,0 };//4방 탐색
int dy[4] = { 0,0,-1,1 };

//동전이 떨어지는가?
bool isFall(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return true;
	return false;
}
//입력
void input() {
	cin>> n>>m;
	for (int i = 0; i < n; i++) cin >> world[i];
}
//초기화
void init() {
	vector<pair<int, int>> initPos;//초기 위치
	bool isSecond = false;//두번째 동전인가?
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (world[i][j] == 'o') {
				if (isSecond == false) {//첫번째 동전
					initPos.push_back({ i,j });
					firstVisit[i][j] = true;
					isSecond = true;
				}
				else if (isSecond == true) {//두번째 동전
					initPos.push_back({ i,j });
					secondVisit[i][j] = true;
				}
			}
		}
	}
	q.push({ initPos[0].first,initPos[0].second,initPos[1].first,initPos[1].second,0 });
}
//동전 이동
void Move() {
	while (!q.empty()) {
		int firstX = q.front().firstPosX;
		int firstY = q.front().firstPosY;
		int secondX = q.front().secondPosX;
		int secondY = q.front().secondPosY;
		int cnt = q.front().Count;
		q.pop();
		
		//10회 초과
		if (cnt >= 10) {
			cout << -1;
			return;
		}
		
		//다음 지점
		for (int i = 0; i < 4; i++) {
			int nextFirstX = firstX + dx[i];
			int nextFirstY = firstY + dy[i];
			int nextSecondX = secondX + dx[i];
			int nextSecondY = secondY + dy[i];
			
			//둘다 떨어지는 경우
			if (isFall(nextFirstX, nextFirstY) && isFall(nextSecondX, nextSecondY)) continue;

			//둘중 하나 떨어짐
			if (isFall(nextFirstX, nextFirstY) && !isFall(nextSecondX, nextSecondY)) {
				cout << cnt+1;
				return;
			}
			else if (!isFall(nextFirstX, nextFirstY) && isFall(nextSecondX, nextSecondY)) {
				cout << cnt+1;
				return;
			}
			//장애물
			if (world[nextFirstX][nextFirstY] == '#') {
				nextFirstX = firstX;
				nextFirstY = firstY;
			}
			if (world[nextSecondX][nextSecondY] == '#') {
				nextSecondX = secondX;
				nextSecondY = secondY;
			}
			q.push({ nextFirstX,nextFirstY,nextSecondX,nextSecondY,cnt + 1 });
		}
	}
	cout << -1;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	init();//초기화
	Move();//동전
	return 0;
}
