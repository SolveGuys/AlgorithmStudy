#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2)
{
    int answer = 0;
    int q1Size = queue1.size(), q2Size = queue2.size();
    int totSize = q1Size + q2Size;
    long long q1Tot = 0, q2Tot = 0;
    vector<int> v;
    
    v.reserve(totSize);
    
    for (int i = 0; i < queue1.size(); ++i)
    {
        q1Tot += queue1[i];
        q2Tot += queue2[i];
        v.push_back(queue1[i]);
        v.push_back(queue2[i]);
    }
    
    int p = 0, q = q1Size;
    
    while (true)
    {
        if (q1Tot == q2Tot)
        {
            break;
        }
        else if ((q1Size == 0) || (q2Size == 0))
        {
            answer = -1;
            break;
        }
        
        if (q1Tot > q2Tot)
        {
            --q1Size;
            ++q2Size;
            q1Tot -= v[p];
            q2Tot += v[p];
            ++p; //p = (p + 1) % totSize;
            
            if (p >= totSize)
            {
                answer = -1;
                break;
            }
        }
        else
        {
            --q2Size;
            ++q1Size;
            q2Tot -= v[q];
            q1Tot += v[q];
            q = (q + 1) % totSize; 
        }
        
        ++answer;
    }
    
    return answer;
}
