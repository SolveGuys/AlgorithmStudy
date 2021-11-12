#include <iostream>
#include <algorithm>
#include <vector>

template<typename Package>
bool compare(Package a, Package b) {
	if (a.to == b.to)
        return a.from < b.from;
    else return a.to < b.to;
}

int main() {
	int n,c,m;
	std::cin >> n >> c;
	std::cin >> m;
    
    struct Package {
        int from;
        int to;
        int weight;
        
        Package(int from, int to, int weight) : from(from),to(to),weight(weight){};
        Package() : from{0},to{0},weight{0} {};
        //Package(const Package& P) : from(P.from),to(P.to),weight(P.weight){};
    };

    //m+1? 10001?
    std::vector<int> capacity(m+9);
    //m? 10000?
    std::vector<Package> Packages(m);
    
    for (int i = 0; i < m; i++)
    {
    	//cin >> Packages[i].from >> Packages[i].to >> Packages[i].weight;
        int from, to, weight;
        std::cin >> from >> to >> weight;
        Packages[i] = Package(from,to,weight);
    }
	
	sort(Packages.begin(), Packages.begin() + m, compare<Package>);
    
    int result = 0;
	for (int i = 0; i < m; i++)
    { 
    
		int maxweight = 0;
		for (int j = Packages[i].from; j < Packages[i].to; j++)
			maxweight = std::max(capacity[j], maxweight);

		int val = std::min(Packages[i].weight, c - maxweight);
		result += val;
		
		for (int j = Packages[i].from; j < Packages[i].to; j++)
			capacity[j] += val; // 택배 경로에 화물 지나감 반영
	}
	
	std::cout << result;
    return 0;
}