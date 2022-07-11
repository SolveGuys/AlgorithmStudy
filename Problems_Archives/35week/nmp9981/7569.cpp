#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

struct Move {//큐에 담을 정보
	Move(int _z, int _x, int _y) ://생성자
		z(_z), x(_x), y(_y) {}

	int z;
	int x;
	int y;
};

class Tomato {
public:
	Tomato() {}

	void input();//입력
	void bfs();//탐색
	void chk();//확인
private:
	//선언부
	static const int maxi = 101;

	int box[maxi][maxi][maxi];//상자
	int visit[maxi][maxi][maxi];//익기까지의 소요시간
	int m,n,h;//체스판의 크기
	int dx[6] = { 0,0,-1,1,0,0 };
	int dy[6] = { 0,0,0,0,-1,1 };
	int dz[6] = { -1,1,0,0,0,0 };
};

//입력
void Tomato::input() {
	cin >>m>>n>>h;//크기
	memset(visit, -1, sizeof(visit));
	for (int z = 0; z < h; z++) {
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) cin >> box[z][x][y];
		}
	}
}

//bfs탐색
void Tomato::bfs() {
	queue<Move> q;
	//시작지점 찾기
	for (int z = 0; z < h; z++) {
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				if (box[z][x][y] == 1) {
					q.emplace(z, x, y);
					visit[z][x][y] = 0;
				}
			}
		}
	}

	while(!q.empty()) {
		Move cur = q.front();
		q.pop();
		
		//인접노드 검사
		for (size_t i = 0; i < 6; i++) {
			Move next(cur.z + dz[i], cur.x + dx[i], cur.y + dy[i]);

			//범위 조건
			if (next.z < 0 || next.z >= h || next.x < 0 || next.x >= n || next.y < 0 || next.y >= m) continue;
			//방문 여부
			if (visit[next.z][next.x][next.y]!= -1) continue;
			//장애물
			if (box[next.z][next.x][next.y] != 0) continue;
			
			visit[next.z][next.x][next.y] = visit[cur.z][cur.x][cur.y]+1;
			q.emplace(next.z, next.x, next.y);
		}
	}
}

void Tomato::chk() {
	int day = 0;
	for (int z = 0; z < h; z++) {
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				day = max(visit[z][x][y], day);
				//갈수있는데 미방문
				if (visit[z][x][y] == -1 && box[z][x][y]==0) {//익지 않은 토마토가 있다면
					cout << -1;
					return;
				}
			}
		}
	}
	cout << day;
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	Tomato tomato;//토마토 클래스

	tomato.input();//입력
	tomato.bfs();//탐색
	tomato.chk();//확인
	return 0;
}
