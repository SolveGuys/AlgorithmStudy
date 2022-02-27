#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int main()
{
    int t;
    std::cin >> t;

    while (t--) 
    {
        std::vector<int> mids;
        int m;
        std::cin >> m;


        
        //bigger,smaller : than mid
        std::priority_queue<int,std::vector<int>, std::greater<int>> bigger_q;
        std::priority_queue<int,std::vector<int>, std::less<int>> smaller_q;

        int count_of_ten = 0;
        int mid;
        for (int i = 1; i <= m; i++)
        {
            int num;
            std::cin >> num;

            if (i==1)
            {
                mid = num;
            }
            else 
            {
                if (num < mid) 
                {
                    smaller_q.push(num);
                }
                else 
                {
                    bigger_q.push(num);
                }
            }
            
            if (i % 2 == 1) 
            {
                while (smaller_q.size() > bigger_q.size()) 
                {
                    bigger_q.push(mid);
                    mid = smaller_q.top();
                    smaller_q.pop();
                }
                while (smaller_q.size() < bigger_q.size())
                {
                    smaller_q.push(mid);
                    mid = bigger_q.top();
                    bigger_q.pop();
                }
                mids.push_back(mid);
                //std::cout << mid << ' '; 
                //count_of_ten++;
            }
            //if (count_of_ten % 10 == 0) { std::cout << '\n'; }

        }

        std::cout << (m + 1) / 2 << '\n';
        for (int i = 0; i < mids.size(); i++)
        {
            std::cout << mids[i] << ' ';
            
            if (i % 10 == 9) 
            {
                std::cout << '\n';
            }
        }
    }
	return 0;
}
