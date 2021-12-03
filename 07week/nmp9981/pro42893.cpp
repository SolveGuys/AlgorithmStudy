#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//페이지 정보
struct page_info{
    int idx;//페이지
    int basic_point;//기본점수
    vector<string> out_link_list;//외부 연결 페이지
    double link_point;//링크점수
    double match_point;//매치점수
};

map<string, int> page_num;//본인을 가르키는 링크 저장
vector<page_info> Page;//각 페이지 정보를 담음

//정렬조건
bool cmp(page_info A, page_info B){
    if(A.match_point>=B.match_point){//매칭점수 기준
        if(A.match_point==B.match_point){//같다면
            if(A.idx>B.idx){
                return false;
            }
            return true;
        }
        return true;
    }
    return false;
}

//페이지명 찾기
string page_name_search(string s){
    //페이지명은 target이후에 있음
    string target = "<meta property=\"og:url\" content=\"https://";
    int idx = s.find(target);
    idx += target.length();//시작점
    
    //페이지명 등록
    string url = "";
    while(s[idx]!='\"'){
        url+=s[idx];
        idx++;
    }
    return url;
}

//기본점수 구하기
int find_word(string s, string w){
    string target1 = "<body>";
    string target2 = "/<body>";
    int idx1 = s.find(target1);
    idx1 += target1.length();//시작점
    int idx2 = s.find(target2);//끝점
    
    s = s.substr(idx1,idx2-idx1);//해당 구간의 문자열만 구함
    
    //단어의 수 세기
    int cnt = 0;
    string cur = "";
    for(int i=0;i<s.length();i++){
        //단어단위로 탐색
        if(isalpha(s[i])==0){//단어가 끝났다면
            if(cur==w){//단어를 찾음
                cnt++;
            }
            cur="";//초기화
        }else{
            cur+=s[i];
        }
    }
    return cnt;
}

//외부링크 구하기
vector<string> link_search(string s){
    vector<string> result;//Page[i]의 외부링크 담는 벡터
    string target = "<a href=\"https://";
    
    int idx = s.find(target);//시작지점
    while(idx!=-1){//못찾을때까지
        idx+=target.length();//링크의 시작지점
        string cur="";
        while(s[idx]!='\"'){
            cur+=s[idx];
            idx++;
        }
        
        result.push_back(cur);//링크등록
        s = s.substr(idx);//다음지점으로
        idx = s.find(target);
    }
    return result;
}

//링크 매치점수 구하기
void calculate_link(){
    for(int i=0;i<Page.size();i++){//각 페이지에 대해
        vector<string> v = Page[i].out_link_list;//i로가는 링크
        int v_size = v.size();//외부링크 개수
        
        for(int j=0;j<v_size;j++){//각 링크들 조사
            string s = v[j];
            //받는 링크가 없음
            if(page_num[s]==0){
                continue;
            }
            //링크점수 계산
            int target_idx = page_num[s]-1;
            Page[target_idx].link_point += ((double)Page[i].basic_point/(double)v_size);
        }
    }
    
    //매칭점수 구하기
    for(int i=0;i<Page.size();i++){
        Page[i].match_point = (double)Page[i].basic_point + (double)Page[i].link_point;
    }
    
    //정렬
    sort(Page.begin(),Page.end(),cmp);
}

int solution(string word, vector<string> pages) {
    int answer = 0;
    //단어를 소문자로 변환
    transform(word.begin(),word.end(),word.begin(),::tolower);
    
    //모든 페이지 탐색
    for(int i=0;i<pages.size();i++){
        //내용을 소문자로 변환
        string s = pages[i];
        transform(s.begin(),s.end(),s.begin(),::tolower);
        
        string name = page_name_search(s);//페이지명 찾기
        page_num[name] = i+1;
        int bp = find_word(s,word);//기본 점수
        vector<string> out_link = link_search(s);//외부링크 구하기
        Page.push_back({i,bp,out_link,0.0,0.0});//페이지에 넣기
    }
    
    //링크, 매치점수 구하기
    calculate_link();
    
    answer = Page[0].idx;//조건을 만족하는 가장 첫 페이지
    return answer;
}
