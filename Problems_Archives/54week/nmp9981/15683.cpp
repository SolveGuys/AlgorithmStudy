#include <iostream>
#include <vector>
using namespace std;

struct CamPos {//카메라 정보
	int xpos, ypos,num;
};
class Office {
private:
	int n, m, area;//행,열 크기, 남은 영역의 수
	vector<vector<int>> world;//지도
	vector<CamPos> cam;//카메라 정보
public:
	Office();
	inline int min(int a, int b);
	void input();//입력
	void Camera();//카메라 모으기
	void Move(int x,int y, int dir);//카메라 이동
	void Search(int cnt);//탐색
	int Area();//영역 개수 세기
	void output() const { cout << area; };//출력
};
//생성자
Office::Office() {
	n = 0; m = 0; area = 65;
}
//min
inline int Office::min(int a, int b) {
	return a > b ? b : a;
}
//입력
void Office::input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		vector<int> row;
		for (int j = 0; j < m; j++) {
			int in; cin >> in;
			row.push_back(in);
		}
		world.push_back(row);
	}
}
//카메라 정보 넣기
void Office::Camera() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (world[i][j] > 0 && world[i][j] <= 5) cam.push_back({ i,j,world[i][j] });
		}
	}
}
//카메라 이동
void Office::Move(int x, int y, int dir) {
	switch (dir) {
	case 0://동
		for (int j = y; j < m; j++) {
			if (world[x][j] == 6) break;//벽일 경우 탐색 종료
			if(world[x][j] == 0) world[x][j] = 7;//감시 표시
		}
		break;
	case 1://남
		for (int i=x; i < n; i++) {
			if (world[i][y] == 6) break;//벽일 경우 탐색 종료
			if(world[i][y] == 0) world[i][y] = 7;//감시 표시
		}
		break;
	case 2://서
		for (int j = y; j >= 0; j--) {
			if (world[x][j] == 6) break;//벽일 경우 탐색 종료
			if (world[x][j] == 0) world[x][j] = 7;//감시 표시
		}
		break;
	case 3://북
		for (int i = x; i >= 0; i--) {
			if (world[i][y] == 6) break;//벽일 경우 탐색 종료
			if (world[i][y] == 0) world[i][y] = 7;//감시 표시
		}
		break;
	}
}
//영역의 수 세기
int Office::Area() {
	int areaCnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (world[i][j] == 0) areaCnt++;//사각지대
		}
	}
	return areaCnt;
}
//탐색
void Office::Search(int cnt) {
	if (cnt == cam.size()) {//감시 완료
		area = min(area, Area());//안전 영역의 수 갱신
		return;
	}
	//감시 카메라
	int cctv = cam[cnt].num;//카메라 번호
	int x = cam[cnt].xpos; int y = cam[cnt].ypos;//위치
	vector<vector<int>> worldCopy = world;//이전 상태 저장

	switch (cctv) {
	case 1://1번
		for (int dir = 0; dir < 4; dir++) {
			Move(x, y, dir);
			Search(cnt + 1);
			world = worldCopy;//원래대로
		}
		break;
	case 2://2번
		for (int dir = 0; dir < 2; dir++) {
			Move(x, y, dir);
			Move(x, y, dir + 2);
			Search(cnt + 1);
			world = worldCopy;//원래대로
		}
		break;
	case 3://3번
		for (int dir = 0; dir < 4; dir++) {
			Move(x, y, dir);
			Move(x, y, (dir + 1)%4);
			Search(cnt + 1);
			world = worldCopy;//원래대로
		}
		break;
	case 4://4번
		for (int dir = 0; dir < 4; dir++) {
			Move(x, y, dir);
			Move(x, y, (dir + 1)%4);
			Move(x, y, (dir + 2)%4);
			Search(cnt + 1);
			world = worldCopy;//원래대로
		}
		break;
	case 5://5번
		Move(x, y, 0);
		Move(x, y, 1);
		Move(x, y, 2);
		Move(x, y, 3);
		Search(cnt + 1);
		world = worldCopy;//원래대로
		break;
	}
}

int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	Office office;//사무실
	office.input();//입력
	office.Camera();//카메라 정보 등록
	office.Search(0);//카메라 탐색
	office.output();//출력
	return 0;
}
