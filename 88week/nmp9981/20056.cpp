#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//파이어볼 정보
struct FireBallInfo {
    int xpos, ypos, mass, speed, dir;
};
int n,m,k;
const int maxi = 51;
vector<FireBallInfo> world[maxi][maxi];//지도
vector<FireBallInfo> fireBall;//파이어볼
//8방 탐색
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

//입력
void input() {
    cin >>n>>m>>k;
    for (int i = 0; i < m; i++) {
        int x, y, m, d, s;
        cin >> x >> y >> m >> s >> d;
        fireBall.push_back({ x-1,y-1,m,s,d });
    }
}

//초기화
void Init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) world[i][j].clear();
    }
}
//이동
void Move() {
    int fireSize = fireBall.size();
    for (int i = 0; i < fireSize; i++) {
        int curX = fireBall[i].xpos;
        int curY = fireBall[i].ypos;
        int nextX = (curX+ dx[fireBall[i].dir] * (fireBall[i].speed%n)+n)%n;
        int nextY = (curY + dy[fireBall[i].dir] * (fireBall[i].speed%n)+n)%n;

        world[nextX][nextY].push_back(fireBall[i]);
    }
}
//병합
void Merge() {
    fireBall.clear();//초기화
    //맵 탐색
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (world[i][j].size() >= 2) {
                int totalMass = 0;
                int totalSpeed = 0;
                int oddCnt = 0;//홀수 개수
                int evenCnt = 0;//짝수 개수
                for (int k = 0; k < world[i][j].size(); k++) {
                    totalMass += world[i][j][k].mass;
                    totalSpeed += world[i][j][k].speed;
                    if (world[i][j][k].dir % 2 == 1) oddCnt++;//방향 홀수
                    else evenCnt++;
                }
                int newMass = totalMass / 5;
                int newSpeed = totalSpeed / world[i][j].size();
                if (newMass > 0) {//질량이 0보다 큼
                    if (oddCnt == 0 || evenCnt==0) {//모두 짝수 or 모두 홀수
                        for (int d = 0; d < 8; d += 2) {
                            fireBall.push_back({ i,j,newMass,newSpeed,d });
                        }
                    }
                    else {
                        for (int d = 1; d < 8; d += 2) {
                            fireBall.push_back({ i,j,newMass,newSpeed,d });
                        }
                    }
                }
            }else if(world[i][j].size()==1) fireBall.push_back({ i,j,world[i][j][0].mass,world[i][j][0].speed,world[i][j][0].dir });
        }
    }
}
//질량 합
void SumMass() {
    int total = 0;
    for (int i = 0; i < fireBall.size(); i++) total += fireBall[i].mass;
    cout << total;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    while (k--) {
        Init();//초기화
        Move();//이동
        Merge();//병합
    }
    SumMass();//질량 합
    return 0;
}
