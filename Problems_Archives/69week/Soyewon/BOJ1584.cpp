// BOJ 1584 - 게임

/*
죽음의 구역 - 들어갈 수 없음
위험한 구역 - 생명 -1씩 소모
안전한 구역

(0,0)에서 출발, 상하좌우 이동 가능

death + dangerous = death
dangerous + safe = dangerous
dangerous + dangerous = dangerous
death + safe = death
>> 데미지가 심한 구역 효과 적용

구역에 들어갈 때만 영향(이동 시에만)

=> 데미지에 따라 결과가 달라지므로 deque 
*/

#include <iostream>
#include <queue>

using namespace std;

int map[505][501]; 
bool visit[501][501]; // 방문한 지점 체크

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1}; // 상하좌우 이동

struct pos{ // 좌표와 누적 데미지를 저장

    int x, y, damage;

};

int main(){

    int n;
    int m;

    cin >> n;

    for (int i = 0; i < n; ++i){
    
        int x1, x2, y1, y2; // 위험지역 모서리값 입력받기
        cin >> x1 >> y1 >> x2 >> y2;

        for (int i = min(x1, x2); i <= max(x1, x2); i++)
            for (int j = min(y1, y2); j <= max(y1, y2); j++)
                map[i][j] = 1; // 위험지역 dmg 1 설정
    }

    cin >> m; // 죽음지역

    for (int i = 0; i < m; ++i){
    
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int i = min(x1, x2); i <= max(x1, x2); i++)
            for (int j = min(y1, y2); j <= max(y1, y2); j++)
                visit[i][j] = true;

    }

    bool check = true;
    deque<pos> dq;
    dq.push_front({0, 0, 0});

    while (!dq.empty())
    {
        auto p = dq.front();
        dq.pop_front();

        if (p.x == 500 && p.y == 500) // 도착했을 때
        {
            cout << p.damage;
            check = false;
            break;
        }

        for (int i = 0; i < 4; ++i) // 상하좌우 이동
        {
            int move_x = p.x + dx[i];
            int move_y = p.y + dy[i];

            // map을 벗어나거나, 방문한 지점일 경우 
            if (0 > move_x || move_x > 500 || 0 > move_y || move_y > 500 || visit[move_x][move_y])
                continue;

            else
            {
                visit[move_x][move_y] = true; // 방문처리

                // 이동한 지역이 위험지역일 경우
                if (map[move_x][move_y] == 1)
                {
                    dq.push_back({move_x, move_y, p.damage + 1}); // 데미지가 있으므로 deque 뒤에 넣기 (가중치 반영)
                }
                // 이동한 지역이 안전지역일 경우
                else
                {
                    dq.push_front({move_x, move_y, p.damage}); // 데미지가 없으므로 deque 앞에 넣기
                }
            }
        }
    }

    if(check){
        cout << "-1"; // 모두 다 죽음지역이서 갈 수 없는 경우
    }
}
