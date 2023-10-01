#include <bits/stdc++.h>


using namespace std;

string ans[12];
map<string, int> m;
int vis[22];
int mx;
void dfs(int cur, string order, int course, int prev)
{
    if(cur == course)
    {
        string tmp = "";
        for(int i = 0; i < cur; i++)
        {
            tmp += ans[i];
        } 
        m[tmp]++;   
        return;
    }
    
    for(int i = prev; i < order.size(); i++)
    {
        if(vis[i] != 0) continue;
        vis[i] = 1;
        ans[cur] = order[i];
        prev = i;
        dfs(cur+1, order, course, prev);
        vis[i] = 0;
    }
    
    
    
    
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int i = 0; i< course.size(); i++)
    {
        int cur_course = course[i];
        
        for(int j = 0; j < orders.size(); j++)
        {
            fill(vis, vis+21, 0);
            mx = 0;
            //sort(orders[j].begin(), orders[j].end());
            dfs(0, orders[j], cur_course, 0);
        }
        
        for(auto e : m) 
        { 
            mx = max(mx, e.second);
        }
        //cout << mx << endl;
        for(auto e : m) 
        {
            if(e.second == mx && mx > 1)
            {
                //cout << e.first << endl;
                answer.push_back(e.first);
            }
        }
        
        m.clear();
          
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
