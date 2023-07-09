#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

int palin(string s, int left, int right) // 블로그 참고 코드
{
    int ssize = s.size();
    while(left >= 0 && right < ssize)
    {
        if(s[left] != s[right])
        {
            break;
        }
        
        left -= 1;
        right += 1;
    }
    return right - left - 1;
}

int palin1(string s, int left, int right) // 내가 짠 코드
{
    int ssize = s.length();
    if(s[left] != s[right])
    {
        return 1;
    }
    while(left-1 >= 0 && right+1 < ssize)
    {
        left -= 1;
        right += 1;
        
        if(s[left] != s[right])
        {
            left+=1;
            right-=1;
            break;
        }
        
        
    }
    
    return right - left + 1;
}

int solution(string s)
{
    int answer = 1;
    int ssize = s.size();
    int odd, even;
    for(int i = 1; i < ssize; i++)
    {
        int left = i-1;
        int right = i+1;
        odd = palin(s, left, right);
        even = palin(s, left, right-1); 
        answer = max({answer, even, odd});    
    }
    return answer;
}
