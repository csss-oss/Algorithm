#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(s);
    int* answer = (int*)malloc((len+1)*sizeof(int));// 길이 * 변수길이도 곱해줘야함.
    memset(answer,-1,sizeof(int)*len);// -1로 초기화해줘서 answer[0]에 -1안넣어도 됨
    for(int i = 1; i< len; i++)
    {
      
        for(int j= i-1; j>=0; j--)//s[i]값에서 가장가까운거부터 체크하기위해 1씩 줄여가면서 0보다 같거나큰수까지만체크
        {
            if(s[i] == s[j])
            {
                answer[i] = i-j;
                break;
            }
           
        }
    }
    return answer;
}