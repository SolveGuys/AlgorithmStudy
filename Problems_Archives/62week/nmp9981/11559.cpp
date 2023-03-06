#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

class Puyo {
private:
	static const int height = 12;//세로
	static const int width = 6;//가로
	string world[height];//지도
	bool visit[height][width];//방문 여부
	vector<pair<int, int>> boom;//터뜨리는 위치

	int dx[4] = { -1,1,0,0 };//4방탐색
	int dy[4] = { 0,0,-1,1 };
public:
	Puyo() {}//생성자

	void init();//초기화
	void input();//입력
	bool IsFour();//4개가 모여있는가?
	int bfs(int x, int y);//bfs탐색
	void Down();//아래로 떨어지기
};
//초기화
void Puyo::init() {
	memset(visit, false, sizeof(visit));
}
//입력
void Puyo::input() {
	for (int i = 0; i < height; i++) cin >> world[i];
}
//bfs탐색
int Puyo::bfs(int i, int j) {
	boom.clear();//초기화
	char color = world[i][j];//색 지정
	queue<pair<int, int>> q;
	q.push({ i,j });
	visit[i][j] = true;
	boom.push_back({ i,j });

	//bfs탐색
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//다음 지점
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= height || ny < 0 || ny >= width) continue;//범위 조건
			if (visit[nx][ny]) continue;//이미 방문

			//같은 색
			if (color == world[nx][ny]) {
				visit[nx][ny] = true;
				q.push({ nx,ny });
				boom.push_back({ nx,ny });
			}
		}
	}
	return boom.size();
}
//4개가 모여있는가?
bool Puyo::IsFour() {
	bool possible = false;//4개가 모인적 있는가?
	//맵을 둘러본다.
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (world[i][j] == '.') continue;//빈칸은 패스
			if (visit[i][j]) continue;//이미 방문

			//4개 이상인가?
			if (bfs(i, j) >= 4) {
				possible = true;
				//터뜨린다.
				for (int k = 0; k < boom.size(); k++) world[boom[k].first][boom[k].second] = '.';
			}
		}
	}
	return possible;
}
//아래로 떨어지기
void Puyo::Down() {
	for (int j = 0; j < width; j++) {//각 열기준
		vector<char> col;//열
		for (int i = height - 1; i >= 0; i--) {//밑에서부터
			if (world[i][j] != '.') col.push_back(world[i][j]);//빈칸이 아니면
		}
		//뿌요 채우기
		for (int i = 0; i < col.size(); i++) world[height - 1 - i][j] = col[i];
		//위에 빈칸
		int upSize = height - col.size();
		for (int i = 0; i < upSize; i++) world[i][j] = '.';
	}
}
int main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	Puyo puyo;
	puyo.input();//입력
	int cnt = 0;//연쇄횟수
	while (true) {
		puyo.init();//초기화
		if (puyo.IsFour()) {//터지면
			cnt++;//횟수 증가
			puyo.Down();//아래로 내리기
		}
		else break;
	}
	cout << cnt;//출력
	return 0;
}
