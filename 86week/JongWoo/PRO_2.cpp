#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    int n = static_cast<int>(A.size());
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    int i = 0, j = 0;
    
    while ((i < n) && (j < n))
    {
        if (B[j] > A[i])
        {
            ++answer;
            ++i, ++j;
        }
        else
        {
            ++i;
        }
    }
    
    return answer;
}
