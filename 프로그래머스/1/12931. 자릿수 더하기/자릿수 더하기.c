#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    //숫자를 입력받아서 문자열로 만든다음 각각 자릿수를 배열로 쪼개서 그 쪼갠걸 다시 숫자로 만들어서 더하자 
    int temp = n;
    int count =0;
    while(temp > 0)
    {
        temp = temp / 10;
        count++;
    }
    
   char buf[100];
   sprintf(buf,"%d",n);
  
    for(int i = 0; i < count; i++)
    {
        answer += (buf[i] -'0');
    }
    return answer;
}