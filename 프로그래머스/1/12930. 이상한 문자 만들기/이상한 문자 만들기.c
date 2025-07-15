#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(s);
    char* answer = (char*)malloc(len+1);
    strcpy(answer,s);
    int word_idx = 0;
    for(int i =0; i <len; i++)
    {
        if(answer[i] == ' ')//공백을 만나면
        {
            word_idx = 0;
        }
        else//공백이 아닐때
        {
            if(word_idx %2 ==0)//짝수이면
            {
                if(answer[i] >= 'a' && answer[i]<= 'z')//소문자이면 그 수에 -32해서 대문자만듦
                 {
                     answer[i] = answer[i] -32;
                    
                 }
            }
          else //홀수번째이면
             {
                 if(answer[i] >= 'A' && answer[i]<= 'Z') // 대문자이니까 +32해서 소문자 만듦
                    {
                         answer[i] = answer[i] + 32;
                            
                    }       
             }
            word_idx++;
        }
    }
    return answer;
}