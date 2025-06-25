#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len) {
    int answer = 45; // 0~9까지 더한 수 
    for(int i =0; i<numbers_len; i++)
    {
       answer -= numbers[i];  // 넘버스배열에 있는 값들을 하나씩 빼서 나온 최종 값이 없는 숫자를 모두 더한 값과 같음 
    }
    return answer;
}