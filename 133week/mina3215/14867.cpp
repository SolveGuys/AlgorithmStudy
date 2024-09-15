#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#include<set>

using namespace std;

int a, b, c, d;
int ans = -1;
set<pair<int, int>> visited;

vector<pair<int, int>> next(int a_water, int b_water) {
	vector<pair<int, int>> available;
	// fill(a), fill(b), empty(a), empty(b)
	available.push_back({ a,b_water });
	available.push_back({ a_water, b });
	available.push_back({ 0, b_water });
	available.push_back({ a_water,0 });

	//move(a_water -> b_water)
	int empty_a = a - a_water;
	int empty_b = b - b_water;
	if (empty_b >= a_water)
		available.push_back({ 0,b_water + a_water });
	else
		available.push_back({ a_water - empty_b,b });
	if (empty_a >= b_water)
		available.push_back({ a_water + b_water,0 });
	else
		available.push_back({ a,b_water - empty_a });
	return available;
}


void BFS() {
	if (c == 0 && d == 0) {
		ans = 0;
		return;
	}
	queue<pair<pair<int,int>,int>> q;
	q.push({ {0,0},0 });
	visited.insert({ 0,0 });
	while (!q.empty()) {
		pair<int, int> water;
		int a_water, b_water, k;
		tie(water, k) = q.front();
		tie(a_water, b_water) = water;
		q.pop();
		vector<pair<int,int>> nxt = next(a_water, b_water);
		for (pair<int, int> p : nxt) {
			if (visited.find(p) != visited.end())
				continue;
			if (c == p.first && d == p.second) {
				ans = k+1;
				return;
			}
			visited.insert(p);
			q.push({ p,k + 1 });
		}
	}
}


int main() {
	cin >> a >> b >> c >> d;
	BFS();
	cout << ans;
}