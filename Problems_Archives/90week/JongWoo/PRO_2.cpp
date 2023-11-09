#include <iostream>
#include <string>

using namespace std;

string solution(int n)
{
    string answer;
    char arr[] = { '4', '1', '2' };
    
    while (n > 0)
    {
        int reminder = n % 3;
        
        answer = arr[reminder] + answer;
        n /= 3;
        
        if (reminder == 0)
        {
            --n;
        }
    }
    
    return answer;
}
