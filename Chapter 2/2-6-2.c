/*
 * 2-6-2. 연속부분수열의 합
 * 동적 프로그래밍으로 해결
 *
 * 시간복잡도 O(n)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int c[1000000];

int max(int num1, int num2) {
    if (num1 > num2) return num1;
    else return num2;
}

// M'(n)을 계산
void calculate_max_consecutive_sum(int arr[], int size) {
    c[0] = arr[0]; // 초깃값

    for (int i = 1; i < size; i++)
        c[i] = max(arr[i], arr[i] + c[i - 1]); // 다음 요소를 포함하게 되었을 때의 최댓값
}

// M(n)을 계산
int find_max_consecutive_sum(int arr[], int size) {
    int max = 0;
    for (int i = 0; i < size; i++) {
        if (c[i] > max)
            max = c[i];
    }
    return max;
}


int main() {
    int size = 1000000;
    srand(time(NULL));
    int arr[size];

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 201 - 100; // -100~100까지의 난수 생성
    }

    calculate_max_consecutive_sum(arr, size);
    printf("result : %d", find_max_consecutive_sum(arr, size));

    return 0;
}

