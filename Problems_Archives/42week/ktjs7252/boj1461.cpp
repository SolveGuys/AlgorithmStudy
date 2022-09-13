#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr[51];
vector<int> v1;
vector<int> v2;
int answer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	sort(arr,arr+n);
	
	for(int i=0;i<n;i++)
	{
		if(arr[i]<0)
		{
			v1.push_back(arr[i]);
		}
		if(arr[i]>0)
		{
			v2.push_back(arr[i]);
		}
	}
	
	if(v1.size() && v2.size())
	{
		if(abs(v1[0])>abs(v2[v2.size()-1])) //음수가 큼 
		{
			for(int i=v2.size()-1;i>=0;i-=m)
			{
				answer+=v2[i]*2;
			}
			answer+=abs(v1[0]);
			for(int i=m;i<v1.size();i+=m)
			{
				answer+=abs(v1[i])*2;
			}
		}
		else if(abs(v1[0])<abs(v2[v2.size()-1]))
		{
			for(int i=0;i<v1.size();i+=m)
			{
				answer+=abs(v1[i])*2;
			}
			answer+=v2[v2.size()-1];
			for(int i=v2.size()-1-m;i>=0;i-=m)
			{
				answer+=abs(v2[i])*2;
			}
		}
		else
		{
			answer+=abs(v1[0])*2;
			for(int i=m;i<v1.size();i+=m)
			{
				answer+=abs(v1[i])*2;
			}
			answer+=v2[v2.size()-1];
			for(int i=v2.size()-1-m;i>=0;i-=m)
			{
				answer+=v2[i]*2;
			}
		}
	}
	else if(v1.size())
	{
		answer+=abs(v1[0]);
		for(int i=m;i<v1.size();i+=m)
		{
			answer+=abs(v1[i])*2;
		}
	}
	else
	{
		answer+=v2[v2.size()-1];
		for(int i=v2.size()-1-m;i>=0;i-=m)
		{
			answer+=v2[i]*2;
		}
	}
	
	cout<<answer;
	
	
	return 0;
}
