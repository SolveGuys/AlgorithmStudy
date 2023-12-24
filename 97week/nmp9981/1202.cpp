#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;//이름공간 선언

int main() {
  cin.tie(0); //실행속도 향상
  //입력
  int n,k;
  cin>>n>>k;
  
  vector<vector<int>> ruby(n,vector<int>(2,0));
  vector<int> weight;
  for(int i=0;i<n;i++){
    cin>>ruby[i][0]>>ruby[i][1];
  }
  for(int i=0;i<k;i++){
    long long x;
    cin>>x;
    weight.push_back(x);
  }

  //정렬
  sort(ruby.begin(),ruby.end());
  sort(weight.begin(),weight.end());

  long long result = 0;
  int idx = 0;
  //무게제한보다 낮은 것은 모두 가방에 넣기
  priority_queue<long long> pq;//최대힙
  for(int i=0;i<k;i++){
    //보석은 총 n개
    while(idx < n && ruby[idx][0]<=weight[i]){
      pq.push(ruby[idx][1]);//가치를 넣기
      idx += 1;
    }
    //보석 가치 더하기
    if(!pq.empty()){
      result += pq.top();
      pq.pop();
    }
  }
  //출력
  cout<<result<<endl;
  return 0;
}
