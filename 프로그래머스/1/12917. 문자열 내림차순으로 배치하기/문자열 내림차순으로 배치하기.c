#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// 뒤로갈수록 아스키 코드 값이 커지는 것을 활용 

char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(s);
    char* answer = (char*)malloc(len +1);
    strcpy(answer,s);
    for(int i =0; i < len; i++ )
    {
        for(int j =i+1; j<len;j++)
        {
             if(answer[i]<answer[j])
             {
                 char temp = answer[i];
                 answer[i]=answer[j];
                 answer[j] = temp;
             }
        }
       
    }
    return answer;
}