#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

using namespace std;//이름공간 선언
int dp[101][10001];//i번째까지 j비용내 공간 최댓값
int cost[101];//가격
int memory[101];//저장공간
int n,m;
int sum_maxi = 0;//최대 가격

//입력
void input(){
	cin>>n>>m;
	//저장공간 입력
	for(int i=1;i<=n;i++){
		cin>>memory[i];
	}
	//가격 입력
	for(int i=1;i<=n;i++){
		cin>>cost[i];
		sum_maxi += cost[i];
	}
}

void app(){
	//점화식
	for(int i=1;i<=n;i++){
		for(int j=0;j<=sum_maxi;j++){
			//i번을 선택할 건가?
			if(j>=cost[i]){
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-cost[i]]+memory[i]);
			}else{
				//돈이 모자라 i번을 선택할 수 없음
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	//최소비용 구하기
	for(int j=0;j<=sum_maxi;j++){
		if(dp[n][j]>=m){//최소공간보다 크면 즉시 종료
			cout<<j;
			break;
		}
	}
}

int main(){
    cin.tie(0);
    cout.tie(0);
    
    input();//입력
    app();
    return 0;
}
