#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int maxi = 11;
map<string,int> wordHouse;//단어 모음
vector<string> menu[maxi][21];//자릿수별 단어 넣기
int wordLength[maxi];//각 자릿수별 가장 많이 주문한 메뉴

//문자열 조합구하기
void StringComb(int idx,string order,string word){
    //2개 이상이면
    if(word.size()>=2){
        //메뉴 개수
        wordHouse[word]++;//개수 증가
        wordLength[word.size()] = max(wordLength[word.size()],wordHouse[word]);//더 큰값
        menu[word.size()][wordHouse[word]].push_back(word);
    }
    //다음 조합
    for(int i=idx;i<order.size();i++){
        word.push_back(order[i]);
        StringComb(i+1,order,word);//재귀
        word.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    //각 문자열에 대해 조합구하기
    for(string order : orders){//각 문자열
        sort(order.begin(),order.end());//각 문자열 정렬
        StringComb(0,order,"");//조합 구하기
    }
    //각 코스별 최대 메뉴 구하기
    for(int i:course){
        if(wordLength[i]<2) continue;
        for(string s:menu[i][wordLength[i]]){
            answer.push_back(s);
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}
