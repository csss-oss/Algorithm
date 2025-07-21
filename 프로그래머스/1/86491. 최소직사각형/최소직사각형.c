#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//두개의 원소 중에 큰값을 왼쪽에 몰고 배열 전체중에서 오른쪽에 있는 원소 중 가장 작은 값과
//왼쪽에 있는 원소 중 가장 큰 값을 곱한 값을 리턴
// sizes_rows는 2차원 배열 sizes의 행 길이, sizes_cols는 2차원 배열 sizes의 열 길이입니다.
int solution(int** sizes, size_t sizes_rows, size_t sizes_cols) {
    int answer = 0;
     int max_width = 0;
    int max_height = 0;
    int temp;
    for(int i =0; i<sizes_rows; i++)
    {
        if(sizes[i][0]<sizes[i][1])
            {
                temp = sizes[i][0];
                sizes[i][0]= sizes[i][1];
                sizes[i][1] = temp;
            }
        
        if(sizes[i][0]> max_width)
            max_width = sizes[i][0];
        
        if(sizes[i][1] >max_height)
            max_height = sizes[i][1];
    }
    return max_width * max_height;
}