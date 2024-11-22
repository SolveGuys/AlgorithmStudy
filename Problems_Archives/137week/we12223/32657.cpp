#include <bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
int dp1[1007][107] = {0};
int dp22[1007][107] = {0};
int move1[1007][2] = {0};
int left1[107] = {0};
int right1[107] = {0};
int A[107] = {0};
void dfs1(int x, int cur){
    if (cur > 99) return;
    if (dp1[x][cur]) return;
    dp1[x][cur] = 1;
    if (cur > 0 && x == 1) return;
    dfs1(move1[x][0],cur+1);
    dfs1(move1[x][1],cur+1);
}
void dfs2(int x, int cur){
    if (cur > 99) return;
    if (dp22[x][cur]) return;
    dp22[x][cur] = 1;
    if (cur > 0 && x == 1) return;
    dfs2(move1[x][0],cur+1);
    dfs2(move1[x][1],cur+1);
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> move1[i][0] >> move1[i][1];
    }
    dfs1(move1[1][0],1);
    dfs2(move1[1][1],1);
    for (int i = 0; i <= 99; i++){
        if (dp1[1][i]){
            left1[i] = 1;
        }
    }
    for (int i = 0; i <= 99; i++){
        if (dp22[1][i]){
            right1[i] = 1;
        }
    }
    A[0] = 1;
    for (int i = 1; i <= 99; i++){
        int fi = 0;
        int se = 0;
        for (int j = 0; j < i; j++){
            if (A[j] && left1[i-j]){
                fi = 1;
            }
        }
        for (int j = 0; j < i; j++){
            if (A[j] && right1[i-j]){
                se = 1;
            }
        }
        if (fi && se){
            A[i] = 1;
        }
    }
    for (int i = 10; i <= 99; i++){
        if (!A[i]){
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}