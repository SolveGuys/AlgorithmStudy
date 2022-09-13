#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, d,ans;

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}
//궁수
class BowMan {
private:
	int maxLine = 0;//탐색하는 가장 윗줄
	int totalEnemy = 0;//제거한 적의 수
	static const int maxi = 16;
	int world[maxi][maxi];
	int originalWorld[maxi][maxi];
	vector<int> selectedBow;
	bool selected[maxi] = {};
public:
	BowMan() {
		memset(world, 0, sizeof(world));
		memset(originalWorld, 0, sizeof(originalWorld));
		memset(selected, false, sizeof(selected));
	}//생성자
	void init();//초기화
	void input();//입력
	bool AllKill();//모두 잡았는가?
	void Selected(int index = 0,int cnt = 0);//선택
	void Hunt();//사냥
	void EnemyMove();//적 이동
};

//입력
void BowMan::input() {
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> originalWorld[i][j];
	}
}
//초기화
void BowMan::init() {
	maxLine = 0;
	totalEnemy = 0;
	selectedBow.clear();
	//맵 복사
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) world[i][j] = originalWorld[i][j];
	}
	//궁수 위치
	for (int i = 0; i < m; i++) {
		if(selected[i]) selectedBow.push_back(i);
	}
}
bool BowMan::AllKill() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (world[i][j] == 1) return false;
		}
	}
	return true;
}
//궁수 선택
void BowMan::Selected(int index, int cnt) {
	//배치 완료
	if (cnt == 3) {
		init();//초기화
		for(int pase=0;pase<n;pase++) {
			Hunt();//사냥
			if (AllKill()) break;//모두 사냥
			EnemyMove();//이동
		}
		ans = max(ans, totalEnemy);//사냥한 적의 수의 최댓값
		return;
	}
	//다음 지점
	for (int i = index; i < m; i++) {
		if (selected[i] == false) {
			selected[i] = true;
			Selected(i + 1, cnt + 1);
			selected[i] = false;
		}
	}
}
//사냥
void BowMan::Hunt() {
	vector<pair<int, int>> dieEnemy;//죽은 적
	//각 궁수별
	for (int k = 0; k < 3; k++) {
		vector<pair<int, pair<int, int>>> enemy;//적
		//적의 위치,거리 담기
		for (int i = maxLine; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (world[i][j] == 1) {
					int dist = abs(j - selectedBow[k]) + n-i;
					if(dist<=d) enemy.push_back({ dist,{j,i} });//거리 제한, 왼쪽부터
				}
			}
		}
		if (enemy.size() == 0) continue;//적이 없는 경우
		sort(enemy.begin(), enemy.end());//거리순 정렬
		dieEnemy.push_back({ enemy[0].second.second,enemy[0].second.first });//죽은 적의 위치
	}
	//적 명중
	for (int i = 0; i < dieEnemy.size(); i++) {
		if (world[dieEnemy[i].first][dieEnemy[i].second] == 1) {//몬스터 사냥
			world[dieEnemy[i].first][dieEnemy[i].second] = 0;
			totalEnemy++;
		}
	}
	maxLine++;//탐색 줄 수 감소
}
//적 이동
void BowMan::EnemyMove() {
	//적 이동
	for (int i = n-1; i > 0; i--) {
		for (int j = 0; j < m; j++) {
			world[i][j] = world[i - 1][j];
		}
	}
}
int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	BowMan bowman;
	bowman.input();//입력
	bowman.Selected();//궁수선택
	cout << ans;//출력
    return 0;
}
