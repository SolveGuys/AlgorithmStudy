#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    int n = scoville.size();
    
    priority_queue<int, vector<int>, greater<>> pq;
    for(int i = 0; i < n; i++)
    {
        pq.push(scoville[i]);
    }
    

    while(true)
    {
        int mn = pq.top();
        if(mn >= K) break;
        pq.pop();
        int mn1 = 0;
        if(pq.size() > 0) 
        {
            mn1 = pq.top();   
            pq.pop();
        }
        else
        {
            answer = -1;
            break;
        }
        
        
        int tmp = mn + mn1 * 2;
        pq.push(tmp);
        answer++;
        
        
    }
    
    return answer;
}
