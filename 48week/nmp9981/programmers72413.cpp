#include <string>
#include <vector>

using namespace std;
const int maxi = 201;
const int inf = 100000001;
int dist[maxi][maxi];//i->j까지의 거리

//min
inline int min(int x,int y){
    return x>y?y:x;
}
//초기화
void init(int n, vector<vector<int>> fares){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = inf;
        }
    }
    //양방향
    for(int i=0;i<fares.size();i++){
        dist[fares[i][0]][fares[i][1]] = fares[i][2];
        dist[fares[i][1]][fares[i][0]] = fares[i][2];
    }
}
//플로이드
void floyd(int n){
    for(int k=1;k<=n;k++){//경유 지점
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
        }
    }
}
int solution(int n, int s,int a, int b, vector<vector<int>> fares) {
    int answer = inf;
    init(n,fares);//초기화
    floyd(n);//플로이드
    //최단 거리 구하기
    for(int t=1;t<=n;t++){//내리는 지점
        answer = min(answer,dist[s][t]+dist[t][a]+dist[t][b]);
    }
    return answer;
}
