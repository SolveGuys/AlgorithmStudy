#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include<algorithm>
using namespace std;

int n, m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    priority_queue<long long, vector<long long>, greater<long long>> _pq; //최소힙

    int x;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        _pq.push(x);
    }

    //sort(a, a+n);
    

    for(int i = 0; i < m; i++)
    {
        long long f = _pq.top(); _pq.pop();
        long long s = _pq.top(); _pq.pop();

        _pq.push(f+s);
        _pq.push(f+s);
    }
    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += _pq.top(); _pq.pop();
    }

    cout << ans;


    
}
