#include <bits/stdc++.h>

using namespace std;

int n,m,k;
int arr[101][101];
int tmp[101][101];
typedef struct mod{
	int r;
	int c;
	int s;
};
vector<mod> v;
int order[7];
int visited[7];
int answer=100000;

void rota(int r,int c,int s)
{
	for (int j = 1; j <= s; j++) {
		int fir = tmp[r - j][c - j];
		//왼쪽변
		for (int i = r - j + 1; i <= r + j; i++) {
			tmp[i - 1][c - j] = tmp[i][c - j];
		}
		//아래쪽변
		for (int i = c - j + 1; i <= c + j; i++) {
			tmp[r + j][i - 1] = tmp[r + j][i];
		}
		//오른쪽변
		for (int i = r + j - 1; i >= r - j; i--) {
			tmp[i + 1][c + j] = tmp[i][c + j];
		}
		//위쪽변
		for (int i = c + j - 1; i > c - j; i--) {
			tmp[r - j][i + 1] = tmp[r - j][i];
		}
		tmp[r - j][c - j + 1] = fir;
	}
} 

void go() //테스트 
{
	for(int i=1;i<=n;i++)  //복사 
	{
		for(int j=1;j<=m;j++)
		{
			tmp[i][j]=arr[i][j];
		}
	}
	int a,b,c,d;
	for(int i=0;i<k;i++)
	{
		int x=order[i];
		int r=v[x].r;
		int c=v[x].c;
		int s=v[x].s;
		rota(r,c,s);
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			sum+=tmp[i][j];
		}
		answer=min(answer,sum);
		sum=0;
	}
}

void solve(int siz) //순열 
{
	if(siz==v.size())
	{
		go();
		return;
	}
	
	for(int i=0;i<v.size();i++)
	{
		if(visited[i]==0)
		{
			order[siz]=i;
			visited[i]=1;
			solve(siz+1);
			visited[i]=0;
		}
	}
}

int main()
{
	int a,b,c;
	cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>arr[i][j];
		}
	}
	
	for(int i=0;i<k;i++)
	{
		cin>>a>>b>>c;
		v.push_back({a,b,c});
	}
	
	solve(0);
	cout<<answer;
	return 0;
}

