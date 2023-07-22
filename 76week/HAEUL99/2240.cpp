#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int t, w;

int arr[1002];
int d[1002][32][3]; //d[현재시간][이동횟수][자두의위치] = 받은 자두의 수

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> w;

    for(int i = 1; i <= t; i++)
    {
        cin >> arr[i];
    }    

    for(int i = 1; i <= t; i++)
    {
        d[i][0][1] = d[i-1][0][1] + (arr[i] == 1 ? 1: 0); //현재시간, 이동횟수가0일때 자두의 위치가 1
        for(int j = 1; j <= w; j++)
        {
            if(i < j) break;
            if(arr[i] == 1)
            {
                d[i][j][1] = max(d[i-1][j][1], d[i-1][j-1][2]) + 1;
                d[i][j][2] = max(d[i-1][j-1][1], d[i-1][j][2]);
            }   
            else 
            {
                d[i][j][1] = max(d[i-1][j-1][2], d[i-1][j][1]);
                d[i][j][2] = max(d[i-1][j][2], d[i-1][j-1][1]) + 1;
            }
        }
    }

    int mx = 0;
    for(int i = 0; i <= w; i++)
    {
        mx = max({mx, d[t][i][1], d[t][i][2]});
    }
    cout << mx;

}
