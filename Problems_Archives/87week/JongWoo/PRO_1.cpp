#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> a)
{
    int answer = 1; // a의 원소 중 최솟값은 반드시 남길 수 있다.
    int n = static_cast<int>(a.size());
    int minIndex = 0;
    
    // 최솟값을 구한다.
    for (int i = 1; i < n; ++i)
    {
        if (a[i] < a[minIndex])
        {
            minIndex = i;
        }
    }
    
    int leftMin = 0x7f7f7f7f, rightMin = 0x7f7f7f7f;
    int l = 0, r = n - 1;
    
    while ((l < minIndex) || (r > minIndex))
    {
        if ((l < minIndex) && (a[l] < leftMin))
        {
            leftMin = a[l];
            ++answer;
        }
        
        if ((r > minIndex) && (a[r] < rightMin))
        {
            rightMin = a[r];
            ++answer;
        }
        
        ++l, --r;
    }
    
    return answer;
}
