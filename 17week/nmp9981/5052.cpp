#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int t,n;
vector<string> tele;//전화번호

//입력
void input(){
    tele.clear();//초기화
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        tele.push_back(s);
    }
    sort(tele.begin(),tele.end());//정렬
}

//전화번호
void chk(){
    for(int i=1;i<tele.size();i++){
        string prev_cur = tele[i-1];
        string cur = tele[i];
        //이전 문자열의 크기가 더 크다면
        if(prev_cur.size()>cur.size()){
            continue;
        }
        //이전 문자열이 포함 되는가?
        if(prev_cur == cur.substr(0,prev_cur.size())){
            cout<<"NO\n";//일관성이 없다.
            return;
        }
    }
    cout<<"YES\n";//일관성이 있다.
}

int main(){
    //빠른 입출력
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    cin>>t;
    while(t--){
        input();//입력
        chk();//일관성이 있는가?
    }
    return 0;
}
