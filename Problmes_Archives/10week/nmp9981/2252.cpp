#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n,m;
const int maxi = 32001;//최대 그래프 크기
vector<int> height[maxi];//그래프
int node[maxi];//진입노드

//입력
void input(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        height[a].push_back(b);//a보다 b가 후순위
        node[b]++;//진입노드 증가
    }
}

//줄세우기
void set_line(){
    //진입노드가 0인것을 큐에 넣기
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(node[i]==0){
            q.push(i);
        }
    }
    //위상정렬
    while(!q.empty()){
        int x = q.front();//현재 노드
        q.pop();
        cout<<x<<" ";//출력
        
        //다음지점
        for(int i=0;i<height[x].size();i++){
            int next = height[x][i];//다음지점
            node[next]--;//간선제거
            if(node[next]==0){//새로운 루트노드 탄생
                q.push(next);//다음지점 넣기
            }
        }
    }
}

int main(){
    input();//입력
    set_line();//줄세우기
    return 0;
}
