#include <iostream>
#include <algorithm>
#include <array>
#include <string>
#include <queue>
#define endl '\n'

constexpr char R{ 'R' }, G{ 'G' }, B{ 'B' }, P{ 'P' }, Y{ 'Y' }, E{ '.' };
constexpr std::array<int, 4> dr = { 1,-1,0,0 };
constexpr std::array<int, 4> dc = { 0,0,1,-1 };
using Field = std::array<std::string, 12>;
using Visited = std::array<std::array<bool, 6>, 12>;
struct Pos {
    Pos() = default;
    Pos(int r, int c) : row(r), col(c) {}
    int row{};
    int col{};
};
struct Move {
    Move() = default;
    Move(int r, int c, int d) : pos(r, c), dep(d) {}
    Pos pos;
    int dep{};
};
void PrintField(const Field& field)
{
    for (std::string row : field)
    {
        std::cout << row << endl;
    }
    std::cout << endl;

}
bool IsValid(const Move& next)
{
    if (next.pos.col < 0 || next.pos.col >= 6 || next.pos.row < 0 || next.pos.row >= 12)
        return false;
    return true;
}
bool BFS(Field& field, Visited& visited, int row, int col)
{
    if (field[row][col] == E) return false;
    if (visited[row][col] == true) return false;
    // 현재 문자
    char tar = field[row][col];
    std::queue<Move> q;
    std::vector<Pos> puyo;
    puyo.reserve(72);

    q.push(Move(row, col, 0));
    puyo.emplace_back(row, col);
    field[row][col] = E;
    while (!q.empty())
    {
        Move cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            Move next(cur.pos.row + dr[i], cur.pos.col + dc[i], cur.dep + 1);
            if (IsValid(next) == false) continue;
            if (field[next.pos.row][next.pos.col] == tar)
            {
                field[next.pos.row][next.pos.col] = E;
                q.push(next);
                puyo.emplace_back(next.pos.row, next.pos.col);
            }
        }
    }
    if (puyo.size() >= 4)
    {
        return true;
    }
    else
    {
        for (const Pos& pos : puyo)
        {
            field[pos.row][pos.col] = tar;
            visited[pos.row][pos.col] = true;
        }
        return false;
    }
}

bool Combo(Field& field)
{
    //PrintField(field);
    bool result{};
    Visited visited{};
    for(int i = 0; i < 12; i++)
        for (int j = 0; j < 6; j++)
        {
            if (BFS(field, visited, i, j))
                result = true;
        }
    return result;
}
void PullDown(Field& field)
{
    for (int i = 11; i >= 0; --i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (field[i][j] == E)
            {
                int idx = i;
                while (idx > 0 && field[idx][j] == E)
                {
                    idx--;
                }
                field[i][j] = field[idx][j];
                field[idx][j] = E;
            }
        }
    }
}
int main()
{    //입출력 성능향상을 위한 설정
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    Field field;
    for (std::string& row : field)
    {
        std::cin >> row;
    }

    int answer{};
    while (Combo(field))
    {
        PullDown(field);
        answer++;
    }
    std::cout << answer;
    return 0;
}