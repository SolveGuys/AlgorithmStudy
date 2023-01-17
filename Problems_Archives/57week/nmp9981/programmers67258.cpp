#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int minLen = 987654321;//최소 구간 길이
set<string> gemstone;//보석 배열
map<string,int> jewel;//보석 종류, 개수
vector<int> answer;//정답 벡터

//보석 개수 세기
void JewelCount(vector<string> &gems){
    for(int i=0;i<gems.size();i++){
        jewel[gems[i]]=0;
        gemstone.insert(gems[i]);
    }
}
//쇼핑
void Shopping(vector<string> &gems){
    int gemSize = gemstone.size();//보석 종류 수
    int start = 0;int end = 0;//시작,종료 위치
    int left,right;//구간 길이
    int cnt = 0;//현재 보석의 개수
    while(true){
        //﻿모든 종류의 보석이 있다.
        if(gemSize==cnt){
            //구간 길이 갱신
            if(minLen>end-start){
                minLen = end-start;
                left = start;
                right = end;
            }
            //시작 지점
            if(jewel[gems[start]]>1){
                jewel[gems[start]]--;
                start++;
            }else{//보석 종류 수 감소
                jewel[gems[start]]--;
                start++;
                cnt--;
            }
        }else if(end==gems.size()) break;//종료
        else{//보석의 개수가 다르다.
            if(jewel[gems[end]]==0) cnt++;//보석 종류 증가
            jewel[gems[end]]++;
            end++;
        }
    }
    //정답
    answer.push_back(left+1);
    answer.push_back(right);
}
vector<int> solution(vector<string> gems) {
    JewelCount(gems);//보석 개수 세기
    Shopping(gems);//쇼핑
    return answer;
}
