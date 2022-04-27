#include <bits/stdc++.h>

using namespace std;

int n;
int arr[10001];
int dp[10001];
int answer;

int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			dp[i]=max(dp[i],dp[i-j]+arr[j]);
		}
	}
	
	printf("%d",dp[n]);
	
	
	return 0;
}
