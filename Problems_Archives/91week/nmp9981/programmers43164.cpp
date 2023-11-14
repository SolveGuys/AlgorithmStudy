#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int maxi = 10001;
vector<string> answer;//경로
bool visit[maxi];//방문 여부 
bool isComplete = false;//완료 여부

//경로 탐색
void RoadSearch(string s,int cnt, vector<vector<string>> tickets){
    if(cnt==tickets.size()) isComplete = true;//모두 연결
    
    answer.push_back(s);
    //다음 지점
    for(int i=0;i<tickets.size();i++){
        if(!visit[i] && tickets[i][0]==s){//다음 지점 미방문, 현재 지점 일치
            visit[i] = true;
            RoadSearch(tickets[i][1],cnt+1,tickets);//다음 지점
            
            if(!isComplete){//완성 불가
                answer.pop_back();
                visit[i] = false;
            }
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(),tickets.end());//알파벳 순서가 앞서는 것부터
    RoadSearch("ICN",0,tickets);//경로 탐색
    return answer;
}
