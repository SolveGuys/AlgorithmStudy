#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

const int big = 1e9;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<int> sum(n,-big);
    std::vector<int> num(n);

    for (int i = 0; i < n; i++)    
    {
        std::cin >> num[i];
    }
    sum[0] = num[0];

    for (int i = 1; i < n; i++) 
    {
        sum[i] = std::max(num[i],sum[i-1]+num[i]);
    }

    std::cout << *std::max_element(sum.begin(), sum.end());
    return 0;
}