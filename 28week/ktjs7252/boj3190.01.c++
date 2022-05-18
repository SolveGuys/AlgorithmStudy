#include <bits/stdc++.h>

using namespace std;

int n,k,l;
int arr[101][101];
int visited[101][101];
int _time,cur_time=-1;
char tmp;
int dir=1;
int x=0,y=0;
int length=1;

int main()
{
	cin>>n>>k;
	
	for(int i=0;i<k;i++)
	{
		int a,b;
		cin>>a>>b;
		arr[a-1][b-1]=1;
	}
	
	cin>>l;
	cin>>cur_time>>tmp;
	while(1)
	{
		if(_time==cur_time) //방향전환 
		{
			if(tmp=='D') dir++;
			else  dir--;
			
			if(dir==5) dir=1;
			else if(dir==0) dir=4;
			
			if(l>1)
			{
				cin>>cur_time>>tmp;
				l--;
			}
		}
		
		if(dir==1) y++; 
		else if(dir==2) x++;
		else if(dir==3) y--;
		else x--;
		
		_time++;
	
		if(arr[x][y]==1)
		{
			arr[x][y]=0;
			length++;
		}
			printf("현재위치 : %d %d     %d   %d\n",x,y,_time,length);
		if(x<0 || y<0 || x>=n || y>=n) //범위를 벗어나면 
		{
			printf("범위에 벗어남\n");
			cout<<_time;
			return 0;
		}
		
		if(visited[x][y]>0 &&visited[x][y]>=_time-length)
		{
			printf("몸에닿음\n");
			cout<<_time;
			return 0;
		 } 
		visited[x][y]=_time;
	}
	
	
	cout<<_time;
	
	return 0;
}



//반례
/*  
4
12
0 0
0 1
0 2
0 3
1 3
2 3
3 3
3 2
3 1
3 0
2 0
1 0
3
3 D
6 D
9 D
*/ 


/*
4
12
1 1
1 2
1 3
1 4
2 4
3 4
4 4
4 3
4 2
4 1
3 1
2 1
3
3 D
6 D
9 D
*/
