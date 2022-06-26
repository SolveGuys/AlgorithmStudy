#include <iostream>
#include <cstring>
using namespace std;

int n, l;
const int maxi = 101;
int world[maxi][maxi];
bool install[maxi][maxi];//경사로 설치여부

//입력
void input() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> world[i][j];
		}
	}
}
//열탐색
bool ColSearch(int j) {
	bool chkRoad = true;//길을 만들 수 있는가?
	for (int i = 1; i < n; i++) {
		if (world[i - 1][j] > world[i][j]) {//이전보다 작으면
			if (world[i - 1][j] - world[i][j] != 1) {//차이가 1이 아니라면
				chkRoad = false;//길을 만들 수 없음
				break;
			}
			else {
				//경사로가 가능한가
				for (int k = 0; k < l; k++) {//l길이가 모두 같아야함
					if (world[i + k][j] != world[i - 1][j] - 1 || i + k >= n || install[i + k][j] == true) {//높이가 다르거나 범위 초과나 이미 설치
						chkRoad = false;
						break;
					}
				}
				//경사로 설치
				if (chkRoad) {
					for (int k = 0; k < l; k++) {
						install[i + k][j] = true;
					}
				}
			}
		}
		else if (world[i - 1][j] < world[i][j]) {//이전보다 크면
			if (world[i][j] - world[i - 1][j] != 1) {//차이가 1이 아니라면
				chkRoad = false;//길을 만들 수 없음
				break;
			}
			else {
				//경사로가 가능한가
				for (int k = 0; k < l; k++) {//l길이가 모두 같아야함
					if (world[i - k - 1][j] != world[i][j] - 1 || i - k - 1 < 0 || install[i - k - 1][j] == true) {//높이가 다르거나 범위 초과나 이미 설치
						chkRoad = false;
						break;
					}
				}
				//경사로 설치
				if (chkRoad) {
					for (int k = 0; k < l; k++) {
						install[i - k - 1][j] = true;
					}
				}
			}
		}
		else if (world[i - 1][j] == world[i][j]) continue;//같으면
	}
	return chkRoad;
}

//행탐색
bool RowSearch(int i) {
	bool chkRoad = true;//길을 만들 수 있는가?
	for (int j = 1; j < n; j++) {
		if (world[i][j - 1] > world[i][j]) {//이전보다 작으면
			if (world[i][j - 1] - world[i][j] != 1) {//차이가 1이 아니라면
				chkRoad = false;//길을 만들 수 없음
				break;
			}
			else {
				//경사로가 가능한가
				for (int k = 0; k < l; k++) {//l길이가 모두 같아야함
					if (world[i][j + k] != world[i][j - 1] - 1 || j + k >= n || install[i][j + k] == true) {//높이가 다르거나 범위 초과나 이미 설치
						chkRoad = false;
						break;
					}
				}
				//경사로 설치
				if (chkRoad) {
					for (int k = 0; k < l; k++) {
						install[i][j + k] = true;
					}
				}
			}
		}
		else if (world[i][j - 1] < world[i][j]) {//이전보다 크면
			if (world[i][j] - world[i][j - 1] != 1) {//차이가 1이 아니라면
				chkRoad = false;//길을 만들 수 없음
				break;
			}
			else {
				//경사로가 가능한가
				for (int k = 0; k < l; k++) {//l길이가 모두 같아야함
					if (world[i][j - k - 1] != world[i][j] - 1 || j - k - 1 < 0 || install[i][j - k - 1] == true) {//높이가 다르거나 범위 초과나 이미 설치
						chkRoad = false;
						break;
					}
				}
				//경사로 설치
				if (chkRoad) {
					for (int k = 0; k < l; k++) {
						install[i][j - k - 1] = true;
					}
				}
			}
		}
		else if (world[i][j - 1] == world[i][j]) continue;//같으면
	}
	return chkRoad;
}
//경사로 탐색
void Slope_Search() {
	int roadCount = 0;//도로의 개수
	//세로 탐색
	memset(install, false, sizeof(install));
	for (int j = 0; j < n; j++) roadCount += ColSearch(j);
	//가로 탐색
	memset(install, false, sizeof(install));
	for (int i = 0; i < n; i++) roadCount += RowSearch(i);
	//출력
	cout << roadCount;
}

int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	input();//입력
	Slope_Search();//경사로 탐색
	return 0;
}
