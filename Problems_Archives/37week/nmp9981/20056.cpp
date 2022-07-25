#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

//파이어볼의 정보를 담는 구조체
struct FireBallInfo {
	int r, c, m, s,d;
};

//마법사 클래스
class Wizard {
private:
	static const int maxi = 51;
	int n, m, k;
	vector<FireBallInfo> fireBall;//파이어볼을 담는 벡터
	vector<FireBallInfo> world[maxi][maxi];//지도
	//방향
	int dr[8] = { -1,-1,0,1,1,1,0,-1 };
	int dc[8] = { 0,1,1,1,0,-1,-1,-1 };
public:
	Wizard() {}

	void MapInit();//맵 초기화
	void input();//입력
	void move();//이동
	void fireAdd();//합치기
	void TotalMass();//질량의 합
};
//맵 초기화
void Wizard::MapInit() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			world[i][j].clear();
		}
	}
}
//입력
void Wizard::input() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int ri, ci, mi, si, di;
		cin >> ri >> ci >> mi >> si >> di;
		fireBall.push_back({ ri-1,ci-1,mi,si,di });//(0,0)부터 시작
	}
}

//이동
void Wizard::move() {
	while (k--) {//명령 k번 실행
		MapInit();//맵 초기화
		for (int i = 0; i < fireBall.size(); i++) {
			//현재 위치
			int pr = fireBall[i].r;
			int pc = fireBall[i].c;
			//다음 위치
			int nr = (n+pr +( fireBall[i].s)%n * dr[fireBall[i].d])%n;
			int nc = (n+pc + (fireBall[i].s)%n * dc[fireBall[i].d])%n;
			//속력, 방향, 질량은 그대로
			world[nr][nc].push_back({ nr,nc,fireBall[i].m,fireBall[i].s ,fireBall[i].d });
		}
		fireAdd();//파이어볼 합치기
	}
}

//파이어볼 합치기
void Wizard::fireAdd() {
	vector<FireBallInfo> nextFire;//다음 파이어볼 정보
	//맵 탐색
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int cnt = world[i][j].size();
			if (cnt == 0) continue;
			if (cnt == 1) {//그대로 넣어준다.
				nextFire.push_back(world[i][j][0]);
				continue;
			}
			//합치기
			int mass = 0;//질량
			int speed = 0;//속력
			int odd = 0;//홀수 개수
			int even = 0;//짝수 개수
			//새로운 질량, 속력 구하기
			for (int k = 0; k < cnt; k++) {
				mass += world[i][j][k].m;
				speed += world[i][j][k].s;
				//방향체크
				if (world[i][j][k].d % 2 == 0) even++;
				else odd++;
			}
			int newMass = mass / 5;//새 질량
			int newSpeed = speed / cnt;//새 속력

			if (newMass == 0) continue;//질량이 0이면 소멸
			if (odd == 0 || even==0) {//모두 짝수이거나 홀수, 0,2,4,6
				for (int k= 0; k < 4; k++) {
					nextFire.push_back({ i,j,newMass,newSpeed,2*k });
				}
			}
			else {//1,3,5,7
				for (int k = 0; k < 4; k++) {
					nextFire.push_back({ i,j,newMass,newSpeed,2*k+1 });
				}
			}
		}
	}
	fireBall = nextFire;//갱신
}

//질량의 총합 구하기
void Wizard::TotalMass() {
	int totalMass = 0;//질량의 합
	for (int i = 0; i < fireBall.size(); i++) totalMass += fireBall[i].m;
	cout << totalMass;//정답 출력
}

int main()
{
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	Wizard wizard;
	wizard.input();//입력
	wizard.move();//파이어볼 이동
	wizard.TotalMass();//질량 구하기
	return 0;
}
