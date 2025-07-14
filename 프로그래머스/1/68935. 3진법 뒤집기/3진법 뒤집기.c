#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solution(int n) {
    int answer = 0;
    int i = 0;
    int temp = n;
    int power_of_3 = 1;
  
    int a[20] = {0,};
    int b[20];
    while(temp >0)
    {
        a[i++] = temp %3;
        temp /= 3;
    }
    for(int j = 0; j<i; j++)
    {
       b[j] = a[i-1-j];
    }
    for(int j = 0; j<i; j++)
    {
       answer += (b[j]*power_of_3);
        power_of_3*=3;
    }
    
    return answer;
}

