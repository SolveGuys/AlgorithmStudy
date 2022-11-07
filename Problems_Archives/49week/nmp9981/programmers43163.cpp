#include <string>
#include <vector>
#include <queue>
using namespace std;
const int maxi = 51;
bool visit[maxi];//방문 여부

//글자 수 차이
int DiffWord(string a,string b){
    int Diffcnt = 0;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]) Diffcnt++;//글자가 서로 다르다
    }
    return Diffcnt;
}
//단어 변환
int TranslateWord(string begin, string target, vector<string> words){
    queue<pair<string,int>> q;
    q.push({begin,0});
    
    while(!q.empty()){
        string word = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        //목표 도착
        if(word==target) return cnt;
        //다음 단어
        for(int i=0;i<words.size();i++){
            if(words[i]==word) continue;//같은 단어
            if(visit[i]==true) continue;//이미 방문
            if(DiffWord(words[i],word)==1){//1글자 차이
                visit[i] = true;
                q.push({words[i],cnt+1});
            }
        }
    }
    return 0;
}
int solution(string begin, string target, vector<string> words) {
    int answer = TranslateWord(begin,target,words);//단어 변환
    return answer;
}
