#include <bits/stdc++.h> 
#define MAX_N 16

const int INF = 987654321;
using namespace std; 
int n, dp[MAX_N][1 << MAX_N], dist[MAX_N][MAX_N];

int tsp(int here, int visited){
    if(visited == (1 << n) - 1){ //끝까지 방문했다면 
        return dist[here][0] ? dist[here][0] : INF;
    }
    int &ret = dp[here][visited]; // 주소값을 쓰는 이유 : 변하는 값을 담기 위해  
    
    if(ret != -1) return ret; //값이 있다면 바로 return 
    ret = INF; //처음엔 무한대로 주고 min값으로 갱신 / 마지막에 INF가 살아있다면 볼 필요도 없음 
    
    for(int i = 0; i < n; i++){
        if(visited & (1 << i)) continue; //방문했다면 
        if(dist[here][i] == 0) continue; //방문하려는 것이 자기 자신이면 
        
        ret = min(ret, tsp(i, visited | (1 << i)) + dist[here][i]); //매번 거리들이 앃이게됨 
    }
    return ret; //최종적으로 끝까지 방문한 함수가 끝나고 return 되는 값이 이 전의 ret값에 쌓이게 되고 전부다 쌓이면 최솟값이 됨 
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> dist[i][j];
        }
    }
    
    memset(dp, -1, sizeof(dp));
    cout << tsp(0, 1) << '\n';
    
    
    return 0;
}
