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
    int idx=0;
    int bus=540;
    
    for(int i=1;i<=n;i++)
    {
        int next=0;
        while(next<m && idx<arr.size())
        {
            if(arr[idx]<=bus){
                next++;
                idx++;
            }
            else break;
        }
        
        if(i==n)
        {
            if(next<m)
            {
                result=bus;
            }
            else
            {
                result=arr[idx-1]-1;
            }
        }
        bus+=t;
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
