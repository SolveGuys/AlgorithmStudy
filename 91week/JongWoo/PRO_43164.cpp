#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;
    unordered_map<string, vector<string>> adjList;
    
    sort(tickets.begin(), tickets.end(),
        [](const auto& a, const auto& b)
         {
             return a[1] > b[1];
         });
    
    for (const vector<string>& t : tickets)
    {
        adjList[t[0]].push_back(t[1]);
    }
    
    stack<string> stk;
    string st = "ICN";

    stk.push(st);
    
    while (!stk.empty())
    {
        string cur = stk.top();
        
        if (adjList[cur].empty())
        {
            stk.pop();
            answer.push_back(cur);
        }
        else
        {
            stk.push(adjList[cur].back());
            adjList[cur].pop_back();
        }
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}
