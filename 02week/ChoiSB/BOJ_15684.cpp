#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

const int INF = 1'000;
int N, M, H; // (2 ≤ N ≤ 10, 1 ≤ H ≤ 30, 0 ≤ M ≤ (N-1)×H)
vector<vector<int>> ladder;

int GetEnd(int c)
{
    for (int i = 1; i < H + 1; ++i)
    {
        if (ladder[i][c] == 1)
            c++;
        else if (ladder[i][c - 1] == 1)
            c--;
    }
    return c;
}
bool Check()
{
    for (int i = 1; i < N + 1; ++i)
    {
        if (i != GetEnd(i)) return false;
    }
    return true;
}
int BT(int dep, int idx, int targetDep)
{

    if (dep == targetDep)
    {
        if (Check()) return dep;
        else return -1;
    }

    for (int i = 0; i < idx; ++i)
    {
        const int r = i / (N - 1) + 1;
        const int c = i % (N - 1) + 1;

        // 가로선을 오른쪽으로 연결 후 백트레킹 탐색
        // c가 N보다 작고, c-1, c, c+1세로 r높이에 다른 가로선이 없는 경우 
        if (ladder[r][c] == 0 && ladder[r][c-1] == 0 && ladder[r][c+1] == 0)
        {
            // 연결
            ladder[r][c] = 1;

            // 탐색
            int retval = BT(dep + 1, i, targetDep);
            if (retval != -1) return retval; // 탐색 성공

            // 연결 해제
            ladder[r][c] = 0;
        }
    }
    return -1;
}

int main()
{
    //입출력 성능향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N >> M >> H;
    ladder.resize(H + 1);
    for_each(ladder.begin(), ladder.end(), [](vector<int>& row) {
        row.resize(N + 2, 0); });

    while (M--)
    {
        int a, b; // a: r , b: c
        cin >> a >> b;
        ladder[a][b] = 1;
    }
    const int maxIdx = (N - 1) * H;

    int answer{ };
    for (int i = 0; i <= 3; ++i)
    {
        answer = BT(0, maxIdx, i);
        if (answer != -1) break;
    }

    cout << answer << endl;
    return 0;
}