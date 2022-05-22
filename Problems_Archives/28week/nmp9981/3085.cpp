#include <iostream>
#include <algorithm>
using namespace std;

int n,ans;
const int maxi = 51;
string board[maxi];//보드

//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> board[i];
}

//사탕 먹는 개수
int EatCandy() {
	int candy = 1;
	//행
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 1; j < n; j++) {
			//같은 문자면 사탕을 먹는다.
			if (board[i][j] == board[i][j - 1]) cnt++;
			else {//다른문자면 최대 사탕개수 갱신후 초기화
				candy = max(candy, cnt);
				cnt = 1;
			}
		}
		candy = max(candy, cnt);//끝에 연속되어있는 사탕까지 처리
	}
	//열
	for (int j = 0; j < n; j++) {
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			//같은 문자면 사탕을 먹는다.
			if (board[i][j] == board[i-1][j]) cnt++;
			else {//다른문자면 최대 사탕개수 갱신후 초기화
				candy = max(candy, cnt);
				cnt = 1;
			}
		}
		candy = max(candy, cnt);//끝에 연속되어있는 사탕까지 처리
	}
	return candy;
}
//바꿀 위치 탐색
void ChangeSearch() {
	//행
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			swap(board[i][j - 1], board[i][j]);//위치 바꾸기
			ans = max(ans, EatCandy());//먹는 사탕 개수 구하기
			swap(board[i][j - 1], board[i][j]);//원래대로
		}
	}
	//열
	for (int j = 0; j < n; j++) {
		for (int i = 1; i < n; i++) {
			swap(board[i-1][j], board[i][j]);//위치 바꾸기
			ans = max(ans, EatCandy());//먹는 사탕 개수 구하기
			swap(board[i-1][j], board[i][j]);//원래대로
		}
	}
	cout << ans;//출력
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	ChangeSearch();//바꿀 위치 탐색
	return 0;
}
