// 백준 1697 - 숨바꼭질

#include <iostream>
#include <queue>

using namespace std;

int n,k;
bool check[100001]; // 중복 검사 막기
int ans = 0; // 최종 시간

int main()
{
    cin >> n >> k;
    queue<pair<int, int>> que; // 수빈의 <위치,시간> 큐
    que.push(make_pair(n, 0)); // 초기 시작위치 n, 시간 0
    check[n] = true;

    while(!que.empty())
    {
        int pos = que.front().first; // 수빈의 위치
        int time = que.front().second; // 수빈의 이동시간
        que.pop();
        

        // 동생 위치에 도달 시 시간 전달 후 반복문 탈출
        if(pos == k)
        {
            ans = time;
            break;
        }

        // 조건(이동 시 문제에서 제한한 범위 내에 있는지 여부) 검사 후, 큐에 이동 후의 위치와 시간 넣기
        if(pos+1>=0 && pos+1<100001)
        {
            if(!check[pos+1])
            {
                check[pos+1] = true;
                que.push(make_pair(pos+1, time+1));
            }
        }
        if(pos-1>=0 && pos-1<100001)
        {
            if(!check[pos-1])
            {
                check[pos-1] = true;
                que.push(make_pair(pos-1, time+1));
            }
        }
        if(2*pos>=0 && 2*pos<100001)
        {
            if(!check[2*pos])
            {
                check[2*pos] = true;
                que.push(make_pair(2*pos, time+1));
            }
        }
    }

    cout << ans << endl;
    return 0;
}
