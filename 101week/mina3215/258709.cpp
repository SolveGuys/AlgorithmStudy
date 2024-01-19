#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> comb;
int sol1[502];
int sol0[502];

int combination(vector<int> v, int i, int n) {
    if (n == N / 2) {
        comb.push_back(v);
        return 0;
    }
    if (i >= N) return 0;

    v[i] = 1;
    combination(v, i + 1, n + 1);
    v[i] = 0;
    combination(v, i + 1, n);

    return 0;
}

void solved(vector<vector<int>>& dice, vector<int>& com, int d, int ans, int flag) {

    if (d == N) {
        if (flag) {
            sol1[ans]++;

        }
        else {
            sol0[ans]++;
        }

        return;
    }

    if (com[d] == flag) {
        for (int i = 0; i < 6; i++) {
            solved(dice, com, d + 1, ans + dice[d][i], flag);
        }
    }
    else {
        solved(dice, com, d + 1, ans, flag);
    }

}

vector<int> solution(vector<vector<int>> dice) {
    N = dice.size();
    vector<int> v(N);
    fill(v.begin(), v.end(), 0);
    v[0] = 1;
    combination(v, 1, 1);

    int ans;
    int flag = 1;
    int win_max = 0;

    vector<int> answer;

    for (int i = 0; i < comb.size(); i++) {
        fill(sol1, sol1 + 502, 0);
        fill(sol0, sol0 + 502, 0);
        solved(dice, comb[i], 0, 0, 1);
        solved(dice, comb[i], 0, 0, 0);
        int win1 = 0;
        int win0 = 0;
        for (int j = 1; j < 502; j++) {
            if (sol1[j]) {
                win1 += sol0[j - 1] * sol1[j];
            }if (sol0[j]) {
                win0 += sol1[j - 1] * sol0[j];
            }
            sol1[j] += sol1[j - 1];
            sol0[j] += sol0[j - 1];
        }
        if (win1 > win0 && win_max < win1) {
            ans = i;
            win_max = win1;
            flag = 1;
        }
        if (win0 > win1 && win_max < win0) {
            ans = i;
            win_max = win0;
            flag = 0;
        }

    }
    for (int i = 0; i < N; i++) {
        if (comb[ans][i] == flag) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}