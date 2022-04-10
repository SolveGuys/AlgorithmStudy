#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

const int EMPTY = -1;

int dock(int i, std::vector<int>& gates) 
{
	if (gates[i] == EMPTY)
	{
		return gates[i] = i;
	}
	else 
	{
		return gates[i] = dock(gates[i],gates);
	}
}

int main() 
{
	int G,P;
	scanf("%d %d", &G, &P);
	std::vector<int> vec_plane(P), vec_gate(G+1,EMPTY);
	for(int i = 0; i < P; i++)
	{
		scanf("%d", &vec_plane[i]);
	}


	int docked = 0;
	for (int i : vec_plane) 
	{
		int gate = dock(i, vec_gate);
		if (gate == 0)
		{
			break;
		}
		else 
		{
			docked++;
			vec_gate[gate] = gate-1;
		}
	}

	printf("%d",docked);

	return 0; 
}