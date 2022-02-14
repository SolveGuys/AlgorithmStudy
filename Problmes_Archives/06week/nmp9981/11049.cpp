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
const int maxi = 501;
const long long inf = 200000000000;
int n;
long long matrix[maxi][2];//각행렬의 크기
long long dp[maxi][maxi];//i~j까지의 결과

//입력
void input(){
	cin>>n;
	//초기화
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dp[i][j] = inf;
		}
	}
	//입력
	for(int i=0;i<n;i++){
		//각 행렬의 크기
		cin>>matrix[i][0]>>matrix[i][1];
		//초기값
		dp[i][i] = 0;
	}
}

//연산횟수
void matrix_multi(){
	//이웃한 2개의 연산결과
	for(int i=0;i<n-1;i++){
		dp[i][i+1] = matrix[i][0]*matrix[i][1]*matrix[i+1][1];
	}
	
	//점화식
	for(int size=2;size<n;size++){//크기
		for(int i=0;i<n-size;i++){//시작위치
			int j = i + size;//종료위치
			//i~j => i~k, k+1~j
			for(int k=i;k<j;k++){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+matrix[i][0]*matrix[k][1]*matrix[j][1]);
			}
		}
	}
	//처음부터 끝까지
	cout<<dp[0][n-1];
}
int main(){
    cin.tie(0);
    cout.tie(0);
    
   	input();//입력
    matrix_multi();//행렬의 곱셈 횟수
    
    return 0;
}
