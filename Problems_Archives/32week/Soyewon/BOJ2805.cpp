// #2805. 나무 자르기

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n; // 나무의 수
    long long m; // 가져가고자 하는 나무의 길이
    long long ans=0; // 절단기 높이 H (0보다는 커야 하므로 0으로 초기화)
    long long start, end, mid, sum;
    
    cin >> n >> m;
    int tree[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> tree[i];
    }
    sort(tree, tree+n); // 이분 탐색 위해 정렬

    start = 0; // 처음 시작
    end = tree[n - 1]; // 나무 중 가장 큰것(끝)

    while(start <= end)
    {
        sum = 0;
        mid = (start + end) / 2;

        for(int i = 0 ; i < n ; i++) // 순차적으로 이진탐색
        {
            if(tree[i] - mid > 0) 
            {
                sum += tree[i] - mid; // 잘린 나무 길이들의 합
            }
        }
        
        if(sum >= m) // 잘린 나무 길이들의 합 > 가져가고자 하는 나무길이 일 때, 
        {
            start = mid + 1; // 최대한 M만큼 가져가게 하기 위해 절단높이 H 증가시키기
            if(mid > ans) 
            {
                ans = mid;
            }
        }
        else // 잘린 나무 길이들의 합 < 가져가고자 하는 나무길이 일 때, 절단높이 H 감소시키기
            end = mid - 1; 
    }

    cout << ans;
    
    return 0;
}
