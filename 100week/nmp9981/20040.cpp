#include <iostream>

using namespace std;//이름공간 선언
using namespace chrono;
int n,m;
int parent[500001];//각 노드의 부모노드

//루트 노드 찾기
int find(int x){
    if(parent[x]==x){
        return x;
    }
    parent[x] = find(parent[x]);
    return parent[x];
}

//합치기
void merge(int x,int y){
    x = find(x);
    y = find(y);
    if(x==y){
        return;
    }else{
        parent[x] = y;
    }
}

//초기화
void init(){
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }
}

//입력
void input(){
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        if(find(a)==find(b)){//루트노드가 같으면 사이클
            cout<<i;
            return;
        }
        merge(a,b);
    }
    cout<<0;
    return;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    init();//초기화
    input();//입력
    return 0;
}
