#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, digit,ans;
const int maxi = 10;
int start = 100;
bool visit[maxi];//고장여부

//입력
void input() {
	cin >> n>>m;
	for (int i = 0; i < m; i++) {
		int not_num;
		cin >> not_num;
		visit[not_num] = true;
	}
	ans = abs(start - n);//처음 채널 100
}
//버튼 조작
void button(int num,int cnt,int digit) {
	//목표 자릿수 도달
	if (digit == cnt) {
		ans = min(digit + abs(num - n), ans);
		return;
	}
	//다음 숫자
	for (int i = 0; i <= 9; i++) {
		//고장난 숫자가 아니면
		if (visit[i] == false) {
			int next_num = 10 * num + i;
			button(next_num, cnt + 1,digit);
		}
	}
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	//자릿수 탐색
	for (int i = 1; i <= 6; i++) {
		//첫숫자 탐색
		for (int j = 0; j <= 9; j++) {
			if (visit[j] == false) {//고장난 숫자가 아닐경우에만
				button(j, 1,i);//숫자, 현재 자릿수, 자릿수
			}
		}
	}
	cout << ans;//출력
	return 0;
}
