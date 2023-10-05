#include <iostream>
#include <vector>

using namespace std;

bool Check(const vector<int>& stones, int k, int cur);

int solution(vector<int> stones, int k)
{
    int answer = 0;
    int st = 0x7f7f7f7f, en = 0;
    
    for (int s : stones)
    {
        if (s < st)
        {
            st = s;
        }
        
        if (s > en)
        {
            en = s;
        }
    }
    
    while (st <= en)
    {
        int md = (st + en) / 2;
        
        if (Check(stones, k, md))
        {
            answer = md;
            st = md + 1;
        }
        else
        {
            en = md - 1;
        }
    }
    
    return answer;
}

bool Check(const vector<int>& stones, int k, int cur)
{
    int skipCount = 0;
    
    for (int s : stones)
    {
        if (s - cur < 0)
        {
            ++skipCount;
            
            if (skipCount == k)
            {
                return false;
            }
        }
        else
        {
            skipCount = 0;
        }
    }
    
    return true;
}
