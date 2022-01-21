#include <iostream>
#include <string>
#include <vector>

constexpr long long int LLONG_MAX = 9223372036854775807;
std::string get_max(int stick_num)
{
	std::string answer = "";
	while ((stick_num) > 3)
		answer += "1", stick_num -= 2;// , std::cout << stick_num << ' ';

	if (stick_num == 3)
		return "7" + answer;
	else
		return "1" + answer;
}
long long int dp_min[101];
const int digits[8] = { 0,0,1,7,4,2,0,8 };

std::string get_num(int testcase, bool bMax)
{
	std::string answer = "";
	if (bMax)
	{
		answer = get_max(testcase);
	}
	else // Min 
	{
		const long long int BIG = LLONG_MAX/2;
		if (dp_min[testcase] != BIG)
		{
			answer = std::to_string(dp_min[testcase]);
		}
		else
		{
			//for(int i = 2; i < 8; i++) dp_min[testcase] = std::min(dp_min[testcase], dp_min[testcase - i] * 10 + digits[i]);

			auto min = [&BIG](int n, auto& min) -> long long int {

				if (dp_min[n] != BIG || n < 8)
				{
					return dp_min[n];
				}
				else 
				{ 
					for (int i = 2; i < 8; i++)
						dp_min[n] = std::min(dp_min[n], min(n - i,min) * 10 + digits[i]);
				}
				return dp_min[n];
			};

			answer = std::to_string(min(testcase, min));
		}
	}

	return answer;
}
// 1 2 3 4 5 6 7 8 9 0 : 숫자
// 2 5 5 4 5 6 3 7 6 6 : 갯수

// 8 0 2 4 7 1 : 많이 사용되는거부터 순서 : 작은 수 만들기
// 7 6 5 4 3 2 : 사용되는 갯수
int main() {

	std::fill(dp_min, dp_min + 101,LLONG_MAX/2);
	//std::cout << LLONG_MAX;
	int testcase_total;
	
    //initializing dp
	{
		dp_min[0] = LLONG_MAX / 2;
		dp_min[1] = LLONG_MAX / 2;
		dp_min[2] = 1;
		dp_min[3] = 7;
		dp_min[4] = 4;
		dp_min[5] = 2;
		dp_min[6] = 6;
		dp_min[7] = 8; 
		//dp_min[8] = 10;
	}
    
	std::cin >> testcase_total;

	while (testcase_total--)
	{
		int testcase;
		std::cin >> testcase;

		std::cout << get_num(testcase, false) << ' ' << get_num(testcase, true) << '\n';
	}

	//for (int i = 0; i <= 100; i++) std::cout << dp_min[i] << ' ';
	return 0;
}