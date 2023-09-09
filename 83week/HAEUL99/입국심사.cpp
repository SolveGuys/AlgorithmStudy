#include <bits/stdc++.h>


using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    long long st = 1;
    long long en = (long long)n * times[times.size()-1];
    
    while(st <= en)
    {
        long long mid = (st + en)/2;
        long long res = 0;
        
        for(int i = 0; i < times.size(); i++)
        {
            res += (mid /times[i]);
        }
        
        if(res >= n)
        {
            en = mid - 1;
            answer = mid;
        }
        else
        {
            st = mid + 1;
        }
    }
    
    
    return answer;
}
