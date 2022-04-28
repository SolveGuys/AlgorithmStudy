#include <bits/stdc++.h>

using namespace std;

typedef struct tmp{
	int imo;
	int time;
	int clip;
};
int s;
int answer;
int visited[1001][1001];

int main()
{
	cin>>s;
	
	queue<tmp> q;
	q.push({1,0,0});
	visited[1][0]=1;
	
	while(q.size())
	{
		tmp x=q.front();
		
		int a=x.imo;
		int b=x.time;
		int c=x.clip;
		q.pop();
		
		if(x.imo==s)
		{
			answer=x.time;
			break;
		}
		
		if(visited[a][a]==0 && a>0 && a<1001) //이모티콘 클립보드에 저장 
		{
			q.push({a,b+1,a});
			visited[a][a]=1;
		}
		if(visited[a+c][c]==0 && c>0 && a+c<1001)   //클립에서 이모티콘 붙이기 
		{
			q.push({a+c,b+1,c});
			visited[a+c][c]=1;
		}
		if(visited[a-1][c]==0 && a>1) //임티 한개 삭제 
		{
			q.push({a-1,b+1,c});
			visited[a-1][c]=1;
		}
		
	
	}
	
	cout<<answer;
	
	return 0;
}
	/*if(a>0) q.push({a,b+1,a});
		if(c>0) q.push({a+c,b+1,c});
		if(a>1) q.push({a-1,b+1,c}); */


