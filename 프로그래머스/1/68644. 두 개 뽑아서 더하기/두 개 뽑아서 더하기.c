#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
    int* answer = NULL;
    // 가능한 최대 합의 개수를 예상하여 충분히 큰 임시 배열을 동적 할당
    // nC2 = n * (n-1) / 2. numbers_len이 100이면 약 4950개.
    // 201은 너무 작으므로, 충분히 크게 잡거나 정확히 계산해야 함.
    // 문제의 제약사항 (numbers_len <= 100)을 고려하여 최대 100 * 99 / 2 = 4950
    // 따라서 임시 배열 temp_sums는 4950 + @ 여유 공간으로 선언
    // numbers 원소는 0~100. 합은 0~200.
    // 여기서는 동적으로 할당하여 유연하게 처리합니다.
    int max_sums_count = numbers_len * (numbers_len - 1) / 2;
    int* temp_sums = (int*)malloc(sizeof(int) * max_sums_count);
    if (temp_sums == NULL) {
        // 메모리 할당 실패 처리
        return NULL;
    }

    int current_sum_count = 0; // temp_sums 배열에 저장된 합의 실제 개수

    // 두 숫자의 합 계산 및 temp_sums 배열에 저장
    for (int i = 0; i < numbers_len - 1; i++) {
        for (int j = i + 1; j < numbers_len; j++) {
            temp_sums[current_sum_count++] = numbers[i] + numbers[j];
        }
    }

    // temp_sums 배열 정렬
    qsort(temp_sums, current_sum_count, sizeof(int), compare);

    // 중복 제거 및 최종 answer 배열에 복사
    // 중복 제거 후 answer 배열에 들어갈 요소의 최대 개수는 current_sum_count와 같거나 작음.
    // 따라서 answer 배열을 위한 메모리를 먼저 할당하고, 필요한 만큼만 값을 복사.
    // 최종적으로 사용된 개수를 세어 realloc으로 메모리 크기를 조정.

    // 첫 번째 요소를 answer에 추가
    int unique_count = 0;
    if (current_sum_count > 0) {
        answer = (int*)malloc(sizeof(int) * current_sum_count); // 일단 최대 크기로 할당
        if (answer == NULL) {
            free(temp_sums);
            return NULL;
        }
        answer[unique_count++] = temp_sums[0];

        // 나머지 요소들 중 중복되지 않는 것만 추가
        for (int i = 1; i < current_sum_count; i++) {
            if (temp_sums[i] != temp_sums[i - 1]) { // 이전 값과 다를 경우에만 추가
                answer[unique_count++] = temp_sums[i];
            }
        }
    } else {
        // numbers_len이 0 또는 1이어서 합이 없는 경우
        answer = (int*)malloc(sizeof(int)); // 최소한 널 포인터가 아닌 유효한 포인터를 반환
        if (answer == NULL) {
            free(temp_sums);
            return NULL;
        }
        unique_count = 0; // 합이 없으므로 고유한 값도 없음
    }

    // 최종적으로 사용된 unique_count 만큼 메모리 재할당 (선택 사항이지만 좋은 습관)
    int* final_answer = (int*)realloc(answer, sizeof(int) * unique_count);
    if (final_answer == NULL) {
        // realloc 실패 시 원래 answer는 여전히 유효함.
        // 이 경우에는 answer를 반환하거나 에러 처리.
        // 여기서는 그냥 answer를 반환하도록 처리
        free(temp_sums);
        return answer;
    }
    answer = final_answer;


    free(temp_sums); // 임시 배열 메모리 해제

    return answer;
}