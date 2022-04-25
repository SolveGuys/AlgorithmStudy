#include <iostream>
#include <vector>
#include <string>

using word_mask = int;

void depth_search(int depth_left, int start_idx, word_mask current_mask, int& max_count, const std::vector<word_mask>& needs)
{
	if (depth_left == 0) 
	{
		int learned_count = 0;

		for (int i = 0; i < needs.size(); i++) 
		{
			if ((needs[i] & current_mask) == needs[i]) learned_count++;
		}

		max_count = std::max(learned_count, max_count);
		return;
	}

	for(int i = start_idx; i < 26; i++)
	{
		if ( !(current_mask & (1 << i)) )
		{
			word_mask next_mask = current_mask | (1 << i);
			depth_search(depth_left -1, i, next_mask, max_count, needs);
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, k;
	std::cin >> n >> k;

	if (k < 5) return std::cout << '0', 0;
	if (k >= 26) return std::cout << n, 0;
	
	word_mask wm_in_use = 0x0;
	wm_in_use |= 1 << ('a' - 'a');
	wm_in_use |= 1 << ('n' - 'a');
	wm_in_use |= 1 << ('t' - 'a');
	wm_in_use |= 1 << ('i' - 'a');
	wm_in_use |= 1 << ('c' - 'a');

	k -= 5;

	std::vector<word_mask> needs(n, 0x0);

	for (int i = 0; i < n; i++) 
	{
		std::string word;
        std::cin >> word;
        size_t word_t = word.length();
        word = word.substr(4, word_t -4);
		for (char c : word) 
		{
			needs[i] |= 1 << (c - 'a');
		}
	}

	//for (int i = 0; i < n; i++) {std::cout << words[i] << ' ', printf("%x\n", needs[i]); }
	int max_count = 0;

	depth_search(k,0,wm_in_use,max_count,needs);

	std::cout << max_count;
	return 0;
}