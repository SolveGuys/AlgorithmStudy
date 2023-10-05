#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int l = *min_element(stones.begin(), stones.end());
    int r = *max_element(stones.begin(), stones.end());


    while(l <= r)
    {
        int mid = (l+r)/2;
        vector<int> tmp(stones);
        int maxcnt = 0;
        int cnt = 0;
        for(int i = 0; i < stones.size(); i++)
        {
            tmp[i]-=mid;
            if(tmp[i] <= 0)
            {
                cnt++;    
            }
            else
            {
                cnt = 0;
            }
            maxcnt = max(maxcnt, cnt);
        }
        
        if(maxcnt >= k) // mid 줄여야됨
        {
            r = mid-1;
            answer = mid;
            
            
        }
        else
        {
            l = mid+1;
            //answer = mid;
            
        }
    }

    return answer;
}
