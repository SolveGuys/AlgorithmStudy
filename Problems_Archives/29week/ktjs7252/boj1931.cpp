#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int>> v;
int answer;
int a,b;

int main()
{
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		v.push_back({b,a});
	}
	
	sort(v.begin(),v.end());

	int here=v[0].first;
	answer=1;

	for(int i=1;i<n;i++)
	{
		if(v[i].second>=here)
		{
			here=v[i].first;
			answer++;
		}
	}
	cout<<answer;
	return 0;
}
