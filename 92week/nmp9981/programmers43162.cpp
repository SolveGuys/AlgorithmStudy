#include <string>
#include <vector>
#include <queue>
using namespace std;

const int maxi = 201;
bool visit[maxi];//방문 여부

//bfs
int bfs(int st,int n,vector<vector<int>> computers){
    visit[st] = true;
    queue<int> q;
    q.push(st);
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        for(int k=0;k<n;k++){//다음 노드
            if(computers[x][k]==0) continue;//연결 안됨
            if(visit[k]) continue;//이미 방문
            if(k==x) continue;//같은 노드
            
            visit[k] = true;
            q.push(k);
        }
    }
    return 1;
}
//네트워크 개수 세기
int NetworkCount(int n, vector<vector<int>> computers){
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(!visit[i]) cnt+=bfs(i,n,computers); 
    }
    return cnt;
}
int solution(int n, vector<vector<int>> computers) {
    return NetworkCount(n,computers);//네트워크 개수 세기
}
