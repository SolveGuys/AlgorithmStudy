#include <iostream>
#include <algorithm>

using namespace std;

int n;
int t[16]={0,}; // 상담 기간
int p[16]={0,}; // 상담 이익
int dp[100]={0,}; // i번째 날부터 마지막 날까지의 최대 이익

void DP(){
	int next;
	for (int i=n; i>0; i--)
	{
		next = i + t[i];
		if (next > n+1) // 상담이 끝나면 퇴사일을 넘어갈 때
		{
			dp[i] = dp[i+1];
		}
		else // 상담이 끝나도 퇴사일을 넘기지 않아 이후 값과 비교를 통해 최대이익 산출
		{ 
			dp[i] = max(dp[i+1], dp[next] + p[i]);
		}
	}
}

int main() 
{
	cin >> n;
	for(int i=1; i<n+1; i++)
	{
    	cin >> t[i] >> p[i];
	}
	DP();
    
    cout << dp[1] << endl;
    return 0;
}
