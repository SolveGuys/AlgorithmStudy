#include <string>
#include <vector>
using namespace std;

//max
inline int max(int x,int y){
    return x>y?x:y;
}
//연속된 0의 개수
int CountZero(vector<int> stones,int x){
    int stonesSize = stones.size();
    int cnt = 0;
    int maxCnt = 0;
    for(int i=0;i<stonesSize;i++){
        if(stones[i]-x<=0) cnt++;
        else {
            maxCnt = max(maxCnt,cnt);
            cnt = 0;
        }
    }
    maxCnt = max(maxCnt,cnt);
    return maxCnt;
}

//다리 건너기
int Bridge(vector<int> stones, int k){
    int left = 0;
    int right = 210000000;
    while(left<=right){
        int mid = (left+right)/2;
        if(CountZero(stones,mid-1)>=k) right = mid-1;//더 줄여야함
        else left = mid+1;//늘림
    }
    return right;
}
int solution(vector<int> stones, int k) {
    return Bridge(stones,k);
}
