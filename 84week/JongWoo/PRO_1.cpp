#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets)
{
    int answer = 0;
    
    if (targets.size() == 1)
    {
        answer = 1;
    }
    else
    {
        sort(targets.begin(), targets.end());
    
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        minHeap.emplace(targets[0][1]);
        
        for (int i = 1; i < targets.size(); ++i)
        {
            if (minHeap.top() <= targets[i][0])
            {
                while (!minHeap.empty())
                {
                    minHeap.pop();
                }
                
                ++answer;
            }
            
            minHeap.push(targets[i][1]);
        }
        
        if (!minHeap.empty())
        {
            ++answer;
        }
    }

    return answer;
}
