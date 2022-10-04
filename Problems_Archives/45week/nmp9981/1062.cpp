#include <iostream>
#include <cstring>
using namespace std;

int n,k;
const int maxiAlpha = 26; const int maxi = 51;
bool selected[maxiAlpha];//알파벳 선택여부
string word[maxi];//단어 목록
int readCount = 0;//읽을 수 있는 단어의 개수

//max
int inline max(int x, int y) {
	return x > y ? x : y;
}
//단어 선택
void selectedWord(int idx, int cnt) {
	//단어를 모두 선택
	if (cnt == k-5) {
		int readCan = 0;//읽을 수 있는 단어의 수
		for (int i = 0; i < n; i++) {
			bool isSuccess = true;//단어 읽기에 성공했는가?
			for (int j = 4; j < word[i].size() - 4; j++) {
				int index = word[i][j] - 'a';
				if (selected[index] == false) isSuccess = false;//읽기 실패
			}
			if(isSuccess) readCan++;
		}
		readCount = max(readCount, readCan);//단어의 최대 개수
	}
	//다음 단어 고르기
	for (int i = idx; i < maxiAlpha; i++) {
		if (selected[i] == false) {
			selected[i] = true;
			selectedWord(i + 1, cnt+1);
			selected[i] = false;
		}
	}
}
//입력
void input() {
	//기본적으로 들어가있는 글자
	memset(selected, false, sizeof(selected));
	selected[0] = true; selected[2] = true; selected[8] = true; selected[13] = true; selected[19] = true;
	//입력
	cin >> n >> k;
	for (int i = 0; i < n; i++)cin >> word[i];

	//결과
	if (k < 5) cout << 0;//읽을 수 없음
	else {
		selectedWord(1,0);//단어선택
		cout << readCount;//출력
	}
}

int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	return 0;
}
