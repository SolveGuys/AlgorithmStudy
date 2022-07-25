#include <bits/stdc++.h>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    sort(timetable.begin(),timetable.end());
    vector<int> arr;
    for( auto &a : timetable)
    {
        arr.push_back(stoi(a.substr(0,2))*60  + stoi(a.substr(3,2)));
    }
    
    int result=0;
    int idx=0; // timetabld의 인덱스 (한명)
    int bus=540; //첫시간
    
    for(int i=1;i<=n;i++) //버스는 n번옴
    {
        int people=0; // 현재 몇명이 버스에 탓는지
        while(people<m && idx<arr.size()) // 현재탄인원이 최대인원보다 작고 인덱스가 전체보다 작아야함
        {
            if(arr[idx]<=bus){ // 탈수 있는지
                people++; //탑습인원 +1
                idx++; // 다음 인덱스
            }
            else break;
        }
        //검사 완료후 버스가 여유로운지 탐색
        if(i==n)
        {
            if(people<m) //더 탈수 있음
            {
                result=bus;
            }
            else //여유없음
            {
                result=arr[idx-1]-1; //마지막버스보다 1분 더빨리
            }
        }
        bus+=t; //버스시간 업뎃
    }
    
    int hours=result/60;
    if(hours<=9)
    {
        answer+="0"+to_string(hours)+":";
    }
    else
    {
        answer+=to_string(hours)+":";
    }
    
    int minutes=result % 60;
    if(minutes<=9)
    {
        answer+="0"+to_string(minutes);
    }
    else
    {
        answer+=to_string(minutes);
    }
    
    
    
    return answer;
}
