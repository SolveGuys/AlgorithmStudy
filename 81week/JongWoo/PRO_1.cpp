#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <utility>

using namespace std;

vector<string> solution(vector<vector<string>> plans)
{
    vector<string> answer;
    
    // <시작 시간, 소요 시간, 과제명>
    priority_queue<tuple<int, int, string>, vector<tuple<int, int, string>>, greater<tuple<int, int, string>>> minHeap;
    
    for (const auto& plan : plans)
    {
        int startMin = 60 * stoi(plan[1].substr(0, 2)) + stoi(plan[1].substr(3, 2));
        int duration = stoi(plan[2]);

        minHeap.emplace(startMin, duration, plan[0]);
    }
    
    // <소요 시간, 과제명>
    stack<pair<int, string>> stk;
    tuple<int, int, string> cur = minHeap.top();
    int curTime = get<0>(cur);
    
    minHeap.pop();
    
    while (!minHeap.empty())
    {
        tuple<int, int, string> nxt = minHeap.top();
        
        if (get<0>(nxt) < curTime + get<1>(cur))
        {
            curTime = get<0>(nxt);
            stk.emplace(get<1>(cur) - (get<0>(nxt) - get<0>(cur)), get<2>(cur));
            minHeap.pop();
            cur = nxt;
        }
        else
        {
            answer.push_back(get<2>(cur));
            curTime = get<0>(cur) + get<1>(cur);

            if (stk.empty())
            {
                curTime = get<0>(nxt);
                minHeap.pop();
                cur = nxt;
            }
            else
            {
                if (get<0>(nxt) == curTime)
                {
                    curTime = get<0>(nxt);
                    minHeap.pop();
                    cur = nxt;
                }
                else
                {
                    cur = tuple(curTime, get<0>(stk.top()), get<1>(stk.top()));
                    stk.pop();
                }
            }
        }
    }
    
    answer.push_back(get<2>(cur));
    
    while (!stk.empty())
    {
        answer.push_back(get<1>(stk.top()));
        stk.pop();
    }
    
    return answer;
}
