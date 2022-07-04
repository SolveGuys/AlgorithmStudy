#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    const int big = 1e9;
    int answer = big;    
    int wsize = weak.size();
    
    for(int i = 0; i < wsize-1; i++)
    {
        weak.emplace_back(weak[i] + n);
    }
    
    sort(dist.begin(),dist.end());
    
    do
    {
        for(int i = 0; i < wsize; i++)
        {
            int start = weak[i];
            int end = weak[i + wsize - 1];

            for(int j = 0; j < dist.size(); j++)
            {
                start += dist[j];
                if(start >= end)
                {
                    answer = min(answer, j+1);
                    break;
                }

                for(int k = i+1; k < i + wsize; k++)
                {
                    if(weak[k] > start)
                    {
                        start = weak[k];
                        break;
                    }
                }
            }
        }
    }
    while(next_permutation(dist.begin(),dist.end()));
    
    if(answer == big)
        answer = -1;
    
    return answer;
}