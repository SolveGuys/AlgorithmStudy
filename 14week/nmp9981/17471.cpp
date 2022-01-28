#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int n;
const int maxi = 11;
const int inf = 98775432;
int city[maxi][maxi];//도시 인접행렬
int popular[maxi];//인구
bool selected[maxi];//조합선택
bool visit[maxi];//방문체크
int ans = inf;

//입력
void input(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>popular[i];
    }
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a;
        for(int j=0;j<a;j++){
            cin>>b;
            city[i][b] = 1;//중복간선으로인해 인접행렬로 구현
            city[b][i] = 1;
        }
    }
}

//연결하기
bool bfs(vector<int> v,bool flag){
    memset(visit,false,sizeof(visit));//초기화
    queue<int> q;
    q.push(v[0]);
    visit[v[0]] = true;//방문체크
    int cnt = 1;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        //다음지점
        for(int i=1;i<=n;i++){
            //연결되어 있고 해당 팀 소속이고 미방문
            if(city[x][i]==1 && selected[i]==flag && visit[i]==false){
                visit[i] = true;//방문체크
                cnt++;
                q.push(i);
            }
        }
    }
    //개수가 맞으면
    if(v.size()==cnt){
        return true;
    }
    return false;
}
//연결되었는지 검사
bool is_connect(){
    //팀 나누기
    vector<int> red,blue;
    for(int i=1;i<=n;i++){
        if(selected[i] == true){
            red.push_back(i);
        }else{
            blue.push_back(i);
        }
    }
    //팀인원수 체크
    if(red.size()==0 || blue.size()==0){
        return false;
    }
    //연결되는가?
    if(bfs(red,true)==false){
        return false;
    }
    if(bfs(blue,false)==false){
        return false;
    }
    return true;
}

//인구 차 계산
int diff_people(){
    int red_sum = 0;int blue_sum = 0;
    for(int i=1;i<=n;i++){
        if(selected[i]==true){
            red_sum+=popular[i];
        }else{
            blue_sum+=popular[i];
        }
    }
    int diff = abs(red_sum-blue_sum);
    return diff;
}
//조합나누기
void combi(int idx,int depth){
    if(depth>=1){
        if(is_connect()==true){//연결 되었으면
            ans = min(ans,diff_people());//계산후 갱신
        }
    }
    for(int i=idx;i<=n;i++){
        //미방문인 곳만 
        if(selected[i]==false){
            selected[i] = true;//조합에 넣기
            combi(i+1,depth+1);//재귀
            selected[i] = false;//원래대로
        }
    }
}
int main(){
    input();//입력
    combi(1,0);//조합나누기
    //결과
    if(ans==inf){
        cout<<-1;
    }else{
        cout<<ans;
    }
    return 0;
}
