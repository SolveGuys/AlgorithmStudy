#include <vector>
#include <cstring>
using namespace std;

const int maxi = 501;
int route[maxi][maxi][2];//위치, 방향
int MOD = 20170805;

//경로 찾기
int Navigation(int m,int n,vector<vector<int>> world){
    //끝 위치(아래)
    for(int i=0;i<m;i++){
        if(world[i][0]==1) break;
        else route[i][0][0]=1;
    }
    //끝 위치(위)
    for(int j=0;j<n;j++){
        if(world[0][j]==1) break;
        else route[0][j][1]=1;
    }
    //경우의 수
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(world[i][j]!=1){
                //아래쪽 방향 : 0
                if(world[i-1][j]==2) route[i][j][0] = route[i-1][j][0];
                else route[i][j][0] = (route[i-1][j][0]+route[i-1][j][1])%MOD;
                //오른쪽 방향 : 1
                if(world[i][j-1]==2) route[i][j][1] = route[i][j-1][1];
                else route[i][j][1] = (route[i][j-1][1]+route[i][j-1][0])%MOD;
            }
        }
    }
    return (route[m-1][n-1][0]+route[m-1][n-1][1])%MOD;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    memset(route,0,sizeof(route));//초기화
    int answer = Navigation(m,n,city_map);//경로 찾기
    return answer;
}
