#include <iostream>
#include <queue>

using namespace std;

int n, m;
priority_queue<long long, vector<long long>, greater<long long>> minHeap;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        int num = 0;
        
        cin >> num;
        minHeap.push(num);
    }

    for (int i = 0; i < m; ++i)
    {
        long long first = minHeap.top();
        
        minHeap.pop();

        long long second = minHeap.top();

        minHeap.pop();
        minHeap.push(first + second);
        minHeap.push(first + second);
    }

    long long answer = 0;

    while (!minHeap.empty())
    {
        answer += minHeap.top();
        minHeap.pop();
    }

    cout << answer << '\n';
}
