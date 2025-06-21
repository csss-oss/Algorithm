#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

long long solution(long long n) {
    long long answer = 0;
    long long sq = sqrt(n);
    if(n == pow(sq,2))
    {
        answer = pow(sq+1,2);
    }
    else
        answer =-1;
    
    return answer;
}