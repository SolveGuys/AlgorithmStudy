#include <iostream>
using namespace std;

class Tornado {
private:
    int n;
    int totalOut = 0;//밖으로 나간 모래의 양
    static const int maxi = 501;
    int Sand[maxi][maxi];//모래의 양
    //동남서북
    int dx[4] = { 0,1,0,-1 };
    int dy[4] = { 1,0,-1,0 };
    //흩날리는 방향
    int flutterDirX[4][10] = { {-1,1,-2,2,-1,1,-1,1,0,0},
                            {0,0,0,0,1,1,-1,-1,2,1},
                            {-1,1,-2,2,-1,1,-1,1,0,0},
                            {0,0,0,0,-1,-1,1,1,-2,-1} };
    int flutterDirY[4][10] = { {0,0,0,0,1,1,-1,-1,2,1},
                            {-1,1,-2,2,-1,1,-1,1,0,0},
                            {0,0,0,0,-1,-1,1,1,-2,-1},
                            {-1,1,-2,2,-1,1,-1,1,0,0} };
    //흩날리는 양
    int Amount[10] = { 7,7,2,2,10,10,1,1,5,55 };
public:
    Tornado() {};
    void input();//입력
    void Move();//이동
    int Flutter(int x, int y,int dir,int sand);//흩날리기
    void Output();//출력
};

//입력
void Tornado::input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> Sand[i][j];
    }
}
//흩날리기
int Tornado::Flutter(int x, int y,int dir,int sand) {
    int outSand = 0;//밖으로 나간 모래
    int restSand = sand;//남은 모래의 양
    
    if (restSand == 0) return 0;//남은 모래의 양이 0

    for (int i = 0; i < 10; i++) {
        int nx = x + flutterDirX[dir][i];//위치
        int ny = y + flutterDirY[dir][i];
        int amount = sand * Amount[i] / 100;//흩날리는 모래의 양

        if (i == 9) amount = restSand;//마지막 지점
        restSand -= amount;//남은 모래의 양

        if (nx < 0 || nx >= n || ny < 0 || ny >= n) outSand += amount;//범위 초과
        else Sand[nx][ny] += amount;
    }

    Sand[x][y] = 0;//기존 지점은 모래의 양이 0이된다.
    return outSand;
}
//이동
void Tornado::Move() {
    int x = n / 2; int y = n / 2;//시작 위치
    int moveAmount = 0;//이동량
    int dir = 2;//이동 방향(처음엔 서쪽)

    while (true) {
        //이동 거리 늘리기
        if (dir % 2 == 0) moveAmount++;
        //이동
        for (int k = 0; k < moveAmount; k++) {
            x = x + dx[dir];
            y = y + dy[dir];
            totalOut+=Flutter(x, y,dir,Sand[x][y]);//흩날리기
            
            if (x == 0 && y == 0) return;//종료
        }
        dir = (dir +3) % 4;//방향 전환(반시계)
    }
}
void Tornado::Output() {
    cout << totalOut;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Tornado tornado;
    tornado.input();//입력
    tornado.Move();//이동
    tornado.Output();//출력
    return 0;
}
