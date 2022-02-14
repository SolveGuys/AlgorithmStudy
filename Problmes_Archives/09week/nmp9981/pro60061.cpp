#include <string>
#include <vector>
#include <cstring>

using namespace std;
const int maxi = 102;
int pillar[maxi][maxi];//겹치는 경우가 있어 기둥과 보를 분리
int beam[maxi][maxi];

//설치 조건
bool is_build(int x,int y,int z){
    //기둥
    if(z==0){
        if(y==0 || pillar[x][y-1]==0){//바닥위에 있거나 다른 기둥위
            return true;
        }else if(beam[x][y]==1 || (x>0 && beam[x-1][y]==1)){//보의 한쪽 끝부분 위
            return true;
        }
    }else if(z==1){//보
        //다른보와 동시 연결
        if((x>0 && beam[x-1][y]==1) && beam[x+1][y]==1){
            return true;
        //한쪽 끝부분이 기둥위
        }else if((y>0 && pillar[x][y-1]==0) || (y>0 && pillar[x+1][y-1]==0)){
            return true;
        }
    }
    return false;
}

//삭제 조건
bool is_del(int x,int y){
    //순회
    int search_x = max(0,x-1);
    for(int i=search_x;i<=x+1;i++){//다음지점까지 봐야함
        for(int j=y;j<=y+1;j++){
            //기둥삭제
            if(pillar[i][j]==0 && is_build(i,j,0)==false){
                return false;
            }
            //보삭제
            if(beam[i][j]==1 && is_build(i,j,1)==false){
                return false;
            }
        }
    }
    return true;
}

//기둥과 보 설치
void frame(vector<vector<int>> build_frame,int n){
    int size_build = build_frame.size();//벡터크기
    memset(pillar,-1,sizeof(pillar));//초기화
    memset(beam,-1,sizeof(beam));
    //조건에 따라 구조물 설치하기
    for(int i=0;i<size_build;i++){
        int x = build_frame[i][0];//x
        int y = build_frame[i][1];//y
        int inst = build_frame[i][2];//설치물
        int ox = build_frame[i][3];//설치여부
        if(inst==0){//기둥
            if(ox==1 && is_build(x,y,inst)==true){
                pillar[x][y] = 0;//기둥 설치
            }else{
                pillar[x][y] = -1;
                if(is_del(x,y)==false){
                    pillar[x][y] = 0;
                }
            }
        }else{//보
            if(ox==1 && is_build(x,y,inst)==true){
                beam[x][y] = 1;//보 설치
            }else{
                beam[x][y] = -1;
                if(is_del(x,y)==false){
                    beam[x][y] = 1;
                }
            }
        }
    }
}

//전체 요약
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    frame(build_frame,n);//기둥과 보 설치
    //설치한것 가져오기
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            //기둥먼저
            if(pillar[i][j]==0){
                answer.push_back({i,j,0});
            }
            if(beam[i][j]==1){
                answer.push_back({i,j,1});
            }
        }
    }
    return answer;
}
