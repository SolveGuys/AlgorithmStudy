#include <string>
#include <vector>
using namespace std;

const int maxi = 101;
int A[maxi][maxi];//배열
vector<int> answer;//정답 벡터

//min
inline int min(int x,int y){
    return x>y?y:x;
}
//배열 세팅(1~r*c)
void ArraySet(int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++) A[i][j] = i*c+j+1;
    }
}
//회전
void Rotation(int startR,int startC,int endR,int endC){
    int temp = A[startR][startC];//한 숫자는 따로 저장
    int minN = temp;//최솟값
    for(int i=startR+1;i<=endR;i++) {//서
        A[i-1][startC] = A[i][startC];
        minN = min(minN,A[i][startC]);
    }
    for(int j=startC+1;j<=endC;j++) {//남
        A[endR][j-1] = A[endR][j];
        minN = min(minN,A[endR][j]);
    }
    for(int i=endR-1;i>=startR;i--) {//동
        A[i+1][endC] = A[i][endC];
        minN = min(minN,A[i][endC]);
    }
    for(int j=endC-1;j>=startC;j--) {//북
        A[startR][j+1] = A[startR][j];
        minN = min(minN,A[startR][j]);
    }
    A[startR][startC+1] = temp;
    answer.push_back(minN);
}
//쿼리 탐색
void QueriesSearch(vector<vector<int>> queries){
    int queriesSize = queries.size();
    for(int i=0;i<queriesSize;i++){
        //회전 시작과 끝지점
        int startR = queries[i][0];
        int startC = queries[i][1];
        int endR = queries[i][2];
        int endC = queries[i][3];
        Rotation(startR-1,startC-1,endR-1,endC-1);//회전
    }
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    ArraySet(rows,columns);//배열 세팅
    QueriesSearch(queries);//쿼리 탐색
    return answer;
}
