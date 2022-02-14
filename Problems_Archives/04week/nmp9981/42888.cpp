#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;//정답배열
    vector<string> uid;//유저아이디
    map<string,string> nick_info;//유저아이디, 닉네임
    stringstream ss;//공백을 구분하여 분리해줌
    string action;
    string id;
    string nickname;
    
    //액션에 따른 결과 
    for(int i=0;i<record.size();i++){
        ss.str(record[i]);
        ss>>action;
        if(action=="Enter"){
            ss>>id;
            ss>>nickname;
            answer.push_back("님이 들어왔습니다.");
            uid.push_back(id);//유저 아이디 등록
            nick_info[id] = nickname;//사전에 등록
        }else if(action == "Leave"){
            ss>>id;
            answer.push_back("님이 나갔습니다.");
            uid.push_back(id);
        }else if(action == "Change"){
            ss>>id;
            ss>>nickname;
            nick_info[id] = nickname;//이름갱신
        }
        ss.clear();
    }
    
    //결과출력
    for(int i=0;i<answer.size();i++){
        answer[i] = nick_info[uid[i]]+answer[i];
    }
    return answer;
}
