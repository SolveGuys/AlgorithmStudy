#include <iostream>
#include <cmath>

using namespace std;

long long solution(int r1, int r2)
{
    long long answer = 0;
    long long rr1 = static_cast<long long>(r1) * r1;
    long long rr2 = static_cast<long long>(r2) * r2;
    
    // 원의 방정식: x^2 + y^2 = r^2
    // y^2 = r^2 - x^2
    for (long long x = 0; x <= r2; ++x)
    {
        long long xx = x * x;
        int y1 = ((rr1 - xx > 0) ? ceil(sqrt(rr1 - xx)) : 0);
        int y2 = sqrt(rr2 - xx);
        
        answer += (y2 - y1 + 1);
    }
    
    return 4 * (answer - (r2 - r1 + 1));
}
