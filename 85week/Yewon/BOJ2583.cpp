#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int board[100][100];
int N,M,K;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
queue<pair<int,int>>q;
int bfs(){
    int cnt=0; //빈 칸이 하나밖에 없는 영역일 경우 그대로 빠져나와버림
    while(!q.empty()){
      
        int x=q.front().second;
        int y=q.front().first;
        q.pop();
      
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
          
            if(nx<0||ny<0||nx>=N||ny>=M)continue;
            if(!board[ny][nx]){
                cnt++;
                board[ny][nx]=1;
                q.push({ny,nx});
            }
        }  
    }
    return cnt;
}
int main(){
    int x1,x2,y1,y2,cnt=0;
    int area[100];
  
    cin>>M>>N>>K;
  
    while(K--){
        cin>>x1>>y1>>x2>>y2;
        for(int i=y1;i<y2;i++)
            for(int j=x1;j<x2;j++)
                board[i][j]=1;
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(!board[i][j]){
                q.push({i,j});
                area[cnt++]=bfs();
                // 여기서 방금전에 area에 담긴 값이 0이면 1로 만들어 줌
                if(!area[cnt-1])area[cnt-1]=1;
            }
        }
    }
  
    sort(area,area+cnt);
    cout<<cnt<<"\n";
    for(int i=0;i<cnt;i++)
        cout<<area[i]<<" ";
}
