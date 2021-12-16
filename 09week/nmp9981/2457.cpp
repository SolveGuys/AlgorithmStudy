#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

//꽃의 정보
struct flower{
    int st,end;//시작, 끝
};

int n;//전체 꽃의 수
vector<flower> f;//꽃들을 담는 배열
int day[13] = {0,0,31,28,31,30,31,30,31,31,30,31,30};//날짜
int sum_day[13];

//달력
void calender(){
    for(int i=1;i<=12;i++){
        sum_day[i] = sum_day[i-1]+day[i];
    }
}

//시작날짜를 기준으로 정렬
bool cmp(const flower& A, const flower& B){
    if(A.st == B.st){//같으면 내림차순
        return A.end > B.end;
    }
    return A.st < B.st;
}

//입력
void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b,c,d,s,e;
        cin>>a>>b>>c>>d;
        s = sum_day[a]+b;//시작 날짜
        e = sum_day[c]+d;//종료 날짜
        f.push_back({s,e});//시작, 종료, 차이
    }
    sort(f.begin(),f.end(),cmp);//정렬
}

//3.1~11.30까지의 꽃들의 개수
int garden(){
    int close = 0,beforeclose = 60,ans = 0,flag = 1;
    //다음지점부터 탐색
    for(int i=0;i<n;i++){
        //날짜가 사이에 끼어 있으면
        if(f[i].st<=beforeclose){
            if(f[i].end>close){
                close = f[i].end;
            }    
            //범위를 넘으면
            if(close>=335){//지는 날이 12/1이후여야함
                break;
            }
        }else if(f[i].st>beforeclose){
            //사이에 끼어있지 않은 경우
            if(f[i].st>close){
                return 0;
            }
            ans++;//개수 증가
            beforeclose = close;//체크포인트 갱신
            close = f[i].end;
        }
    }
    //다 못채운 경우(11/30이전)
    if(close<=334){
        return 0;
    }
    return ans+1;//기본적으로 1개는 채워져있음
}

int main(){
    calender();//달력
    input();//입력
    cout<<garden()<<"\n";//꽃들의 개수
    return 0;
}
