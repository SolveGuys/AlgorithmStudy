#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int LANG = 3 + 1;
const int WEB = 2 + 1;
const int CAREER = 2 + 1;
const int FOOD = 2 + 1;
vector<int> db[LANG][WEB][CAREER][FOOD];

const int cpp = 0, java = 1, python = 2, all_lang = 3;
const int frontend = 0, backend = 1, all_web = 2;
const int junior = 0, senior = 1, all_career = 2;
const int chicken = 0, pizza = 1, all_food = 2;

vector<string> parse(const string& s)
{
	size_t start = 0;
	size_t end = s.find_first_of(' ');

	std::vector<std::string> output;

	while (end <= std::string::npos)
	{
		output.emplace_back(s.substr(start, end - start));

		if (end == std::string::npos)
			break;

		start = end + 1;
		end = s.find_first_of(' ', start);
	}

	return output;
}
vector<int> solution(vector<string> info, vector<string> query) {

	for (int i = 0; i < info.size(); i++)
	{
		vector<string> parsed = parse(info[i]);
		int lang = -1, web = -1, career = -1, food = -1;

		lang = parsed[0] == "cpp" ? cpp : (parsed[0] == "java" ? java : python);
		web = parsed[1] == "frontend" ? frontend : backend;
		career = parsed[2] == "junior" ? junior : senior;
		food = parsed[3] == "chicken" ? chicken : pizza;

		db[lang][web][career][food].push_back(stoi(parsed[4]));
		//db[all_lang][all_web][all_career][all_food].push_back(stoi(parsed[4]));
	}


	vector<int> answer;
	struct range 
	{
		int begin, end;
		range(int i, int j) :begin(i), end(j) {}
		range(int i):begin(i),end(i) {}
		range() {}
	};
	for (int i = 0; i < query.size(); i++)
	{
		vector<string> parsed = parse(query[i]);

		range lang , web , career , food;

		lang = parsed[0] == "-" ? range(0, 2) : (parsed[0] == "cpp" ? range(cpp) : (parsed[0] == "java" ? range(java) : range(python)));
		web = parsed[2] == "-" ? range(frontend,backend) : (parsed[2] == "frontend" ? range(frontend): range(backend));
		career = parsed[4] == "-" ? range(junior,senior) : (parsed[4] == "junior" ? range(junior) : range(senior));
		food = parsed[6] == "-" ? range(chicken,pizza) : (parsed[6] == "chicken" ? range(chicken) : range(pizza));

		int score = stoi(parsed[7]);

		int g_a = 0;
		for (int a = lang.begin; a <= lang.end; a++)
		for (int b = web.begin; b <= web.end; b++)
		for (int c = career.begin; c <= career.end; c++)
		for (int d = food.begin; d <= food.end; d++)
		{
			auto& current_db = db[a][b][c][d];
			sort(current_db.begin(), current_db.end());

			int a = current_db.end() - lower_bound(current_db.begin(), current_db.end(), score);
			g_a += a;
		}
		answer.push_back(g_a);
		//cout << lang << ' ' << web << ' ' << career << ' ' << food << '\n';
	}

	return answer;
}