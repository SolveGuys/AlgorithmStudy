#include <vector>
using namespace std;

const int maxi = 501;
int road[maxi][maxi][2];
int MOD = 20170805;

//초기화
void init(int m,int n,vector<vector<int>> &world){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            road[i][j][0] = 0;//아래쪽
            road[i][j][1] = 0;//오른쪽
        }
    }
    //첫 열
    for(int i=0;i<m;i++){
        if(world[i][0]==1) break;
        else road[i][0][0] = 1;//아래쪽
    }
    //첫 행
    for(int j=0;j<n;j++){
        if(world[0][j]==1) break;
        else road[0][j][1] = 1;//오른쪽
    }
}
//주행
int Race(int m,int n,vector<vector<int>> &world){
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(world[i][j]==1) continue;
            //아래쪽
            if(world[i-1][j]==2) road[i][j][0] = road[i-1][j][0];
            else road[i][j][0] = (road[i-1][j][0]+road[i-1][j][1])%MOD;
            
            //오른쪽
            if(world[i][j-1]==2) road[i][j][1] = road[i][j-1][1];
            else road[i][j][1] = (road[i][j-1][1]+road[i][j-1][0])%MOD;
        }
    }
    return (road[m-1][n-1][0]+road[m-1][n-1][1])%MOD;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    init(m,n,city_map);//초기화
    return Race(m,n,city_map);//주행
}
