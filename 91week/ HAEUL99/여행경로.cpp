#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> _tickets;
vector<string> answer;
bool vis[10002];
bool isFind;
string ans[10002];

void dfs(string st, int cnt)
{
    ans[cnt] = st;
    if(isFind) return;
    if(cnt == _tickets.size())
    {
        isFind = true;
        for(int i = 0; i <= cnt; i++)
        {
            answer.push_back(ans[i]);
        }
        return;
    }
    
    for(int i = 0; i < _tickets.size(); i++)
    {
        if(vis[i]) continue;
        if(_tickets[i][0] == st)
        {
            vis[i] = true;
            dfs(_tickets[i][1], cnt+1);
            vis[i] = false;
             
            
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    
    
    sort(tickets.begin(), tickets.end());
    _tickets = tickets;
    
    dfs("ICN", 0);

    
    return answer;
}
