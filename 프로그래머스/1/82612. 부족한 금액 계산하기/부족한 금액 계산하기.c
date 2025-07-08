#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//놀이기구 이용금액 식을 구한다음에 

long long solution(int price, int money, int count) {
    long long answer = 0;
    long long a =0; //놀이기구 이용 금액
    for(long long i =1; i<=count; i++)
    {
        a +=  (long long)price * i;
    }
    printf("%ld",a);
    if(money > a)
    {
        answer =0;
    }
    else
    {
        answer = a - money;
    }
    return answer;
}