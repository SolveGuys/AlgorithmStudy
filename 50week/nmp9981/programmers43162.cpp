#include <string>
#include <vector>

using namespace std;
const int maxi = 201;
bool visit[maxi];//노드 방문 여부

//네트워크
void network(int i,vector<vector<int>> computers){
    visit[i] = true;//방문체크
    //다음 지점
    for(int k=0;k<computers[i].size();k++){
        if(i==k) continue;//같은 지점
        int next = computers[i][k];//다음 노드 연결여부
        if(next==1 && visit[k]==false) network(k,computers);//연결되어 있고 미방문
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<n;i++){//시작지점
        if(visit[i]==false){//미방문인 지점
            network(i,computers);//네트워크
            answer++;//덩어리 개수 추가
        }
    }
    return answer;
}
