#include <stdio.h>
#include <queue>
using namespace std;
struct CLEAN { //simulation 문제로 규칙에 따라 로봇을 움직이고, 이때 로봇이 청소한 공간을 ret 로 출력.
    int y, x, dir;
};
int n, m;
int map[50][50];
CLEAN robot;
const int dy[] = { -1, 0, +1, 0 };
const int dx[] = { 0, +1, 0, -1 };
int main()
{
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &robot.y, &robot.x, &robot.dir);
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            scanf("%d", &map[y][x]);
        }
    }
    queue<CLEAN> q;
    q.push(robot);
    int ret = 0; //청소 구역 갯수 
    while (!q.empty()) {
        CLEAN cur = q.front();
        q.pop();
        if (map[cur.y][cur.x] == 0) { //빈칸인 경우 청소
            map[cur.y][cur.x] = 2;
            ++ret;}
            for (int dir = 0; dir < 4; ++dir) { //현재 칸의 주변 4칸중 청소되지 않은 빈칸이 있는 경우
                CLEAN temp; //temp next 구조체 생성
                temp.dir = (cur.dir + 3 - dir) % 4;
                temp.y = cur.y + dy[temp.dir];
                temp.x = cur.x + dx[temp.dir];
                if (temp.y < 0 || temp.y >= n || temp.x < 0 || temp.x >= m //맵 밖이거나, 청소가 되었거나 벽
                || map[temp.y][temp.x] != 0) {
                    continue;  // dir ++ 네 방향 따지기 위함
                    }
                q.push(temp); //q.push 동작을 통해 for문 내의 네 방향에서 가장 먼저 청소할 수 있는 구역을 queue에 삽입.
                break;
            }
            if (q.empty()) { //현재 칸의 주변 4칸 중 청소되지 않은 빈칸이 없는 경우
                CLEAN temp; // temp next 구조체 생성
                temp.dir = cur.dir;
                temp.y = cur.y + dy[(temp.dir + 2) % 4]; //한칸 후진 북 -> 남
                temp.x = cur.x + dx[(temp.dir + 2) % 4];
                if (temp.y < 0 || temp.y >= n || temp.x < 0 || temp.x >= m || map[temp.y][temp.x] == 1) { // 맵 밖이거나, 청소가 되었거나 벽
                    break;
                }
                q.push(temp);
            }
    }
        printf("\n%d\n", ret);
        return 0;
}
