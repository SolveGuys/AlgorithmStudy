#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct PosInfo {//위치 정보
	int z, x, y, cnt;
};
class Maze {
private:
	static const int maxi = 5;
	static const int inf = maxi * maxi * maxi;
	int moveCnt;//이동 횟수
	int board[maxi][maxi][maxi] = {
        {{0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 1, 1},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0}},
        
        {{0,1,0,0,0},
        {1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 0, 1, 0}},
        
        {{0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 0, 0}},

        {{1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 1, 0, 1},
        {0, 1, 1, 0, 0},
        {0, 1, 0, 0, 0}},
        
        {{0, 0, 0, 1, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 1, 0, 0, 0}}
    };//원본 보드
	int Rotateboard[maxi][4][maxi][maxi];//회전 보드
	int World[maxi][maxi][maxi];//탐색 맵
	bool visit[maxi][maxi][maxi];//방문 여부
	vector<int> selectedBoard;//각 판자마다 몇번 회전을 선택했는가?
	bool isFloor[maxi];//층 선택 여부
	int Floor[maxi * maxi];//각 층마다 몇번 판자를 선택했는지

	//6방 탐색
	int dz[6] = { -1,1,0,0,0,0 };
	int dx[6] = { 0,0,-1,1,0,0 };
	int dy[6] = { 0,0,0,0,-1,1 };
public:
	Maze() {}//기본 생성자로 초기화
	inline int min(int a, int b);//min
	void input();//입력
	void Rotation();//회전
	void Select(int num);//선택
	void Build(int floors);//건축
	void Start();//출발
	int Escape(int k, int i, int j);//미로 탈출
	void output();//출력
};

//min
inline int Maze::min(int a, int b) {
	return a > b ? b : a;
}
//입력
void Maze::input() {
    /*
	for (int k = 0; k < maxi; k++) {
		for (int i = 0; i < maxi; i++) {
			for (int j = 0; j < maxi; j++) {
				cin >> board[k][i][j];
			}
		}
	}
	*/
	moveCnt = inf;
}
//출력
void Maze::output() {
	if (moveCnt == inf) cout << -1;
	else cout << moveCnt;
}
//회전
void Maze::Rotation() {
	for (int k = 0; k < maxi; k++) {//각 판에 대해
		//0
		for (int i = 0; i < maxi; i++) {
			for (int j = 0; j < maxi; j++) {
				Rotateboard[k][0][i][j] = board[k][i][j];
			}
		}
		//90
		for (int i = 0; i < maxi; i++) {
			for (int j = 0; j < maxi; j++) {
				Rotateboard[k][1][i][j] = board[k][j][maxi - 1 - i];
			}
		}
		//180
		for (int i = 0; i < maxi; i++) {
			for (int j = 0; j < maxi; j++) {
				Rotateboard[k][2][i][j] = board[k][maxi - 1 - i][maxi - 1 - j];
			}
		}
		//270
		for (int i = 0; i < maxi; i++) {
			for (int j = 0; j < maxi; j++) {
				Rotateboard[k][3][i][j] = board[k][maxi - 1 - j][i];
			}
		}
	}
}
//미로 탈출
int Maze::Escape(int startZ, int startX, int startY) {
	//방문 지점 초기화
	for (int k = 0; k < maxi; k++) {
		for (int i = 0; i < maxi; i++) {
			for (int j = 0; j < maxi; j++) visit[k][i][j] = false;
		}
	}
	queue<PosInfo> q;
	q.push({ startZ,startX,startY,0 });
	visit[startZ][startX][startY] = true;
	//탐색
	while (!q.empty()) {
		PosInfo pos = q.front();
		q.pop();

		//도착
		if (pos.z == 4 - startZ && pos.x == 4 - startX && pos.y == 4 - startY) {
			return pos.cnt;
		}

		//다음 지점
		for (int dir = 0; dir < 6; dir++) {
			int nz = pos.z + dz[dir];
			int nx = pos.x + dx[dir];
			int ny = pos.y + dy[dir];
			if (nz < 0 || nz >= maxi || nx < 0 || nx >= maxi || ny < 0 || ny >= maxi) continue;//범위 조건
			if (visit[nz][nx][ny]) continue;//방문 조건
			if (World[nz][nx][ny] == 0) continue;//장애물

			visit[nz][nx][ny] = true;
			q.push({ nz,nx,ny,pos.cnt + 1 });
		}
	}
	return inf;//탈출 불가
}
//출발
void Maze::Start() {
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				int startZ = k * 4; int startX = i * 4; int startY = j * 4;
				if (World[startZ][startX][startY] == 1 && World[4 - startZ][4 - startX][4 - startY] == 1){
				    moveCnt = min(moveCnt, Escape(startZ, startX, startY));//들어갈 수 있는 칸만
				}
			}
		}
	}
}
//건축
void Maze::Build(int floors) {
	//건축 완료
	if (floors == maxi) {
		for (int k = 0; k < maxi; k++) {
			int stage = Floor[k];//선택한 판자
			for (int i = 0; i < maxi; i++) {
				for (int j = 0; j < maxi; j++) {
					//ex) 3번 판자의 3번을 쓰기로 함
					World[k][i][j] = Rotateboard[stage][selectedBoard[stage]][i][j];
				}
			}
		}
		Start();//출발
		return;
	}
	//다음 층
	for (int f = 0; f < maxi; f++) {
		if (!isFloor[f]) {//선택하지 않음
			isFloor[f] = true;
			Floor[floors] = f;
			Build(floors + 1);
			isFloor[f] = false;
		}
	}
}
//선택
void Maze::Select(int num) {
	//모두 선택
	if (num == 5) {
		Build(0);//건축
		return;
	}
	//판자번호별 사용할 회전 판자 선택
	for (int dir = 0; dir < 4; dir++) {
		selectedBoard.push_back(dir);
		Select(num + 1);
		selectedBoard.pop_back();
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Maze maze;//미로
	maze.input();//입력
	maze.Rotation();//회전
	maze.Select(0);//선택
	maze.output();//출력
	return 0;
}
