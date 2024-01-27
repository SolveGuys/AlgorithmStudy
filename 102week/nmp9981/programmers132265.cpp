#include <string>
#include <vector>
#include <cstring>
using namespace std;

const int maxi = 1000001;
int toppingSize;//토핑 벡터 길이
bool visit[maxi];//방문 여부
int topCaseNum[maxi];//1~n번까지의 토핑 가짓수
int topCaseNumReverse[maxi];//n~1번까지의 토킹 가짓수

//토핑하기
void SetTopping(vector<int> topping){
    toppingSize =topping.size();
    //정방향
    topCaseNum[0] = 1;
    visit[topping[0]] = true;
    for(int i=1;i<toppingSize;i++){//자르는 위치
        if(!visit[topping[i]]){//미방문
            visit[topping[i]] = true;
            topCaseNum[i] = topCaseNum[i-1]+1; 
        }else topCaseNum[i] = topCaseNum[i-1]; 
    }
    memset(visit,false,sizeof(visit));//초기화
    //역방향
    topCaseNumReverse[toppingSize-1] = 1;
    visit[topping[toppingSize-1]] = true;
    for(int i=toppingSize-2;i>=0;i--){//자르는 위치
        if(!visit[topping[i]]){//미방문
            visit[topping[i]] = true;
            topCaseNumReverse[i] = topCaseNumReverse[i+1]+1; 
        }else topCaseNumReverse[i] = topCaseNumReverse[i+1]; 
    }
}

//토핑 자르기
int CutTopping(){
    int caseNum = 0;
    for(int i=0;i<toppingSize-1;i++){//자르는 위치
        if(topCaseNum[i]==topCaseNumReverse[i+1]) caseNum+=1;//서로 가짓 수가 같음
    }
    return caseNum;
}

int solution(vector<int> topping) {
    SetTopping(topping);//토핑하기
    return CutTopping();//토핑 자르기
}
