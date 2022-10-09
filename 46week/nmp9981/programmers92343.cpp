#include <string>
#include <vector>
#include <set>

using namespace std;
const int maxi = 18;
int maxCntSheep = 0;//양의 최대 마릿수
vector<int> graph[maxi];//인접 리스트

//max
inline int max(int x,int y){
    return x>y?x:y;
}
//인접 리스트 만들기
void MakeGraph(vector<vector<int>> edges){
    for(int i=0;i<edges.size();i++){
        int from = edges[i][0];
        int to = edges[i][1];
        graph[from].push_back(to);
    }
}

//양 모으기(늑대 배열, 현재 노드, 갈 수 있는 노드 , 양의 마릿수 , 늑대 마릿수)
void GetSheep(vector<int> info, int idx,set<int> node,int cntSheep,int cntWolf){
    maxCntSheep = max(cntSheep,maxCntSheep);//갱신
    //양이 더 적거나 더 이상 갈 수 없다
    if(cntWolf>=cntSheep) return;
        
    node.erase(idx);//현재 노드 삭제
    //갈 수 있는 노드 넣기
    for(int i=0;i<graph[idx].size();i++){
        int nextNode = graph[idx][i];
        node.insert(nextNode);
    }
    //재귀 탐색
    for(auto s:node){
        //양인가? 늑대인가?
        if(info[s]==0) GetSheep(info,s,node,cntSheep+1,cntWolf);//양
        else if(info[s]==1) GetSheep(info,s,node,cntSheep,cntWolf+1);//늑대
    }
}
int solution(vector<int> info, vector<vector<int>> edges) {
    MakeGraph(edges);//그래프 만들기
    GetSheep(info,0,{0},1,0);//양 모으기
    int answer = maxCntSheep;
    return answer;
}
