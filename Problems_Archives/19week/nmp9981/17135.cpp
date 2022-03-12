#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n,m,k;
const int maxi=16;
int ori_world[maxi][maxi];//지도
int world[maxi][maxi];//복사본
vector<pair<int,pair<int,int>>> enemy;//적
bool archer[maxi];//궁수
vector<int> bowman;//궁수 위치
int res = 0;

//입력
void input(){
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) cin>>ori_world[i][j];
	}
}
//맵 복사
void copy_map(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			world[i][j] = ori_world[i][j];
		}
	}
}
//적 담기 
bool enemies(int ax){
	enemy.clear();//초기화
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(world[i][j]==1){
				//맨해튼 거리
				int dist = abs(j-ax)+n-i;
				//사정거리 내
				if(dist>k) continue;
				enemy.push_back({dist,{j,i}});
			}
		}
	}
	if(enemy.size()==0) return false;//적이 없다
	sort(enemy.begin(),enemy.end());//정렬
	return true;
}
//적 이동
void move(int p){
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<m;j++){
			if(i<=p) world[i][j] = 0;
			else world[i][j]=world[i-1][j];
		}
	}
}
//모두 처리?
bool all_kill(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(world[i][j]==1) return false;
		}
	}
	return true;
}
//공격
int attack(){
	int total = 0;//총 제거한 적의 수
	copy_map();//맵 복사
	//초기화
	bowman.clear();
	//궁수 위치
	for(int i=0;i<m;i++){
		if(archer[i]==true) bowman.push_back(i);
	}
	//각 페이즈 별로
	for(int p=0;p<n;p++){
		vector<pair<int,int>> target;
	    //각 궁수 공격
	    for(int i=0;i<3;i++){
		    int bow_x = bowman[i];
		    if(enemies(bow_x)==false) continue;
		    //적 공격 위치
		    int x = enemy[0].second.second;
		    int y = enemy[0].second.first;
		    target.push_back({x,y});
	    }
	    //적 명중
	    for(int i=0;i<target.size();i++){
	    	int nx = target[i].first;
	    	int ny = target[i].second;
	    	if(world[nx][ny]==1){
	    		world[nx][ny]=0;
	    		total++;
	    	}
	    }
	    //모두 처리했는가?
	    if(all_kill()) break;
	    //적 이동
	    move(p);
	}
	return total;
}
//궁수선택
void select_archer(int cnt,int idx){
	if(cnt==3){//모두 배치했으면
		res = max(res,attack());//공격
	}
	//선택하기
	for(int i=idx;i<m;i++){
		if(archer[i]==true) continue;
		archer[i] = true;
		select_archer(cnt+1,i+1);
		archer[i] = false;
	}
}

int main(){
	input();//입력
	select_archer(0,0);//궁수선택
	cout<<res;//출력
	return 0;
}
