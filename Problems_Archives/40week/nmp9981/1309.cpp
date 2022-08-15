#include <iostream>
#include <cstring>
using namespace std;

int n;
const int maxi = 100001;
const int mod = 9901;
int zoo[maxi][3];//사자를 가두는 경우의 수

//입력
void input() {
	cin >> n;
}

//사자를 가두는 경우의 수
void Lion() {
	//초기값
	zoo[1][0] = 1;//선택x
	zoo[1][1] = 1;//왼쪽 선택
	zoo[1][2] = 1;//오른쪽 선택

	//점화식
	for (int i = 2; i <= n; i++) {
		zoo[i][0] = (zoo[i - 1][0] + zoo[i - 1][1] + zoo[i - 1][2])%mod;//선택X
		zoo[i][1] = (zoo[i - 1][0] + zoo[i - 1][2])%mod;//왼쪽 선택
		zoo[i][2] = (zoo[i - 1][0] + zoo[i - 1][1])%mod;//오른쪽 선택
	}
	//출력
	cout << (zoo[n][0] + zoo[n][1] + zoo[n][2])%mod;
}
int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	Lion();//사자를 가두는 경우의 수
    return 0;
}
