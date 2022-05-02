#include <string>
#include <vector>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    
    int time=0;
    int idx=0;
    int sum=0;
    
    for(int i=0;i<food_times.size();i++)
    {
        sum+=food_times[i];
    }
    
    if(sum<=k)
    {
        return -1;
    }
    
    while(time<=k)
    {
        if(time==k)  //끝에 왓다면
        {
            if(idx==food_times.size()) //끝에 있는 인덱스에 왔다면
            {
            idx=0;
            }
            if(food_times[idx]>0)
            {
                answer=idx+1;
            }
            else
            {
                while(1)
                {
                    if(food_times[idx]>0)
                    {
                        answer=idx+1;
                        break;
                    }
                    idx++;
                    if(idx==food_times.size())
                    {
                        idx=0;
                    }
                }
            }
            break;
        }
        if(idx==food_times.size()) //끝에 있는 인덱스에 왔다면
        {
            idx=0;
        }
        
        if(food_times[idx]>0)
        {
          //  printf("현재의 인데스 %d   %d\n",idx,time);
            food_times[idx]--;
          //  printf("%d\n",food_times[idx]);
            time++;
            idx++;
        }
        else
        {
            idx++;
        }
    }
    
    
    
    return answer;
}
