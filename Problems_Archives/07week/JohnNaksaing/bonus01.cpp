#include <vector>
#include <memory>
#include <functional>
#include <string>
class Rule_base
{
public:
	virtual ~Rule_base() = default;
};

template<typename ... input>
class Rule : public Rule_base
{
	using rule_type = std::function<bool(input ...)>;

	rule_type inner_rule;
public:
	Rule(const rule_type& rule) : inner_rule(rule) {};
	//~Rule()  = default;
	bool operator()(input ... inputs)
	{
		return inner_rule(inputs ...);
	}
};

void solve(const std::vector<int>& vec)
{
	const std::vector<int> straight_nums = { 1,2,4,5,7 };
	const std::vector<int> curved_nums = { 3,6,7,8,0 };

	Rule<int>  rule1([&vec, &straight_nums](int i)->bool {
		std::string str_i = std::to_string(vec[i]);

		for (int straight_num : straight_nums)
		{
			if (str_i.find(std::to_string(straight_num)) != std::string::npos) return true;
		}

		return false;
	});
	Rule<int>  rule2([&vec](int i)->bool { return i != vec.size() - 1; });
	Rule<int&> rule3([&vec](int idx)->bool
		{
			for (int i = 0; i < idx; i++)
				if (vec[i] == vec[idx]) return true;

			return false;
		});

#define make_stone( x ) std::make_shared<Rule_base>( x ) 
	std::vector<std::shared_ptr<Rule_base>> Gauntlet = { make_stone(rule1), make_stone(rule2), make_stone(rule3) };
#undef make_stone(x)

	for (auto stone : Gauntlet)
	{
		//stone(3);
	}

	std::vector<int> answer;
	for (int i = 0; i < vec.size(); i++)
	{
		if (rule3(i) && rule2(i) && rule1(i)) answer.push_back(-1);

		else answer.push_back(vec[i]);
	}

	for (auto a : answer) std::cout << a << " ";
	std::cout << "\n";

	//return answer;
}

int main()
{
	std::vector<int> vec = { 2, 1, 2, 3, 4, 8, 4, 2, 6, 8, 1, 7, 8 };
	solve(vec);

	return 0;
}