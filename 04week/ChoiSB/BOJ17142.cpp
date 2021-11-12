#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
#define endl '\n'
using namespace std;
struct Virus {
    Virus(int _row, int _col) : row(_row), col(_col){}
    int row;
    int col;
    bool active{};
};
struct Move {
    Move(int _row, int _col, int _dep) : row(_row), col(_col), dep(_dep) {}
    int row;
    int col;
    int dep;
};

using Map = vector<vector<int>>;
constexpr int INF = 987'654'321;
constexpr int dr[4] = { 1,-1,0,0 };
constexpr int dc[4] = { 0,0,1,-1 };

void PrintMap(Map& map)
{
    for (auto& row : map)
    {
        for (int n : row)
        {
            if (n == INF)
                cout << setw(2)<<"*";
            else
                cout << setw(2) << n;
        }
        cout << endl;
    }
}
// 모두 감염됐는지 확인
bool Check(Map& map)
{
    for (auto& row : map)
        for (int n : row)
            if (n == 0) 
                return false;
    return true;
}
// map은 pass by value로 복사해옴
int BFS(Map map, vector<Virus>& viruses)
{
    if (Check(map)) return 0;

    int N = map.size();
    queue<Move> q;
    for (auto& virus : viruses)
    {
        if (virus.active)
        {
            q.push(Move(virus.row, virus.col, 0));
            map[virus.row][virus.col] = -1; // 활성화 바이러스 표시
        }
    }

    int maxDep{};
    while (!q.empty())
    {
        Move cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            Move next(cur.row + dr[i], cur.col + dc[i], cur.dep + 1);
            if (next.row < 0 || next.row >= N || next.col < 0 || next.col >= N) continue; // 범위를 넘어선 경우
            if (map[next.row][next.col] == 0 || map[next.row][next.col] == -2) // 인접 노드가 빈칸이거나 비활성 바이러스인 경우
            {
                // next가 바이러스인 경우는 maxDep을 기록하지 않음.
                if (map[next.row][next.col] != -2)
                    maxDep = next.dep;

                map[next.row][next.col] = next.dep;
                q.push(next);
            } 
        }
    }
    //PrintMap(map);
    //cout << endl;
    if (Check(map))
        return maxDep;
    else 
        return INF;
}

int BT(Map& map, vector<Virus>& viruses, size_t idx, int dep, int M)
{
    if (dep == M)
    {
        return BFS(map, viruses);
    }
    int retval{ INF };

    for (size_t i = idx; i < viruses.size(); ++i)
    {
        viruses[i].active = true;
        retval = min(retval, BT(map, viruses, i + 1, dep + 1, M));
        viruses[i].active = false;
    }
    return retval;
}
int main()
{
    //입출력 성능향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N, M; //N(4 ≤ N ≤ 50), M(1 ≤ M ≤ 10)
    cin >> N >> M;
    vector<Virus> viruses;
    Map map(N, vector<int>(N));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> map[i][j];
            if(map[i][j] == 1)
                map[i][j] = INF;

            else if (map[i][j] == 2)
            {
                map[i][j] = -2; // 비활성 바이러스는 -2.
                viruses.emplace_back(i, j);
            }
        }

    int answer = BT(map, viruses, 0, 0, M);
    if (answer == INF) answer = -1;
    cout << answer;

    return 0;
}