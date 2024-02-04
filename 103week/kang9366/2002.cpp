#include <iostream>
#include <deque>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    string str;
    deque<string> dq1;
    queue<string> dq2;
    cin >> N;

    // 들어오는 자동차 번호를 dequeue에 저장
    for(int i = 0; i < N; i++) {
        cin >> str;
        dq1.push_back(str);
    }

    // 나오는 자동차 번호를 queue에 저장
    for(int i = 0; i < N; i++) {
        cin >> str;
        dq2.push(str);
    }

    int answer = 0;

    // deque와 queue가 빌때까지 반복
    while(!dq1.empty() && !dq2.empty()) {
        if(dq1.front() != dq2.front()) {
            // deque의 첫번째 원소와 queue의 첫번쨰 원소가 다른 경우
            answer++;
            dq1.erase(remove(dq1.begin(), dq1.end(), dq2.front()));
            dq2.pop();
        } else {
            // deque의 첫번째 원소와 queue의 첫번쨰 원소가 다른 경우
            dq1.erase(dq1.begin());
            dq2.pop();
        }
    }
    // 정답 출력
    cout << answer; 
}
