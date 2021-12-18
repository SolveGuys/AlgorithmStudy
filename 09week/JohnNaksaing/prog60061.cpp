#include <vector>
#include <set>
#include <iostream>
using building_ty = std::set<std::vector<int>>;

bool bVaild(const building_ty& building) 
{
	for (auto& frame : building) 
	{
		int x = frame[0], y = frame[1], a = frame[2];

#define  bSearch(...) ( building.find(__VA_ARGS__) != building.end() ) 
		//기둥은 바닥 위에 있거나 보의 한쪽 끝 부분 위에 있거나, 또는 다른 기둥 위에 있어야 합니다.
		if (a - 1) //a == 0 : pillar
		{
			if (y == 0 || bSearch({ x,y - 1,0 }) || bSearch({ x - 1, y, 1 }) || bSearch({ x, y, 1 }))
				continue;
			else return false;
		}
		//보는 한쪽 끝 부분이 기둥 위에 있거나, 또는 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다.
		else //a == 1 : beam
		{
			if (bSearch({ x, y - 1, 0 }) || bSearch({ x + 1, y - 1, 0 }) || bSearch({ x + 1, y, 1 }) && bSearch({ x - 1, y, 1 }))
				continue;
			else return false;
		}
	}
#undef bSearch
	return true;
}

std::vector<std::vector<int>> solution(int n, std::vector<std::vector<int>> build_frame) {

	std::vector<std::vector<int>> answer;
	building_ty building;

	for(const std::vector<int>& task : build_frame)
	{
		int x = task[0], y = task[1], a = task[2], b = task[3];
		std::vector<int> new_frame = {x,y,a};
		if (b-1) //b == 0
		{
			building.erase(new_frame);
			if(!bVaild(building)) building.insert(new_frame);
		}
		else //b == 1 
		{
			building.insert(new_frame);
			if (!bVaild(building)) building.erase(new_frame);
		}
	}
	
	for (const auto& frame : building)
	{
		answer.push_back(frame);
	}

	return answer;
}
