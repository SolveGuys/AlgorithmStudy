#include <iostream>
#include <vector>

using namespace std;

int chulsu[10'002];
int brother[10'002];
int chulsuCnt, broCnt;

int solution(vector<int> topping)
{
    int answer = 0;
    int n = static_cast<int>(topping.size());
    
    for (int i = 0; i < n; ++i)
    {
        if (chulsu[topping[i]] == 0)
        {
            ++chulsuCnt;
        }
        
        ++chulsu[topping[i]];
    }
    
    for (int i = 0; i < n; ++i)
    {
        --chulsu[topping[i]];
        
        if (chulsu[topping[i]] == 0)
        {
            --chulsuCnt;
        }
        
        if (brother[topping[i]] == 0)
        {
            ++broCnt;
        }
        
        ++brother[topping[i]];
        answer += (chulsuCnt == broCnt);
    }
    
    return answer;
}
