#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b) {
    long long answer = 0;
    if(a>b)
    {
        answer =a+b;
        for(int i = b+1; i< a; i++)
        {
            answer+=i;
        }
    }
    else if(a==b)
    {
        answer =a;
    }
    else
    {
         answer =a+b;
        for(int i = a+1; i< b; i++)
        {
            answer+=i;
        }
    }
    return answer;
}