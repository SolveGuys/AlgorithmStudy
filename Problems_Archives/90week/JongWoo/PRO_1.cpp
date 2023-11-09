#include <iostream>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> stones, int k)
{
    int answer = 0;
    int n = static_cast<int>(stones.size());
    multiset<int> ms;
    
    for (int i = 0; i < k; ++i)
    {
        ms.insert(stones[i]);
    }
    
    answer = *prev(ms.end());
    
    for (int i = 0; i < n - k; ++i)
    {   
        ms.erase(ms.find(stones[i]));
        ms.insert(stones[i + k]);

        int maxValue = *prev(ms.end());
        
        if (answer > maxValue)
        {
            answer = maxValue;
        }
    }
    
    return answer;
}
