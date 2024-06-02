#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
<����>
�˰��� �з� : �׸���
cap ��ŭ ���� �� �ִ�. �� �̵� �Ÿ� �� �ּ� ���ϱ�.

1) ������ �˰����� ������ -> �׳� �������� �ϴ� ����
2) ���̵��
    - ���/���� ��� ���� ���� �� ������ ���°� �´� (������ for)
    - ���/���Ÿ� �ϴ� ������ ����� ����. (d, p ������ cap ���� ���� ��ŭ ���� �����Ѵ�.)

=> �ѹ� �̵� �ÿ� �ڽ��� �ִ� ���� �� ������ ���� ���ƿ��鼭 ó�����ش�.
**/

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int d = 0, p = 0, cnt = 0;

    // d, p�� 0���� �����ϰ� ������ ��� ���� �Ÿ� ����� ��. 
    // 1) ó���� ���� â���� ���� �� 1ȸ. 
    //    d=0, p=0 -> d-=deliveries, p-pickups
    //    cnt+=1
    // 2) �������� �ڽ��� ����, ��� �ϸ鼭 0���� �۾����� cnt++;
    for (int i = n - 1; i >= 0; i--) {
        d -= deliveries[i];
        p -= pickups[i];

        while (true) {
            if (d >= 0 && p >= 0)
                break;
            d += cap;
            p += cap;
            cnt++;
        }
        answer += (i + 1) * 2 * cnt;
        cnt = 0;
    }
    return answer;
}
