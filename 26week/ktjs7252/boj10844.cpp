#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// dp[N][k] : N길이의 숫자중, k란 수로 끝나는 경우.

// if dp[2][0] 
// else if dp[2][9]
// else dp[2][1~8]

int main(void)
{
    long long dp[101][10];
    int N;
    int i,j;
    long long answer=0;

    scanf("%d", &N);
    
    dp[1][0] = 0;
    for (i = 1; i < 10; i++)
    {
        dp[1][i] = 1;
    }
   
    for (i = 2; i <= N; i++)
    {
        
        for (j = 0; j < 10; j++)
        {
            if (j == 0)
            {
                dp[i][j] = (dp[i - 1][j + 1])% 1000000000;
            }
            else if (j == 9)
            {
                dp[i][j] = (dp[i - 1][j - 1]) % 1000000000;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
                
                /*
                if (i % 2 == 0)
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j + 1];
                }*/
            }
        }
    }


    for (i = 0; i < 10; i++)
    {
        answer += dp[N][i];

    }
    
    printf("%d", answer%1000000000);
    return 0;
}
