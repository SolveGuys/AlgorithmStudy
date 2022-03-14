#include <iostream>
using namespace std;

int n,m,res;
const int maxi = 501;
int board[maxi][maxi];//숫자판
bool visit[maxi][maxi];//방문체크

//축이동
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int d_shape[4][4][2] = {{{0,0},{1,0},{2,0},{1,1}},
                    {{0,0},{0,1},{1,1},{0,2}},
                    {{0,1},{1,0},{1,1},{2,1}},
                    {{0,1},{1,0},{1,1},{1,2}}};

//입력
void input(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>board[i][j];
    }
}

//블록 시도
int dfs(int cnt,int sum,int x,int y){
    //4칸이 모두 채워지면
    if(cnt==4){
        res = max(sum,res);
        return res;
    }
    
    //다음지점
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        //범위내에 드는가?
        if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
        //미방문이면
        if(visit[nx][ny]==false){
            visit[nx][ny] = true;
            int next = sum + board[nx][ny];//다음 값
            dfs(cnt+1,next,nx,ny);
            visit[nx][ny] = false;
        }
    }
    return 0;
}
//ㅏ 모양 탐색
void ah(int x,int y){
    for(int k=0;k<4;k++){
        int tot=0;
        for(int i=0;i<4;i++){//다음 지점
            int nx = x+d_shape[k][i][0];
            int ny = y+d_shape[k][i][1];
            //범위내에 드는가?
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            tot+=board[nx][ny];
        }
        res = max(res,tot);
    }
}
int main(){
    input();//입력
    //맵탐색
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visit[i][j] = true;//방문 체크
            dfs(1,board[i][j],i,j);//최댓값 갱신
            visit[i][j] = false;//체크 해제
            ah(i,j);//ㅏ 모양 탐색
        }
    }
    cout<<res;//출력
    return 0;
}
