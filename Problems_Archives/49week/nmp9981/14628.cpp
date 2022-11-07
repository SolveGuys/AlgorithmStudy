#include <iostream>
#include <cstring>
using namespace std;

int n, m,k;
const int maxi = 101;
const int inf = 10000001;
int mana[maxi];//마나 소비량
int damage[maxi];//데미지
int skill[maxi][maxi];//i번 스킬까지 썼을때 남은 체력 => 총 데미지

//min
inline int min(int x, int y) {
	return x > y ? y : x;
}
//초기화
void init() {
	for (int i = 0; i < maxi; i++) {
		for (int j = 1; j < maxi; j++) skill[i][j] = inf;
	}
}
//입력
void input() {
	//입력
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> mana[i]>>damage[i];//마나 소비량, 데미지
}
//공격
void Attack() {
	//공격
	for (int i = 1; i <= n;i++) {//스킬 번호
		for (int j = 1; j <=m; j++) {//총 데미지
			for (int c = j / damage[i];c>=0; c--) {//횟수
				//i번을 계속쓸지,i+1로 넘어갈지
				skill[i][j] = min(skill[i][j], skill[i-1][j-c*damage[i]]+c*mana[i]+k*((c*(c-1))/2));
			}
		}
	}
	cout << skill[n][m];//출력
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	init();//초기화
	input();//입력
	Attack();//공격
	return 0;
}
