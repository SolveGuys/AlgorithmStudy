#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string,int> genresCount;//각 장르별 출현 빈도
vector<pair<string,int>> musicFreq;//음악 빈도수, 장르
vector<pair<int,pair<string,int>>> playList;//재생 횟수, 장르, 인덱스

//내림차순 정렬
bool compare(pair<string,int> a,pair<string,int> b){
    return a.second > b.second;
}
bool compareVector(pair<int,pair<string,int>> a,pair<int,pair<string,int>> b){
    if(a.first==b.first){//재생 횟수가 같다면
        return a.second.second < b.second.second;//인덱스 오름차순
    }
    return a.first > b.first;//재생 횟수기준 내림차순
}

//각 장르별 출변 빈도 구하기
void Freq(vector<string> genres, vector<int> plays){
    //장르별 빈도
    for(int i=0;i<genres.size();i++){
        genresCount[genres[i]]+=plays[i];
        playList.push_back({plays[i],{genres[i],i}});//재생 횟수, 장르, 인덱스
    }
    musicFreq.assign(genresCount.begin(),genresCount.end());//맵을 벡터에 복사
    
    sort(musicFreq.begin(),musicFreq.end(),compare);//빈도수 기준으로 내림차순 정렬
    sort(playList.begin(),playList.end(),compareVector);//재생 횟수 내림차순 정렬
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    Freq(genres,plays);//빈도 구하기
    //출력
    for(int i=0;i<musicFreq.size();i++){//음악 장르 꺼내오기
        int cnt = 0;
        string genresName = musicFreq[i].first;//장르명
        for(int j=0;j<playList.size();j++){//플레이 리스트 둘러보면서
            //장르명 일치
            if(genresName==playList[j].second.first){
                answer.push_back(playList[j].second.second);
                cnt++;
            }
            if(cnt==2) break;//각 장르별 2개까지만
        }
    }
    return answer;
}
