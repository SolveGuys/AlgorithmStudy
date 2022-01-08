#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

stack<int> s;//삭제된 페이지
set<int> table;//현재 존재하는 페이지
set<int>::iterator cs;

//메인 함수
string solution(int n, int k, vector<string> cmd) {
    string answer(n,'X');//모두 X로 초기화
    //페이지를 모두 집합에 담기
    for(int i=0;i<n;i++){
        table.insert(i);
    }
    cs = table.find(k);//현재 커서
    
    //벡터 탐색
    for(string i : cmd){
        if(i[0]=='C'){//삭제
            s.push(*cs);//삭제된 페이지를 스택에 넣기
            cs = table.erase(cs);
            if(cs==table.end()){//마지막 페이지일 경우
                cs--;//한칸 위로
            }      
        }else if(i[0]=='Z'){//복구
            table.insert(s.top());
            s.pop();
        }else{
            int d = stoi(i.substr(2,i.size()));//이동량
            if(i[0]=='U'){//위로
                while(d--){
                    cs--;
                }
            }else if(i[0]=='D'){//아래로
                while(d--){
                    cs++;
                }
            }
        }
    }
    //현재 존재하는 행번호만 'O'로 바꾸기
    for(int i:table){
        answer[i]='O';
    }
    return answer;
}
