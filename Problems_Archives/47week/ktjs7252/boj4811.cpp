#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp[31][31];

ll solve(int whole,int not_whole)
{
	if(whole==0 && not_whole==0)
	{
		return 1;
	}
	if(dp[whole][not_whole])
	{
		return dp[whole][not_whole];
	}
	ll &ret=dp[whole][not_whole];
	if(whole>0)
	{
		ret+=solve(whole-1,not_whole+1);
	}
	if(not_whole>0)
	{
		ret+=solve(whole,not_whole-1);
	}
	return ret;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while(1)
	{
		int a;
		cin>>a;
		if(a==0) break;
		cout<<solve(a,0)<<"\n";
	}
	

	return 0;
}

