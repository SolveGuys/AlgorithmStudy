#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr[100001];
bool visited[500001];
int mid,hi,lo;
int answer;

bool check(int mid)
{
	memset(visited,0,sizeof(visited));
	queue<int> q;
	int tmp=0;
	
	for(int i=0;i<n;i++)
	{
		if(!visited[arr[i]])
		{
			q.push(arr[i]);
			visited[arr[i]]=1;
		}
		else
		{
			while(q.size())
			{
				int x=q.front();
				visited[x]=0;
				q.pop();
				if(x==arr[i])
				{
					break;
				}
			}
			q.push(arr[i]);
			visited[arr[i]]=1;
		}
		if(q.size()==mid)
		{
			tmp++;
			//q.clear();
			while(q.size())
			{
				int x=q.front();
				q.pop();
			}
			memset(visited,0,sizeof(visited));
		}
		if(tmp==m)
		{
			return true;
		}
	}
	return tmp>=m;
}
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
	
	lo=1;
	hi=n;
	
	while(lo<=hi)
	{
		mid=(lo+hi)/2;
		if(check(mid))
		{
			answer=mid;
			lo=mid+1;
		}
		else
		{
			hi=mid-1;
		}
	}
	
	cout<<answer;
	
	
	
	return 0;
}









