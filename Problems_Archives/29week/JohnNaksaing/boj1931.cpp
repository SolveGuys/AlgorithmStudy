#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N;
	std::cin >> N;
	
	struct time 
	{
		int start, end;
	};
	std::vector<time> room(N);
	for (int i = 0; i < N; i++) 
	{
		std::cin >> room[i].start >> room[i].end;
	}
	std::sort(room.begin(), room.end(), [](const time& _lft, const time& _rht)->bool {
		if (_lft.end == _rht.end) return _lft.start < _rht.start;
		else return _lft.end < _rht.end;
	});	
	int current_endtime = room[0].end;
	int count = 1;
	for (int i = 1; i < N; i++) 
	{
		if (room[i].start >= current_endtime) 
		{
			current_endtime = room[i].end, count++;
		}
	}
	std::cout << count;
	return 0;
}