#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <utility>

using namespace std;

int n, m;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int groupNums[502][502];
vector<int> sizes;

void BFS(const vector<vector<int>>& land, int sx, int sy, int groupNum);

int solution(vector<vector<int>> land)
{
    int answer = 0;
    int groupNum = 0;
    
    n = static_cast<int>(land.size());
    m = static_cast<int>(land.front().size());
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            groupNums[i][j] = -1;
        }
    }
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if ((land[i][j] == 1) && (groupNums[i][j] == -1))
            {
                BFS(land, i, j, groupNum++);
            }
        }
    }
    
    for (int i = 0; i < m; ++i)
    {
        set<int> s;
        
        for (int j = 0; j < n; ++j)
        {
            if (groupNums[j][i] != -1)
            {
                s.insert(groupNums[j][i]);
            }
        }
        
        int tot = 0;
        
        for (int g : s)
        {
            tot += sizes[g];
        }
        
        answer = max(answer, tot);
    }
    
    return answer;
}

void BFS(const vector<vector<int>>& land, int sx, int sy, int groupNum)
{
    int siz = 0;
    queue<pair<int, int>> q;
    
    groupNums[sx][sy] = groupNum;
    q.emplace(sx, sy);
    
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        ++siz;
        
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if ((nx < 0) || (nx >= n) || (ny < 0) || (ny >= m) || (land[nx][ny] != 1) || (groupNums[nx][ny] != -1))
            {
                continue;
            }
            
            groupNums[nx][ny] = groupNum;
            q.emplace(nx, ny);
        }
    }
    
    sizes.push_back(siz);
}
