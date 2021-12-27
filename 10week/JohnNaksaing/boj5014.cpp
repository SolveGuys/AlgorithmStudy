#pragma once
#include <iostream>
#include <queue>
#include <vector>

struct elevator_info 
{
	int floor;
	int howmany_move;

	static std::vector<bool> bVisited;
};
std::vector<bool> elevator_info::bVisited;

template<typename Ty>
using search_ds_type = std::queue<Ty>;
using node = elevator_info;

int main()
{	
	int F, S, G, U, D;
	std::cin >> F >> S >> G >> U >> D;

	elevator_info::bVisited = std::vector<bool>(F+1,false);
	search_ds_type<node> elevator;

	node::bVisited[S] = true, elevator.push({ S,0 });
	
	int answer_howmany_move = -1;
	while (!elevator.empty()) 
	{
		node now = elevator.front();
		elevator.pop();

		int floor = now.floor;
		int moves = now.howmany_move;

		if (floor == G)
		{
			answer_howmany_move = moves;
			break;
		}

		if (floor + U <= F && !node::bVisited[floor + U])
			node::bVisited[floor + U] = true, elevator.push({ floor + U, moves + 1 });
		if (floor - D > 0 && !node::bVisited[floor - D])
			node::bVisited[floor - D] = true, elevator.push({ floor - D, moves + 1 });
	}

	if (answer_howmany_move == -1) std::cout << "use the stairs";
	else std::cout << answer_howmany_move;

	return 0;
}