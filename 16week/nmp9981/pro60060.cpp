#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int trie_size = 26;//트라이 문자열 종류 개수
const int maxi = 10001;//문자 길이
//트라이 구조체
struct Trie{
    int count;
    bool finish;//끝나는 지점인가?
    Trie* next[trie_size];//trie_size개 문자에 대한 트라이
    //생성자
    Trie() : finish(false),count(1){
        memset(next,0,sizeof(next));
    }
    //소멸자
    ~Trie(){
        for(int i=0;i<trie_size;i++){
            if(next[i]){
                delete next[i];
            }
        }
    }
    //삽입
    void insert(const char* key){
        if(*key == '\0'){//문자열이 끝나는 지점이면
            finish = true;
        }else{
            int cur = *key-'a';//다음 문자열
            if(next[cur]==NULL){//다음 노드가 없는가?
                next[cur] = new Trie();//트리 생성
            }else{
                next[cur]->count++;//개수 증가
            }
            next[cur] -> insert(key+1);//다음문자 삽입
        }
    }
    //찾기
    int find(const char* key){
        if(*key=='?'){//?지점
            int cnt = 0;//개수 구하기
            //다음지점 탐색
            for(int k=0;k<trie_size;k++){
                if(next[k] != NULL){
                    cnt+=next[k]->count;
                }
            }
            return cnt;//개수 반환
        }
        int cur = *key-'a';//다음 문자열
        if(next[cur]==NULL){//다음 노드가 없는가?
            return 0;//찾는값이 없음
        }
        if(*(key+1)=='?'){//다음 지점이 ?라면
            return next[cur]->count;
        }
        return next[cur] -> find(key+1);//다음문자 탐색
    }
};

Trie *root[maxi];//정방향, AA??
Trie *reroot[maxi];//역방향, ???AB

vector<int> solution(vector<string> words, vector<string> queries) {
    int qsize = queries.size();//쿼리 문자 길이
    vector<int> answer(qsize,0);//초기화
    
    //트라이 만들기
    for(auto word : words){
        int wsize = word.size();//단어 길이
        //정방향 글자
        const char* wordChar = word.c_str();//string->char*로 변환
        //노드가 비었으면 새 트라이 생성
        if(root[wsize]==NULL){
            root[wsize] = new Trie();
        }
        //글자수에 맞춰 원소 넣기
        root[wsize]->insert(wordChar);
        
        //역방향 글자
        string reword = word;
        reverse(reword.begin(),reword.end());
        
        const char* rewordChar = reword.c_str();//string->char*로 변환
        //노드가 비었으면 새 트라이 생성
        if(reroot[wsize]==NULL){
            reroot[wsize] = new Trie();
        }
        //글자수에 맞춰 원소 넣기
        reroot[wsize]->insert(rewordChar);
    }
    
    //쿼리 확인
    int idx = 0;
    for(auto query : queries){
        int qsize = query.size();//쿼리 문자 길이
        
        //뒤에서 시작하는가, 정방향
        if(query[qsize-1]=='?'){
            const char* quChar = query.c_str();//string->char*로 변환
            //커리와 단어의 길이가 다르면
            if(root[qsize]==NULL){
                idx++;
                continue;
            }
            answer[idx] = root[qsize]->find(quChar);
        }else{//앞에서부터 시작, 역방향
            //역방향 쿼리
            string requery = query;
            reverse(requery.begin(),requery.end());
            
            const char* requChar = requery.c_str();//string->char*로 변환
            //커리와 단어의 길이가 다르면
            if(reroot[qsize]==NULL){
                idx++;
                continue;
            }
            answer[idx] = reroot[qsize]->find(requChar);
        }
        idx++;//다음 쿼리로
    }
    return answer;
}
