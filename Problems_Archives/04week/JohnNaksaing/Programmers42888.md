


# 프로그래머스 오픈채팅방

### 난이도 : Level 2
[문제 보러가기](https://programmers.co.kr/learn/courses/30/lessons/42888)

오픈 채팅창에서 중복 닉네임을 허용하고, 마지막으로 변경한 이름으로 채팅창 출입로그를 만드는 문제입니다.

## 자료구조
```vector<pair<string,char>> in_outs```에 ```uid```와 ```입/출```을 기록하고,  ```unordered_map<string, string> dict```에 ```uid```에 해당하는 ```이름```을 기록하였습니다.  
순서대로 ```dict```에 기록한다면 마지막에 변경한 이름으로 덮어쓰이는 걸 이용했습니다.
첫 번째 범위 for문에서 자료구조에 기록하고, 두번째 for문에서 자료구조를 통해 ```answer```를 유추하도록 구현했습니다.
## 풀이

```c++
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string,char>> in_outs;
    unordered_map<string, string> dict {};
    
    for(string query : record)
    {
        auto pos = query.find(" ");
        string e_l_c = query.substr(0,pos);
        string uid_name = query.substr(pos+1);
        auto pos1 = uid_name.find(" ");
        string uid = uid_name.substr(0,pos1);
        string name = uid_name.substr(pos1+1);
        switch(e_l_c[0])
        {
            case 'E':
                dict[uid] = name;
                in_outs.push_back(make_pair(uid,'E'));
                break;
            case 'L':
                in_outs.push_back(make_pair(uid,'L'));
                break;
            case 'C':
                dict[uid] = name;
                break;
            default:break;      
        }
    }
    
    for(pair<string,char> q : in_outs)
    {
        if(q.second == 'C') continue;
        string ans = dict[q.first] + "님이 ";
        if(q.second == 'E') ans += "들어왔습니다";
        else if(q.second == 'L') ans += "나갔습니다";
        
        answer.push_back(ans + ".");
    }
    
    return answer;
}
```
	
## 참고
**stringstream**이라는 게 있다고 합니다. 다른 사람의 풀이 중에서 참고했는데, 공백이나 줄 바꿈 문자를 제외하고 쓸만한 것들을 가져오는 데 좋은 방법이라고 하네요. 코드를 예쁘게 만들어주는 데 좋을 것 같습니다.

## Refs
c++ reference

## 느낀 점
난이도가 낮은 카카오 문제는 항상 지저분한 코드가 나오고, 깔끔하게 구현하려면 아는 게 많아야 한다고 느꼈습니다.