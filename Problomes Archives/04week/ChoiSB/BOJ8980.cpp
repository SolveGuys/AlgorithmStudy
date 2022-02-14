#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
struct Box {
    int from;
    int to;
    int cnt;
    bool operator< (const Box& other) { return to < other.to; }
};
constexpr int INF = 987'654'321;
int main()
{
    //입출력 성능향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N, C; // 마을 수 N, 트럭의 용량 C / N은 2이상 2,000이하 정수, C는 1이상 10,000이하 정수
    cin >> N >> C;
    int M; // 보내는 박스 개수(1이상 10,000이하 정수)
    cin >> M;
    vector<Box> boxes(M);
    for (int i = 0; i < M; ++i)
    {
        cin >> boxes[i].from >> boxes[i].to >> boxes[i].cnt;
    }
    sort(boxes.begin(), boxes.end());

    // i 위치에서 트럭의 빈공간(C로 초기화)
    vector<int> truck(N+1,C); 

    int idx{}; // box index
    int shippedBox{};
    for (int i = 1; i < N+1; ++i)
    {
        // 현재 집이 첫번째 박스의 목적지 앞에 있다면 continue
        if (boxes[idx].to > i) continue;

        while (idx < M && boxes[idx].to == i)
        {
            // 잔여공간
            int space{ INF };
            for (int j = boxes[idx].from; j < boxes[idx].to; ++j)
            {
                space = min(truck[j], space);
            }
            if (space >= boxes[idx].cnt) // 잔여 공간이 넉넉하다면
            {
                shippedBox += boxes[idx].cnt; // 배송된 상자 수에 현재 배송물량 모두 추가
                for (int j = boxes[idx].from; j < boxes[idx].to; ++j) // 각 위치 트럭의 빈공간 감소
                {
                    truck[j] -= boxes[idx].cnt;
                }
            }
            else if (space > 0) // 잔여공간이 조금 남았다면
            {
                shippedBox += space;
                for (int j = boxes[idx].from; j < boxes[idx].to; ++j)
                {
                    truck[j] -= space;
                }
            }
            idx++;
        }
    }

    //for (int i = 0; i < N+1; ++i)
    //{
    //    cout << C - truck[i] << " ";
    //}
    cout << shippedBox << endl;
    return 0;
}