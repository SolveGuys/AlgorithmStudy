#include <iostream>
#include <vector>
using namespace std;

int n;
const int maxi = 21;
const int inf = 1e+8;
int ability[maxi][maxi];//능력치
bool team[maxi];//팀 결성
int diff = inf;//점수차

//크기비교
inline int min(int x, int y) {
	return x > y ? y : x;
}

//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> ability[i][j];
	}
}

//점수 차이
int score() {
	int score_a = 0;
	int score_b = 0;
	vector<int> team_a;//팀a인원
	vector<int> team_b;//팀b인원

	for (int i = 0; i < n; i++) {
		if (team[i]) team_a.push_back(i);
		else team_b.push_back(i);
	}
	for (int i = 0; i < n/2; i++) {
		for (int j = i+1; j < n/2; j++) {
			score_a += ability[team_a[i]][team_a[j]] + ability[team_a[j]][team_a[i]];
			score_b += ability[team_b[i]][team_b[j]] + ability[team_b[j]][team_b[i]];
		}
	}
	return abs(score_a-score_b);
}
//팀 결정
void select_team(int idx,int cnt) {
	//팀 결성 완료
	if (cnt == n / 2) {
		diff = min(diff, score());
		return;
	}
	for (int i = idx; i < n; i++) {
		if (team[i] == false) {//아직 팀 결성이 안되었다면
			team[i] = true;//팀원 선택
			select_team(i + 1, cnt + 1);//다음 팀원 선택
			team[i] = false;
		}
	}
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	select_team(0,0);//팀결정
	cout << diff;//출력
	return 0;
}
