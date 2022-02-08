#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

struct college 
{
	int pay;
	int day;
};

bool operator> (college _lef, college _rig)
{
	if (_lef.pay == _rig.pay) { return _lef.day > _rig.day;	}
	else { return _lef.pay > _rig.pay; }
}

int main()
{
	int n;
	std::cin >> n;

	std::vector<college> colleges(n);

	for (int i = 0; i < n; i++) 
	{
		std::cin >> colleges[i].pay >> colleges[i].day;
	}

	std::sort(colleges.begin(), colleges.end(),std::greater<college>());

	//for (int i = 0; i < n; i++)	std::cout << colleges[i].pay << ' ' << colleges[i].day << '\n';

	std::unordered_map<int,int> schedule;
	
	for (int i = 0; i < n; i++) 
	{
		for (int j = colleges[i].day; j > 0; j--) 
		{
			if (schedule[j] < colleges[i].pay)
			{
				schedule[j] = colleges[i].pay;
				break;
			}
		}
	}

	int money = 0;
	for (const std::pair<const int, int>& pay : schedule) 
	{
		//std::cout << pay.first << ' ' << pay.second << '\n';
		money += pay.second;
	}

	std::cout << money;

	return 0;
}
