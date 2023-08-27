#include <iostream>
#include <string>

using namespace std;

char dir[] = { 'd', 'l', 'r', 'u' };
int dx[] = { 1, 0, 0, -1 };
int dy[] = { 0, -1, 1, 0 };

void DFS(int n, int m, int x, int y, int r, int c, int k, const string& path, string& answer);

string solution(int n, int m, int x, int y, int r, int c, int k)
{
    string answer = "";
    
    DFS(n, m, x, y, r, c, k, "", answer);
    
    if (answer.empty())
    {
        answer = "impossible";
    }
    
    return answer;
}

void DFS(int n, int m, int x, int y, int r, int c, int k, const string& path, string& answer)
{
    int len = static_cast<int>(path.length());
    
    // 이전에 (r, c)에 도착하여 answer 값이 설정되었다면, 나머지 탐색은 수행할 필요 없다.
    if (!answer.empty())
    {
        return;
    }
    else if (len == k)
    {
        if ((x == r) && (y == c))
        {
            answer = path;
        }
        
        return;
    }
    
    // 목적지까지의 거리가 이동해야 하는 거리(k)보다 크다면 더이상 탐색하지 않는다.
    // 또한, 두 값의 차가 홀수라면 목적지에 도착할 수 없으므로 더이상 탐색하지 않는다.
    int manhattanDist = abs(r - x) + abs(c - y);
    
    if ((manhattanDist > k - len) || ((k - len - manhattanDist) % 2 == 1))
    {
        return;
    }
    
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if ((nx < 1) || (nx > n) || (ny < 1) || (ny > m))
        {
            continue;
        }
        
        DFS(n, m, nx, ny, r, c, k, path + dir[i], answer);
    }
}
