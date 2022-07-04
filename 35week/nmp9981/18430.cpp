#include<iostream>
using namespace std;

int n, m,ans;
const int maxi = 5;
int weapon[maxi][maxi];//재료 정보
bool chk[maxi][maxi];//부메랑 사용 여부 체크
//방향 이동
int dr[4] = { 1,1,-1,-1 };
int dc[4] = { 1,-1,1,-1 };
//입력
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> weapon[i][j];
	}
}

//크기비교
inline int max(int x, int y) {
	return x > y ? x : y;
}

//부메랑 만들기
void boomerang(int r, int c, int sum) {
	//다음 행으로 이동
	if (c == m) {
		r++;
		c = 0;
	}
	//종료
	if (r == n) {
		ans = max(ans, sum);
		return;
	}
	//각 부메랑
	if (!chk[r][c]) {
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nc >= m || nc < 0 || nr >= n || nr < 0) continue;//범위 조건
			if (chk[r][nc] || chk[nr][c]) continue;//방문 여부
			//방문체크
			chk[r][c] = true;
			chk[r][nc] = true;
			chk[nr][c] = true;

			int next_sum = sum + 2*weapon[r][c] + weapon[r][nc] + weapon[nr][c];//누적 점수
			boomerang(r,c+1,next_sum);//다음 부메랑
			chk[r][c] = false;
			chk[r][nc] = false;
			chk[nr][c] = false;
		}
	}
	boomerang(r, c + 1, sum);//다음 부메랑
	return;
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	
	if (m == 1 || n == 1) cout << 0;//부메랑을 만들 수 없음
	else {
		boomerang(0, 0, 0);//부메랑 만들기
		cout << ans;
	}
	return 0;
}
