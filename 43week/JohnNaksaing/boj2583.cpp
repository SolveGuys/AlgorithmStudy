#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

const int dx[]{ -1,1,0,0 };
const int dy[]{ 0,0,1,-1 };

int n, m, k;
void search(int i, int j, int& area, std::vector<std::vector<bool>>& map) 
{
    struct node 
    {
        int x, y;
    };

    std::queue<node> q;

    q.push({ i,j });

    while (!q.empty()) 
    {
        node here = q.front();
        q.pop();
        area++;

        for (int dir = 0; dir < 4; dir++) 
        {
            node next = { here.x + dx[dir],here.y + dy[dir] };
            
            if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m || map[next.x][next.y])
                continue;

            map[next.x][next.y] = true;
            q.push(next);
        }
    }
}

int main()
{
    std::cin >> m >> n >> k;

    std::vector<std::vector<bool>> map(n, std::vector<bool>(m));
    
    std::vector<int> area;
 
    while(k--)
    {
        int xld, yld, xru, yru;
        std::cin >> xld >> yld >> xru >> yru;

        for (int i = xld; i < xru; i++) 
        for (int j = yld; j < yru; j++)
        {
            map[i][j] = true;
        }
    }

    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
        if (!map[i][j]) 
        {
            int areaCount = 0;
            map[i][j] = true;

            search(i,j, areaCount,map);

            area.push_back(areaCount);
        }
    }
    std::sort(area.begin(),area.end());

    std::cout << area.size() << '\n';

    for (int a : area)
    {
        std::cout << a << ' ';
    }
    
    return 0;
}