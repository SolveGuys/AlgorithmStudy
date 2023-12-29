#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

map<int,int> tangerineKindCount;//각 크기별 귤의 개수
priority_queue<int> tangerineCount;
//박스에 담기
void BoxTangerine(vector<int> tangerine){
    int tangerineSize = tangerine.size();
    for(int i=0;i<tangerineSize;i++) tangerineKindCount[tangerine[i]]++;//박스에 담기
    for(auto num : tangerineKindCount) tangerineCount.push(num.second);//크기별 개수
}
//귤 종류의 개수 세기
int KindCount(int k){
    int cnt = 0;
    int sum = 0;
    while(!tangerineCount.empty()){
        sum+=tangerineCount.top();
        cnt++;
        tangerineCount.pop();
        if(sum>=k) return cnt;
    }
    return cnt;
}
int solution(int k, vector<int> tangerine) {
    BoxTangerine(tangerine);//박스에 담기
    return KindCount(k);//귤 종류 세기
}
