#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int num[1000002];
int rnum[1000002];
set<int> s;
set<int> rs;
int solution(vector<int> topping) {

    for (int i = 0; i < topping.size();i++) {
        s.insert(topping[i]);
        num[i] = s.size();
    }

    for (int i = topping.size() - 1; i >= 0; i--) {
        rs.insert(topping[i]);
        rnum[i] = rs.size();
    }

    int answer = 0;

    for (int i = 0; i < topping.size() - 1;i++) {
        if (num[i] == rnum[i + 1]) answer++;
    }

    return answer;
}