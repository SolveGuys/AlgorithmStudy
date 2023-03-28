#include <iostream>
using namespace std;

int n,m;
const int maxi = 501;
int world[maxi][maxi];//지도
bool visit[maxi][maxi];//방문 여부
int ans = 0;//정답

//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}
//min
inline int min(int x, int y) {
	return x < y ? x : y;
}
//입력
void input() {
	cin >> n>>m;
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++)cin>>world[i][j];
	}
}

//깊이 4인 지점까지 탐색
void depth4(int x,int y,int depth,int sum){
    if(depth==4){
        ans = max(ans,sum);
        return; 
    }
    //다음 지점
    for(int k=0;k<4;k++){
        int nx = x+dx[k];
        int ny = y+dy[k];
        if(nx<0 || nx>=n || ny<0 || ny>=m) continue;//범위 조건
        if(visit[nx][ny]) continue;//방문 여부
        visit[nx][ny] = true;
        depth4(nx,ny,depth+1,sum+world[nx][ny]);
        visit[nx][ny] = false;
    }
}
//테트로미노
void tetromino(){
    for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++) depth4(i,j,0,0);//시작 지점
	}
}
//ㅏ 
int bfs(int x,int y){
    int cnt = 0;//가능한 개수
    int sumAh = world[x][y];
    int minAh = 10000;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0 || nx>=n || ny<0 || ny>=m) continue;//범위 조건
        cnt++;
        sumAh+=world[nx][ny];
        minAh = min(minAh,world[nx][ny]);
    }
    
    if(cnt==3) return sumAh;
    else if(cnt==4) return sumAh-minAh;
    return 0;
}
//ㅏ 모양
void Ah(){
    for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++) ans = max(ans,bfs(i,j));//ㅏ 
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	tetromino();//테트로미노
	Ah();//ㅏ모양
	cout<<ans;//정답
	return 0;
}
