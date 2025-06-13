#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    int answer = 0;
    int sum = 0;
    int count =0;
    for(int i = 0; i<nums_len; i++)
    {
        for(int j= i+1; j<nums_len; j++)
        {
            for(int k = j+1; k<nums_len; k++)
            {
                 sum = nums[i]+nums[j]+nums[k];
                count = 0;// 한번할때마다 카운트 증가시키기위해 포문돌때마다 한번씩 초기화
                for(int h =2; h*h <= sum; h++)// sum=15라고 하면 sqrt(sum)는 3.xxx 그러면 1,2,3을 비교할 수있는데
                    // 그 수중에 약수가 하나라도 있으면 소수가 아님 여기서 반대로 sum을 제곱해서 나타내면 위와 같음
                {
                    if(sum % h == 0)
                        count++;
                }
            
                if(count == 0)
                    answer++;
            }
        }
    }
    return answer;
}