#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int,vector<int>,greater<int>> pq;//최소힙
int cnt = 0;//횟수

//세팅
void Setting(vector<int> scoville){
    int scoSize = scoville.size();
    for(int i=0;i<scoSize;i++) pq.push(scoville[i]);
}
//음식 제작
int MakeFood(int k){
    while(!pq.empty()){
        if(pq.top()>=k) return cnt;//모든 음식이 k이상
        if(pq.size()==1) break;//더 이상 섞기 불가능
        
        //음식 섞기
        int firstScov = pq.top();
        pq.pop();
        int secondScov = pq.top();
        pq.pop();
        int newScov = firstScov+2*secondScov;
        
        pq.push(newScov);
        cnt++;
    }
    return -1;
}
int solution(vector<int> scoville, int K) {
    Setting(scoville);//세팅
    return MakeFood(K);//음식 제작
}
