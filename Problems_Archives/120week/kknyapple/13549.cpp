#include <iostream>
#include <deque>

using namespace std;

int n, k; // 수빈 현재 위치 n, 동생의 위치 k
int vv[100001];

void go(int here) {
    deque<int> q;
    q.push_back(here); // 수빈이의 현재 위치를 덱에 넣음
    vv[here] = 1;

    while (!q.empty()) { // 덱이 비어있지 않으면 반복
        int num = q.front(); // 큐의 맨 앞 원소를 꺼냄
        q.pop_front(); // 덱에서 제거, 순간이동 우선순위를 높게 처리 가능

        if (num == k) { // 현재 위치가 동생의 위치와 같으면 종료
            return;
        }

        // 순간이동 -> 뒤 -> 앞
        // num*2 위치로 이동 (순간이동, 0초 소요)
        if (num * 2 <= 100000 && vv[num * 2] == 0) { // 범위 내이고 아직 방문하지 않은 경우
            q.push_front(num * 2); // 가중치 0 간선으로 덱 앞에 삽입
            vv[num * 2] = vv[num]; // 시간 증가 없음
        }
        
        // num-1 위치로 이동 (걷기, 1초 소요)
        if (num - 1 >= 0 && vv[num - 1] == 0) { // 범위 내이고 아직 방문하지 않은 경우
            q.push_back(num - 1);
            vv[num - 1] = vv[num] + 1; // 시간 1초 증가
        }

        // num+1 위치로 이동 (걷기, 1초 소요)
        if (num + 1 <= 100000 && vv[num + 1] == 0) { // 범위 내이고 아직 방문하지 않은 경우
            q.push_back(num + 1);
            vv[num + 1] = vv[num] + 1; // 시간 1초 증가
        }
    }
}

int main() {
    cin >> n >> k;

    go(n); // bfs

    cout << vv[k] - 1 << "\n"; // 동생의 위치에 도달하는 데 걸린 시간 출력

    return 0;
}
