#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int V,E,M,S,x,y,res;
const int maxi = 10011;
const int inf = 1e+9;
vector<pair<int,int>> graph[maxi];
bool star[maxi];//스타벅스
bool mac[maxi];//맥도날드
int dist[maxi];//스타벅스 더미 노드에서부터의 거리
int add_dist[maxi];//맥도날드 더미 노드에서부터의 거리

//다익스트라
void dijk(int start){
    //거리 초기화
    for(int i=1;i<=maxi;i++){
        dist[i] = inf;
    }
    //처음값 저장
    priority_queue<pair<int,int>> pq;//거리, 정점
    dist[start] = 0;
    pq.push({0,start});
    
    while(!pq.empty()){
        int pre_dist = -pq.top().first;//거리
        int p = pq.top().second;//정점
        pq.pop();
        
        //이전 거리보다 더 크다면
        if(dist[p] < pre_dist){
            continue;//갱신할 필요 없다
        }
        
        //이웃탐색
        for(int i=0;i<graph[p].size();i++){
            int next_node = graph[p][i].first;//다음지점
            int next_dist = pre_dist + graph[p][i].second;//다음 지점까지의 거리
            
            //더 작은 거리가 나오는가?
            if(dist[next_node]>next_dist){
                dist[next_node] = next_dist;
                pq.push({-next_dist,next_node});
            }
        }
    }
}

//입력
void input(){
    cin.tie(0);
    //그래프 입력
    cin>>V>>E;
    for(int i=1;i<=E;i++){
        int a,b,d;
        cin>>a>>b>>d;
        graph[a].push_back({b,d});//양방향 그래프
        graph[b].push_back({a,d});
    }
    //맥도날드
    cin>>M>>x;
    for(int i=0;i<M;i++){
        int num;
        cin>>num;
        mac[num] = true;
        graph[0].push_back({num,0});//더미노드
    }
    dijk(0);//0번에서 시작
    for(int i=1;i<=V;i++){
        add_dist[i] = dist[i];
    }
    //스타벅스
    cin>>S>>y;
    for(int i=0;i<S;i++){
        int num;
        cin>>num;
        mac[num] = true;
        graph[V+1].push_back({num,0});//더미노드
    }
    dijk(V+1);//V+1번에서 시작
    
    //맥세권, 스세권
    res = 2*inf;
    for(int i=1;i<=V;i++){
        //스타벅스나 맥도날드이면
        if(star[i]==true || mac[i]==true){
            continue;
        }
        if(add_dist[i]<=x && dist[i]<=y){
            res = min(res,add_dist[i]+dist[i]);
        }
    }
}
int main(){
    input();//입력
    //출력
    if(res>=2*inf){
        cout<<-1;
    }else{
        cout<<res;
    }
    return 0;
}
