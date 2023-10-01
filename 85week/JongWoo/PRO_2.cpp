#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> freq;
int maxFreq[11];

void DFS(int n, int idx, const string& order, const string& cur);

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    
    for (string& o : orders)
    {
        sort(o.begin(), o.end());
    }
    
    for (int i = 0; i < orders.size(); ++i)
    {
        for (int j = 0; j < course.size(); ++j)
        {
            DFS(course[j], -1, orders[i], "");
        }
    }
    
    for (const auto& p : freq)
    {
        if ((p.second >= 2) && (p.second == maxFreq[p.first.length()]))
        {
            answer.push_back(p.first);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}

void DFS(int n, int idx, const string& order, const string& cur)
{
    if (cur.length() == n)
    {
        ++freq[cur];
        
        if (freq[cur] >= maxFreq[cur.length()])
        {
            maxFreq[cur.length()] = freq[cur];
        }
        
        return;
    }
        
    for (int i = idx + 1; i < order.size(); ++i)
    {
        DFS(n, i, order, cur + order[i]);
    }
}
