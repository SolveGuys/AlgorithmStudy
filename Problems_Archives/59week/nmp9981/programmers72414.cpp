#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

//동영상 정보
struct playTime{
    int startTime,endTime;
};
vector<playTime> vedio;//동영상
const int maxi = 360001;//최대 시간
long long vedioCount[maxi];//각 시각별 동영상 총 개수
int addTime;//광고 재생시간
int playTime;//총 재생시간
string answer = "";//정답

//숫자를 시간으로 바꾸기
string ChangeTime(int x){
    string Times = "";
    int hours = x/3600;
    int minutes = (x/60)%60;
    int seconds = x%60;
    
    //한자리수
    Times+= (hours<=9?"0"+to_string(hours)+":":to_string(hours)+":");
    Times+= (minutes<=9?"0"+to_string(minutes)+":":to_string(minutes)+":");
    Times+= (seconds<=9?"0"+to_string(seconds):to_string(seconds));
    return Times;
}
//숫자로 바꾸기
void ChangeNumber(vector<string> log,string adv_t,string play_t){
    addTime = stoi(adv_t.substr(6,2))+stoi(adv_t.substr(3,2))*60+stoi(adv_t.substr(0,2))*3600;
    playTime = stoi(play_t.substr(6,2))+stoi(play_t.substr(3,2))*60+stoi(play_t.substr(0,2))*3600;
    for(int i=0;i<log.size();i++){
        int stTime = stoi(log[i].substr(6,2))+stoi(log[i].substr(3,2))*60+stoi(log[i].substr(0,2))*3600;
        int edTime = stoi(log[i].substr(15,2))+stoi(log[i].substr(12,2))*60+stoi(log[i].substr(9,2))*3600;
        vedio.push_back({stTime,edTime});
    }
}
//동영상 개수 세기
void CountVideo(){
    int vedioSize = vedio.size();
    for(int i=0;i<vedioSize;i++){
        int start = vedio[i].startTime;//시작 시각
        int end = vedio[i].endTime;//종료 시각
        vedioCount[start]+=1;//동영상 들어옴
        vedioCount[end]-=1;//동영상 나감
    }
    for(int i=1;i<=playTime;i++) vedioCount[i] += vedioCount[i-1];//시각별 총 동영상 개수
}
//광고 넣기
void AD_Insert(){
    for(int i=1;i<=playTime;i++) vedioCount[i] += vedioCount[i-1];//누적 시청자 수
    int AD_start = 0;long long maxCount = vedioCount[addTime-1];
    for(int i=1;i<=playTime-addTime+1;i++){
        long long people = vedioCount[i+addTime-1]-vedioCount[i-1];
        if(maxCount < people){//더 많은 조회수
            maxCount = people;
            AD_start = i;
        }
    }
    answer=ChangeTime(AD_start);//시간 형식으로 변환
}
string solution(string play_time, string adv_time, vector<string> logs) {
    ChangeNumber(logs,adv_time,play_time);//숫자로 바꾸기
    CountVideo();//동영상 개수 세기
    AD_Insert();//광고 넣기
    return answer;
}
