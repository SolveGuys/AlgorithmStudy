#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m,ans;
const int maxi = 31;
const int inf = 1e+7;
string board[maxi];//보드
bool visit[maxi][maxi];//방문 체크
int max_blank = 0;//빈칸 개수
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//초기화
void init() {
	max_blank = 0;
	ans = inf;
	for (int i = 0; i < maxi; i++) board[i] = "";
	memset(visit, false, sizeof(visit));//방문 지점 초기화
}

//입력
void input() {
	for (int i = 0; i < n; i++) cin >> board[i];
	//빈칸의 총 개수 세기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '.') max_blank++;
		}
	}
}
//방향 바꾸는 조건
bool change_dir(int x, int y) {
	//범위내에 들고 장애물이 아니고 미방문이면
	if (x >= 0 && x < n && y >= 0 && y < m && visit[x][y] == false && board[x][y] == '.') return false;
	return true;
}

//탐색
void dfs(int i,int j,int cnt,int dir, int move) {//위치, 진행 블록 개수, 방향, 이동 횟수
	//모두 탐색
	if (cnt == max_blank) {
		ans = min(ans, move);
		return;
	}
	//다음 지점
	int nx = i + dx[dir];
	int ny = j + dy[dir];
	//범위내에 들고 장애물이 아니면
	if (!change_dir(nx,ny)) {
		visit[nx][ny] = true;//방문체크
		dfs(nx, ny, cnt + 1, dir, move);
		visit[nx][ny] = false;//체크해제
	}
	else {//방향을 틀어야함
		//다음 방향으로 이동
		for (int d = 0; d < 4; d++) {
			if (d == dir) continue;//같은 방향
			nx = i + dx[d];
			ny = j + dy[d];

			//튼 방향이 범위내에 들고 장애물이 아니면
			if (!change_dir(nx,ny)) {
				visit[nx][ny] = true;//방문체크
				dfs(nx, ny, cnt + 1, d, move + 1);
				visit[nx][ny] = false;//체크해제
			}
		}
	}
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc = 1;
	while (cin >> n >> m) {//EOP입력 받을때까지
		init();//초기화
		input();//입력
		//예외
		if (max_blank == 1) {
			cout << "Case " << tc << ": " << 0 << "\n";
			tc++;
			continue;
		}
		
		//시작 위치 지정
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				//빈칸이면
				if (board[i][j] == '.') {
					//4방향 탐색
					for (int dir = 0; dir < 4; dir++) {
						visit[i][j] = true;//방문체크
						dfs(i, j, 1, dir, 1);
						visit[i][j] = false;//체크해제
					}
				}
			}
		}
		
		//출력
		if (ans == inf) ans = -1;
		cout << "Case " << tc << ": " << ans << "\n";
		tc++;
	}
	return 0;
}
