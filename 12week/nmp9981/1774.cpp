#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int n,m;
const int maxi = 1001;
double map_x[maxi];//x,y좌표
double map_y[maxi];
double cost = 0;
int parent[maxi];//k의 부모노드
vector<pair<double,pair<int,int>>> ufo;//거리와 번호쌍

//입력
void input(){
    cin>>n>>m;
    //우주선 입력
    for(int i=1;i<=n;i++){
        cin>>map_x[i]>>map_y[i];
        parent[i] = i;//부모노드 초기화
    }
    //거리배열 담기
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            double dx = map_x[j]-map_x[i];
            double dy = map_y[j]-map_y[i];
            double d = sqrt(dx*dx+dy*dy);
            ufo.push_back({d,{i,j}});
        }
    }
    //이미 연결된것 입력
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        ufo.push_back({0,{a,b}});//이미 연결된것은 0으로
    }
    sort(ufo.begin(),ufo.end());//거리순 정렬
}

//각 노드의 부모노드 찾기
int find(int x){
    if(parent[x]==x){//부모가 루트노드
        return x;
    }
    parent[x] = find(parent[x]);//거슬러 올라감
    return parent[x];
}

//크루스칼
void kruskal(){
    int node = 0;
    for(int i=0;i<ufo.size();i++){
        double dist = ufo[i].first;
        int x = ufo[i].second.first;
        int y = ufo[i].second.second;
        
        //루트노드가 서로 다르면 합체
        int a = find(x);
        int b = find(y);
        if(a!=b){
            parent[b] = a;//부모노드끼리 합체
            cost+=dist;
            node++;
        }
        
        //종료 및 출력
        if(node==n-1){
            printf("%.2f",cost);
            return;
        }
    }
}
int main(){
    input();//입력
    kruskal();//크루스칼 알고리즘
    return 0;
}
