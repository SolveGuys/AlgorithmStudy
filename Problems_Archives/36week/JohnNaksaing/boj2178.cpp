#include <bits/stdc++.h>

bool nm[102][102];
bool visited[102][102];

struct node
{
    int x, y;
    int c;
    static const int dx[];
    static const int dy[];
};
const int node::dx[] = {-1,1,0,0};
const int node::dy[] = {0,0,-1,1};

int main()
{
    int n, m;
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    {
        int a;
    	scanf("%1d",&a);
    	nm[i][j] = (bool)a;
    }
    std::queue<node> q;
    q.push({1,1,1});
    visited[1][1] = true;
    
    int answer = -1;
    while(!q.empty())
    {
        node here = q.front();
        
        if(here.x == n && here.y == m)
        {
            answer = here.c;
            break;
        }
        
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int next_x = here.x + node::dx[i];
            int next_y = here.y + node::dy[i];
            
            if(!nm[next_x][next_y] || visited[next_x][next_y]) continue;
            
            int next_c = here.c + 1;
            q.push({next_x,next_y,next_c});
            visited[next_x][next_y] = true;
        }
    }
    
    printf("%d",answer);
    return 0;
}