#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int n, m;
vector<int> _vec;
int dp[42];
int main()
{           
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    cin >> m;

    int x;
    int prev = 0;
    for(int i = 0; i < m; i++)
    {
        cin >> x;
        // if(x-prev-1 > 0)
        //     _vec.push_back(x-prev-1);
        // else 
        //     _vec.push_back(1);
        _vec.push_back(x-prev-1);
        prev = x;
    }
    // if(n-prev>0)
    //     _vec.push_back(n-prev);
    // else 
    //     _vec.push_back(1);
    _vec.push_back(n-prev);

    int ans = 1;
    int cur = 0;

    dp[2] = 2;
    dp[1] = 1;

    for(int i = 3; i < 41; i++)
    {
        dp[i] = dp[i-1]+dp[i-2];
    }
    for(int i = 0; i < _vec.size(); i++)
    {
        int n = _vec[i];
        //cout << n << endl;
        if(n > 2)
        {
            cur += dp[n-1];
            cur += dp[n-2];
            
        }
        else if(n == 2)
        {
            cur += 2;
        }
        else if(n == 1)
        {
            cur += 1;
        }
        else
        {
            cur +=1;
        }
        ans = ans * cur;
        cur = 0;
    }
    
    cout << ans;
    
}
