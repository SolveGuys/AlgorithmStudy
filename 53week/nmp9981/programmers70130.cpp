#include <string>
#include <vector>
#include <map>
using namespace std;
map<int,int> numCnt;//각 숫자의 등장횟수

//max
inline int max(int x,int y){
    return x>y?x:y;
}
//스타 수열 구하기
int Star(vector<int> a){
    int starLen = 0;//스타 수열의 길이
    //각 숫자의 등장횟수 세기
    for(int i=0;i<a.size();i++) numCnt[a[i]]++;
    //각 기준 숫자별 탐색
    for(auto i:numCnt){
        if(i.second*2<=starLen) continue;//기존 길이 이하
        int Len = 0;//스타 수열 길이
        for(int j=0;j<a.size()-1;j++){
            //교집합 유무
            if(a[j]!=i.first && a[j+1]!=i.first) continue;
            //같은 숫자
            if(a[j]==a[j+1]) continue;
            Len+=2;//스타 수열 길이 증가
            j++;
        }
        starLen = max(starLen,Len);//최대 길이 갱신
    }
    return starLen;
}
int solution(vector<int> a) {
    int answer = -1;
    if(a.size()<2) answer = 0;//예외처리
    else answer = Star(a);//스타 수열 구하기
    return answer;
}
