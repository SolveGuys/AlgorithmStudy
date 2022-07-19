#include <iostream>
#include <vector>
#include <queue>
int main()
{
    int n, t;
    std::cin >> n >> t;

    std::vector<std::vector<bool>> coms(n,std::vector<bool>(n,false));
    std::vector<bool> visited(n);

    while (t--) 
    {
        int a, b;
        std::cin >> a >> b;
        coms[a - 1][b - 1] = true;
        coms[b - 1][a - 1] = true;
    }
    int answer = 0;
    
    std::queue<int> q;
    q.push(0);

    while (!q.empty()) 
    {
        int here = q.front();
        q.pop();

        visited[here] = true;
        answer++;

        for (int i = 0; i < n; i++) 
        {
            if (coms[here][i] && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    std::cout << answer-1;
    return 0;
}