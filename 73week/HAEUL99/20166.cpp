#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <tuple>
#include <set>
#include <cstring>
#include <string>
#include <stdio.h>
#include <limits.h>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <sstream>
//#include <bits/stdc++.h>
using namespace std;

int n, m, k;
string board[12];
int dx[8] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};

unordered_map<string, int> cnt;


void func(int x, int y, string s)
{
    cnt[s]++;
    if(s.size() == 5) return;
    for(int dir = 0; dir < 8; dir++)
    {
        int nx = (x + dx[dir] + n) % n;
        int ny = (y + dy[dir] + m) % m;

        func(nx, ny, s + board[nx][ny]);
    }
    


   
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> board[i];
    }


    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
    
            func(i, j, string(1, board[i][j]));
        }
    }

    while(k--)
    {
        string s;
        cin >> s;
        cout << cnt[s] << '\n';

    }   
}
