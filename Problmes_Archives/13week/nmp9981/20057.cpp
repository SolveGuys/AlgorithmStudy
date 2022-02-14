#include <iostream>
#include <cstring>
using namespace std;

int n,r,c,length,total;
const int maxi = 499;
int maps[maxi][maxi];//지도
//축 방향
int dr[4] = {0,1,0,-1};
int dc[4] = {-1,0,1,0};
//흩날리는 모래 방향
int sr[4][10] = {
    {1,-1,2,-2,1,-1,1,-1,0,0},
    {-1,-1,0,0,0,0,1,1,2,1},
    {1,-1,2,-2,1,-1,1,-1,0,0},
    {1,1,0,0,0,0,-1,-1,-2,-1}
};
int sc[4][10] = {
    {1,1,0,0,0,0,-1,-1,-2,-1},
    {-1,1,-2,2,-1,1,-1,1,0,0},
    {-1,-1,0,0,0,0,1,1,2,1},
    {-1,1,-2,2,-1,1,-1,1,0,0}
};
//흩날리는 모래 비율
int scat[10] = {1,1,2,2,7,7,10,10,5,55};

//입력
void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maps[i][j];
        }
    }
}

//모래 이동
int sand(int r,int c,int dir){
    int outside = 0;//바깥으로 이동한 모래의 양
    int present_sand = maps[r][c];//현재 칸의 총 모래의 양
    //현재 칸이 0이면 다음으로 넘어간다.
    if(present_sand==0){
        return 0;
    }
    //모래가 쌓인다.
    for(int i=0;i<10;i++){
        int next_r = r + sr[dir][i];
        int next_c = c + sc[dir][i];
        int next_sand = maps[r][c]*scat[i]/100;
        //남은 모래 처리
        if(i==9){
            next_sand = present_sand;
        }
        //범위 내
        if(next_r>=0 && next_r<n && next_c>=0 && next_c<n){
            maps[next_r][next_c] += next_sand;
        }else{//범위 밖
            outside += next_sand;
        }
        present_sand -= next_sand;
    }
    maps[r][c] = 0;//모든 모래 이동
    return outside;
}

//토네이도 이동
void tornado(){
    r = n/2;c = n/2;//시작위치
    length = 0;//시작길이
    total = 0;//격자 바깥에 있는 모래의 양
    while(true){
        for(int dir=0;dir<4;dir++){
            if(dir%2==0){//직선 길이 증가
                length++;
            }
            //length만큼 직선이동
            for(int k=1;k<=length;k++){
                //다음 지점
                r = r + dr[dir];
                c = c + dc[dir];
                total+=sand(r,c,dir);//모래 누적
                //토네이도 소멸
                if(r==0 && c==0){
                    cout<<total;
                    return;
                }
            }
        }
    }
}

int main(){
    input();//입력
    tornado();//토네이도
    return 0;
}
