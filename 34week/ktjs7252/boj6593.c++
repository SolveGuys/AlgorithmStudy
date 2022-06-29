#include <bits/stdc++.h>

using namespace std;

char arr[31][31][31];
int visited[31][31][31];
int l,r,c;

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

int main()
{
	while(1)
	{
		int z,x,y;
		cin>>l>>r>>c;
		if(l==0 && r==0 && c==0) break;
		
		memset(visited,0,sizeof(visited));
		
		for(int k=0;k<l;k++)
		{
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					cin>>arr[k][i][j];
					if(arr[k][i][j]=='S')
					{
						z=k,x=i,y=j;
					}
				}
			}
		}
		
		queue<pair<int,pair<int,int>>> q;
		q.push({z,{x,y}});
		visited[z][x][y]=1;
		int sign=0;
		
		while(q.size())
		{
			int z=q.front().first;
			int x=q.front().second.first;
			int y=q.front().second.second;
			q.pop();
			
			if(arr[z][x][y]=='E')
			{
				printf("Escaped in %d minute(s).\n",visited[z][x][y]-1);
				sign=1;
				break;
			}
			
			if(z+1<l && arr[z+1][x][y]!='#' && visited[z+1][x][y]==0)
			{
				q.push({z+1,{x,y}});
				visited[z+1][x][y]=visited[z][x][y]+1;
			}
			if(z-1>=0 && arr[z-1][x][y]!='#' && visited[z-1][x][y]==0)
			{
				q.push({z-1,{x,y}});
				visited[z-1][x][y]=visited[z][x][y]+1;
			}
			
			for(int i=0;i<4;i++)
			{
				int nx=x+dx[i];
				int ny=y+dy[i];
				
				if(nx>=0 && ny>=0 && nx<r && ny<c && visited[z][nx][ny]==0 && arr[z][nx][ny]!='#')
				{
					q.push({z,{nx,ny}});
					visited[z][nx][ny]=visited[z][x][y]+1;
				}
			}
		}
		if(sign==0)
		{
			cout<<"Trapped!\n";
		}
	}
	
	
	
	
	return 0;
}
