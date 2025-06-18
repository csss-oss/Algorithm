#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    for(int i = 2; i<n; i++) //n이 3이고 나머지가 1이 되도록하는 나누는 수는 2부터시작, 1부터하면 다 나머지 1이니까
    {
        if(n % i == 1) //젤 처음 나머지가 1일때경우 그래야지 제일 작으니까
        {
            answer = i; //answer 에 가장 작은 나눈 수를 넣고 
            break; //반복문 빠져나와서 바로 answer가 리턴 될 수 있게 
        }
            
    }
    return answer;
}