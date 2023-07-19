#include <iostream>
#include <vector>

using namespace std;

int n;
int board[101][101];

void Curve(int g, vector<int>& dirs);
void DrawBoard(int x, int y, const vector<int>& dirs);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int x = 0, y = 0, d = 0, g = 0;

        cin >> x >> y >> d >> g;

        vector<int> dirs = { d };

        Curve(g - 1, dirs);

        // 주어진 좌표 (x, y)를 board[x][y]와 사용하기 위해서 x와 y의 위치를 바꾸어 전달해야한다.
        DrawBoard(y, x, dirs);
    }

    int answer = 0;

    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            if ((board[i][j] == 1) && (board[i][j + 1] == 1) && (board[i + 1][j] == 1) && (board[i + 1][j + 1] == 1))
            {
                ++answer;
            }
        }
    }

    cout << answer << '\n';
}

void Curve(int g, vector<int>& dirs)
{
    if (g < 0)
    {
        return;
    }

    for (int i = dirs.size() - 1; i >= 0; --i)
    {
        dirs.push_back((dirs[i] + 1) % 4);
    }

    Curve(g - 1, dirs);
}

void DrawBoard(int x, int y, const vector<int>& dirs)
{
    for (int dir : dirs)
    {
        switch (dir)
        {
        case 0: // x좌표가 증가하는 방향 (→)
            board[x][y] = board[x][y + 1] = 1;
            y = y + 1;
            break;
        case 1: // y좌표가 감소하는 방향 (↑)
            board[x][y] = board[x - 1][y] = 1;
            x = x - 1;
            break;
        case 2: // x좌표가 감소하는 방향 (←)
            board[x][y] = board[x][y - 1] = 1;
            y = y - 1;
            break;
        case 3: // y좌표가 증가하는 방향 (↓)
            board[x][y] = board[x + 1][y] = 1;
            x = x + 1;
            break;
        }
    }
}