#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 10;
const int RED = 100, BLUE = 200;

struct Marble {
    int ry, rx, by, bx;
    int r_goal = 0, b_goal=0;
    int prev = -1;
    int cnt = 0;
};

int N, M;
Marble H;
char board[MAX][MAX];

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

Marble move(Marble now, int i) {
    /*
    int prx = now.rx;
    int pry = now.ry;
    int pbx = now.bx;
    int pby = now.by;
    */
    while (board[now.ry][now.rx] != '#') {
        now.rx += dx[i];
        now.ry += dy[i];
        if (board[now.ry][now.rx] == 'O') {
            now.r_goal = 1;
            break;
        }
    }
    while (board[now.by][now.bx] != '#') {
        now.bx += dx[i];
        now.by += dy[i];
        if (board[now.by][now.bx] == 'O') {
            now.b_goal = 1;
            break;
        }
    }

    now.by -= dy[i];
    now.ry -= dy[i];
    now.bx -= dx[i];
    now.rx -= dx[i];
    now.prev = i;
    now.cnt++;
    return now;

}
int BFS(Marble Marbles) {
    queue<Marble> q;
    q.push(Marbles);

    while (!q.empty()) {
        Marble now = q.front();
        q.pop();

        // cnt 10ȸ �ʰ��� �ȵ�. 
        if (now.cnt >= 10) continue;
        
        for (int i = 0; i < 4; i++) {
            int rx_prev = now.rx < now.bx ? 1 : 0;
            int ry_prev = now.ry < now.by ? 1 : 0;
            Marble next = move(now, i);
            //�Ķ��� ����ϸ� �̰� ���̻� ������� ����.
            if (next.b_goal) continue;
            
            // ���� ���� ���� ����ߴٸ� return 1
            if (next.r_goal)
            {
                //cout << "x :"<<next.bx << " y:" << next.by << '\n';
                return 1;
            }

            if (next.ry == next.by && next.rx == next.bx) {
                if (now.ry == now.by) {
                    //�������� ���ʿ� �ְ� �������� ����� ���ų� �������� �������̰� ����������
                    if ((rx_prev && i == 2) || (!rx_prev && i == 3)) next.bx -= dx[i];
                    // �������� ���ʿ� �ְ� ���������� ����� ���ų� �������� �������̰� ��������
                    else if ((rx_prev && i == 3) || (!rx_prev && i == 2)) next.rx -= dx[i];
                }
                else if (now.rx == now.bx) {
                    //�������� ���ʿ� �ְ� �������� ����� ���ų� �������� �Ʒ����̰� �Ʒ���
                    if ((ry_prev && i == 0) || (!ry_prev && i == 1)) next.by -= dy[i];
                    // �������� ���ʿ� �ְ� �Ʒ������� ����� ���ų� �������� �Ʒ��̰� ��������
                    else if ((ry_prev && i == 1) || (!ry_prev && i == 0)) next.ry -= dy[i];
                }
            }
            
            if(next.cnt<=10) q.push(next);
        }
    }
    return 0;

}

int main() {
    cin >> N >> M;

    Marble Marbles;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> board[y][x];
            if (board[y][x] == 'B') { Marbles.bx = x; Marbles.by = y; }
            else if (board[y][x] == 'R') { Marbles.rx = x; Marbles.ry = y; }
        }
    }

    cout << BFS(Marbles);

}