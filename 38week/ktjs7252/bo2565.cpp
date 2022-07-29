#include <bits/stdc++.h>

using namespace std;

int n,lis,answer;
vector<pair<int,int>> v;
int dp[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//memset(dp,1,sizeof(dp));
	fill(dp,dp+101,1);
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		v.push_back({a,b});
	}
	
	sort(v.begin(),v.end());
	
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<i;j++)
		{
			if(v[i].second<v[j].second) continue;
			dp[i]=max(dp[i],dp[j]+1);
			
		}
		answer=max(answer,dp[i]);
	}
	
	cout<<n-answer;
	
	
	
	
	return 0;
}
