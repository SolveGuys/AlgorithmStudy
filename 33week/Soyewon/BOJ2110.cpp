#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, c; // n-집 좌표 c-공유기 개수
vector<int> home;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> c;
    for(int i=0; i<n; i++) // 공유기 위치 받기
    {
        int tmp;
        cin >> tmp;
        home.push_back(tmp);
    }
    sort(home.begin(), home.end()); // 집 위치 오름차순 정렬

    int start_dis = 0; // 처음 간격 초기화
    int end_dis = home[n-1] - home[0]; // 첫번째~마지막 공유기 사이 간격
    int ans = 0; // 최종 최대간격

    while(start_dis <= end_dis)
    {
        int mid = (start_dis + end_dis)/2;
        int installed = 1; // 첫번째 집에 공유기 설치하고 시작
        int prev_c = home[0]; // 전에 설치한 공유기 위치 (첫번째 집 위치로 초기화)

        for(int i=0; i<n; i++)
        {
            if(home[i]-prev_c >= mid) // 다음 집과 현재 공유기를 설치한 집 사이의 dis가 mid보다 크거나 같을 때
            {
                installed+=1; // 공유기 설치
                prev_c = home[i];
            }
        }

        if(installed >= c) // 설치한 공유기 개수가 c보다 크거나 같을 때 ( 간격 좁음 의미 )
        {
            ans = mid;
            start_dis = mid+1; // 간격 넓혀주기 위해 mid+1
        }
        else
        {
            end_dis = mid-1; // 간격 좁혀주기 위해 mid-1
        }
    }

    cout << ans;
    return 0;
}
