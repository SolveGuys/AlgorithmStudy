#include <bits/stdc++.h>

using namespace std;
char str[8] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'}; 
int vis[8];

int cnt;

void dfs(int cur, char ans[], vector<string> _data)
{
    if(cur == 8)
    {
        for(int i = 0; i < _data.size(); i++)
        {
            int f1 = 0; int f2 = 0;
            for(int j = 0; j < 8; j++)
            {
                if(ans[j] == _data[i][0]) f1 = j;
                else if(ans[j] == _data[i][2]) f2 = j;
            }
            
            char op = _data[i][3];
            int num = _data[i][4] - '0';
            
            if(op == '=' && abs(f1-f2) != num+1) return;
            else if(op == '>' && abs(f1-f2) <= num+1) return;
            else if(op == '<' && abs(f1-f2) >= num+1) return;
            
        }
        cnt++;
        return;
    }
    
    for(int i = 0; i < 8; i++)
    {
        if(vis[i] == 1) continue;
        vis[i] = 1;
        ans[cur] = str[i];
        dfs(cur+1, ans, _data);
        vis[i] = 0;
            
    }
}

int solution(int n, vector<string> data) {

    cnt = 0;
     
    char ans[8] = {NULL, };

    dfs(0, ans, data);
    

    return cnt;
}
