#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include<algorithm>
using namespace std;
#define mod 1000000;
string str;
int dp[5002]; // i번째 자리까지 봤을 때 해석할 수 있는 단어 개수 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    if(str[0] == '0')
    {
        cout << '0';
        return 0;
    }

    dp[0] = 1; dp[1] = 1;
    for(int i = 2; i <= str.size(); i++)
    {
        if(str[i-1]>'0')
        {
            dp[i] = dp[i-1]%mod; 
        }
        //else dp[i] = dp[i-2]%mod;

        int n = (str[i-2]-'0')* 10 + str[i-1] -'0';
        if(10 <= n && 26 >= n)
        {
            dp[i] = (dp[i]+dp[i-2])%mod;
        }
    }

    cout << dp[str.size()];
  
}
