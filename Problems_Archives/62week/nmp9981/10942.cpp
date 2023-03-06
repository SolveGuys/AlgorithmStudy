#include <iostream>
using namespace std;

int n,m;
const int maxi = 2001;
int A[maxi];//수열
bool isPalindrome[maxi][maxi];//팰린드롬인가?

//입력
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
}
//팰린드롬 판단
void JudgePalindrome() {
	//초기화
	for (int i = 1; i <= n; i++) isPalindrome[i][i] = true;//한자리
	for (int i = 1; i < n; i++) {//두자리
		if(A[i]==A[i+1]) isPalindrome[i][i + 1] = true;//두 수가 일치하면 팰린드롬
		else isPalindrome[i][i + 1] = false;
	}
	//팰린드롬 판단
	for (int i = 3; i <= n; i++) {//사이즈
		for (int j = 1; j <= n-i+1; j++) {//시작지점
			//가운데가 팰린드롬이고 양끝 숫자가 같다면
			if (isPalindrome[j + 1][j + i - 2] == true && A[j] == A[j + i - 1]) isPalindrome[j][j + i - 1] = true;
			else isPalindrome[j][j + i - 1] = false;
		}
	}
}
//질문
void Question() {
	cin >> m;
	for (int i = 0; i < m; i++) {
		int s,e;
		cin >> s >> e;
		cout << isPalindrome[s][e] << "\n";
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	JudgePalindrome();//팰린드롬 판단
	Question();//질문
	return 0;
}
