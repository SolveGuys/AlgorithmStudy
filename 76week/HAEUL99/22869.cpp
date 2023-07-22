#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int n, k;
int arr[5002];
int vis[5002];
queue<int> _queue;
int main()
{           
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vis[0] = 1;
    _queue.push(0);

    while(!_queue.empty())
    {
        int curidx = _queue.front();
        int curv = arr[curidx];
        _queue.pop();
         if(curidx == n-1)
         {
             cout << "YES";
             return 0;
         }
        for(int i = curidx + 1; i < n; i++)
        {
            int curj = arr[i];

            if((i-curidx) * (1+abs(curj - curv)) <= k && vis[i] == 0)
            {
                _queue.push(i);
                vis[i] = 1;
            }

        }
    }
    cout << "NO";
}
