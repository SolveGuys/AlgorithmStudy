#include <iostream>
#include <string>
using namespace std;

const int maxi = 2501;
int strSize;//문자열 길이
int maxPalin = 1;//최대 팰린드롬 길이
bool isPalin[maxi][maxi];//i~j번 문자열이 팰린드롬인가?

//배열 초기화
void initArray(string s){
    strSize = s.size();
    for(int i=0;i<strSize;i++) isPalin[i][i] = true;//1개
    for(int i=0;i<strSize-1;i++){//2개
        if(s[i]==s[i+1]) {
            isPalin[i][i+1] = true;
            maxPalin = 2;
        }
    }
}
//팰린드롬 길이
void Palindrome(string s){
    for(int siz=3;siz<=strSize;siz++){//팰린드롬 사이즈
        for(int i=0;i<strSize-siz+1;i++){//문자열 시작 지점
            if(isPalin[i+1][i+siz-2] && s[i]==s[i+siz-1]){//팰린드롬 조건 만족
                isPalin[i][i+siz-1] = true;
                maxPalin = siz;
            }
        }
    }
}
int solution(string s)
{
    initArray(s);//배열 초기화
    Palindrome(s);//팰린드롬 길이
    return maxPalin;
}
