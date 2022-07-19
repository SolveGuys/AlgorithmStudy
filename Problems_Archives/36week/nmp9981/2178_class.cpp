#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

//큐에 담을 정보
struct Move {
	Move(int _x, int _y) : x(_x), y(_y) {}//생성자 리스트
	int x; int y;
};

class Maze {
public:
	Maze() {}

	void input();//입력
	void mazeMove();//미로 탐색
private:
	static const int maxi = 101;
	int n, m;//미로 크기
	int maze[maxi][maxi];//미로
	int visit[maxi][maxi];//지나가는 칸수
	//이동
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
};

//입력
void Maze::input() {
	cin >> n>>m;
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) maze[i][j] = s[j] - '0';
	}
}

//미로 이동
void Maze::mazeMove() {
	queue<Move> q;
	q.emplace(0,0);
	visit[0][0] = 1;//첫번째칸 방문

	while (!q.empty()) {
		Move cur = q.front();
		q.pop();
		//종료
		if (cur.x == n - 1 && cur.y == m - 1) {
			cout << visit[cur.x][cur.y];//출력
			return;
		}

		//다음 지점
		for (size_t i = 0; i < 4; i++) {
			Move next(cur.x + dx[i], cur.y + dy[i]);
			//범위내에 드는가?
			if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m) continue;
			//이미 방문한 지역인가?
			if (visit[next.x][next.y] != 0) continue;
			//장애물이 있는가?
			if (maze[next.x][next.y] == 0) continue;

			q.emplace(next.x, next.y);
			visit[next.x][next.y] = visit[cur.x][cur.y] + 1;//다음 지점 방문
		}
	}
}

int main()
{
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	Maze maze;//maze클래스
	maze.input();//입력
	maze.mazeMove();//미로 탐색
	return 0;
}
