#include <bits/stdc++.h>

int pow_10[] {1,10,100,(int)1e3,(int)1e4,(int)1e5,(int)1e6,(int)1e7,(int)1e8,(int)1e9};

inline int get_gcd(int a, int b)
{
	return b ? get_gcd(b, a % b) : a;
}

std::pair<int,int> to_rational(std::string str) 
{
	auto point = str.find(".");
	auto begin = str.find('(');
	auto end = str.find(')');
	
	int madi_len = end - begin - 1;	
	std::string _integer = str.substr(0, point);
	std::string _non_madi =  str.substr(point + 1, begin - point - 1);
	
	if(_non_madi.find('(') != _non_madi.npos)
		_non_madi.replace(_non_madi.find("("),1,"");

	std::string _madi = str.substr(begin + 1, madi_len);

	int quo, div;
	if (!_non_madi.compare("")) 
	{
		quo = std::stoi(_madi);
		div = pow_10[_madi.length()] - 1;
	}
	else 
	{
		auto _front = _non_madi + _madi;
		quo = std::stoi(_front) - std::stoi(_non_madi);
		div = pow_10[_front.length()] - pow_10[_non_madi.length()];
	}
	int gcd = get_gcd(quo,div);
	int integer = std::stoi(_integer);

	return { quo/gcd + integer *div/gcd ,div/gcd };
}

int main() 
{
	std::string str;

	while (std::cin >> str) 
	{
		std::pair<int, int>  pair = to_rational(str);
		std::cout << str << " = " << pair.first << " / " << pair.second <<'\n';
	}

	return 0;
}
