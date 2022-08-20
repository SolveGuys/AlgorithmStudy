#include <string>
#include <vector>
using namespace std;

//max함수
inline int max(int x,int y){
    return x>y?x:y;
}
//연속한 0의 개수 세기
int ContinueZero(vector<int> stones,int x){
    int cnt = 0;//연속한 0의 개수
    int maxiCnt = 0;//연속한 0의 최대 갯수 
    for(int i=0;i<stones.size();i++){
        if(stones[i]-x<=0){
            cnt++;
        }else{
            maxiCnt = max(maxiCnt,cnt);//최댓값 갱신
            cnt=0;
        }
    }
    maxiCnt = max(maxiCnt,cnt);//최댓값 갱신
    return maxiCnt;
}
//징검다리 건너기
int cross(vector<int> stones,int k){
    //건너는 인원 수
    int start = 0;
    int end = 200000000;
    while(start<=end){
        int mid = (start+end)/2;//건너는 인원 수
        if(ContinueZero(stones,mid-1)>=k){//너무 많이 건넜다
            end = mid-1;
        }else{//좀 더 건널 수 있다.
            start = mid+1;
        }
    }
    return end;
}
int solution(vector<int> stones, int k) {
    int answer = cross(stones,k);//건너는 인원
    return answer;
}
