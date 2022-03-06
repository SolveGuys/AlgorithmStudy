#include <iostream>
#include <cmath>
using namespace std;

//원 구조체 정의
struct circle{
    double x,y,r;
};

circle A,B;//두 원
double center_dist,s1,s2;///두 중심사이의 거리,넓이

//입력
void input(){
    cin>>A.x>>A.y>>A.r;
    cin>>B.x>>B.y>>B.r;
    //두 원으 중심간의 거리
    center_dist = sqrt(pow(abs(A.x-B.x),2)+pow(abs(A.y-B.y),2));
}

//넓이 구하기
double area(){
    if(center_dist<=abs(A.r-B.r)){//원안에 포함
        return min(A.r*A.r*M_PI,B.r*B.r*M_PI);
    }else if(center_dist>=A.r+B.r){//두 원이 접하지 않음
        return 0;
    }else{//일부만 겹침
        //각도구하기, 코사인법칙 활용
        double cos_a = (pow(A.r,2)+pow(center_dist,2)-pow(B.r,2))/(2*A.r*center_dist);
        double cos_b = (pow(B.r,2)+pow(center_dist,2)-pow(A.r,2))/(2*B.r*center_dist);
        double theta_a = 2*acos(cos_a);
        double theta_b = 2*acos(cos_b);
        //부채꼴-삼각형
        s1 = A.r*A.r*theta_a/2-A.r*A.r*sin(theta_a)/2;
        s2 = B.r*B.r*theta_b/2-B.r*B.r*sin(theta_b)/2;
    }
    return s1+s2;
}
int main(){
    input();//입력
    printf("%.3f",area());//넓이
    return 0;
}
