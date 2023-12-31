#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine)
{
    int answer = 0;
    int maxSize = *max_element(tangerine.begin(), tangerine.end());
    vector<int> freq(maxSize + 1);
    
    for (int t : tangerine)
    {
        ++freq[t];
    }
    
    vector<int> v;
    
    for (int i = 1; i <= maxSize; ++i)
    {
        if (freq[i] == 0)
        {
            continue;
        }
        
        v.push_back(freq[i]);
    }
    
    sort(v.begin(), v.end(), greater<int>());
    
    int n = static_cast<int>(tangerine.size());
    
    while (!v.empty())
    {
        n -= v.back();
        
        if (n < k)
        {
            answer = static_cast<int>(v.size());
            break;
        }
        
        v.pop_back();
    }
    
    return answer;
}
