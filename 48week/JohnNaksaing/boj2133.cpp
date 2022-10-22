#include <string>
#include <vector>
#include <iostream>
using namespace std;
const long long by_mod = 1e9 + 7;

int solution(int n) 
{
    if(n%2 != 0) return 0;
    vector<long long> vec(5010);
    //vec.resize(n+1);
    long long answer;
    vec[0] = 1;
    vec[2] = 3;
    for(int i = 4; i <= n; i+=2)
    {
        vec[i] += 3 * vec[i-2];
        
        for(int j = 4; j <= i; j+=2)
            vec[i] += 2 * vec[i-j];
        
        vec[i] %= by_mod;
        //vec[i] += 2;
    }
    answer = (int)vec[n];
    
    return answer;
}

int main()
{
    int n;
    cin >> n;
    cout << solution(n);
    return 0;
}