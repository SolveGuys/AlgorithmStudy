#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int>> v;
int answer;
int a,b;


priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		v.push_back({a,b});
	}
	sort(v.begin(),v.end());
	
	for(int i=0;i<n;i++)
	{
		pq.push(v[i].second);
		if(pq.size()>v[i].first)
		{
			pq.pop();
		}
	}
	while(pq.size())
	{
		answer+=pq.top();pq.pop();
	}
	cout<<answer;
	
	
	return 0;
}
