#include<bits/stdc++.h> 
using namespace std;


int n, m, k, A[14][14], yangbun[14][14], ret;

vector<int> a[14][14];

const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

// 봄 + 여름
void springSummer() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 나무가 있는 칸인지 판별
            if (a[i][j].size() == 0) continue;
            int die_tree = 0;
            vector<int> temp;
            // 나이 순 정렬
            sort(a[i][j].begin(), a[i][j].end());
            
            // 영양소가 남으면 temp에 넣는다.
            for (int tree : a[i][j]) {
                if (yangbun[i][j] >= tree) {
                    yangbun[i][j] -= tree;
                    temp.push_back(tree + 1);
                }
                // 영양소 부족하면 die_tree
                else {
                    die_tree += tree / 2;
                }
            }

            // a[i][j] 의 나무 목록
            a[i][j] = temp;
            // 양분 추가
            yangbun[i][j] += die_tree;
        }
    }
}
void fall() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j].size() == 0) continue;
            for (int tree : a[i][j]) {
                if (tree % 5 == 0) {
                    for (int d = 0; d < 8; d++) {
                        int ny = i + dy[d];
                        int nx = j + dx[d];
                        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                        a[ny][nx].push_back(1);
                    }
                }
            }
        }
    }
}
void winter() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            yangbun[i][j] += A[i][j];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    fill(&yangbun[0][0], &yangbun[0][0] + 14 * 14, 5);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> y >> z; x--; y--;
        a[x][y].push_back(z);
    }
    for (int i = 0; i < k; i++) {
        springSummer();fall(); winter();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ret += a[i][j].size();
        }
    }
    cout << ret << "\n";
    return 0;
}