#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<int> ports(n);
    std::vector<int> smol;

    for (int i = 0; i < n; i++) 
    {
        std::cin >> ports[i];
    }

    smol.emplace_back(ports[0]);

    using iter = std::vector<int>::iterator;

    for (int i = 0; i < n; i++) 
    {
        if (ports[i] > smol.back()) 
        {
            smol.emplace_back(ports[i]);
        }
        else 
        {
            iter place = std::lower_bound(smol.begin(),smol.end(), ports[i]);
            *place = ports[i];
        }
    }
    std::cout << smol.size();
    return 0;
}
