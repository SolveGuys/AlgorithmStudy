#include <string>
#include <vector>


using namespace std;

int board[102][102];

int solution(int m, int n, vector<vector<int>> puddles) {
    //fill(&dp[0][0],&dp[0][0]+102*102,0);
    for (vector<int> v : puddles) {
        board[v[1]][v[0]] = -1;
    }

    board[1][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i][j] == -1) { board[i][j] = 0; continue; }
            board[i][j] = (board[i - 1][j] + board[i][j - 1]) % 1000000007;
        }
    }


    return board[n][m];
}