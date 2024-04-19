#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
using namespace std;

int n, m, a[10][10], visited[10][10], ret;
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
vector<pair<int, int>> two;
vector<pair<int, int>> zero;

void go(int y, int x) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (visited[ny][nx])continue;
        if (a[ny][nx] == 1) continue;

        go(ny, nx);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2)two.push_back({ i,j });
            else if (a[i][j] == 0) zero.push_back({ i,j });
        }
    }

    for (int i = 0; i < zero.size(); i++) {
        for (int j = i + 1; j < zero.size(); j++) {
            for (int k = j + 1; k < zero.size(); k++) {
                a[zero[i].first][zero[i].second] = 1;
                a[zero[j].first][zero[j].second] = 1;
                a[zero[k].first][zero[k].second] = 1;

                fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
                
                for (int z = 0; z < two.size(); z++) {
                    go(two[z].first, two[z].second);
                } 
                int cnt = 0;
                for (int p = 0; p < n; p++) {
                    for (int q = 0; q < m; q++) {
                        if (a[p][q] == 0 && visited[p][q]==0) cnt++;
                    }
                }

                    ret = max(ret, cnt);

                a[zero[i].first][zero[i].second] = 0;
                a[zero[j].first][zero[j].second] = 0;
                a[zero[k].first][zero[k].second] = 0;
            }
        }
    }

    cout << ret << "\n";

    return 0;
}
