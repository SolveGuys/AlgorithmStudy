#include <iostream>
#include <cstring>
using namespace std;

int n,m;
const int maxi=1001;
int name[maxi];//i번째 이름의 길이
int dp[maxi][maxi];//i번째 이름,길이 j까지

//입력
void input(){
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>name[i];
	memset(dp,-1,sizeof(dp));//초기화
}
//재귀
int dfs(int idx,int len){//len은 뒤에 빈칸 포함
	//마지막줄
	if(idx>=n) return 0;
	//이미 값이 있으면
	if(dp[idx][len]!=-1) return dp[idx][len];
	
	//줄바꿈
	dp[idx][len] = (m-len+1)*(m-len+1)+dfs(idx+1,name[idx]+1);
	//같은줄
	if(len+name[idx]<=m){
		dp[idx][len] = min(dp[idx][len],dfs(idx+1,len+name[idx]+1));
	}
	return dp[idx][len];
}
int main(){
	input();//입력
	cout<<dfs(0,0);
	return 0;
}
