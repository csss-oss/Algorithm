#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

long long solution(int k, int d) {
    long long answer = 0;
    //점 찍는 건 카운트 
    // d가 4인경우는 0~4 
    //k가 2인경우 2씩 증가 해서 점을 찍음 첨에 x좌표는 0을 고정한채로 y좌표가 d까지
    //카운트가 총 몇인지를 리턴하면됨
    //a^2 + b^2 = d^2 -> a^2= d^2 - b^2
   
    for(long long x=0; x<=d; x+=k)
    {
       int maxY = sqrt((long long)d*d - (long long)x*x); // y=sqrt(d^2-x^2)
        answer += (maxY /k) +1;
        //구해지는 최대값 y에서 가능한 k배수의 개수 
        //즉 맥스 와이가 6이면 케이가 2이면  3개가나옴
        //즉 카운트 개수를 구하려고 저식을 쓴거임 
        //+1은 와이가 0일때 값
        
        
    }

    return answer;
}

