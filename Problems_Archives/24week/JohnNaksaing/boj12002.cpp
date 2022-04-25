#include <iostream>
#include <vector>
#include <algorithm>

struct cow 
{
	int x, y;
};

int main() 
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<cow> cows(n);
	std::vector<int> xs(n), ys(n);
    
	for (int i = 0; i < n; i++) 
	{
		int x, y;
		std::cin >> x >> y;
		cows[i] = { x,y };
		std::tie(xs[i],ys[i]) = {x,y};
	}

    //finding max_outliners & min_outliners
	std::sort(xs.begin(), xs.end());
	std::sort(ys.begin(), ys.end());

	int result = (xs[n - 1] - xs[0]) * (ys[n - 1] - ys[0]);

	for (int i_min = 0; i_min < 4; i_min++) // 0 1 2 3
	for (int i_max = n - 4; i_max < n; i_max++) // n-4 n-3 n-2 n-1
	{
		for (int j_min = 0; j_min < 4; j_min++)
		for (int j_max = n - 4; j_max < n; j_max++) 
		{
			int x_min = xs[i_min], x_max = xs[i_max];
			int y_min = ys[j_min], y_max = ys[j_max];

            //counting outliner of rectangle
            int outliner_count = 0;
            for (int i = 0; i < n; i++) 
            {
		        if(cows[i].x < x_min || cows[i].x > x_max ||
		           cows[i].y < y_min || cows[i].y > y_max) 
                {
                    outliner_count++;
                }
		    }
	        
            //is this rectangle vaild?
			if(outliner_count <= 3)
				result = std::min(result,(x_max - x_min) * (y_max - y_min));
		}

	}
	std::cout << result;
	return 0;
}