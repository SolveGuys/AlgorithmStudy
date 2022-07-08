#include <bits/stdc++.h>

using namespace std;

int k;
char arr[30];
bool visited[30];
vector<string> s;

void solve(int idx,string num)
{
	if(idx==k+1)
	{
		s.push_back(num);
		return;
	}
	
	for(int i=0;i<10;i++)
	{
		if(visited[i]) continue;
		if(idx==0)
		{
			visited[i]=true;
			solve(idx+1,num+to_string(i));
			visited[i]=false;
		}
		else if(arr[idx-1]=='<' && num[idx-1]<i+'0')
		{
			visited[i]=true;
			solve(idx+1,num+to_string(i));
			visited[i]=false;
		}
		else if(arr[idx-1]=='>' && num[idx-1]>i+'0')
		{
			visited[i]=true;
			solve(idx+1,num+to_string(i));
			visited[i]=false;
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>k;
	
	for(int i=0;i<k;i++)
	{
		cin>>arr[i];
	}
	
	solve(0,"");
	
	sort(s.begin(),s.end());
	
	cout<<s[s.size()-1]<<"\n"<<s[0];
	
	
	return 0;
}
