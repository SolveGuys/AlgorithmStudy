#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int,int>> bookTimeMinutes;//분으로 환산

//분으로 환산
void ChangeMinutes(vector<vector<string>> book_time){
    for(int i=0;i<book_time.size();i++){
        int startHour = stoi(book_time[i][0].substr(0,2));
        int startMinute = stoi(book_time[i][0].substr(3,2));
        int endHour = stoi(book_time[i][1].substr(0,2));
        int endMinute = stoi(book_time[i][1].substr(3,2));
        bookTimeMinutes.push_back({startHour*60+startMinute, endHour*60+endMinute});
    }
    sort(bookTimeMinutes.begin(), bookTimeMinutes.end());//시작 시각 순으로 정렬
}
//호텔 예약
int HotelBooking(){
    priority_queue<int,vector<int>,greater<int>> endTimeQueue;//끝나는 시각, 최소 힙
    endTimeQueue.push(bookTimeMinutes[0].second);
    int roomCount = 1;//방 개수
    
    for(int i=1;i<bookTimeMinutes.size();i++){
        int startTime = bookTimeMinutes[i].first;
        int endTime = bookTimeMinutes[i].second;
        if(endTimeQueue.top()+10 > startTime) roomCount++;//방을 늘림    
        else endTimeQueue.pop();//바로 이용 가능
        
        endTimeQueue.push(endTime);
    }
    return roomCount;
}
int solution(vector<vector<string>> book_time) {
    ChangeMinutes(book_time);//분으로 환산
    return HotelBooking();//호텔 예약
}
