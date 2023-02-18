#include <iostream>
#include <vector>
using namespace std;

int n,m,k;
const int maxi = 41;
const int stickerMaxi = 101;
int board[maxi][maxi];//전체 모눈종이
int sticker[stickerMaxi][maxi][maxi];//스티커
vector<pair<int,int>> stickerInfo;//스티커 정보

//입력
void input() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int ri,ci;
		cin >> ri >> ci;
		//각 스티커 입력
		stickerInfo.push_back({ ri,ci });
		for (int r = 0; r < ri; r++) {
			for (int c = 0; c < ci; c++) cin >> sticker[i][r][c];
		}
	}
}
//채우기
bool Fill(int x, int y, int num) {//시작 위치
	int R = stickerInfo[num].first;
	int C = stickerInfo[num].second;
	int chk[maxi][maxi];//체크

	if (x + R >= n || y + C >= m) return false;//범위 초과

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			//모눈종이가 빈칸이고 스티커 영역이라면 
			if (board[x + r][y + c] == 0 && sticker[num][r][c] == 1) chk[r][c] = 1;
		}
	}
	//가능한가?
	bool flag = true;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (sticker[num][r][c] != chk[r][c]) flag = false;//불일치
		}
	}
	//일치하면 붙인다.
	if (flag == true) {
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				if (sticker[num][r][c] == 1) board[x + r][y + c] = 1;
			}
		}
	}
	return flag;
}
//붙일 수 있는가?
bool isCan(int num) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//빈칸
			if (board[i][j] == 0) {
				if(Fill(i, j, num)) return true;//붙일 수 있음
			}
		}
	}
	return false;
}
//회전
void Rotation(int num) {
	int R = stickerInfo[num].first;
	int C = stickerInfo[num].second;
	int rotaBoard[maxi][maxi];//회전 이후

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			rotaBoard[c][R-r-1] = sticker[num][r][c];
		}
	}
	//초기화
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) sticker[num][r][c] = 0;
	}
	//갱신
	for (int r = 0; r < C; r++) {
		for (int c = 0; c < R; c++) {
			sticker[num][r][c] = rotaBoard[r][c];
		}
	}
	stickerInfo[num].first = C;
	stickerInfo[num].second = R;
}
//스티커 붙이기
void Attach() {
	for (int i = 0; i < k; i++) {
		for (int ro = 0; ro < 4; ro++) {
			if (isCan(i)) break;//붙일 수 있음
			Rotation(i);//90,180,270,360
		}
	}
}
//스티커 개수 세기
int CountSticker() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j]==1) cnt++;
		}
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	Attach();//스티커 붙이기
	cout<<CountSticker();//스티커 개수 세기
	return 0;
}
