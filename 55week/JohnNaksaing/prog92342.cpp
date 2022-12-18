#include <string>
#include <vector>

int cal(const std::vector<int>& info, int score_board) 
{
	int a = 0, b = 0;

	for (int j = 0; j < 11; j++) 
	{
		if ((1 << j) & score_board)
			a += j;
		else if (info[10 - j] > 0)
			b += j;
	}
	return a - b;
}

bool bHigher(const std::vector<int>& left, const std::vector<int>& right)
{
    int left_idx = 1e9;
    for(int i = 10; i >= 0; i--)
    {
        if(left[i] > 0)
        {
            left_idx = i;
            break;
        }
    }
    int right_idx = 1e9;
    for(int j = 10; j >= 0; j--)
    {
        if(right[j] > 0)
        {
            right_idx = j;
            break;
        }
    }
    return left_idx > right_idx;
}

std::vector<int> solution(int n, std::vector<int> info) 
{
	std::vector<int> answer = { 0,0,0,0,0,0,0,0,0,0,0 };
	int max_score = 0;
	//for (int i = 0; i < 1 << 11; i++) 
    for (int i = 0; i < 1 << 11; i++) 
	{
		int arrow_count = 0;
		std::vector<int> next_status(11,0);

		for (int j = 0; j < 11; j++) 
		{
			if ((1 << j) & i) 
			{
				arrow_count += info[10 - j] + 1;
				next_status[10 - j] = info[10 - j] + 1;
			}
			
			if (arrow_count > n)
				break;
		}
		if (arrow_count > n)
			continue;
        else
            next_status[10] = n - arrow_count;
        
		int next_score = cal(info,i);

		if (next_score > max_score) 
		{
			max_score = next_score;
			answer = std::move(next_status);
		}
        else if (next_score == max_score)
        {
            if(bHigher(next_status,answer))
                answer = std::move(next_status);
        }

	}

	if (max_score == 0)
		answer = { -1 };
    
	return answer;
}