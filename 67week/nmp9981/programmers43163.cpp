#include <string>
#include <vector>
#include <queue>
using namespace std;

const int maxi = 51;
bool visit[maxi];

//단어 차이
int DiffWord(string word, string nextWord){
    int diffCnt = 0;
    if(word.size()!=nextWord.size()) return 0;
    else{
        for(int i=0;i<word.size();i++){
            if(word[i]!=nextWord[i]) diffCnt++;
        }
    }
    return diffCnt;
}
int Change(string begin, string target, vector<string> words){
    queue<pair<string,int>> q;
    q.push({begin,0});
    
    while(!q.empty()){
        string word = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        //목표 단어
        if(word==target){
            return cnt;
        }
        //다음 단어 변환
        for(int i=0;i<words.size();i++){
            string nextWord = words[i];//다음 단어
            if(visit[i]) continue;//이미 변환한것
            int diff = DiffWord(word,nextWord);//서로 다른 글자 개수
        
            if(diff==1){
                visit[i] = true;
                q.push({nextWord,cnt+1});
            }
        }
    }
    return 0;
}
int solution(string begin, string target, vector<string> words) {
    return Change(begin, target,words);//변환
}
