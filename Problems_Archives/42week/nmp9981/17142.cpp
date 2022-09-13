#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int n, m;
const int inf = 10000000;
int ans = inf;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//min
inline int min(int x, int y) {
	return x > y ? y : x;
}
//연구실
class Lab {
private:
	vector<pair<int, int>> virus;//초기 바이러스 위치
	int virusNum = 0;//바이러스 개수
	static const int maxi = 51;
	int world[maxi][maxi];//연구소
	int visit[maxi][maxi];//방문 시간
	bool isSelected[maxi];//바이러스 선택 여부
public:
	Lab() {//생성자
		memset(world, 0, sizeof(world));
		memset(visit, -1, sizeof(visit));
		memset(isSelected, false, sizeof(isSelected));
	}
	void input();//입력
	void SelectedVirus(int idx = 0, int cnt = 0);//바이러스 선택
	int Spread();//확산
};
//입력
void Lab::input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> world[i][j];
			if (world[i][j] == 2) {//바이러스 넣기
				virus.push_back({ i,j });
				virusNum++;
			}
		}
	}
}
//바이러스 선택
void Lab::SelectedVirus(int idx, int cnt) {
	//모두 선택
	if (cnt == m) {
		ans = min(ans, Spread());//확산
		return;
	}
	//다음 바이러스
	for (int i = idx; i < virusNum; i++) {
		if (isSelected[i] == false) {//아직 선택한 바이러스가 아니라면
			isSelected[i] = true;
			SelectedVirus(i + 1, cnt + 1);
			isSelected[i] = false;
		}
	}
}
//확산
int Lab::Spread() {
	int timeVirus = 0;
	queue<pair<int, int>> q;//유효한 바이러스
	memset(visit, -1, sizeof(visit));//초기화
	
	//유효한 바이러스 넣기
	for (int i = 0; i < virusNum; i++) {
		if (isSelected[i]) {
			int nx = virus[i].first;
			int ny = virus[i].second;
			q.push({ nx,ny });
			visit[nx][ny] = 0;//방문 체크
		}
	}
	//확산
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//다음지점
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			//범위조건
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			//벽이 아니고 미방문
			if (world[nx][ny] != 1 && visit[nx][ny] == -1) {
				visit[nx][ny] = visit[x][y] + 1;//방문 시간 증가
				q.push({ nx,ny });
				//빈공간에서만 시간을 센다.
				if (world[nx][ny] == 0) timeVirus = visit[nx][ny];
			}
		}
	}
	//빈공간 검사
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == -1 && world[i][j] != 1) return inf;//벽이 아닌데 미방문 지역
		}
	}
	return timeVirus;
}
int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	Lab lab;//연구소 클래스
	lab.input();//입력
	lab.SelectedVirus(0,0);//바이러스 확산
	//정답 출력
	if (ans < inf) cout << ans;
	else cout << -1;
    return 0;
}
