#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int l,r,c;
const int maxi = 31;
string world[maxi][maxi];//지도
int visit[maxi][maxi][maxi];//방문 시간
//축이동
int dz[6] = { -1,1,0,0,0,0 };
int dx[6] = { 0,0,-1,1,0,0 };
int dy[6] = { 0,0,0,0,-1,1 };

//입력
bool input() {
	cin >> l >> r>>c;
	if (l + r + c == 0) return false;//프로그램 종료
	for (int k = 0; k < l; k++) {
		for (int i = 0; i < r; i++) cin >> world[k][i];
	}
	return true;
}

//초기화
void init() {
	memset(visit, -1, sizeof(visit));
}
//탈출
void escape() {
	queue<pair<int, pair<int, int>>> q;//큐
	for (int k = 0; k < l; k++) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (world[k][i][j] == 'S') {//시작지점
					q.push({ k,{i,j} });
					visit[k][i][j] = 0;//방문 체크
					break;
				}
			}
		}
	}

	while (!q.empty()) {
		int z = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		//도착지점
		if (world[z][x][y] == 'E') {
			cout <<"Escaped in "<< visit[z][x][y]<<" minute(s).\n";
			return;
		}

		//다음지점
		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int nx = x + dx[i];
			int ny = y + dy[i];
			//범위내에 드는가?
			if (nx < 0 || ny < 0 || nz < 0 || nx >= r || ny >= c || nz >= l) continue;
			//방문 여부
			if (visit[nz][nx][ny] != -1) continue;
			//금으로 막힘
			if (world[nz][nx][ny] == '#') continue;
			//다음 지점
			q.push({ nz,{nx,ny} });
			visit[nz][nx][ny] = visit[z][x][y] + 1;
		}
	}
	cout << "Trapped!\n";//탈출 실패
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (1) {
		init();//초기화
		if (input() == false) break;//입력 및 종료
		escape();//탈출
	}
	return 0;
}
