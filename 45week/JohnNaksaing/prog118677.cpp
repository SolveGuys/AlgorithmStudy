#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool bSame(const vector<int>& queue1, const vector<int>& queue2, long int& sum1, long int& sum2)
{
    sum1 = 0, sum2 = 0;
    for(int i = 0; i < queue1.size(); i++)
        sum1 += queue1[i];
    
    for(int i = 0; i < queue2.size(); i++)
        sum2 += queue2[i];   
    return sum1 == sum2;
}
// ref https://algosu.tistory.com/108
// memo : 시키는 대로 구현 해주기에는 STL이 너무 비싸다. 큐는 미끼일 뿐이고 투 포인터처럼 풀어야 한다.
int solution(vector<int> queue1, vector<int> queue2) 
{    
    long int sum1, sum2;
    int depth = 0;
    
    if(bSame(queue1,queue2,sum1,sum2))
        return depth;
    
    using iter = std::vector<int>::iterator;
    iter left = queue1.begin(), right = queue2.begin();
    while(!queue1.empty() && !queue2.empty())        
    {
        if(sum1 == sum2)
        {
            break;
        }
        else if (left == queue2.end() || right == queue1.end())//(sum1 == 0 || sum2 == 0) // 0은 왜 틀릴까?
        {
            depth = -1;
            break;
        }
        else if (sum1 < sum2) //2를 떼서 1에 넣기
        {
            int value = *right;
            sum1 += value;
            sum2 -= value;
            
            //queue1.insert(queue1.end(), queue2.begin(), queue2.begin()+1);
            //queue2.erase(queue2.begin());
            
            right++;
            if(right == queue2.end())
                right = queue1.begin();
        } 
        else //if (sum1 > sum2) //1을 떼서 2에 넣기
        {
            int value = *left;
            sum1 -= value;
            sum2 += value;
            
            //queue2.insert(queue2.end(), queue1.begin(), queue1.begin()+1);
            //queue1.erase(queue1.begin());
            
            left++;
            if(left == queue1.end())
                left = queue2.begin();            
        }
        depth++;
    }

    if(queue1.empty() || queue2.empty())
        depth = -1;
    return depth;
}


#if 0
int solution(vector<int> queue1, vector<int> queue2) // TLE 11, 24, 28
{
    long int sum1, sum2;
    int depth = 0;
    if(bSame(queue1,queue2,sum1,sum2))
        return depth;
    while(!queue1.empty() && !queue2.empty())
    {
        if(sum1 == sum2)
        {
            break;
        }
        else if (sum1 == 0 || sum2 == 0)//(left == queue2.end() || right == queue1.end())
        {
            depth = -1;
            break;
        }
        else if (sum1 < sum2)
        {
            int value = *queue2.begin();
            sum1 += value;
            sum2 -= value;
            //2를 떼서 1에 넣기
            queue1.insert(queue1.end(), queue2.begin(), queue2.begin()+1);
            queue2.erase(queue2.begin());
        } 
        else // (sum1 > sum2)
        {
            int value = *queue1.begin();
            sum1 -= value;
            sum2 += value;
            //1을 떼서 2에 넣기
            queue2.insert(queue2.end(), queue1.begin(), queue1.begin()+1);
            queue1.erase(queue1.begin());
        }
        depth++;
    }

    if(queue1.empty() || queue2.empty())
        depth = -1;
    return depth;
}
#endif