#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int s : scoville)
    {
        minHeap.push(s);
    }
    
    while ((minHeap.size() >= 2) && (minHeap.top() < K))
    {
        int first = minHeap.top(); minHeap.pop();
        int second = minHeap.top(); minHeap.pop();
        
        minHeap.push(first + 2 * second);
        ++answer;
    }
    
    if ((minHeap.empty()) || (minHeap.top() < K))
    {
        answer = -1;
    }
    
    return answer;
}
