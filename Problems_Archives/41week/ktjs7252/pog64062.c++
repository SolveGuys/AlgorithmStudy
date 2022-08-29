#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

bool check(int mid,vector<int> &stones,int k)
{
    int tmp=0;
    for(int i=0;i<stones.size();i++)
    {
        if(stones[i]-mid<=0)
        {
            tmp++;
        }
        else
        {
            tmp=0;
        }
        if(tmp>=k)
        {
            return true;
        }
    }
    return false;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int mid,hi,lo=1;
    for(int i=0;i<stones.size();i++)
    {
        hi=max(hi,stones[i]);
    }
    
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        if(check(mid,stones,k))
        {
            hi=mid-1;
            answer=mid;
        }
        else
        {
            lo=mid+1;
        }
    }
    
    
    return answer;
}
