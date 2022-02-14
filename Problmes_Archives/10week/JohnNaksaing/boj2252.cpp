#include <vector>
#include <queue>
#include <iostream>

struct student
{
	int id;
	int ref_count = 0;

	std::vector<int> vec_afters;

	student() {}
};

int main()
{
	//input assemblies
	int N,M;
	std::cin >> N >> M;
	std::vector<student> vec_students(N+1);

	for (int i = 1; i <= N; i++) 
	{
		vec_students[i].id = i;	
	}

	for (int i = 0; i < M; i++) 
	{
		int former, latter;
		std::cin >> former >> latter;

		vec_students[latter].ref_count++;
		vec_students[former].vec_afters.push_back(latter);
	}

	//topology sorting
	std::queue<student> queue_topology;

	for (int i = 1; i <= N; i++)
	{
		student ith = vec_students[i];

		if (ith.ref_count == 0)
			queue_topology.push(ith);
	}
	std::vector<int> vec_sorted;

	while (!queue_topology.empty()) 
	{
		student st_now = queue_topology.front();
		queue_topology.pop();
		
		vec_sorted.push_back(st_now.id);

		for (int next_id : st_now.vec_afters) 
		{			
			if(--vec_students[next_id].ref_count == 0)
				queue_topology.push(vec_students[next_id]);
		}

	}

	//printing result
	for (int i = 0; i < vec_sorted.size(); i++)
		std::cout << vec_sorted[i] << " ";

	return 0;
}