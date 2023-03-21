#include <iostream>
#include <queue>
using namespace std;

//로못 정보
struct Info {
	int xpos, ypos, direction;//위치, 방향
};

class Robot {
private:
	int n, m, r, c, d;
	static const int maxi = 51;
	bool isStop;
	int Room[maxi][maxi];//방
	bool visit[maxi][maxi];//방문 체크
	queue<Info> q;
	//시계방향
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };
public:
	Robot() {}//기본 생성자
	void input();//입력
	int Clean();//청소
	void Move(int x, int y, int dir, bool isBlank);//이동
};

//입력
void Robot::input() {
	cin >> n>>m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> Room[i][j];
	}
}

//청소
int Robot::Clean() {
	isStop = false;
	int total = 0;//총 개수
	q.push({ r,c,d });

	while (!q.empty()) {
		int x = q.front().xpos;
		int y = q.front().ypos;
		int dir = q.front().direction;
		q.pop();

		//현재 칸 청소
		if (Room[x][y] == 0) {
			//cout << x << " " << y << "\n";
			Room[x][y] = -1;
			total++;
		}
		//주변 확인
		bool isBlank = false;
		for (int i = 0; i < 4; i++) {
			int ndir = (dir - i+7) % 4;
			int nx = x + dx[ndir];
			int ny = y + dy[ndir];
			//빈칸이 있음
			if (Room[nx][ny] == 0) {
				q.push({ nx,ny,ndir });
				isBlank = true;
				break;
			}
		}
		//빈칸이 없다.
		if (!isBlank) {
			//후진 가능한가?
			int nextX = x - dx[dir];int nextY = y - dy[dir];
			if (Room[nextX][nextY] != 1) q.push({ nextX,nextY,dir });//이동
			else if (Room[nextX][nextY] == 1) break;//멈춤
		}
	}
	return total;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Robot robot;//로봇 청소기
	robot.input();//입력
	cout << robot.Clean();//청소
	return 0;
}
