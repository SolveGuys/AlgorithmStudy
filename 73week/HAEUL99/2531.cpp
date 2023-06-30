#include <bits/stdc++.h>
using namespace std;

int n, d, k, c;
int arr[30002];
int isvis[3002]; // 수열에 들어있는 초밥의 종류별 개수
int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> d>> k >> c;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int en = 0; 
    //while문을 보면 en이 1부터 시작하기 때문에 en가 0일때 처리를 해주고 시작함(ex. count, num, isvis[arr[0]]을 1로 설정)
    int count = 1; // 연속해서 먹는 접시 수 
    int num = 1; //현재 수열에 들어있는 다른 종류의 초밥 수
    bool isC = false; //c종류 초밥이 있는지 체크
    int mx = 0; // 초밥 가짓수의 최댓값
    isvis[arr[0]] += 1;
    for(int st = 0; st < n; st++)
    {   
        while(count < k) 
        {
            count++;
            en++;
            if(en == n) {en = 0;}
            if(isvis[arr[en]] == 0) {num++;} // 수열에 해당 종류의 초밥이 없으면
            if(arr[en] == c) {isC = true;} // 해당 종류 초밥이 c이면 
            isvis[arr[en]] += 1; 
            
        }

        if(isC)
        {
            mx = max(mx, num);
        }
        else
        {
            mx = max(mx, num + 1);
        }

        //st 다음 값으로 옮기기 전 처리
        if(arr[st] == c && isvis[arr[st]] == 1) 
        {
            isC = false;
        }

        if(isvis[arr[st]] == 1)
        {
            num -= 1;
        }

        isvis[arr[st]] -= 1; 
        count -= 1;
        
    }

    cout << mx;

 
}
