#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<pair<int, int>> lecture;

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num, st, ed;
        cin >> num >> st >> ed;
        lecture.push_back({ st,ed });
    }
    sort(lecture.begin(), lecture.end());//시작시간 기준으로 오름차순 정렬
}

//강의실
void Classroom() {
    int room = 1;//처음 강의실
    priority_queue<int, vector<int>, greater<int>> pq;//최소힙(강의 종료시간)
    pq.push(lecture[0].second);

    for (int i = 1; i < n; i++) {
        int nextStart = lecture[i].first;//다음 강의 시작시간
        int endTime = pq.top();//가장 먼저 종료되는 강의

        if (endTime > nextStart) {
            room++;
            pq.push(lecture[i].second);
        }
        else {
            pq.pop();//강의실은 하나씩 뺀다
            pq.push(lecture[i].second);
        }
    }
    cout << room;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Classroom();//강의실
    return 0;
}
