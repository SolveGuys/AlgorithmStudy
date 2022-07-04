#include <string>
#include <iostream>
#include <map>
std::map<char, int> dic = { {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
std::pair<std::string, int> special_cases[] = { {"IV",4},{"IX",9},{"XL",40},{"XC",90},{"CD",400},{"CM",900} };
std::string Ms[] = {"","M","MM","MMM"};
std::string Hs[] = {"","C","CC","CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
std::string Ts[] = {"","X","XX","XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
std::string Os[] = {"","I","II","III", "IV", "V", "VI", "VII", "VIII", "IX"};
int to_arabic(std::string roman)
{
	int arabic = 0;

	for (int i = 0; i < 6; i++) 
	{
		auto idx = roman.find(special_cases[i].first);
		if (idx != std::string::npos) 
		{
			roman.replace(idx, special_cases[i].first.length(),"");
			arabic += special_cases[i].second;
		}
	}

	for (int i = 0; i < roman.size(); i++) 
	{
		char c = roman[i];

		arabic += dic[c];
	}

	return arabic;
}
std::string to_roman(int arabic) 
{
	int ms = arabic / 1000;
	int hs = (arabic % 1000) / 100;
	int ts = (arabic % 100) / 10;
	int os = arabic % 10;
	
	return Ms[ms] + Hs[hs] + Ts[ts] + Os[os];
}

int main()
{
	std::string num1, num2;
	std::cin >> num1 >> num2;
	
	int sum = to_arabic(num1) + to_arabic(num2);
	std::cout << sum << '\n' << to_roman(sum);
	return 0;
}