#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
<실패>
알고리즘 분류 : 그리디
cap 만큼 실을 수 있다. 총 이동 거리 합 최소 구하기.

1) 가능한 알고리즘이 없었음 -> 그냥 구현으로 하는 문제
2) 아이디어
    - 배달/수거 상관 없이 가장 먼 곳부터 가는게 맞다 (역방향 for)
    - 배달/수거를 하는 순서는 상관이 없다. (d, p 변수로 cap 넘지 않을 만큼 따로 수행한다.)

=> 한번 이동 시에 박스가 있는 가장 먼 곳에서 부터 돌아오면서 처리해준다.
**/

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int d = 0, p = 0, cnt = 0;

    // d, p를 0에서 시작하고 집으로 배달 가는 거만 고려해 줌. 
    // 1) 처음에 물류 창고에서 가는 거 1회. 
    //    d=0, p=0 -> d-=deliveries, p-pickups
    //    cnt+=1
    // 2) 다음으로 박스를 수거, 배달 하면서 0보다 작아지면 cnt++;
    for (int i = n - 1; i >= 0; i--) {
        d -= deliveries[i];
        p -= pickups[i];

        while (true) {
            if (d >= 0 && p >= 0)
                break;
            d += cap;
            p += cap;
            cnt++;
        }
        answer += (i + 1) * 2 * cnt;
        cnt = 0;
    }
    return answer;
}
