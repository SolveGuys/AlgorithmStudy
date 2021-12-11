#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxi = 20;//열쇠 최대 크기
const int lock_maxi = 58;//자물쇠 판 최대 크기
int m,n;
//4방향의 키
int key1[maxi][maxi];
int key2[maxi][maxi];
int key3[maxi][maxi];
int key4[maxi][maxi];
//자물쇠
int lock_board[lock_maxi+3][lock_maxi+3];
int home_cnt = 0;//자물쇠 홈의 개수

//회전하기
void rotation_key(vector<vector<int>> key){
    m = key.size();//열쇠 크기
    //정위치 열쇠
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            key1[i][j] = key[i][j];
        }
    }
    //90도 회전열쇠
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            key2[i][j] = key[j][m-i-1];
        }
    }
    //180도 회전열쇠
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            key3[i][j] = key[m-i-1][m-j-1];
        }
    }
    //270도 회전열쇠
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            key4[i][j] = key2[m-i-1][m-j-1];
        }
    }
}

//자물쇠 세팅
void set_lock(vector<vector<int>> lock){
    //전체판의 중앙에 세팅
    n = lock.size();//자물쇠 사이즈
    memset(lock_board,-1,sizeof(lock_board));//초기화
    int start = (lock_maxi-n)/2;//시작지점
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            lock_board[start+i][start+j] = lock[i][j];
            //자물쇠의 홈의 개수 구하기
            if(lock[i][j]==0){
                home_cnt++;
            }
        }
    }
}

//자물쇠 풀기
bool unlock(){
    //1~4번 열쇠로 풀기 시전
    int l = lock_maxi - n + 1;//시작할 최대 지점
    //1번 열쇠
    for(int i=0;i<l;i++){//시작지점
        for(int j=0;j<l;j++){
            //종료지점
            int end_x = i + m;
            int end_y = j + m;
            //구멍이 맞는가?
            int cnt = 0;//맞는 홈의 개수
            for(int x=i;x<end_x;x++){
                for(int y=j;y<end_y;y++){
                    //자물쇠가 맞으면
                    if(key1[x-i][y-j]==1 && lock_board[x][y]==0){
                        //돌기끼리 만나는게 있는가?
                        bool bump_meet = false;
                        for(int a=i;a<end_x;a++){
                            for(int b=j;b<end_y;b++){
                                //돌기끼리 만나면
                                if(key1[a-i][b-j]==1 && lock_board[a][b]==1){
                                    bump_meet = true;
                                    break;
                                }
                            }
                        }           
                        if(bump_meet == false){//돌기끼리 만나는게 없을 경우만
                            cnt++;
                        }
                    }
                }
            }
            //자물쇠 해제?
            if(cnt==home_cnt){
                return true;
            }
        }
    }
    //2번 열쇠
    for(int i=0;i<l;i++){//시작지점
        for(int j=0;j<l;j++){
            //종료지점
            int end_x = i + m;
            int end_y = j + m;
            //구멍이 맞는가?
            int cnt = 0;//맞는 홈의 개수
            for(int x=i;x<end_x;x++){
                for(int y=j;y<end_y;y++){
                    //자물쇠가 맞으면
                    if(key2[x-i][y-j]==1 && lock_board[x][y]==0){
                        //돌기끼리 만나는게 있는가?
                        bool bump_meet = false;
                        for(int a=i;a<end_x;a++){
                            for(int b=j;b<end_y;b++){
                                //돌기끼리 만나면
                                if(key2[a-i][b-j]==1 && lock_board[a][b]==1){
                                    bump_meet = true;
                                    break;
                                }
                            }
                        }           
                        if(bump_meet == false){//돌기끼리 만나는게 없을 경우만
                            cnt++;
                        }
                    }
                }
            }
            //자물쇠 해제?
            if(cnt==home_cnt){
                return true;
            }
        }
    }
    //3번 열쇠
    for(int i=0;i<l;i++){//시작지점
        for(int j=0;j<l;j++){
            //종료지점
            int end_x = i + m;
            int end_y = j + m;
            //구멍이 맞는가?
            int cnt = 0;//맞는 홈의 개수
            for(int x=i;x<end_x;x++){
                for(int y=j;y<end_y;y++){
                    //자물쇠가 맞으면
                    if(key3[x-i][y-j]==1 && lock_board[x][y]==0){
                        //돌기끼리 만나는게 있는가?
                        bool bump_meet = false;
                        for(int a=i;a<end_x;a++){
                            for(int b=j;b<end_y;b++){
                                //돌기끼리 만나면
                                if(key3[a-i][b-j]==1 && lock_board[a][b]==1){
                                    bump_meet = true;
                                    break;
                                }
                            }
                        }           
                        if(bump_meet == false){//돌기끼리 만나는게 없을 경우만
                            cnt++;
                        }
                    }
                }
            }
            //자물쇠 해제?
            if(cnt==home_cnt){
                return true;
            }
        }
    }
    //4번 열쇠
    for(int i=0;i<l;i++){//시작지점
        for(int j=0;j<l;j++){
            //종료지점
            int end_x = i + m;
            int end_y = j + m;
            //구멍이 맞는가?
            int cnt = 0;//맞는 홈의 개수
            for(int x=i;x<end_x;x++){
                for(int y=j;y<end_y;y++){
                    //자물쇠가 맞으면
                    if(key4[x-i][y-j]==1 && lock_board[x][y]==0){
                        //돌기끼리 만나는게 있는가?
                        bool bump_meet = false;
                        for(int a=i;a<end_x;a++){
                            for(int b=j;b<end_y;b++){
                                //돌기끼리 만나면
                                if(key4[a-i][b-j]==1 && lock_board[a][b]==1){
                                    bump_meet = true;
                                    break;
                                }
                            }
                        }           
                        if(bump_meet == false){//돌기끼리 만나는게 없을 경우만
                            cnt++;
                        }
                    }
                }
            }
            //자물쇠 해제?
            if(cnt==home_cnt){
                return true;
            }
        }
    }
    return false;//1~4번 열쇠 모두 안맞을때
}

//전체 과정
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    rotation_key(key);//회전
    set_lock(lock);//자물쇠 세팅
    //자물쇠 풀기
    if(unlock()==true){
        answer = true;
    }else{
        answer = false;
    }
    return answer;
}
