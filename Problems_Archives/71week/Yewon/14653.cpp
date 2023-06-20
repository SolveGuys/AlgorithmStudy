#include <iostream>

using namespace std;

 
const int MAX = 10000 + 1;

int n; // 사람 수
int k; // 총 메시지 개수
int q; // 정보를 알고 싶은 메시지 번호
pair<int, char> arr[MAX];
bool Read[26];

 

int main(void)

{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> q;

    for (int i = 1; i <= k; i++)
        cin >> arr[i].first >> arr[i].second;

    int unRead = arr[Q].first; 

    if(!unRead)
        cout << -1 << '\n';
    else {
        for(int i=1; i<=k; i++) {
            if(unRead <= arr[i].first) {
                int index = arr[i].second - 'A';
                Read[index] = true;
            }
        }

        for(int i=1; i<n; i++) {
            if(!Read[i])
                cout << char(i+65) << " ";
        }
        return 0;
    }
}
