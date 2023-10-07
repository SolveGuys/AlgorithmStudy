#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int x;
    int y;
    int prevDir;
};

int n;
int price[27][27];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int BFS(const vector<vector<int>>& board);

int solution(vector<vector<int>> board)
{
    int answer = 0;
    
    n = static_cast<int>(board.size());
    answer = BFS(board);
    
    return answer;
}

int BFS(const vector<vector<int>>& board)
{
    queue<Node> q;
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            price[i][j] = 0x7f7f7f7f;
        }
    }
    
    price[0][0] = 0;
    q.push({ 0, 0, -1 });
    
    while (!q.empty())
    {
        Node cur = q.front();
        
        q.pop();
        
        for (int i = 0; i < 4; ++i)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            
            if ((nx < 0) || (nx >= n) || (ny < 0) || (ny >= n) || (board[nx][ny] == 1) || ((i / 2 == cur.prevDir / 2) && (abs(i - cur.prevDir) == 1)))
            {
                continue;
            }
            
            int newPrice = 0;
            
            if ((cur.prevDir == -1) || (cur.prevDir == i))
            {
                newPrice = price[cur.x][cur.y] + 100;
            }
            else
            {
                newPrice = price[cur.x][cur.y] + 600;
            }
                       
            if (price[nx][ny] >= newPrice)
            {
                price[nx][ny] = newPrice;
                q.push({ nx, ny, i });
            }
        }
    }
    
    //for (int i = 0; i < n; ++i)
    //{
    //    for (int j = 0; j < n; ++j)
    //    {
    //        cout << price[i][j] << ' ';
    //    }
    //    
    //    cout << '\n';
    //}
    
    return price[n - 1][n - 1];
}
