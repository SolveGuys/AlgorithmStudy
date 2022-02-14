#include <iostream>
#include <vector>
#include <algorithm>
class Matrix3x3 
{
	int r, c, k;
	int row, col;
	std::array<std::array<int, 101>, 101> element;
	std::array<int, 101> counter;

	void R();
	void C();

	void sort(std::vector<int>& v);

	void print_element();

public:
	Matrix3x3(int r, int c, int k) : element(), counter(), r(r),c(c),k(k), row(3), col(3)
	{
		for (int i = 0; i < 3; i++) 
		{
			for (int j = 0; j < 3; j++)
				std::cin >> element[i][j];
		}
	}

	int get_time();
};

bool compare_pair(const std::pair<int, int>& a, const std::pair<int, int>& b)  //수의 등장 횟수가 커지는 순으로,,
{                                                
	if (a.second != b.second) return a.second < b.second;
	else return a.first < b.first;
}

void Matrix3x3::sort(std::vector<int>& v) 
{
	std::vector<std::pair<int, int>> tmp;

	counter.fill(0);
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i])
			counter[v[i]]++;
	}
	for (int i = 1; i <= 100; i++)
	{
		if (counter[i] > 0)
			tmp.push_back(std::make_pair(i, counter[i]));
	}

	std::sort(tmp.begin(), tmp.end(), compare_pair);

	v.clear();
	for (int i = 0; i < tmp.size(); i++)
	{
		if (v.size() > 100) break;
		v.push_back(tmp[i].first);
		v.push_back(tmp[i].second);
	}
}

//R 연산: 배열 A의 모든 행에 대해서 정렬을 수행한다. 행의 개수 ≥ 열의 개수인 경우에 적용된다.
void Matrix3x3::R() 
{
	int max_col = 0;
	for (int i = 0; i < row; i++)
	{
		std::vector<int> v;
		for (int j = 0; j < col; j++)
		{
			v.push_back(element[i][j]);
		}

		sort(v);

		int j = 0;
		max_col = std::max(max_col, (int)v.size());
		for (; j < v.size(); j++)
		{
			element[i][j] = v[j];
		}
		for (; j < col; j++)
		{
			element[i][j] = 0;
		}
	}
	col = max_col;
}

//C 연산: 배열 A의 모든 열에 대해서 정렬을 수행한다. 행의 개수 < 열의 개수인 경우에 적용된다.
void Matrix3x3::C() 
{
	int max_row = 0;
	for (int j = 0; j < col; j++)
	{
		std::vector<int> v;
		for (int i = 0; i < row; i++)
		{
			v.push_back(element[i][j]);
		}

		sort(v);

		int i = 0;
		max_row = std::max(max_row, (int)v.size());
		for (; i < v.size(); i++)
		{
			element[i][j] = v[i];
		}
		for (; i < row; i++)
		{
			element[i][j] = 0;
		}
	}
	row = max_row;
}

void Matrix3x3::print_element()
{
	std::cout << "\n";
	std::cout << row << " " << col << "\n";
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++) {
			std::cout << element[i][j] << " ";
		}
		std::cout << "\n";
	}
}

int Matrix3x3::get_time()
{
	int time = -1;
	while (time++ < 100) 
	{
		//print_element();
		//std::cout << time << " ";
		if (element[r-1][c-1] == k) return time;

		if (row >= col) R();
		else C();

	}
	return -1;
}


int main()
{

	int r, c, k;
	std::cin >> r >> c >> k;
	Matrix3x3 Matrix = Matrix3x3(r,c,k);
	
	std::cout << Matrix.get_time();

	return 0;
}
