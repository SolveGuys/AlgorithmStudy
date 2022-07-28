#include <bits/stdc++.h>

using namespace std;

int arr[11][11];
int visited[11][11];
int answer=987654321;
int paper[6];
void solve(int x,int y,int counting)
{
	
	if(y==10)
	{
		x++;
		y=0;
	}
	if(x==10)
	{
		answer=min(answer,counting);
		return;
	}
	
	if(arr[x][y]==0)
	{
		solve(x,y+1,counting);
	}
	else
	{
		for(int k=5;k>=1;k--)
		{
			if(x+k>10 || y+k>10 || paper[k]>=5) continue;
			
			int sign=0;
			
			for(int i=x;i<x+k;i++)
			{
				for(int j=y;j<y+k;j++)
				{
					if(arr[i][j]==0)
					{
						sign=1;
						break;
					}
				}
				if(sign==1) break;
			}
			
			if(sign==1) continue;
			
			for(int i=x;i<x+k;i++)
			{
				for(int j=y;j<y+k;j++)
				{
					arr[i][j]=0;
				}
			}
			paper[k]++;
			solve(x,y+1,counting+1);
			paper[k]--;
			
			for(int i=x;i<x+k;i++)
			{
				for(int j=y;j<y+k;j++)
				{
					arr[i][j]=1;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			cin>>arr[i][j];
		}
	}
	
	solve(0,0,0);
	
	if(answer==987654321)
	{
		cout<<-1;
	}
	else
	{
		cout<<answer;
	}
	
	
	
	return 0;
}
