#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n,m,total,max_h;
const int maxi = 51;
int maps[maxi][maxi];//지도
bool visit[maxi][maxi];//방문여부
//축이동
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
queue<pair<int,pair<int,int>>> q;//높이, 좌표

//입력
void input(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d",&maps[i][j]);
            max_h = max(maps[i][j],max_h);//최대높이 구하기
        }
    }
}

//bfs탐색
int bfs(int wx,int wy,int depth){
    int water = 1;//채우는 물의 양
    queue<pair<int,int>> q;
    q.push({wx,wy});
    bool flag = true;//수영장이 형성되는가?
    
    //큐가 비지 않는 동안 탐색
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        //다음지점 탐색
        for(int k=0;k<4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            //범위를 벗어남
            if(nx<0 || nx>=n || ny<0 || ny>=m){
                flag = false;
                continue;
            }
            //미방문
            if(visit[nx][ny]==false && maps[nx][ny]<=depth){
                q.push({nx,ny});
                visit[nx][ny] = true;//방문체크
                water++;//물의 양 증가
            }
        }
    }
    //수영장을 이루는가?
    if(flag==true){
        return water;
    }
    return 0;//수영장을 이루지 못함
}

//수영장 풀 채우기
void pool(){
    for(int h=1;h<max_h;h++){//높이 1부터 차례대로 채운다.
        memset(visit,false,sizeof(visit));//방문기록 초기화
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //미방문이고 높이 h이하
                if(visit[i][j]==false && maps[i][j]<=h){
                    visit[i][j] = true;//방문체크
                    total+=bfs(i,j,h);//좌표 높이
                }
            }
        }
    }
    cout<<total;//출력
}

int main(){
    input();//입력
    pool();//수영장 풀
    return 0;
}
