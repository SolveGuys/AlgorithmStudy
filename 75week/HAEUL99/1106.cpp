#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int c, n;
int d[1101]; // i명 늘릴 때 비용의 최솟값
int a[1002][2]; 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> c >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cin >> a[i][j];        
        }
    }

    for(int i =0; i < n; i++)
    {
        if(d[a[i][1]] != 0) d[a[i][1]] = min(a[i][0], d[a[i][1]]);
        else d[a[i][1]] = a[i][0];
    }

    for(int i = 1; i <= 1101; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i-a[j][1]>=0 && d[i-a[j][1]] != 0)
            {
                if(d[i] == 0) d[i] = d[i-a[j][1]]+ a[j][0];
                else d[i] = min(d[i], d[i-a[j][1]]+ a[j][0]);
                
            }
        }
    }

    int ans = INT_MAX;
    for(int i = 0; i < 101; i++)
    {
        if(d[c+i] != 0)
            ans = min(ans, d[c+i]);
    }

    cout << ans;

}
