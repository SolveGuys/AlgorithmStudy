#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int GetMinute(const string& bt);

int solution(vector<vector<string>> book_time)
{
    // book_time의 길이가 1인 경우
    int answer = 1;
    
    // 예약 시각을 시작 시각 기준으로 오름차순 정렬한다.
    sort(book_time.begin(), book_time.end());
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int st = 0, en = 0;
    
    en = GetMinute(book_time[0][1]) + 10;
    minHeap.push(en);
    
    for (int i = 1; i < book_time.size(); ++i)
    {
        st = GetMinute(book_time[i][0]);
            
        if (st >= minHeap.top())
        {
            minHeap.pop();
        }
        
        en = GetMinute(book_time[i][1]) + 10;
        minHeap.push(en);
        answer = max(answer, static_cast<int>(minHeap.size()));
    }
    
    return answer;
}

int GetMinute(const string& bt)
{
    return 60 * stoi(bt.substr(0, 2)) + stoi(bt.substr(3, 2));
}
