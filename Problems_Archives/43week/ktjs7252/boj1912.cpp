#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100001];
int dp[100001];
int answer;
int sum;

int main()
{
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	dp[0]=arr[0];
	sum=arr[0];
	for(int i=1;i<n;i++)
	{
		if(sum<0)
		{
			sum=0;
		}
		sum+=arr[i];
		if(sum>dp[i-1])
		{
			dp[i]=sum;
		}
		else
		{
			dp[i]=dp[i-1];
		}
	}
	answer=dp[0];
	for(int i=1;i<n;i++)
	{
		answer=max(answer,dp[i]);
	}
	
	
	
	cout<<answer;
	
	
	
	return 0;
}
