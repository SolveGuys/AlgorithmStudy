#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int n;
const int maxi=4001;
int a[maxi];int b[maxi];int c[maxi];int d[maxi];
vector<int> s1;vector<int> s2;//정렬 벡터
//입력
void input(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i]>>d[i];
}
//풀이
void solve(){
	//2개로 나누어 합을 구하기
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			s1.push_back(a[i]+b[j]);
			s2.push_back(c[i]+d[j]);
		}
	}
	sort(s1.begin(),s1.end());//오름차순
	sort(s2.begin(),s2.end(),greater<int>());//내림차순
	
	ll cnt = 0;
	int up=0;int down=0;
	int up_size = s1.size();
	int down_size = s2.size();
	while(1){
		if(up==up_size || down==down_size) break;//종료
		
		if(s1[up]+s2[down]>0) down++;
		else if(s1[up]+s2[down]<0) up++;
		else{//같을 경우
			ll cnt_up=0;ll cnt_down=0;
			while(up<up_size && s1[up]+s2[down]==0){
				cnt_up++;
				up++;
			}
			up--;
			while(down<down_size && s1[up]+s2[down]==0){
				cnt_down++;
				down++;
			}
			cnt+=(cnt_up*cnt_down);//개수 증가
		}
	}
	cout<<cnt;
}
int main(){
	input();
	solve();
	return 0;
}
