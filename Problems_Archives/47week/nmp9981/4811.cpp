#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

const int maxi = 31;
ll dp[maxi][maxi];//정상 i, 반개 j개일때 경우의 수

//초기화
void init() {
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < maxi; i++) dp[0][i] = 1;//모두 반쪽
	dp[1][0] = 1;//정상 알약 1개
}
//경우의 수
ll F(int x,int y) {
	if (dp[x][y] != 0) return dp[x][y];//이미 값이 있음

	if (x < 0 || x >= maxi || y < 0 || y >= maxi) return 0;//범위 검사
	return dp[x][y] = F(x-1,y+1)+F(x, y - 1);//정상을 선택하는 경우 + 반쪽을 선택하는 경우
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	init();//초기화
	int x;
	while(cin>>x){
		if (x == 0) break;//입력 종료
		cout << F(x-1,1)<<"\n";
	}
	return 0;
}
