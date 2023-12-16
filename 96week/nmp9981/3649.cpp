#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int x,n;
vector<int> A;//수열
int changeUnit = 10000000;

//입력
void input() {
    A.clear();
    for (int i = 0; i < n; i++) {
        int na; cin >> na;
        A.push_back(na);
    }
    sort(A.begin(), A.end());//오름차순 정렬
}
//선택
void Select() {
    int left = 0;
    int right = A.size()-1;
    while (left < right) {
        int diff = A[right] + A[left];
        if (diff == x * changeUnit) {
            cout <<"yes " << A[left] << " " << A[right]<<"\n";
            return;
        }
        if (diff < x * changeUnit) left++;
        else if (diff > x * changeUnit) right--;
    }
    cout << "danger\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> x>>n) {
        input();//입력
        Select();//선택
    }
    return 0;
}
