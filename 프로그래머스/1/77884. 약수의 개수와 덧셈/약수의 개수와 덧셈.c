#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//약수의 개수 관련한 변수 선언,약수의 개수 구한 로직도 구현,
//약수의 개수가 짝수이면 answer에 left[0]+ , 홀수면  left [해당수] answer -=
int solution(int left, int right) {
    int answer = 0;
    int ans =0; //약수의개수
    for(int i =left; i<= right; i++)
    {
        for(int j =1; j<=i; j++)
        {
            if(i%j == 0)
                ans++;
        }
        if(ans % 2 ==0)//약수의 개수가 짝수라면
        {
            answer += i;
            ans =0;
        }
        else
        {
            answer -= i;
            ans=0;
        }
            
    }
    
    return answer;
}