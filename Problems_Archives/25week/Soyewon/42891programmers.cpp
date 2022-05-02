// 프로그래머스 42891.무지의 먹방 라이브

#include <string>
#include <vector>
#include <algorithm> 
#include <queue>

using namespace std;

int solution(vector<int> food_times, long long k) 
{
    long long sum = 0; // 전체 음식 먹는데 걸리는 시간
    for(int i=0; i<food_times.size(); i++)
    {
        sum += food_times[i];
    }
    if(sum <= k) //  전체 음식을 먹는 시간보다 k가 더 클때 섭취해야 할 음식 없으므로
        return -1; // -1 반환

    priority_queue<pair<int,int>> food; // <시간, 번호> 우선순위 큐

    for(int i =0; i<food_times.size(); i++)
    {
        food.push({-food_times[i], i+1}); //  음식 시간 오름차순 삽입
    }

    long long prev = 0; // 직전 식사시간
    while((-food.top().first - prev) * food.size() <= k)
    {
        k -= (-food.top().first - prev) * food.size(); // {남은 전체시간 - (남은 음식 중 섭취시간이 가장 작은것) * (남은 음식 개수)} 로 전체시간 초기화
        prev = -food.top().first;
        food.pop(); // 다 먹은 음식 pop
    }

    vector<pair<int,int>> leftover; // K초 초과 후 남은 음식 넣을 벡터
    while(!food.empty())
    {
        leftover.push_back(make_pair(food.top().second, -food.top().first)); // <번호, 시간> 벡터
        food.pop(); // leftover에 넣은 벡터 pop
    }

    sort(leftover.begin(), leftover.end()); // 음식 번호기준 정렬
    return leftover[k % leftover.size()].first; // 몇 번 음식부터 먹으면 되는지 계산 후 반환 
}








