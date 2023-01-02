#include <string>
#include <vector>
using namespace std;

vector<int> answer;
vector<int> bow;//화살 결과
vector<int> getScore;//어디서 점수를 얻을 것인가
bool isWin = false;
int maxDiff = 0;//최고 점수차

//점수 세기
void Judge(int n,vector<int> getScore,vector<int> apach){
    int arrow = 0;//사용 화살 개수
    int apachScore = 0;int lionScore = 0;//각 점수
    for(int i=0;i<getScore.size();i++){
        if(getScore[i]==1){//라이언의 득점
            arrow+=(apach[i]+1);
            lionScore+=(10-i);
        }else if(getScore[i]==0 && apach[i]>=1) apachScore+=(10-i);//어파치 득점
    }
    int diff = lionScore-apachScore;//점수 차
    
    //라이언의 승리
    if(arrow<=n && diff>=maxDiff && diff>=1){//화살 개수 충분하고 더 큰 점수차가 나오면
        isWin = true;//승리
        //득점 결과
        bow.clear();
        for(int i=0;i<getScore.size();i++){
            if(getScore[i]==1) bow.push_back(apach[i]+1);
            else bow.push_back(0);
        }
        bow.push_back(n-arrow);//마지막에 0점 몰아주기
        
        //동점인 경우
        if(diff == maxDiff){
            for(int i=answer.size()-1;i>=0;i--){//더 낮은 점수가 많으면 갱신
                if(answer[i] < bow[i]) {
                    answer = bow;
                    break;
                }
            }
        }else{
            answer = bow;maxDiff = diff;//갱신
        }
    }
}
//화살 쏘기
void Shoot(int cnt,int n, vector<int> info){
    //0점 제외 모두 결과가 나옴
    if(cnt == 10){
        Judge(n,getScore,info);//점수 세기
        return;
    }
    //화살 쏘기
    for(int i=0;i<=1;i++){
        getScore.push_back(i);
        Shoot(cnt+1,n,info);
        getScore.pop_back();
    }
}
vector<int> solution(int n, vector<int> info) {
    Shoot(0,n,info);//화살 쏘기
    if(isWin == false) answer.push_back(-1);//우승 불가능 할 경우
    return answer;
}
