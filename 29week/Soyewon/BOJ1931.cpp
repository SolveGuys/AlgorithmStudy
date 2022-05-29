#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

pair<int,int>arr[100001];
int main(){
    int n,end,start,res=1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>start>>end;
        arr[i]={end,start}; // end기준으로 정렬시켜주기 위해 end먼저 삽입
    }
    sort(arr,arr+n); // 종료 시간 오름차순 정렬
    int t=arr[0].first; // 1번째로 끝나는 회의 종료시간 저장
    for(int i=1;i<n;i++){
        if(t<=arr[i].second){ 
            // 이미 정렬된 상태이므로 가장 먼저 조건에 맞는 시작시간이 현재 강의 종료 후 시작되는 가장 빠른 강의
            res++;
            t=arr[i].first; // 갱신
        }
    }
    cout<<res;
}
