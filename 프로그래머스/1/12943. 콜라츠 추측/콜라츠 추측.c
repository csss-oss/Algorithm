#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num) {
    int answer = 0;
    long long NUM = num;
    while(NUM != 1)
    {
        if(NUM % 2 == 0) //짝수라면
        {
            NUM /= 2;
          
        }
        else //홀수라면
        {
            NUM = NUM * 3 + 1;
        }
        answer++;
        if(answer>500)
        {
            answer = -1;
            break;
        }
        printf("num = %d\n",NUM);
    }
    
   return answer;
  
}