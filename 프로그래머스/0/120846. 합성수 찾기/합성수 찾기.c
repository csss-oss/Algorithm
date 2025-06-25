#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int divisor = 0;
    for(int i =2; i<=n; i++)
    {
        for(int j =2; j<=i; j++)
        {
            if(i%j == 0)
            {
                divisor++;
            }
        }
          if(divisor >= 2)
            {
                divisor =0;
                answer++;
                printf("%d ",i);
             }
        divisor= 0;
    }
    
    return answer;
}