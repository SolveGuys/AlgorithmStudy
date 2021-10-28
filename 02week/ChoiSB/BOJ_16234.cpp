#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

struct Node {
    int population{};
    int ID{-1};
};
struct Pos {
    Pos() {}
    Pos(int _r, int _c) : r{ _r }, c{ _c } {}
    int r{};
    int c{};
};
using Level = vector<vector<Node>>;
const int dr[4] = { 1, -1, 0, 0 };
const int dc[4] = { 0, 0, 1, -1 };
queue<Pos> updated;
int BFS(Level& level, int id, Pos start, int N, int L, int R)
{
    int sum{};
    int cnt{};
    level[start.r][start.c].ID = id;
    cnt++;
    sum += level[start.r][start.c].population;
    queue<Pos> q;
    q.push(start);
    //cout << "start: "<<start.r << ", " << start.c << endl;
    while (!q.empty())
    {
        Pos cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            Pos next(cur.r + dr[i], cur.c + dc[i]);
            if (next.r < 0 || next.r >= N || next.c < 0 || next.c >= N || level[next.r][next.c].ID != -1) continue;

            const int diff = abs(level[cur.r][cur.c].population - level[next.r][next.c].population);

            if (L <= diff && diff <= R)
            {
                //cout << "add: " << next.r << ", " << next.c << endl;
                cnt++;
                sum += level[next.r][next.c].population;
                level[next.r][next.c].ID = id;
                q.push({ next.r, next.c });
            }
        }
    }
    if (cnt == 1) {
        level[start.r][start.c].ID = -1;
        return -1;
    }

    int avg = sum / cnt;
    return avg;
}
void PrintAll(Level& level)
{
    cout << endl;
    for (auto& row : level)
    {
        for (Node& n : row)
            cout << n.population << " ";
        cout << endl;
    }
}
bool OneDay(Level& level, int N, int L, int R)
{
    // 국경 확인 및 이동인구 계산
    vector<int> avgs;
    while(!updated.empty())
    {
        Pos start = updated.front();
        updated.pop();        

        if (level[start.r][start.c].ID != -1) continue;
        int avg = BFS(level, avgs.size(), start, N, L, R);
        if(avg != -1) avgs.emplace_back(avg);
    }
    
    bool isMove = false;
    // 인구 이동 및 방문기록 초기화 
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            const int ID = level[i][j].ID;
            // 값의 변화가 있는 경우 true
            if (ID != -1 && level[i][j].population != avgs[ID])
            {
                updated.push({ i,j });
                level[i][j].population = avgs[ID];
                isMove = true;
            }
        }
    }    

    //PrintAll(level);
    // 방문기록 초기화 
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            level[i][j].ID = -1;
        }
    }

    return isMove;
}
int main()
{
    //입출력 성능향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N, L, R; // (1 ≤ N ≤ 50, 1 ≤ L ≤ R ≤ 100)
    cin >> N >> L >> R;
    Level level(N, vector<Node>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> level[i][j].population;
            updated.push({ i, j });
        }
    }
    int answer{};
    while (OneDay(level, N, L, R)) answer++;
    cout << answer;
    return 0;
}