#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>

const int SMOL = -1;

void print_weight(const std::vector<int>& weight){
    for(int a : weight){
        if(a == SMOL)
            std::cout << "SMOL" << ' ';    
        else
            std::cout << a << ' ';
    }
    std::cout<<'\n';
}

int solution(int n, std::vector<std::vector<int>> edge) 
{
    int answer = 0;
    
    std::vector<std::vector<int>> roads(n+1);
    
    for(const std::vector<int>& road : edge)
    {
        roads[road[0]].push_back(road[1]);
        roads[road[1]].push_back(road[0]);
    }
    
    std::vector<int> weight(n+1,SMOL);
    
    std::queue<int> queue; 
    weight[1] = 0;

    queue.push(1);
    
    while(!queue.empty())
    {
        int here = queue.front();
        queue.pop();

        for(int next : roads[here])
        {
            if(weight[next] == SMOL)
            {
                weight[next] = weight[here]+1;
                queue.push(next);
            }
        }        
    }
        
    int max = *max_element(weight.begin(),weight.end());
    for(int i = 1; i <= n; i++)
    {
        if(weight[i] == max)
            answer++;
    }
    return answer;
}