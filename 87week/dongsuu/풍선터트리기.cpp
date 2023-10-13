#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    
    int lIdx = 0;
    int rIdx = a.size() - 1;
    int lMin = a[0];
    int rMin = a[a.size() - 1];
    
    while(lIdx+1 < rIdx){
        int left = lMin;
        int right = rMin;
        
        if(left < right){ // 오른쪽이 크면 오른쪽 이전값과 비교
            if(right < a[rIdx-1]){ // 좌, 우 구간의 최소값보다 모두 큰 경우 -> 남길 수 없음
                rIdx--;
            } else {
                answer++;
                rIdx--;
                rMin = a[rIdx];
            }
            
        } else if(left > right){
            if(left < a[lIdx+1]){ // 좌, 우 구간의 최소값보다 모두 큰 경우 -> 남길 수 없음
                lIdx++;
            } else {
                answer++;
                lIdx++;
                lMin = a[lIdx];
            }
        }
    }
    
    return answer + 2; // 양쪽 2개는 항상 가능
}
