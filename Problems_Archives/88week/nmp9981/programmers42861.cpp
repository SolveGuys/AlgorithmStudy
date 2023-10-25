#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int maxi = 101;
vector<pair<int,pair<int,int>>> graph;//그래프
int root[maxi];//각 노드의 루트노드

//초기화
void Init(int n){
    for(int i=0;i<n;i++) root[i] = i;
}
//그래프 세팅
void GraphSetting(vector<vector<int>> costs){
    int costSize = costs.size();
    for(int i=0;i<costSize;i++) graph.push_back({costs[i][2],{costs[i][0],costs[i][1]}});
    
    sort(graph.begin(),graph.end());//비용순 정렬
}
//루트노드
int Find(int a){
    if(root[a]==a) return a;
    return root[a] = Find(root[a]);
}
//합체
void Merge(int a,int b){
    if(a<b) root[b] = a;
    else root[a] = b;
}
//섬 연결
int Connect(int n){
    int node = 0;
    int total = 0;
    int graphSize = graph.size();
    for(int i=0;i<graphSize;i++){
        int x = graph[i].second.first;
        int y = graph[i].second.second;
        int co = graph[i].first;
        
        int rx = Find(x);
        int ry = Find(y);
        if(rx!=ry){//루트노드가 다르면 연결
            Merge(rx,ry);//그래프 합체
            total+=co;
            node++;
        }
        if(node==n-1) break;//모두 연결
    }
    return total;
}
int solution(int n, vector<vector<int>> costs) {
    Init(n);//초기화
    GraphSetting(costs);//비용
    return Connect(n);//섬 연결
}
