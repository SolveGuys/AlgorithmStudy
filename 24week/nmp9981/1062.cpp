#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
const int maxi = 51;
string A[maxi];//문자열 A
bool alpha_chk[26];//알파벳이 쓰였는가
int ans = 0;

//입력
void input() {
	cin >> n>>k;
	for (int i = 0; i < n; i++) cin >> A[i];
	//이미 배운5글자 a,c,i,n,t
	alpha_chk[0] = true;
	alpha_chk[2] = true;
	alpha_chk[8] = true;
	alpha_chk[13] = true;
	alpha_chk[19] = true;
}
//알파벳 조합
void dfs(int idx,int cnt) {
	if (cnt == k) {
		int cnt_word = 0;
		//알파벳 탐색
		for (int i = 0; i < n; i++) {
			int alpha_cnt = 0;
			for (int j = 4; j < A[i].size() - 4; j++) {
				if (alpha_chk[A[i][j]-97] == true) {//배웠는가?
					alpha_cnt++;
				}
			}
			if (alpha_cnt == A[i].size() - 8) cnt_word++;//셀 수 있다.
		}
		ans = max(cnt_word, ans);
		return;
	}
	//다음 알파벳
	for (int i = idx; i < 26; i++) {
		if (alpha_chk[i] == false) {//아직 배우지 않은 알파벳
			alpha_chk[i] = true;
			dfs(i+1, cnt + 1);
			alpha_chk[i] = false;
		}
	}
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	if (k < 5) {//모든 단어를 배울 수 없다
		cout << 0;
	}else {//읽을 수 있는 단어의 개수
		dfs(1,5);//알파벳 조합 뽑기
		cout << ans;//출력
	}
	return 0;
}
