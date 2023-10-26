#include <iostream>
#include <vector>
using namespace std;

struct RobotPos {//로봇 정보
    int xpos, ypos,dir;
};

int A,B,n,m;
const int maxi = 101;
int world[maxi][maxi];//지도
vector<RobotPos> Robot;//로봇
//동남서북
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };

//방향 변환
int ChangeDir(char d) {
    if (d == 'E') return 0;
    else if (d == 'S') return 1;
    else if (d == 'W') return 2;
    return 3;
}
//입력
void input() {
    cin >> A>>B;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, y; char d;
        cin >> x >> y >> d;
        int changeDir = ChangeDir(d);//방향 변환
        Robot.push_back({ y-1,x-1,changeDir });
        world[y - 1][x - 1] = i+1;//로봇이 있음
    }
}

//명령 실행
void CommandPlay() {
    for (int k = 0; k < m; k++) {
        int num; char dir; int re;
        cin >> num >> dir >> re;
        num--;
        
        //실행할 로봇 정보
        int x = Robot[num].xpos;
        int y = Robot[num].ypos;
        int curDir = Robot[num].dir;

        if (dir == 'L') {//왼쪽
            re = re % 4;
            Robot[num].dir = (curDir -re+8)%4;
        }
        else if (dir == 'R') {//오른쪽
            re = re % 4;
            Robot[num].dir = (curDir + re)%4;
        }
        else if (dir == 'F') {//앞
            world[x][y] = 0;
            while (re--) {
                x += dx[curDir];
                y += dy[curDir];

                //벽과 충돌
                if (x < 0 || x >= B || y < 0 || y >= A) {
                    num++;
                    cout << "Robot "<<num<<" crashes into the wall";
                    return;
                }
                //로봇과 충돌
                if (world[x][y] > 0) {
                    num++;
                    cout << "Robot "<<num<<" crashes into robot "<<world[x][y];
                    return;
                }
            }
            //위치 갱신
            Robot[num].xpos = x;
            Robot[num].ypos = y;
            world[x][y] = num + 1;
        }
        //cout << x << " " << y<<" "<<Robot[num].dir << "\n";
    }
    cout << "OK";//이상 없음
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    CommandPlay();//명령 실행
    return 0;
}
