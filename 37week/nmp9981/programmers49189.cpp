#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
const int maxi = 20001;
vector<int> graph[maxi];//그래프
int visit[maxi];//방문 거리
int maxDist = 0;//최대 거리

//최댓값
inline int max(int x,int y){
    return x>y?x:y;
}

//그래프 세팅
void GraphSet(vector<vector<int>> edge){
    memset(visit,-1,sizeof(visit));//초기화
    for(int i=0;i<edge.size();i++){
        int from = edge[i][0];int to = edge[i][1];//양방향 간선
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
}

//탐색
void bfs(){
    queue<int> q;
    q.push(1);//1번부터
    visit[1] = 0;//방문 체크
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int i=0;i<graph[node].size();i++){
            //방문여부
            if(visit[graph[node][i]]!=-1) continue;
            
            visit[graph[node][i]] = visit[node]+1;//거리 증가
            maxDist = max(maxDist,visit[graph[node][i]]);//최대 거리 갱신
            q.push(graph[node][i]);
        }
    }
}

//최대 거리에 있는 노드 개수 세기
int CountNode(int n){
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(visit[i]==maxDist) cnt++;
    }
    return cnt;
}

int solution(int n, vector<vector<int>> edge) {
    GraphSet(edge);//그래프 세팅
    bfs();//탐색
    return CountNode(n);//최대 거리에 있는 노드 개수 세기
}
