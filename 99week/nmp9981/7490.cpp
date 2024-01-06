#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
char cal[3] = {'+','-',' '};
vector<string> equals;

//입력
void input(){
    cin>>n;
    equals.clear();
}
//출력
void output(){
    for(int i=0;i<equals.size();i++) cout<<equals[i]<<"\n";
}
//0만들기
void Make0(int res,int num,string s){
    //모두 계산
    if(num==n+1){
        if(res==0) cout<<s<<"\n";//출력
        return;
    }
    //다음 연산자
    for(int i=0;i<3;i++){
        if(i==1){
            string next = s+"+"+to_string(num);
            Make0(res+num,num+1,next);
        }else if(i==2){
            string next = s+"-"+to_string(num);
            Make0(res-num,num+1,next);
        }else if(i==0){
            int preNum = num-1;//이전 숫자
            if(num==2){
                string next = "1 2";
                Make0(12,num+1,next);
            }else{
                if(s[2*num-5]=='+'){
                    string next = s+' '+to_string(num);
                    //cout<<next<<"\n";
                    Make0(res-preNum+(preNum*10+num),num+1,next);
                } 
                else if(s[2*num-5]=='-'){
                    string next = s+' '+to_string(num);
                    Make0(res+preNum-(preNum*10+num),num+1,next);
                }
            }
        }
    }
}
int main()
{
    int t;cin>>t;
    while(t--){
        input();//입력
        Make0(1,2,"1");//0만들기
        cout<<"\n";
    }
    return 0;
}
