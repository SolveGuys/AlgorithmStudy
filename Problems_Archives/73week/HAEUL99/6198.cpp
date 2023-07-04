#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>
#include <queue>

using namespace std;


int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long ans;
    stack<int> s;

    int n;
    cin >> n;

    int height;
    while(n--)
    {
        cin >> height;
        while(!s.empty() && s.top() <= height)
        {
            s.pop();
        }
        ans += s.size();
        s.push(height);
        
    }
    cout << ans;

}
