#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int n = static_cast<int>(truck_weights.size());
    queue<pair<int, int>> q; // <트럭의 무게, 다리를 건널 때의 시간>
    int curWeight = 0, idx = 0;
    
    while (idx < n)
    {  
        ++answer;
        
        if (answer == q.front().second)
        {
            curWeight -= q.front().first;
            q.pop();
        }
        
        if ((q.size() < bridge_length) && (curWeight + truck_weights[idx] <= weight))
        {
            curWeight += truck_weights[idx];
            q.emplace(truck_weights[idx], answer + bridge_length);
            ++idx;
        }
        
        //cout << answer << ": " << q.size() << '\n';
    }
    
    if (!q.empty())
    {
        answer = q.back().second;
    }
    
    return answer;
}
