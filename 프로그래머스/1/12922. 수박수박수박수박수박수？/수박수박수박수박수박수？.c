#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(int n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    
    char* answer = (char*)malloc(n*strlen("수")+1);// 한글의 크기는 3바이트이므로 strlen을써서 그 크기만큼 동적할당+1은 널문자 처리
    strcpy(answer,"");//쓰레기값 제거
    for(int i=0; i<n; i++)
    {
        if(i %2 ==0) //짝수이면0,2이면 수를 넣어야하므로
        {
            strcat(answer,"수");
        }
        else //홀수일때는 박을 넣는다
        {
             strcat(answer,"박");
        }
    }
    return answer;
}
