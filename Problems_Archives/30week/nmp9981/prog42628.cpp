#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> solution(vector<string> s) {
    vector<int> answer;//정답 배열
    priority_queue<int> max_pq;//최대힙
    priority_queue<int,vector<int>,greater<int>> min_pq;//최소힙
    map<int,bool> dict;//x가 중복되어 있는가?
    
    for(int i=0;i<s.size();i++){
        string str_num = s[i].substr(2);//문자열 추출
        int num = stoi(str_num);//문자열->숫자
        if(s[i][0] == 'I'){//삽입
            max_pq.push(num);
            min_pq.push(num);
            dict[num] = true;//중복 표시
        }else if(s[i] == "D 1"){//최댓값 삭제
            //최소값으로 삭제된 수는 스킵
            while(!max_pq.empty() && !dict[max_pq.top()]) max_pq.pop();
            
            if(!max_pq.empty()){
                dict[max_pq.top()] = false;
                max_pq.pop();
            }
        }else if(s[i] == "D -1"){//최솟값 삭제
            //최대값으로 삭제된 수는 스킵
            while(!min_pq.empty() && !dict[min_pq.top()]) min_pq.pop();
            if(!min_pq.empty()){
                dict[min_pq.top()] = false;
                min_pq.pop();
            }
        }
    }
    //최소값으로 삭제된 수는 스킵
    while(!max_pq.empty() && !dict[max_pq.top()]) max_pq.pop();
    //최대값으로 삭제된 수는 스킵
    while(!min_pq.empty() && !dict[min_pq.top()]) min_pq.pop();
    
    //출력
    if(!max_pq.empty() && !min_pq.empty()){//둘다 비어있지 않으면
        answer.push_back(max_pq.top());
        answer.push_back(min_pq.top());
    }else{//비어있으면
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}
