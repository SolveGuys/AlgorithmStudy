#include <iostream>
#include <queue>
using namespace std;

int n,x;
priority_queue<int> maxQ;//최대 힙
priority_queue<int, vector<int>, greater<int>> minQ;//최소 힙

//말하기
void Speak() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        //번갈아가면서 원소 넣기
        if (i%2 == 0) maxQ.push(x);
        else minQ.push(x);

        //swap
        if (minQ.size() > 0) {//최소힙에 원소가 있을때만
            if (minQ.top() < maxQ.top()) {//최대힙이 더 크다
                int temp = maxQ.top();
                maxQ.pop();
                maxQ.push(minQ.top());
                minQ.pop();
                minQ.push(temp);
            }
        }
        cout << maxQ.top() << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Speak();//말하기
    return 0;
}
