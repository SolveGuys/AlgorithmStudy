#include <iostream>
#include <vector>
#include <algorithm>

struct Calander 
{
	static const int end_of_day[13];
	int month, day;

	Calander(int mon, int day) : month(mon),day(day), val(end_of_day[mon]+day) {}
	Calander() : month{}, day{}, val{} {}
	bool operator<(const Calander& other) { return val < other.val; }
	bool operator==(const Calander& other) { return val == other.val; }
	bool operator<=(const Calander& other) { return val <= other.val; }
private:
	int val;
};
const int Calander::end_of_day[13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

class Flower 
{
	Calander start;
	Calander end;

public:
	Calander start_() { return start; }
	Calander end_() { return end; }

	Flower() {}
	Flower(int b_m, int b_d, int e_m, int e_d) : start(b_m, b_d), end(e_m,e_d) {}
	//~Flower() {};
	bool operator<(const Flower& other) 
	{
		return start < other.start;
	}
};

int main_dirty()
{
	int n;
	std::cin >> n;
	std::vector<Flower> Flowers(n);
	
	for (int i = 0; i < n; i++) 
	{
		int b_m, b_d, e_m, e_d;
		std::cin >> b_m >> b_d >> e_m >> e_d;
		Flowers[i] = Flower(b_m, b_d, e_m, e_d);
	}

	std::sort(Flowers.begin(),Flowers.end());

	//for (int i = 0; i < n; i++)		std::cout << Flowers[i].start_().month << " " << Flowers[i].start_().day << " " << Flowers[i].end_().month << " " << Flowers[i].end_().day << "\n";

	Calander today = Calander(3,1);
	
	int answer = 0;
	int max_i;

	Calander max_date = Calander(0,0);
	for (int i = 0; i < n; i++) 
	{
		if(Calander(11, 30) < today) break;

		//pick greedy
		if (max_date < Flowers[i].end_() && Flowers[i].start_() <= today) 
		{
			max_i = i;
			max_date = Flowers[i].end_();
		}

		//out of bound : move today to tomorrow
		if (today < Flowers[i].start_() && Calander(0,0) < max_date) 
		{
			today = Flowers[max_i].end_();
			answer++;
			i--;
			max_date = Calander();
		}
		else if (Calander(0, 0) < max_date && i == n-1)
		{
			today = Flowers[max_i].end_();
			answer++;
		}
		else if (max_date < Calander(0, 1)) 
		{
			answer = 0; break;
		}
	}
    if (today <= Calander(11, 30))
        answer = 0;

	std::cout << answer;
	return 0;
}

int main()
{
	int n;
	std::cin >> n;
	std::vector<Flower> Flowers(n);
	
	for (int i = 0; i < n; i++) 
	{
		int b_m, b_d, e_m, e_d;
		std::cin >> b_m >> b_d >> e_m >> e_d;
		Flowers[i] = Flower(b_m, b_d, e_m, e_d);
	}

	std::sort(Flowers.begin(),Flowers.end());

	//for (int i = 0; i < n; i++)		std::cout << Flowers[i].start_().month << " " << Flowers[i].start_().day << " " << Flowers[i].end_().month << " " << Flowers[i].end_().day << "\n";

	Calander today = Calander(3,1);
	
	int answer = 0;
	int max_i;

	Calander max_date = Calander(0,0);
	for (int i = 0; i < n; i++) 
	{

	}

	std::cout << answer;
	return 0;
}


int main()
{
	int n;
	std::cin >> n;
	std::vector<Flower> Flowers(n);
	
	for (int i = 0; i < n; i++) 
	{
		int b_m, b_d, e_m, e_d;
		std::cin >> b_m >> b_d >> e_m >> e_d;
		Flowers[i] = Flower(b_m, b_d, e_m, e_d);
	}

	std::sort(Flowers.begin(),Flowers.end());

	//for (int i = 0; i < n; i++)		std::cout << Flowers[i].start_().month << " " << Flowers[i].start_().day << " " << Flowers[i].end_().month << " " << Flowers[i].end_().day << "\n";

	Calander today = Calander(3,1);
	
	int answer = 0;
	
	int i = -1;
	Calander max_date = Calander(0,0);
	while (today < Calander(12, 1) && i < n) 
	{
		bool bHit = false; i++;
        
		for (int next_i = i; next_i < n; next_i++) 
		{
			if (today < Flowers[next_i].start_())  break;

			//pick greedy
			if (max_date < Flowers[next_i].end_())
			{
				max_date = Flowers[next_i].end_();
				bHit = true;
                i = next_i;
			}
		}

		//out of bound : move today to tomorrow
		if (bHit) 
		{
			today = max_date;
			answer++;
		}
		else 
		{
			answer = 0;
			break;
		}
	}

	std::cout << answer;
	return 0;
}