#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* phone_number) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(phone_number);
    char* answer = (char*)malloc(len + 1);
     //memset(answer,0,sizeof(len+1));
    strcpy(answer,phone_number);// phone_number는 원본을 건드리면 안되는 const형
    for(int i=0; i < len-4; i++)//끝에 4자리만 남기기때문에 len-4
    {
        answer[i] = '*'; //문자형태이므로 ""가 아닌 ''형태로
    }
    return answer;
}