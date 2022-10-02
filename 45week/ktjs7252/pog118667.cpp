
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    queue<int> q1;
    queue<int> q2;
    long long sum1=0;
    long long  sum2=0;

    for(int i=0;i<queue1.size();i++)
    {
        sum1+=queue1[i];
        q1.push(queue1[i]);
    }
    for(int j=0;j<queue2.size();j++)
    {
        sum2+=queue2[j];
        q2.push(queue2[j]);
    }
    int counting=0;
    while(1)
    {
        if(sum1==sum2){
            break;
        }
        if(counting>290000){
            return -1;
        }
        if(sum1>sum2){
            int tmp=q1.front();
            q1.pop();
            q2.push(tmp);
            sum1-=tmp;
            sum2+=tmp;
            counting++;
        }
        else{
            int tmp=q2.front();
            q2.pop();
            q1.push(tmp);
            sum1+=tmp;
            sum2-=tmp;
            counting++;
        }
    }

    answer=counting;

    return answer;
}
