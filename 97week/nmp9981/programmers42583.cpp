#include <string>
#include <vector>
#include <queue>
using namespace std;

queue<int> bridgeTruck;//다리에 있는 트럭
int sumWeight = 0;//무게 합

//다리 건너기
int CrossBridge(int bridge_length, int weight, vector<int> truck_weights){
    int idx = 0;//건너는 트럭의 번호
    int times = 0;//시간
    int truckTotalCount = truck_weights.size();//총 트럭 개수
    bridgeTruck.push(0);
    
    while(true){
        if(idx==truckTotalCount) {//마지막 트럭
            times+=bridge_length;
            break;
        }
         
        if(bridgeTruck.size() == bridge_length) {//다리 통과
            sumWeight -= bridgeTruck.front();
            bridgeTruck.pop();
        }
        
        if(sumWeight + truck_weights[idx] <= weight){//무게 만족
            sumWeight += truck_weights[idx];
            bridgeTruck.push(truck_weights[idx]);
            idx++;
        }else bridgeTruck.push(0);//무게 초과
        times++;
    }
    return times;
}
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    return CrossBridge(bridge_length, weight,truck_weights);//다리 건너기
}
