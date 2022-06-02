#include <string>
#include <vector>
#include <queue>
#include <iostream>

template<typename Ty>
class DoublePriorityQueue
{
	std::priority_queue<Ty, std::vector<Ty>, std::less<Ty>> pq_max;
	std::priority_queue<Ty, std::vector<Ty>, std::greater<Ty>> pq_min;
	int m_count = 0;
	bool bEmpty() { return m_count == 0; }
public:
	void Insert(Ty num);
	void Delete(int MinMax);
	void print();
	void act(char id, Ty data);
	std::vector<Ty> get()
	{
		if (bEmpty())
			return { 0,0 };
		return { pq_max.top(),pq_min.top() };
	}
};
template<typename Ty>
void DoublePriorityQueue<Ty>::act(char id, Ty data)
{
	if (id == 'I')
	{
		Insert(data);
	}
	else if (id == 'D')
	{
		Delete(data);
	}
	//print();
}

template<typename Ty>
void DoublePriorityQueue<Ty>::print() 
{
	std::vector<Ty> vec;
	std::cout << "min : ";
	while (!pq_min.empty())
	{
		Ty min = pq_min.top();
		std::cout << min << ' ';
		pq_min.pop();
		vec.push_back(min);
	}
	for (int i = 0; i < vec.size(); i++)
	{
		pq_min.push(vec[i]);
	}
	vec.clear();

	std::cout << '\n';
	std::cout << "max : ";
	while (!pq_max.empty())
	{
		Ty max = pq_max.top();
		std::cout << max << ' ';
		pq_max.pop();
		vec.push_back(max);
	}
	for (int i = 0; i < vec.size(); i++)
	{
		pq_max.push(vec[i]);
	}
	std::cout << '\n';
	std::cout << "count : " << m_count << '\n';
}

template<typename Ty>
void DoublePriorityQueue<Ty>::Insert(Ty num)
{
	pq_max.push(num);
	pq_min.push(num);
	m_count++;
}

template<typename Ty>
void DoublePriorityQueue<Ty>::Delete(int MinMax)
{
	if (bEmpty()) return;

	if (MinMax == 1)
		//delete max
	{
		pq_max.pop();
		m_count--;
	}
	else if (MinMax == -1)
		//delete min
	{
		pq_min.pop();
		m_count--;
	}

	if (bEmpty())
	{
		while (!pq_max.empty())pq_max.pop();
		while (!pq_min.empty())pq_min.pop();
	}
}

std::vector<int> solution(std::vector<std::string> operations) {

	DoublePriorityQueue<int> dpq;

	for (const auto& operation : operations)
	{
		char id = operation[0];
		int data = std::stoi(operation.substr(1));

		std::cout << id << ' ' << data << '\n';
		dpq.act(id,data);
	}
	std::vector<int> answer = dpq.get();

	return answer;
}