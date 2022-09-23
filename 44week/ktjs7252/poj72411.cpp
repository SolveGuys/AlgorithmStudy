#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

map<string,int> m;
int num[11];

void solve(string order,int start,string tmp)
{
    if(order.size()==start)
    {
        m[tmp]++;
        num[tmp.size()]=max(num[tmp.size()],m[tmp]);
        return;
    }
    
    solve(order,start+1,tmp+order[start]);
    solve(order,start+1,tmp);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int i=0;i<orders.size();i++)
    {
        sort(orders[i].begin(),orders[i].end());
        solve(orders[i],0,"");
    }
    
    for(int i=0;i<course.size();i++)
    {
        for(auto x:m)
        {
            if(num[course[i]]==x.second && x.first.size()==course[i] &&x.second>=2)
            {
                answer.push_back(x.first);
            }
        }
    }
    
    sort(answer.begin(),answer.end());
    
    
    
    return answer;
}
