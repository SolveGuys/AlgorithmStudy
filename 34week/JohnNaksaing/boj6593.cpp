#include <iostream>
#include <queue>

struct pos { int l = 0, r = 0, c = 0, time = 0; };

int dl[] = {1,-1,0, 0,0,0};
int dr[] = {0, 0,1,-1,0,0};
int dc[] = {0, 0,0, 0,1,-1};
const int big = 1e7;

void reset_visited(int l, int r, int c, bool visit[31][31][31])
{
    for (int i = 1; i <= l; i++)
    for (int j = 1; j <= r; j++)
    for (int k = 1; k <= c; k++)
        visit[i][j][k] = false;
}

char map[31][31][31];
bool visit[31][31][31];

int main()
{
    
    int L, R, C;

    while (true)
    {
        int end_time = big;
        pos start;
        std::cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0)
        {
            break;
        }

        for (int i = 1; i <= L; i++)
        {
            for (int j = 1; j <= R; j++)
            {
                for (int k = 1; k <= C; k++)
                {
                    std::cin >> map[i][j][k];
                    if (map[i][j][k] == 'S')
                        start = { i,j,k,0 };
                }
            }
        }

        reset_visited(L, R, C, visit);

        std::queue<pos> q;
        q.push(start);
        visit[start.l][start.r][start.c] = true;

        while (!q.empty()) 
        {
            const auto& front = q.front();

            int l = front.l;
            int r = front.r;
            int c = front.c;
            int t = front.time;

            q.pop();

            for (int dir = 0; dir < 6; dir++)
            {
                int next_l = l + dl[dir];
                int next_r = r + dr[dir];
                int next_c = c + dc[dir];

                if (
                    next_l < 1 || next_l > L ||
                    next_r < 1 || next_r > R ||
                    next_c < 1 || next_c > C ||
                    map[next_l][next_r][next_c] == '#' ||
                    visit[next_l][next_r][next_c]
                ) 
                { continue; }

                if (map[next_l][next_r][next_c] == 'E')
                {
                    end_time = std::min(end_time, t + 1);
                    break;
                }
                else
                {
                    visit[next_l][next_r][next_c] = true;
                    q.push({ next_l,next_r,next_c, t + 1 });
                }
            }
        }

        if (end_time == big)
            std::cout << "Trapped!\n";
        else 
            std::cout << "Escaped in " << end_time << " minute(s).\n";

        std::cin.get();
    }

    return 0;
}